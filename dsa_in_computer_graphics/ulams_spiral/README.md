### Instructions
`primes.cpp` draws the Ulam's spiral using OpenGL.

Requirements:
1. freeglut and mesa libraries for Ubuntu. Refer `README.md` for steps to install.
2. `xzoom` package for magnification utility.
Use `sudo apt install xzoom` to install if missing.
3. `g++` for cpp program compilation. Available by default in most linux distros.

Steps to execute:
1. Compile and execute the program and spiral should start running.
```
$ g++ primes.cpp -o primes -lglut -lGL -lGLU
$ ./primes
```
2. Hit `Ctrl+Alt+T` to open a new terminal and enter:
```
xzoom -mag 10
```
This opens a zoom window of magnification 10x.

3. Program controls from terminal:
  * Pause : `Ctrl+S`
  * Resume: `Ctrl+Q`
  * Stop  : `Ctrl+C`

***

