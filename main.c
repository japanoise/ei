#include <locale.h>
#include <libgen.h>
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

	/* GENERAL SETUP */
	buffer *curbuf = Buffer_Create("*scratch*");
	if (argc > 1) {
		buffer *scrbuf = curbuf;
		for (int i = 1; i < argc; i++) {
			curbuf->next_chain_entry = Buffer_Create(basename(argv[i]));
			curbuf = curbuf->next_chain_entry;
			Set_File_Name(curbuf, argv[i]);
			Buffer_Read(curbuf);
		}
		curbuf->next_chain_entry = scrbuf;
	}

	/* SCREEN SETUP */
	/* Needed for UTF-8 support */
	setlocale(LC_CTYPE, "");
	/* Enable the Good options and start curses */
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	if (curbuf->num_chars > 9) {
		for (int i = 0; i < 9; i++) {
			mvaddch(0, i, curbuf->contents->data[i]);
		}
	} else {
		printw("‘Hello World!’");
	}
	refresh();

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
