# le-fishe
Barebone 3D FPS Fishing Simulator with raylib in C.\
Used to demonstrate working with camera, models, billboard, timer, etc. using minimal external libraries.

## Installation

### Requirements
Your system should have the GNU C Compiler, GNU Make. You should also have raylib libraries

### Instructions
* First you need to get the source code. Download source as .zip on Github, or use 
```
git clone https://github.com/houri314/le-fishe
```
to clone it on your system (preferred way).

* Next you might want to get raylib libraries (either download a precompiled version or build them yourselves).
Then you create a lib/ folder then put the raylib libraries in there.

* After that, you can call `make game` to build the game. When you're rebuilding it, use `make clean game`.

### Extras
Here are some `make` options you might find useful:
- OPT (default 0): value can vary depend on your C compiler (0, 1, 2, 3, fast, ...). Optimization of program.
- DEBUG (default `DISABLED`): use `ENABLED` to enable program verbose outputs.
- RAYLIBEXT (default `so`): raylib library file extension name. Change to `a` or `dll` or whatever
based on your machine.
- RAYLIBNAME (default `libraylib`): raylib library file name.
- COMPLEVEL (default 6): change compression level of `make archive-xz`.
