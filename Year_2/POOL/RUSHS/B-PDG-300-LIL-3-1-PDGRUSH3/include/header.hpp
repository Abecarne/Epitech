/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** header
*/

#ifndef HEADER_HPP
#define HEADER_HPP

// ~~~~ STD ~~~~
#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <fstream>
#include <ctime>
#include <sys/utsname.h>
#include <limits.h>
#include <sstream>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <iomanip>

// ~~~~ SFML ~~~~
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// ~~~~ INCLUDE ~~~~
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Cpu.hpp"
#include "Info.hpp"
#include "Network.hpp"
#include "RamCore.hpp"
#include "AllInfo.hpp"

// ~~~~ MODULES ~~~~
#include "Module.hpp"
#include "CpuG.hpp"
#include "Infos.hpp"
#include "Ram.hpp"
#include "NetworkG.hpp"

#include "Display.hpp"

//--------NCURSES--------
void init(void);

#endif // HEADER_HPP
