# 2048---FOR-CLASS
2048, you know it :P

makefiles are not included because Raylib requires different commands for each OS

To compile it, install raylib following instructions here: https://github.com/raysan5/raylib?tab=readme-ov-file#build-and-installation
The CMake instructions for Mac are useless and don't work

Then, ```g++ -c game.o ./include/game.hpp ./src/game.cpp``` and ```g++ -o 2048 game.o ./src/game.cpp``` with your OS's raylib compilation flags on the end, and the 2048 executable will be in ./bin
<br><br><br>
This *should* work. Good luck if it doesn't
