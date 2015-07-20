#include <ncurses.h>

int main()
{
  WINDOW *my_wins[3];
  int lines = 10, cols = 40, y = 2, x = 4, i;

  initscr();
  cbreak();
  noecho();
  /* Create windows for the panels */
  my_wins[0] = newwin(lines, cols, y, x);
  my_wins[1] = newwin(lines, cols, y + 1, x + 5);
  my_wins[2] = newwin(lines, cols, y + 2, x + 10);

  /* 
   * Create borders around the windows so that you can see the effect
   * of panels
   */
  for(i = 0; i < 3; ++i)
    {
      puts("caca");
      wborder(my_wins[i], '|', '|', '-', '-', '+', '+', '+', '+');
    }
  wrefresh(my_wins[0]);
  wrefresh(my_wins[1]);
  wrefresh(my_wins[2]);
 
  getch();
  endwin();
}
