# 2048---FOR-CLASS
2048, you know it :P

makefiles are not included because Raylib requires different commands for each OS

To compile it, install raylib following instructions here: https://github.com/raysan5/raylib?tab=readme-ov-file#build-and-installation
The CMake instructions for Mac are useless and don't work

Then, ```g++ -o 2048 ./include/game.hpp ./src/main.cpp ./src/game.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11``` with your OS's raylib compilation flags on the end. The 2048 executable will be in the current directory
<br><br><br>
This *should* work. Good luck if it doesn't
