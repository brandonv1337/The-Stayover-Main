"""Builds DT_Lines.csv for import into Unreal as a DataTable of S_Line.

This file is the source of truth for every line of dialogue.  Edit ROWS, run
    py -3 Design/Data/build_lines_csv.py
then Reimport DT_Lines in the editor.

The Sound column is filled automatically for any row that has a matching asset
at Content/Audio/VO/<RowName>.uasset, so reimporting never wipes VO.
Written as UTF-8 with BOM so the editor keeps em dashes and ellipses intact.
"""
import csv
import os
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
VO_DIR = os.path.join(REPO, "The Stayover", "Content", "Audio", "VO")
OUT = os.path.join(HERE, "DT_Lines.csv")

# (RowName, Speaker, Text, Source, Act, Pool)
ROWS = [
    # --- S00 The Chair (cinematic)
    ("K_S00_WHISPER", "Kidnapper", "This isn't a game.", "Ear", 0, "None"),
    ("E_S00_KEEPIT", "Elias", "Keep it together. You're better than this.", "None", 0, "None"),
    ("K_S00_CHAMP", "Kidnapper", "Hey, champ. How's it going?", "Phone", 0, "None"),
    ("E_S00_WHO", "Elias", "Who is this?", "None", 0, "None"),
    ("K_S00_SAFE", "Kidnapper", "Shh. Don't worry about that. Your son's safe with me.", "Phone", 0, "None"),
    ("E_S00_FRIENDS", "Elias", "David's at a friend's. I dropped him—", "None", 0, "None"),
    ("K_S00_LOOKBACK", "Kidnapper", "You did. Did you look back?", "Phone", 0, "None"),
    ("C_S00_SCREAM", "Child", "[gunshot — a child screams]", "Phone", 0, "None"),
    ("E_S00_DAVID", "Elias", "David— DAVID—", "None", 0, "None"),
    ("K_S00_GREAT", "Kidnapper", "Great. Now you're listening. You'll get a text with an address. Don't call anyone, Elias. If you do — pow.", "Phone", 0, "None"),
    # --- S01 The Floor
    ("E_S01_FLOOR", "Elias", "The floor. Why am I on the floor.", "None", 0, "None"),
    ("E_S01_TWOLEFT", "Elias", "Two left.", "None", 0, "None"),
    ("E_S01_STUCK", "Elias", "Stuck. Always has been.", "None", 0, "None"),
    ("E_S01_PIPES", "Elias", "Pipes.", "None", 0, "None"),
    ("E_S01_DROPPED", "Elias", "I dropped it.", "None", 0, "None"),
    ("E_S01_LOCKED", "Elias", "Locked. From the outside.", "None", 0, "None"),
    # --- S02 The Yard
    ("E_S02_ADDRESS", "Elias", "That's the house. That's… why would he bring him here?", "None", 1, "None"),
    # --- S03 The Side of the House
    ("K_S03_WELCOME", "Kidnapper", "Welcome! You made it. I know this is confusing, but bear with me — it'll all make sense. The side door's open. Well. It will be. Don't get scared, don't be afraid. After all, you're not alone.", "Megaphone", 1, "None"),
    ("E_S03_FAMILIAR", "Elias", "This looks familiar.", "None", 1, "None"),
    ("E_S03_FROMWHERE", "Elias", "I don't know from where.", "None", 1, "None"),
    ("K_S03_OKAY", "Kidnapper", "Don't worry about it, Elias. You'll be okay.", "Megaphone", 1, "None"),
    ("E_S03_REMEMBER", "Elias", "It isn't how I remember it.", "None", 1, "None"),
    ("K_S03_MEMORIES", "Kidnapper", "Memories change, don't they?", "Megaphone", 1, "None"),
    ("K_S03_INSIDEVOICES", "Kidnapper", "Good. Now — inside voices.", "Megaphone", 1, "None"),
    # --- S04 The House
    ("E_S04_NAILED", "Elias", "Nailed from in here.", "None", 2, "None"),
    ("E_S04_PAPER1", "Elias", "\"Family missing.\" \"Last seen at a friend's house.\"", "None", 2, "None"),
    ("E_S04_PAPER2", "Elias", "Same. Different year.", "None", 2, "None"),
    ("E_S04_PAPER3", "Elias", "\"—wife and son. Husband—\"", "None", 2, "None"),
    ("K_S04_NOTALONE", "Kidnapper", "You're not alone in here, Elias.", "Radio", 2, "None"),
    ("E_S04_TOGETHER", "Elias", "Keep it together.", "None", 2, "None"),
    ("K_S04_WHOLETIME", "Kidnapper", "I've been with you the whole time.", "Radio", 2, "None"),
    ("K_S04_CHECKIN", "Kidnapper", "Just checking in. How are you holding up?", "HallPhone", 2, "None"),
    ("K_S04_GOOD", "Kidnapper", "That's good. That's really good.", "HallPhone", 2, "None"),
    # --- S05 David's Room
    ("E_S05_CARD", "Elias", "\"Happy ninth, champ.\"", "None", 2, "None"),
    # --- S06 The Basement
    ("E_S06_COMEON", "Elias", "Come on. Come on—", "None", 3, "None"),
    ("K_S06_LIGHT", "Kidnapper", "Why do you need the light? You already know what's here.", "Ear", 3, "None"),
    ("C_S06_LETGO", "Child", "Please… please, let me go.", "Tape", 3, "None"),
    ("C_S06_HOME", "Child", "I want to go home.", "Tape", 3, "None"),
    ("C_S06_SCREAM", "Child", "[gunshot — a child screams]", "Tape", 3, "None"),
    ("E_S06_TONIGHT", "Elias", "That was on the phone. That was— that was tonight—", "None", 3, "None"),
    ("K_S06_KNOW", "Kidnapper", "You know exactly what this is.", "Ear", 3, "None"),
    ("E_S06_NOTHIM", "Elias", "It's not him.", "None", 3, "None"),
    ("K_S06_NOTHIM", "Kidnapper", "No. Not him.", "Ear", 3, "None"),
    # --- S07 The Room of Monitors
    ("E_S07_CHAIR", "Elias", "That's my chair.", "None", 4, "None"),
    ("E_S07_MINE", "Elias", "Mine.", "None", 4, "None"),
    ("E_S07_NUMBER", "Elias", "That's my number.", "None", 4, "None"),
    ("K_S07_WHOCALLING", "Kidnapper", "Then who's been calling you, Elias?", "Mind", 4, "None"),
    ("E_S07_SAWIT", "Elias", "It was right there. It was— I saw it—", "None", 4, "None"),
    ("K_S07_WASIT", "Kidnapper", "Was it?", "Mind", 4, "None"),
    # --- S08 The Tunnel
    ("K_S08_NEVER", "Kidnapper", "You've never been down here.", "Mind", 4, "None"),
    ("E_S08_NO", "Elias", "No.", "None", 4, "None"),
    ("K_S08_IHAVE", "Kidnapper", "I have.", "Mind", 4, "None"),
    # --- S09 The Door
    ("S_S09_HELLO", "Survivor", "Hello? Is someone — please. Please, I can hear you. He's coming back.", "Door", 4, "None"),
    ("E_S09_HOLDON", "Elias", "Hold on. Hold on, I'll—", "None", 4, "None"),
    ("K_S09_NOTYET", "Kidnapper", "Not yet. Up first.", "Mind", 4, "None"),
    # --- S10 The Chair, Again
    ("TV_S10_CHAMP", "TV", "Hey, champ. How's it going?", "TV", 5, "None"),
    ("E_S10_NO", "Elias", "No. No, no—", "None", 5, "None"),
    ("TV_S10_SAFE", "TV", "Shh. Don't worry about that. Your son's safe with me.", "TV", 5, "None"),
    ("K_S10_TAKEHIM", "Kidnapper", "She was going to take him, Elias. What else could we do?", "Mind", 5, "None"),
    ("E_S10_DIDNT", "Elias", "I didn't—", "None", 5, "None"),
    ("K_S10_WEDID", "Kidnapper", "We did.", "Mind", 5, "None"),
    # --- S11 The Chamber
    ("S_S11_THANKGOD", "Survivor", "Oh God — oh, thank God — please, he's coming back, he'll — get me out. Get me out.", "World", 5, "None"),
    ("S_S11_GETYOU", "Survivor", "Did he get you too? Your kid — he said he had a kid, he kept saying—", "World", 5, "None"),
    ("E_S11_SEENOW", "Elias", "I see now.", "None", 5, "None"),
    # The only Elias row that ever gets a Sound: the Kidnapper's actor, unprocessed.
    ("E_S11_LAUGH", "Elias", "[Elias laughs]", "Mind", 5, "None"),
    ("S_S11_THATSHIM", "Survivor", "No. No, that's — that's him. You're — you told me you had a son. You told me you had a son—", "World", 5, "None"),
    # --- Pools: Yard
    ("K_P1_TAKETIME", "Kidnapper", "Take your time. He's not going anywhere.", "Megaphone", 1, "Yard"),
    ("K_P1_OTHERLEFT", "Kidnapper", "Left. No — your other left.", "Megaphone", 1, "Yard"),
    ("K_P1_SOWELL", "Kidnapper", "You're doing so well.", "Megaphone", 1, "Yard"),
    ("K_P1_COAT", "Kidnapper", "Cold out. You should've brought a coat.", "Megaphone", 1, "Yard"),
    # --- Pools: House
    ("K_P2_EVERYROOM", "Kidnapper", "Every room, Elias. Don't skip any.", "Radio", 2, "House"),
    ("K_P2_HOUSELIKE", "Kidnapper", "You used to have a house like this. Didn't you.", "Radio", 2, "House"),
    ("K_P2_READTHEM", "Kidnapper", "Read them. Read all of them.", "Radio", 2, "House"),
    ("K_P2_ALMOST", "Kidnapper", "Almost. Almost.", "Radio", 2, "House"),
    # --- Pools: Basement
    ("K_P3_BREATHE", "Kidnapper", "Breathe.", "Ear", 3, "Basement"),
    ("K_P3_DARK", "Kidnapper", "It's just dark. You've been in the dark before.", "Ear", 3, "Basement"),
    ("K_P3_STEP", "Kidnapper", "Don't step there.", "Ear", 3, "Basement"),
    ("K_P3_RIGHTHERE", "Kidnapper", "I'm right here.", "Ear", 3, "Basement"),
    # --- Pools: Episode (any act)
    ("K_EP_JUSTUS", "Kidnapper", "Don't run. It's just us.", "Ear", -1, "Episode"),
    ("K_EP_HIDE", "Kidnapper", "Hide if you want. I know the house.", "Ear", -1, "Episode"),
    ("K_EP_NOTREAL", "Kidnapper", "He can't hurt you. He's not real. Neither am I.", "Ear", -1, "Episode"),
    # --- Pools: Blackout (any act)
    ("K_BO_WELCOME", "Kidnapper", "Welcome back.", "Ear", -1, "Blackout"),
    ("K_BO_TIDIED", "Kidnapper", "You were gone a while. I tidied up.", "Ear", -1, "Blackout"),
    ("K_BO_SLEEP", "Kidnapper", "Did you sleep? You looked like you needed it.", "Ear", -1, "Blackout"),
    ("K_BO_MOVED", "Kidnapper", "I moved some things. You'll find them.", "Ear", -1, "Blackout"),
    # --- Pools: Survivor through the door
    ("S_DOOR_DONTLEAVE", "Survivor", "Are you still there? Don't leave. Don't leave.", "Door", 4, "SurvivorDoor"),
    ("S_DOOR_HISKID", "Survivor", "He talks about his kid. The whole time. The whole time.", "Door", 4, "SurvivorDoor"),
    ("S_DOOR_DAUGHTER", "Survivor", "I have a daughter. Please. I have a daughter.", "Door", 4, "SurvivorDoor"),
]


def sound_path(row_name: str) -> str:
    if os.path.isfile(os.path.join(VO_DIR, row_name + ".uasset")):
        return f"/Game/Audio/VO/{row_name}.{row_name}"
    return "None"


def main() -> None:
    names = [r[0] for r in ROWS]
    dupes = [n for n, c in Counter(names).items() if c > 1]
    assert not dupes, f"duplicate row names: {dupes}"

    with open(OUT, "w", encoding="utf-8-sig", newline="") as fh:
        w = csv.writer(fh, quoting=csv.QUOTE_MINIMAL, lineterminator="\r\n")
        w.writerow(["---", "Speaker", "Text", "Sound", "Source", "Act", "Once", "Duration", "Pool"])
        for name, speaker, text, source, act, pool in ROWS:
            w.writerow([name, speaker, text, sound_path(name), source, act, "True", 0, pool])

    with open(OUT, encoding="utf-8-sig", newline="") as fh:
        rows = list(csv.reader(fh))
    assert all(len(r) == 9 for r in rows), "column count mismatch"
    body = rows[1:]
    print(f"{len(body)} lines -> {OUT}")
    print("speakers:", dict(Counter(r[1] for r in body)))
    print("sources: ", sorted({r[4] for r in body}))
    print("pools:   ", sorted({r[8] for r in body}))
    print("with VO: ", sum(1 for r in body if r[3] != "None"))


if __name__ == "__main__":
    main()
