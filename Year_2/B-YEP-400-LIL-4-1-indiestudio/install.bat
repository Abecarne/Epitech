@ECHO OFF
cls
ECHO [95mInstalling Indie Studio...[0m
ECHO [96mCreating Build directory...[0m
MKDIR "build\"
CD "build\"
ECHO [92mBuild directory succesfully created![0m
ECHO [96mCompiling Indie Studio...[0m
cmake .. -G "Visual Studio 17 2022"
ECHO [96mBuilding Indie Studio...[0m
cmake --build . --config Release
ECHO [96mCompilation done![0m
CD ..
ECHO [96mMoving binary to root directory...[0m
MOVE Release\bomberman.exe .
ECHO [1;92mInstall done![0m