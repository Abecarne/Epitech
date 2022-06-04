/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** ncurses
*/

#include "ncurses.hpp"

arcade::display::ADisplayModule::~ADisplayModule() {};

// ~~~~~~ Beginning of member functions ~~~~~~

class_ncurses::class_ncurses(void)
{
   std::cout << "constructor ncurse" << std::endl;
   this->state_game = 1;
   this->lib_name = "ncurses";
   class_ncurses::ncurse_init_screen();

}

class_ncurses::~class_ncurses()
{
   std::cout << "Destructeur ncurses" << std::endl;
   ncurse_encap::nocbreak_ncurse();
   ncurse_encap::clear_ncurse();
   ncurse_encap::endwin_ncurse();
}

std::string class_ncurses::getLibName(void)
{
   return (this->lib_name);
}

void class_ncurses::setGame(std::string gameName)
{
   (void)gameName;
}

void class_ncurses::print_info()
{
   ncurse_encap::mvprintw_ncurse((this->win_y / 2) - 9, (this->win_x / 2) - 22, "Welcome to the ncurse's menu for the arcade");
   ncurse_encap::mvprintw_ncurse((this->win_y / 2) - 8, (this->win_x / 2) - 27, "Press A to use the previous lib, and E for the next one");
   ncurse_encap::mvprintw_ncurse((this->win_y / 2) - 7, (this->win_x / 2) - 28, "Press O to play the previous game, and P for the next one");
}

arcade::Keys class_ncurses::displayMenu(std::vector<std::string> gameLibs, std::vector<std::string> graphicLibs)
{
   WINDOW *menu;
   const char *str = "Game Menu Arcade";
   int x;
   chtype color = COLOR_PAIR(0);
   arcade::Keys inputKey = arcade::Keys::NONE;

   menu = newwin(10, 40, (this->win_y / 2) - 20, (this->win_x / 2) - 20);
   ncurse_encap::keypad_ncurse(menu, TRUE);
   x = strlen(str);
   wattron(menu, color);
   ncurse_encap::box_ncurse(menu, 10, 40);
   ncurse_encap::mvwprintw_ncurse(menu, ((40 - x) / 2), 1, str);
   ncurse_encap::mvwprintw_ncurse(menu, ((20 - strlen("game available:")) / 2), 2, "game available:");
   ncurse_encap::mvwprintw_ncurse(menu, ((60 - strlen("lib available:")) / 2), 2, "lib available:");
   for(unsigned int i = 0; i < gameLibs.size(); i++) {
      str = gameLibs[i].c_str();
      ncurse_encap::mvwprintw_ncurse(menu, ((19 - strlen(str)) / 2), (i + 3), str);
   }
   for(unsigned int i = 0; i < graphicLibs.size(); i++) {
      str = graphicLibs[i].c_str();
      ncurse_encap::mvwprintw_ncurse(menu, ((60 - strlen(str)) / 2), (i + 4), str);
   }
   ncurse_encap::refresh_ncurse();
   ncurse_encap::wrefresh_ncurse(menu);
   touchwin(menu);
   wattroff(menu, color);
   class_ncurses::print_info();
   inputKey = this->keyPressed();
   return (inputKey);
}

arcade::State class_ncurses::endLib(arcade::State)
{
   return (arcade::State::EXIT);
}

void class_ncurses::loadScreen(MapType map)
{
   chtype color = COLOR_PAIR(1);
   const char *str;

   for(unsigned int i = 0; i < map.size(); i++) {
      str = map[i].c_str();
      ncurse_encap::attron_ncurse(color);
      ncurse_encap::mvprintw_ncurse((this->win_y / 2) - 15, (this->win_x / 2) - 15, str);
      ncurse_encap::attroff_ncurse(color);
   }
}

void class_ncurses::refreshScreen(MapType map)
{
   chtype color = COLOR_PAIR(1);
   const char *str;

   for(unsigned int i = 0; i < map.size(); i++) {
      str = map[i].c_str();
      ncurse_encap::attron_ncurse(color);
      ncurse_encap::mvprintw_ncurse((this->win_y / 2) - 15, (this->win_x / 2) - 15, str);
      ncurse_encap::attroff_ncurse(color);
   }
}

int ncurse_encap::wrefresh_ncurse(WINDOW *windows)
{
   return (wrefresh(windows));
}

bool class_ncurses::updateScore(int score)
{
   (void)score;
   return (true);
}

arcade::Keys class_ncurses::keyPressed(void)
{
   int x = ncurse_encap::getch_ncurse();

   while (x != 27) {
      x = ncurse_encap::getch_ncurse();
      if (x == 'a') {
         ncurse_encap::endwin_ncurse();
         return (arcade::Keys::PREVLIB);
      }
      if (x == 'e') {
         ncurse_encap::endwin_ncurse();
         return (arcade::Keys::NEXTLIB);
      }
      if (x == 'o') {
         return (arcade::Keys::PREVGAME);
      }
      if (x == 'p') {
         return (arcade::Keys::NEXTGAME);
      }
      if (x == 'm') {
         return (arcade::Keys::MENU);
      }
      if (x == ' ') {
         return (arcade::Keys::ENTER);
      }
      if (x == '\n') {
         return (arcade::Keys::ENTER);
      }
      if (x == 27) {
         ncurse_encap::endwin_ncurse();
         return (arcade::Keys::ESC);
      }
   }
   return (arcade::Keys::NONE);
}

// ~~~~~~ End of member functions ~~~~~~

extern "C" {
    arcade::display::IDisplayModule *EntryPoint(void)
    {
        arcade::display::IDisplayModule *instance = new class_ncurses();
        return instance;
    }

    void deleteInstance(arcade::display::IDisplayModule *instance)
    {
        delete instance;
    }
}

// replace graphical1.cpp here

void ncurse_encap::clear_ncurse()
{
   clear();
}

int ncurse_encap::refresh_ncurse()
{
   return(refresh());
}

int ncurse_encap::endwin_ncurse()
{
   return(endwin());
}

WINDOW *ncurse_encap::subwin_ncurse(WINDOW *o, int l, int c, int y, int x)
{
   return(subwin(o, l, c, y, x));
}

void ncurse_encap::mvwprintw_ncurse(WINDOW *windows, int y, int x, const char *frmt)
{
   mvwprintw(windows, x, y, frmt);
}

int ncurse_encap::getch_ncurse()
{
   return (getch());
}

void ncurse_encap::nodelay_ncurse(WINDOW *windows, bool state)
{
   nodelay(windows, state);
}

void ncurse_encap::start_color_ncurse()
{
   start_color();
}

int ncurse_encap::init_color_ncurse(short a, short b, short c, short d)
{
   return (init_color( a, b, c, d));
}

void ncurse_encap::newterm_ncurse()
{
   newterm(NULL, stderr, stdin);
}

void ncurse_encap::getmaxyx_ncurse(WINDOW *windows, int *x, int *y)
{
   getmaxyx(windows, *y, *x);
   (void)y;
}

void ncurse_encap::keypad_ncurse(WINDOW *windows, bool state)
{
   keypad(windows, state);
}

void ncurse_encap::mvprintw_ncurse(int x, int y, const char *str)
{
   mvprintw(x, y , str);
}

int ncurse_encap::box_ncurse(WINDOW *windows, chtype type1, chtype type2)
{
   return box(windows, type1, type2);
}

int ncurse_encap::nocbreak_ncurse()
{
   return (nocbreak());
}

int ncurse_encap::cbreak_ncurse()
{
   return (cbreak());
}

int ncurse_encap::attron_ncurse(int x)
{
  return (attron(x));
}

int ncurse_encap::attroff_ncurse(int x)
{
   return (attroff(x));
}

void ncurse_encap::init_pair_ncurse(short pair, short f, short b)
{
   init_pair(pair, f, b);
}

void class_ncurses::ncurse_init_screen()
{
   std::system("echo -n arcade");
   ncurse_encap::clear_ncurse();
   ncurse_encap::newterm_ncurse();
   ncurse_encap::nodelay_ncurse(stdscr, TRUE);
   ncurse_encap::start_color_ncurse();
   ncurse_encap::keypad_ncurse(stdscr, TRUE);
   ncurse_encap::getmaxyx_ncurse(stdscr, &this->win_x, &this->win_y);
   ncurse_encap::init_color_ncurse(0, 0, 0, 0);
   ncurse_encap::init_pair_ncurse(1, COLOR_GREEN, COLOR_GREEN);
   srand(time(NULL));
}

void class_ncurses::ncurse_stop_screen()
{
   ncurse_encap::endwin_ncurse();
}

void class_ncurses::ncurse_draw_screen()
{
   ncurse_encap::mvprintw_ncurse(this->win_x, this->win_y, "avion");
}

arcade::Keys class_ncurses::ncurse_key_getter()
{
   int key = ncurse_encap::getch_ncurse();
   if (key == 'a')
      return (arcade::Keys::NEXTLIB);
   if (key == 'z')
      return (arcade::Keys::PREVLIB);
   if (key == 'o')
      return (arcade::Keys::NEXTGAME);
   if (key == 'p')
      return (arcade::Keys::PREVGAME);
   if (key == KEY_UP)
      return (arcade::Keys::UP);
   if (key == KEY_DOWN)
      return (arcade::Keys::DOWN);
   if (key == KEY_RIGHT)
      return (arcade::Keys::RIGHT);
   if (key == KEY_LEFT)
      return (arcade::Keys::LEFT);
   if (key == 27)
      return (arcade::Keys::ESC);
   return (arcade::Keys::NONE);
}

void class_ncurses::ncurse_game_won()
{
   if (this->state_game != 1)
      this->state_game = 1;
   ncurse_encap::mvprintw_ncurse(this->win_x / 2, this->win_y / 2, "You win!");
}

void class_ncurses::ncurse_game_loose()
{
   if (this->state_game != 0)
      this->state_game = 0;
   ncurse_encap::mvprintw_ncurse(this->win_x / 2, this->win_y / 2, "Game Over");
}