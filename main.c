#include <locale.h>
#include <curses.h>
#include <stdbool.h>
#include "buffer.h"
#include "keys.h"

int main(int argc, char *argv[])
{
	int ch;
	bool escape, running;
	escape = false;
	running = true;

	/* SCREEN SETUP */
	/* Needed for UTF-8 support */
	setlocale(LC_CTYPE, "");
	/* Enable the Good options and start curses */
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("‘Hello World!’");
	refresh();

	/* GENERAL SETUP */
	buffer *curbuf = Buffer_Create("*scratch*");

	/* Main loop */
	while (running) {
		ch = getch();
		if (escape) {
			/* Alt was pressed */
			running = do_key(ch & 0xdf);
		} else if (ch == 0x1b) {
			/* Escape */
			escape = true;
		} else if (ch < ' ') {
			/* Control character */
			running = do_key(ch + 0x40);
		}
	}

	/* Teardown */
	Buffer_Delete(curbuf);
	endwin();

	return 0;
}
