# Phase 1 — The Spine
*Spec v1 — 2026-09-17. Blueprint only. No C++ changes.*

**Done when:** Scene 1 ("The Floor") plays start to finish — wake in the back bedroom, pick up the flashlight, "Two left," "Stuck. Always has been," the thud and "Pipes," phone on the floor, "Locked. From the outside," the note, the ring drawer, the key, out the door — and in the side yard the megaphone delivers the welcome line from the wall. Save, quit, load: fired lines stay fired.

## What exists today (and what happens to it)

| Asset | What it does now | Phase 1 |
|---|---|---|
| `Subtitles/SubtitlesStruct` | `SubtitleText`, `SpeakerName`, `Audio` | Superseded by `S_Line`. Leave in place until Scene 1 works, then delete with `DA_*`. |
| `Subtitles/BP_SubtitleData` + `Dialogue/DA_*` | Data assets holding arrays of lines | Superseded by `DT_Lines`. |
| `Subtitles/BP_SubtitleManager` | Placed trigger: on overlap, steps `CurrentData` with `PlayNextLine`, `Delay` by duration, `PlaySoundAtLocation`, `SetSubtitleText`, `PlayFadeInAnOut` | Its sequencing logic moves into `BP_Director`. Its trigger role becomes `BP_LineTrigger`. Retire after migration. |
| `Subtitles/WB_Subtitle` | Text + fade | **Kept and extended** (speaker tag, colour, italic). |
| `Save/BPI_Saveable` | `SaveData(SaveGameRef)`, `LoadData(SaveGameRef)` | Director implements it. |
| `Save/BP_SaveGame` | Save object | Gains four variables (below). |
| `Blueprints/Interface/BPI_Interact` | Interaction | `BP_Inspect` implements it; doors gain a `LockedLine` name. |

## New assets

```
Content/Story/
  E_Speaker            enum
  S_Line               struct (row type)
  BP_Director          actor, one per gameplay map
  BP_VoiceSource       actor, one per speaker position
  BP_LineTrigger       actor, box volume
  BP_Inspect           actor, box + BPI_Interact
  BFL_Story            function library: GetDirector
Content/Subtitles/
  DT_Lines             DataTable of S_Line   (lives here because this folder is
                                              already in the localization gather paths)
```

### `E_Speaker`
`Elias`, `Kidnapper`, `Survivor`, `Child`, `TV`

### `S_Line` — member names must match exactly (the CSV imports by name)

| Member | Type | Meaning |
|---|---|---|
| `Speaker` | E_Speaker | Who the subtitle tag names |
| `Text` | Text | Subtitle. Localizable. |
| `Sound` | Sound Base (object ref) | Empty for every Elias line except `E_S11_LAUGH` |
| `Source` | Name | `Phone` `Megaphone` `Radio` `HallPhone` `TV` `Tape` `Door` `World` = play from the matching `BP_VoiceSource`; `Ear` `Mind` `None` = 2D |
| `Act` | Integer | 0–5. `-1` = any act (pools only) |
| `Once` | Boolean | Never replays in one playthrough |
| `Duration` | Float | `0` = automatic |
| `Pool` | Name | `None`, `Yard`, `House`, `Basement`, `Episode`, `Blackout`, `SurvivorDoor` |

**Importing.** Drag `Design/Data/DT_Lines.csv` into `Content/Subtitles/`, choose *DataTable*, row type `S_Line`. **The CSV is the source of truth — never hand-edit the table.** To change a line, edit `Design/Data/build_lines_csv.py`, run `py -3 Design/Data/build_lines_csv.py`, then right-click `DT_Lines` → *Reimport*. When VO exists, name each sound asset after its row (`K_S03_WELCOME`) under `Content/Audio/VO/`; the script fills the `Sound` column automatically for every file it finds, so reimporting never wipes audio. If the `Speaker` column fails to import, tell me — user-defined enums occasionally want internal names and the script can emit those instead.

## `BP_Director`

One per gameplay map. Everything story-related asks it; it asks nobody.

**Variables**

| Name | Type | Notes |
|---|---|---|
| `Lines` | DataTable ref | `DT_Lines` |
| `Act` | Integer | 0 at start |
| `Flags` | Set of Name | Story state: `HasCottageKey`, `ReadKeyNote`, `SideDoorOpen`… |
| `FiredLines` | Set of Name | Row names already played |
| `Queue` | Array of Name | Waiting scripted lines |
| `bLinePlaying` | Boolean | |
| `bEliasRed` | Boolean | Set in Scene 10; never cleared |
| `PoolCooldown` | Float = 30 | Seconds between pool lines |
| `LastPoolTime` | Float | |
| `VoiceSources` | Map Name → BP_VoiceSource | Built on BeginPlay with *Get All Actors Of Class* |
| `SubtitleWidget` | WB_Subtitle ref | Created on BeginPlay, added to viewport |

**Event dispatchers** — `OnLineStarted(RowName, Speaker)`, `OnLineFinished(RowName)`, `OnFlagSet(Flag)`, `OnActChanged(NewAct)`. Phase 2's panic system listens to `OnLineStarted`; nothing in Phase 1 needs them, but add them now.

**Functions**

- `PlayLine(RowName)` — look up the row. If `Once` and already in `FiredLines`, return. Otherwise add to `Queue`; if `bLinePlaying` is false, call `PlayNext`.
- `PlaySequence(Array of Name)` — `PlayLine` for each, in order.
- `PlayFromPool(Pool)` — if a line is playing or `now − LastPoolTime < PoolCooldown`, return (pool lines are dropped, never queued). Loop *Get Data Table Row Names*; collect rows where `Pool` matches, `Act` is `-1` or the current act, and the row is not in `FiredLines`. If any, pick one at random, set `LastPoolTime`, `PlayLine`.
- `PlayNext` *(private)* — pop the first name; get the row; add it to `FiredLines`; set `bLinePlaying`; broadcast `OnLineStarted`; call `SubtitleWidget.ShowLine(Speaker, Text, bEliasRed)`; if `Sound` is valid, route it (below); compute the hold time — `Duration` if above zero, otherwise the larger of the sound's length and `1.2 + 0.06 × character count`; *Set Timer by Event* → `FinishLine`.
- `FinishLine` *(private)* — hide the subtitle; broadcast `OnLineFinished`; after a 0.35 s gap, `PlayNext` if the queue has entries, else clear `bLinePlaying`.
- `SetFlag(Name)` / `HasFlag(Name)` / `ClearFlag(Name)` — `SetFlag` broadcasts `OnFlagSet`.
- `SetAct(Integer)` — broadcasts `OnActChanged`.
- `SetEliasRed()` — sets `bEliasRed`.

**Routing a sound.** `Ear`, `Mind`, `None` → *Spawn Sound 2D*. Anything else → find `VoiceSources[Source]` and call its `PlayVoice(Sound, Act)`. If no source with that tag exists, play 2D and print a warning naming the tag — a missing megaphone should be loud in the log, not silent in the game.

**Rules.** One line at a time. Scripted lines queue; pool lines never do. The opening cinematic calls `PlayLine` from a Sequencer event track, so cinematic and gameplay subtitles look identical.

**Saving.** Implement `BPI_Saveable`. `SaveData`: write `Act`, `Flags`, `FiredLines`, `bEliasRed` into four new variables on `BP_SaveGame`. `LoadData`: read them back. Do not save `Queue`.

**`BFL_Story.GetDirector`** — *Get Actor Of Class (BP_Director)*. Pure. Every other Blueprint uses this; nobody stores a hard reference.

## `WB_Subtitle` — extend, don't replace

Add a speaker-tag TextBlock above the line. New function `ShowLine(Speaker, Text, bEliasRed)`:

| Speaker | Tag | Tag colour | Line style |
|---|---|---|---|
| Elias | `ELIAS` | White — **red when `bEliasRed`** | Italic |
| Kidnapper | `KIDNAPPER` | Red | Regular |
| TV | `TV` | Grey | Regular |
| Survivor | `MAN` | Grey | Regular |
| Child | `TAPE` | Grey | Regular |

The red used for the Kidnapper and for late-game Elias must be the *same* colour value — store it once as a variable. Keep `PlayFadeInAnOut` for the fade.

**Options menu:** the subtitles toggle may hide voiced lines only. Elias lines always show; they are the only channel he has.

## `BP_VoiceSource`

Variables: `SourceTag` (Name, instance-editable), `ChainsByAct` (array of Source Effect Preset Chain — leave empty in Phase 1). Components: an Audio Component with attenuation; an optional mesh. Function `PlayVoice(Sound, Act)`: if `ChainsByAct` has an entry for the act, apply it; set the sound; play. Blueprint-implementable events `OnVoiceStart` / `OnVoiceStop` for a radio light or a TV flicker later.

Phase 1 placements: `Megaphone` under the eave on the side wall; `Phone` at the cottage phone. The rest arrive with their scenes. For the radio and TV, place a `BP_VoiceSource` at the prop rather than editing `BP_NewRadio` / `BP_Television`.

## `BP_LineTrigger`

Box collision. Instance-editable: `Lines` (array of Name), `Pool` (Name, used when `Lines` is empty), `RequiredFlag`, `BlockedByFlag`, `SetsFlag`, `RequiredAct` (−1 = any), `bOnce` (true), `Delay` (seconds). On player overlap: check act and flags → wait `Delay` → `PlaySequence` or `PlayFromPool` → `SetFlag` → if `bOnce`, disable collision.

## `BP_Inspect`

Box collision + `BPI_Interact`. Instance-editable: `Lines`, `RequiredFlag`, `SetsFlag`. On interact: check flag → `PlaySequence` → `SetFlag`. It is the "look at a thing, Elias thinks a thing" actor: the pill bottle, the grocery list, the phone on the carpet, the boards on the front door.

**Doors.** Add one instance-editable Name to the door Blueprint: `LockedLine`. Where the door currently handles a failed open, call `GetDirector → PlayLine(LockedLine)`. The cottage front door gets `E_S01_LOCKED`; the cellar door gets `E_S01_STUCK`.

## Scene 1 wiring

| Where | Actor | Lines | Requires | Sets |
|---|---|---|---|---|
| Back bedroom, spawn | `BP_LineTrigger` (Delay 1.5) | `E_S01_FLOOR` | — | — |
| Nightstand | existing flashlight pickup | — | — | `HasFlashlight` |
| Bathroom, pill bottle | `BP_Inspect` | `E_S01_TWOLEFT` | — | — |
| Kitchen, cellar door | door `LockedLine` | `E_S01_STUCK` | — | `TriedCellar` |
| Kitchen | `BP_LineTrigger` + thud sound (Delay 2) | `E_S01_PIPES` | `TriedCellar` | — |
| Living room, phone on carpet | `BP_Inspect` | `E_S01_DROPPED` | — | — |
| Front door | door `LockedLine` | `E_S01_LOCKED` | — | `TriedFrontDoor` |
| Side table | existing `BP_Notes` | *(note text on the actor)* | — | `ReadKeyNote` |
| Ring drawer | existing drawer + key pickup | — | `ReadKeyNote` | `HasCottageKey` |
| Front door | existing key logic | — | `HasCottageKey` | `LeftCottage`; `SetAct(1)` |
| Side yard entry | `BP_LineTrigger` | `K_S03_WELCOME` | — | — |

The drawer should not open until the note has been read — otherwise the player finds the key by rummaging and the note means nothing.

## Build order — each step is testable before the next

1. `E_Speaker`, `S_Line`; import `DT_Lines`. *Test: open the table — 88 rows, speakers and acts correct, em dashes intact.*
2. `WB_Subtitle.ShowLine`. *Test: call it from the level Blueprint with each speaker; check tag, colour, italic, and red Elias.*
3. `BP_Director` with `PlayLine`, `PlayNext`, `FinishLine` only; `BFL_Story.GetDirector`. *Test: a key press plays `E_S01_FLOOR`; a second press does nothing (`Once`).*
4. `PlaySequence` and the queue. *Test: queue three lines; they play in order with gaps and never overlap.*
5. `BP_LineTrigger`, `BP_Inspect`, flags. *Test: "Pipes" only fires after the cellar door has been tried.*
6. Door `LockedLine`; wire the whole Scene 1 table. *Test: play Scene 1 cold, without touching the editor.*
7. `BP_VoiceSource` and routing; the megaphone. *Test: the welcome line comes from the wall and pans as you turn; remove the actor and confirm the warning prints.*
8. `PlayFromPool`. *Test: a yard trigger with `Pool = Yard` fires a different line on each re-entry and respects the cooldown.*
9. `BPI_Saveable` on the Director. *Test: play half of Scene 1, save, quit to menu, load — fired lines stay silent and the flags hold.*

Commit after each step. Paste the graph (select nodes → Ctrl+C) for review before moving on.

## Not in Phase 1

Panic, pills, the apparition, blackouts, world-changes, the processing chain presets, the phone text UI, any cinematic. `OnLineStarted` and `ChainsByAct` are the hooks those will use; add them, leave them unused.
