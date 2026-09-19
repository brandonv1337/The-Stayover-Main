# THE STAYOVER — Development Phases
*v1 — 2026-09-17. Engine: UE 5.3.2, Blueprint-first. Stay on 5.3 through alpha.*

**The rule:** build the spine before any scene, prove the fear loop in the smallest space that already exists, then add content in story order. Every phase ends in something playable from the chair forward. Nothing gets built that you can't walk to.

## How the pieces talk

One direction only:

**Interactables / triggers / puzzles → `BP_Director` → subtitles, voice sources, panic, world-changes, save**

- **`BP_Director`** — one placed actor. Holds the act, story flags (a Set of Names), lines already fired, blackout count per act. Implements the existing `BPI_Saveable`.
- **`DT_Lines`** — one DataTable for every line in the script. Nothing hardcodes dialogue; everything says "Director, play `K_S03_WELCOME`."
- **`DT_WorldChanges`** *(Phase 2)* — per act, ordered: which hidden actors switch on after blackout 1, 2, 3.

Interactables never talk to each other or to the UI. They tell the Director what happened. That is what keeps late changes cheap.

## Phases

| Phase | Build | Reuses | Done when |
|---|---|---|---|
| **0 — Lock & greybox** | Script + bible in `Design/`; config description updated; line IDs assigned. **Greybox every missing space** — side door, red rooms, monitor room, tunnel, cottage basement (landing + chamber) — with CubeGrid blocks. | The level, modeling tools | You can walk chair → chamber in five minutes with no gameplay. *This is the fluidity test.* Fix the walk now, while walls are free. |
| **1 — The spine** | Director; `DT_Lines`; subtitle upgrade (speaker tag + colour, Elias italic, red-tag switch); `BP_VoiceSource`; `BP_LineTrigger`; `BP_Inspect`. See `Phase1-Spec.md`. | `BP_SubtitleManager`, `WB_Subtitle`, `SubtitlesStruct`, `BP_NewRadio`, `BP_Television`, `BP_Notes`, `BPI_Saveable` | **Scene 1 is fully playable**: wake, flashlight, "Two left," "Pipes," locked from outside, note → ring → key, out the door. Megaphone speaks in the side yard. |
| **2 — The fear loop** | `BPC_Panic` on `HP_Character` (in: darkness, dread zones, Kidnapper lines; out: hallucination post-process, heartbeat, episode at threshold); pills (count, pickup, use, small HUD pip — **no panic bar**); light/dark volumes; apparition — `BP_AI_Character` as the Plague Doctor, spawned out of sight, leashed to the area, chase → search → give up; `BP_HideSpot`; blackout (static → checkpoint → next world-change → blackout line). | `Hallucination*_MAT`, heartbeat cues, stamina, `BT_AI`/`BB_AI`, `BP_CheckpointSaveGame`, `WB_Respawn`, `TV_Static` | On the main-house ground floor a tester gets an episode, hides, gets caught once, and wakes to a changed room. Save/load survives it. |
| ★ **Vertical slice** | Scenes 0–4 rough: opening cinematic blocked, cottage, yard + text + two cars, side yard + positional lock, ground floor + one puzzle. Temp Kidnapper VO recorded by Brandon. | `IntroSequence`, `I_Pills_*` anims, `StartingCar`, `BP_FrontGate` lock logic | **Three strangers play 15 minutes.** Are they afraid of an empty house? Is the blackout fair? Do not start Phase 3 until yes. |
| **3 — Content, in story order** | **3a** House: radio batteries + tuning, frames, keypad, safe, newspapers, David's room. **3b** Basement: flashlight-dead zones, tape deck, the sheet, corpse-door. **3c** Monitor room: desk props, checklist, drawer, replay. **3d** Tunnel, cottage basement, cottage end-state. **3e** Scenes 10–12: TV call, red tag, chamber, laugh, credits stinger. | `BP_NumberSafe`, `BP_Keypad`, `BP_PictureFrame*`, `WB_RadioWidget`, `BP_BasementDoor/Key`, `DeadBody`, `SecurityCamera`, `90sPCMonitor`, credits widgets | After each sub-phase: playable from the chair to that point, save/load clean. |
| **4 — Alpha** | Whole game start to finish; temp art and VO fine. Pacing pass: line cooldowns, panic tuning per act, world-change order. Save/load soak. | — | Someone finishes it and explains the twist back correctly. |
| **5 — Beta** | Final VO (one lead, survivor, child) + the per-act processing chain; production lighting bake; ambience zones and mix; **second-playthrough audit** (walk the plant map in `StoryBible.md`); UI backlog (notes in pause, menu SFX, flashlight ring, note blur); Spanish; accessibility; performance. | Sound classes, loc pipeline, options menus | Content-complete, no placeholders. |
| **6 — Ship** | Packaging, store page, content warnings, spoiler-free trailer, QA. | — | — |

## Decisions made now so they don't bite later

- **Voice processing is an effect chain, not baked files.** One clean recording per line; a source-effect preset per act (heavy → medium → light → none). Re-recording a line means one file.
- **Monitors are mostly video, not live cameras.** Render the feeds and the "hiding from nothing" replay once through Sequencer and play them as media, the way the TV already works. At most one live scene capture.
- **Cottage end-state = movable actors only.** Lighting is baked; the open cellar door, the TV content and the hatch are fine as movable. Change nothing static between start and end.
- **Check navmesh on day one of Phase 2.** The house is built from modeling-tool meshes; if their collision is complex-as-simple, the apparition will not path.
- **Basement, tunnel and cottage basement as sublevels.** Keeps lighting builds and map-open time sane.
- **Subtitles can never be fully disabled.** Elias's lines exist *only* as subtitles. The options toggle hides subtitles for voiced lines only.
- **No panic bar.** Heartbeat, vignette, hallucination material. The only HUD addition is the pill count.

## Working agreement

Blueprint graphs cannot be read from `.uasset` files, but **selected nodes copied with Ctrl+C paste as text** that can be reviewed. Per system: spec → build → paste graph → review → commit. One system per commit. Close the editor before any `Config/*.ini` edit made outside it.

## Backlog carried from earlier notes

Note animation + background blur · outside vs inside ambience · corpse-door scare · notes section in pause menu · quit confirmation · radio batteries + tuning · rotatable picture frames unlocking a door · per-instance note image · per-lock safe digits · menu hover/press SFX · flashlight ring · slower door open.
