/* 
 * Not part of the main program; tests what getch returns.
 * Comes from the ncurses programming HOWTO.
 */
#include <ncurses.h>

int main()
{
	int ch;

	initscr();		/* Start curses mode            */
	cbreak();		/* Line buffering disabled      */
	keypad(stdscr, TRUE);	/* We get F1, F2 etc..          */
	noecho();		/* Don't echo() while we do getch */

	for (;;) {
		printw("Type any character to see it in bold\n");
		ch = getch();	/* If raw() hadn't been called
				 * we have to press enter before it
				 * gets to the program          */
		if (ch == KEY_F(1))	/* Without keypad enabled this won't work */
			printw("F1 Key pressed");
		else {
			printw("The pressed key is ");
			attron(A_BOLD);
			printw("%c", ch);
			attroff(A_BOLD);
		}
		refresh();	/* Print it on to the real screen */
		printw("\n");	/* Next line. */
	}
	endwin();		/* End curses mode                */

	return 0;
}
