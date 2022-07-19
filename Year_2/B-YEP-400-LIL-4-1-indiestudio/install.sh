#!/bin/bash

RED='\033[0;31m'
BLUE='\033[0;34m'
PURPLE='\033[0;95m'
CYAN='\033[0;96m'
GREEN='\033[0;92m'
YELLOW='\033[0;93m'
WHITE='\033[1;37m'
NC='\033[0m'
BACKWHITE='\033[7m'

clear
echo -e "${PURPLE}Installing Indie Studio...${NC}"
echo -e "${CYAN}Creating Build directory...${NC}"
mkdir "build/" && echo -e "${GREEN}Build directory succesfully created!${NC}" || echo -e "${YELLOW}Build directory already created!${NC}"
cd build
echo -e "${CYAN}Compiling Indie Studio...${NC}"
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
echo -e "${CYAN}Building Indie Studio...${NC}"
cmake --build . --config Release
echo -e "${GREEN}Indie Studio succesfully built!${NC}"
echo -e "${BACKWHITE}INSTALLATION DONE!${NC}"
