# octoshell 🐙🐚
- CS 321: Final Project (Spring 2022)

# Building
```bash
mkdir build
cd build
cmake ..
make
./terminal
```
## See it in action
[![asciicast](https://asciinema.org/a/fFj4uxhDZroUGkrAL6bynU0Ms.svg)](https://asciinema.org/a/fFj4uxhDZroUGkrAL6bynU0Ms)
## Requirements
 - [x] External commands
    - [x] ls
    - [x] emacs
 - [x] Internal commands
    - [x] exit: terminate the shell
    - [x] print: print out the current pid
    - [x] help: help information of your shell
 - [x] Multiple commands
    - [ ] ampersand (&): multiple commands on one line
 - [x] Input of lines of up to 100 characters
    - [x] Words consist of the characters A–Z, a–z, 0–9, dash, dot, forward slash, and underscore.
