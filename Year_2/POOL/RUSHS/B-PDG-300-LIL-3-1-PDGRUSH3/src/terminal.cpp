/*
** EPITECH PROJECT, 2022
** CPP pool rush3
** File description:
** info class to get all the structs and classes
*/

#include <ncurses.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include "../include/AllInfo.hpp"

//-------------------------------Prints----------------------------------------

void printHeader(std::string const header, int &lines)
{
    std::string buff;

    for (size_t i = 0; i < (COLS - header.size()) / 2; i++)
        buff += ' ';

    buff += header;
    for (size_t i = 0; i < (COLS - header.size()) / 2; i++)
        buff += ' ';

    attron(COLOR_PAIR(4));
    mvprintw(lines, 0, buff.c_str());
    attroff(COLOR_PAIR(4));
    lines++;
}

void printGraph(double percent, int line)
{
    int color = 1;

    attron(COLOR_PAIR(color));
    for (int i = 0; i <= 50; i++) {
        if (i * 2 > 50 && color != 2) {
            attroff(COLOR_PAIR(color));
            color = 2;
            attron(COLOR_PAIR(color));
        } else if (i * 2 > 75 && color != 3) {
            attroff(COLOR_PAIR(color));
            color = 3;
            attron(COLOR_PAIR(color));
        }
        if (i * 2 < percent)
            printw("|");
        else
            printw(" ");
    }
    attroff(COLOR_PAIR(color));
}

void printInfo(Info *info, int &lines)
{
    std::ostringstream oss;
    utsname core = info->getCoreInfo();
    std::string buff = "Date and time: ";

// Datetime and runtime
    oss << std::put_time(info->getDate(), "%A %d-%m-%Y %H:%M:%S");
    buff += oss.str();
    buff += " - Uptime: " + info->getRuntime();
    mvprintw(lines, 0, buff.c_str());

// Host and user
    buff = "Host: ";
    buff += info->getHostName();
    buff += " - User:";
    buff += info->getUserName();
    mvprintw(lines, (COLS - buff.size()) / 2, buff.c_str());

// Sys info
    buff = core.sysname;
    buff += " - ";
    buff += core.release;
    mvprintw(lines, COLS - buff.size(), buff.c_str());
    lines += 2;
}

void printRam(RamCore *ram, int &lines)
{
    double percent = ram->getUsedMem() / ram->getTotMem() * 100;
    std::string spercent = std::to_string(percent);
    std::string used = std::to_string(ram->getUsedMem());
    std::string totMem = std::to_string(ram->getTotMem());
    int len = 63;

    if (percent < 10) {
        spercent = spercent.substr(0, 4);
    } else {
        spercent = spercent.substr(0, 5);
    }

    if (ram->getUsedMem() < 10) {
        used = used.substr(0, 4);
    } else {
        used = used.substr(0, 5);
    }
    if (ram->getTotMem() < 10) {
        totMem = totMem.substr(0, 4);
    } else {
        totMem = totMem.substr(0, 5);
    }
    len += spercent.size() + used.size() + totMem.size();

    mvprintw(lines, (COLS - len) / 2, "Mem [");

    printGraph(percent, lines);

    used = "] " + spercent + "% (" + used + "/" + totMem + "G)";
    printw(used.c_str());
    lines++;
}

void printSwp(RamCore *ram, int &lines)
{
    double percent = ram->getUsedSwap() / ram->getTotSwap() * 100;
    std::string spercent = std::to_string(percent);
    std::string used = std::to_string(ram->getUsedSwap());
    std::string totMem = std::to_string(ram->getTotSwap());
    int len = 63;

    if (percent < 10) {
        spercent = spercent.substr(0, 4);
    } else {
        spercent = spercent.substr(0, 5);
    }

    if (ram->getUsedSwap() < 10) {
        used = used.substr(0, 4);
    } else {
        used = used.substr(0, 5);
    }
    if (ram->getTotSwap() < 10) {
        totMem = totMem.substr(0, 4);
    } else {
        totMem = totMem.substr(0, 5);
    }
    len += spercent.size() + used.size() + totMem.size();

    mvprintw(lines, (COLS - len) / 2, "Swp [");

    printGraph(percent, lines);

    used = "] " + spercent + "% (" + used + "/" + totMem + "G)";
    printw(used.c_str());
    lines++;
}

void printCPu(std::string spercent, int nb, int lines)
{
    std::string buff = "CPU" + std::to_string(nb + 1) + " [";
    double percent = stod(spercent);
    int len = 60;

    if (percent < 10) {
        spercent = spercent.substr(0, 4);
    } else {
        spercent = spercent.substr(0, 5);
    }

    len += spercent.size();

    mvprintw(lines, (COLS - len) / 2, buff.c_str());

    printGraph(percent, 17 + nb);

    buff = "] " + spercent + "%%";
    printw(buff.c_str());
}

void printNetwork(Network *net, int &lines)
{
    std::vector<std::string> names = net->getNames();
    std::vector<std::pair<size_t, size_t>> networkRc = net->getRC();
    std::vector<std::pair<size_t, size_t>> networkTr = net->getTr();
    std::string buff;

    buff = "Name, Received bytes, Received packets, Transmited bytes, Transmited packets";
    mvprintw(lines, (COLS - buff.size()) / 2,buff.c_str());
    lines++;

    for (size_t i = 0; i < names.size(); i++) {
        buff = names[i] + " ";
        buff += std::to_string(networkRc[i].first) + " " + std::to_string(networkRc[i].second);
        buff += "\t" + std::to_string(networkTr[i].first);
        buff += "\t" + std::to_string(networkTr[i].second);
        mvprintw(lines, (COLS - buff.size()) / 2, buff.c_str());
        lines++;
    }
}
//----------------------------------------End of Prints------------------------
void checkSize(int lines)
{
    while (COLS < 80 || LINES < lines) {
        clear();
        mvprintw(LINES / 2, (COLS - 30) / 2, "Please, expand the terminal :)");
        refresh();
        sleep(1);
    }
}

// permet de vérifier si une catégorie est bien cliqué
void getCat(MEVENT event, bool &change, std::vector<std::tuple<int, bool>> &actif)
{
    for (int i = 0; i < 4; i++) {
        if (std::get<0>(actif[i]) == event.y) {
            std::get<1>(actif[i]) = !(std::get<1>(actif[i]));
            change = true;
            break;
        }
    }
}

void init(void)
{
    AllInfo info;
    WINDOW *stdsrc = initscr();
    MEVENT event;
    int key = 0;
    int lines = 0;
    int rep = 0;
    std::vector<std::tuple<int, bool>> actif;
    bool change = false;

    actif.push_back(std::tuple<int, bool>(0, true));
//---------------------Colors---------------
    if (has_colors() == false) {
        printw("Terminal doesn't support colors");
        getch();
        return;
    }
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    // Header
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
//---------------------End of Colors-------------

//-------------Controles for ncurses------------
    keypad(stdscr, TRUE);
    nodelay(stdsrc,true);
    curs_set(0);
    noecho();
    mousemask(BUTTON1_RELEASED, NULL);
//----------End of Controles for ncurses-----

    while (true) {
        key = getch();
        if (key == 'q') {
            break;
        } else if (key == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                getCat(event, change, actif);
            }
        }
        clear();

        //-------------Prints-----------------

        // Permet de check si actif ou non
        printHeader("Informations", lines);
        if (actif.size() != 4 || std::get<1>(actif[rep]) == true) {
            printInfo(info.getInfo(), lines);
        }
        rep++;

        printHeader("Memory", lines);
        if (actif.size() != 4 || std::get<1>(actif[rep]) == true) {
            if (actif.size() != 4) {
                actif.push_back(std::tuple<int, bool>(lines - 1, true));
            } else if (change == true) {
                std::get<0>(actif[rep]) = lines - 1;
            }
            printRam(info.getRamCore(), lines);
            printSwp(info.getRamCore(), lines);
        }
        rep++;

        printHeader("CPUs", lines);
        if (actif.size() != 4 || std::get<1>(actif[rep]) == true) {
            if (actif.size() != 4) {
                actif.push_back(std::tuple<int, bool>(lines - 1, true));
            } else if (change == true) {
                std::get<0>(actif[rep]) = lines - 1;
            }

            for (int i = 0; i < info.getCpu()->getNumberCore(); i++) {
                printCPu(info.getCpu()->getUsage()[i], i, lines);
                lines++;
            }
            lines++;
        }
        rep++;

        printHeader("Network", lines);
        if (actif.size() != 4 || std::get<1>(actif[rep]) == true) {
            if (actif.size() != 4) {
                actif.push_back(std::tuple<int, bool>(lines - 1, true));
            } else if (change == true) {
                std::get<0>(actif[rep]) = lines - 1;
            }
            printNetwork(info.getNetwork(), lines);
        }
        //-----------End of prints--------------

        checkSize(lines);

        refresh();
        info.refresh();
        sleep(1);
        lines = 0;
        rep = 0;
    }
    endwin();
}
