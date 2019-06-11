# Keys
A simple ncurses keyboard program.
Keyboard.c is a more compacted (only 50 lines) and less feature rich version of keyboardbackup.c.

# Installation
Clone the repo with
```
git clone https://github.com/TheCatOverlord/keys.git
```
and run
```
cd lines/
gcc "keyboard.c" -o "keyboard" -lncurses
```
to compile the compacted version and
```
gcc "keyboardbackup.c" -o "keyboardbackup" -lncurses
```
to compile the less compact version.
# Running
You can run the program with
```
./keyboard
```
or
```
./keyboardbackup
```

