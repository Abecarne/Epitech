/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "../../include/abstracts/ADisplayModule.hpp"
#include <ncurses.h>
#include <curses.h>
#include <string.h>
#include <menu.h>

class class_ncurses : public arcade::display::ADisplayModule {
    public:
        class_ncurses(void);
        ~class_ncurses();

        std::string getLibName(void) override;
        void setGame(std::string gameName) override;
        arcade::Keys displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs) override;
        arcade::State endLib(arcade::State) override;

        void loadScreen(MapType map) override;
        void refreshScreen(MapType map) override;
        bool updateScore(int score) override;
        arcade::Keys keyPressed(void) override;
        void ncurse_game_won();
        void ncurse_game_loose();
        arcade::Keys ncurse_key_getter();
        void ncurse_init_screen();
        void ncurse_stop_screen();
        void ncurse_draw_screen();
        void print_info();
    private:
        std::string _currentGame;
        int win_x;
        int win_y;
        int state_game;
        std::string lib_name;
};

class ncurse_encap
{
   public:
      static void clear_ncurse();
      static int refresh_ncurse();
      static int wrefresh_ncurse(WINDOW *windows);
      static int endwin_ncurse();
      static WINDOW *subwin_ncurse(WINDOW *o, int l, int c, int y, int x);
      static void mvwprintw_ncurse(WINDOW *windows, int y, int x, const char *frmt);
      static int getch_ncurse();
      static void nodelay_ncurse(WINDOW *windows, bool state);
      static void start_color_ncurse();
      static int init_color_ncurse(short a, short b, short c, short d);
      static void newterm_ncurse();
      static void getmaxyx_ncurse(WINDOW *windows, int *x, int *y);
      static void keypad_ncurse(WINDOW *windows, bool state);
      static void mvprintw_ncurse(int x, int y, const char *str);
      static int box_ncurse(WINDOW *windows, chtype type1, chtype tyep2);
      static int nocbreak_ncurse();
      static int cbreak_ncurse();
      static int attron_ncurse(int x);
      static int attroff_ncurse(int x);
      static void init_pair_ncurse(short pair, short f, short b);
};

#endif /* !NCURSES_HPP_ */