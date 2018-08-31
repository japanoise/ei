#include <locale.h>
#include <curses.h>
#include <stdbool.h>
#include "keys.h"

int main(int argc, char *argv[])
{
	int ch;
	bool escape, running;
	escape = false;
	running = true;

	/* SETUP */
	/* Needed for UTF-8 support */
	setlocale(LC_CTYPE, "");
	/* Enable the Good options and start curses */
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("‘Hello World!’");
	refresh();

	/* Main loop */
	while(running) {
		ch = getch();
		if (escape) {
			/* Alt was pressed */
			running = do_key(ch&0xdf);
		} else if (ch == 0x1b) {
			/* Escape */
			escape = true;
		} else if (ch < ' ') {
			/* Control character */
			running = do_key(ch+0x40);
		}
	}

	endwin();

	return 0;
}
