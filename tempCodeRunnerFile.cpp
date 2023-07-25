
#include <iostream>
#include <ncurses.h>
#include <stdio.h>

int main()
{
  initscr();
  clear();
  mvprintw(10, 10, "Hello, world!");
  refresh();
  getch();
  endwin();
  return 0;
}