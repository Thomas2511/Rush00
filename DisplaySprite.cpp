#include <iostream>
#include <ncurses.h>
#include "DisplaySprite.hpp"
#include "Position.hpp"

bool    DisplaySprite::_VERBOSE = false;
int     DisplaySprite::_instanceNb = 0;

// constructor and destructor
DisplaySprite::DisplaySprite(void) {
    if (DisplaySprite::_VERBOSE) {
        std::cout << "\033[35mDisplaySprite Default constructor\033[0m";
    }
    DisplaySprite::_instanceNb++;
}

DisplaySprite::DisplaySprite(DisplaySprite const &src) {
    *this = src;

    if (DisplaySprite::_VERBOSE) {
        std::cout << "\033[33mDisplaySprite Copy constructor\033[0m";
    }
    DisplaySprite::_instanceNb++;
}

DisplaySprite::~DisplaySprite(void) {
    if (DisplaySprite::_VERBOSE) {
        std::cout << "\033[31mDisplaySprite Destructor\033[0m";
    }
}

//setters and getters

// overload
DisplaySprite  &DisplaySprite::operator=(DisplaySprite const &rhs) {
    (void) rhs;
    return *this;
}
std::ostream    &operator<<(std::ostream &o, DisplaySprite const &i) {
    (void) i;
    o << "#" << DisplaySprite::_instanceNb << std::endl;
    return o;
}

// methods

// erase polymorphic methods
void       DisplaySprite::erase(Position p) {
    attron(COLOR_PAIR(1));
    mvaddch(p.getY(), p.getX(), ' ');
    attroff(COLOR_PAIR(1));
}

void       DisplaySprite::erase(Position p, WINDOW *window) {
    wattron(window, COLOR_PAIR(1));
    mvwaddch(window, p.getY(), p.getX(), ' ');
    wattroff(window, COLOR_PAIR(1));
}

void       DisplaySprite::erase(Sprite s, Position p) {
    attron(COLOR_PAIR(1));
    for (int i = 0; i < s.tempH; i++) {
        mvprintw(p.getY() + i, p.getX(), s.tempT[i].c_str());
    }
    attroff(COLOR_PAIR(1));
}

void       DisplaySprite::erase(Sprite s, Position p, WINDOW *window) {
    wattron(window, COLOR_PAIR(1));
    for (int i = 0; i < s.tempH; i++) {
        mvwprintw(window, p.getY() + i, p.getX(), s.tempT[i].c_str());
    }
    wattroff(window, COLOR_PAIR(1));
}

// display polymorphic methods

void    DisplaySprite::display(int c, Position p, int color) {
    attron(COLOR_PAIR(color));
    mvaddch(p.getY(), p.getX(), c);
    attroff(COLOR_PAIR(color));
}

void    DisplaySprite::display(int c, Position p, int color, WINDOW *window) {
    wattron(window, COLOR_PAIR(color));
    mvwaddch(window, p.getY(), p.getX(), c);
    wattroff(window, COLOR_PAIR(color));
}

void       DisplaySprite::display(Sprite s, Position p, int color) {
    attron(COLOR_PAIR(color));
    for (int i = 0; i < s.tempH; i++) {
        mvprintw(p.getY() + i, p.getX(), s.tempT[i].c_str());
    }
    attroff(COLOR_PAIR(color));
}

void       DisplaySprite::display(Sprite s, Position p, int color, WINDOW *window) {
    wattron(window, COLOR_PAIR(color));
    for (int i = 0; i < s.tempH; i++) {
        mvwprintw(window, p.getY() + i, p.getX(), s.tempT[i].c_str());
    }
    wattroff(window, COLOR_PAIR(color));
}

void       DisplaySprite::display(std::string str, Position p, int color) {
    attron(COLOR_PAIR(color));
    mvprintw(p.getY(), p.getX(), str.c_str());
    attroff(COLOR_PAIR(color));
}

void       DisplaySprite::display(std::string str, Position p, int color, WINDOW *window) {
    wattron(window, COLOR_PAIR(color));
    mvwprintw(window, p.getY(), p.getX(), str.c_str());
    wattroff(window, COLOR_PAIR(color));
}

