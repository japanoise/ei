#include <locale.h>
#include <libgen.h>
#include <curses.h>
#include <stdbool.h>
#include "buffer.h"
#include "keys.h"
#include "world.h"

void draw(buffer * curbuf)
{
	int sx, sy;
	getmaxyx(stdscr, sy, sx);
	sy -= 2;		/* Save space for the mode line & minibuffer */

	int i, x, y;
	i = x = y = 0;
	int cpx, cpy;
	move(0, 0);
	while (y <= sy && i < curbuf->num_chars) {
		if (curbuf->contents->data[i] == '\n') {
			y++;
			x = 0;
			move(y, 0);
		} else {
			addch(curbuf->contents->data[i]);
			if (i == curbuf->point) {
				cpx = x;
				cpy = y;
			}
			x++;
		}
		i++;
		if (x > sx) {
			while (curbuf->contents->data[i] != '\n' && i < curbuf->num_chars)
				i++;
		}
	}

	move(cpy, cpx);
	refresh();
}

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
	world *w = World_Create(curbuf);

	/* SCREEN SETUP */
	/* Needed for UTF-8 support */
	setlocale(LC_CTYPE, "");
	/* Enable the Good options and start curses */
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	/* Main loop */
	while (running) {
		draw(curbuf);
		ch = getch();
		if (escape) {
			/* Alt was pressed */
			running = do_key(w, ch & 0xdf);
		} else if (ch == 0x1b) {
			/* Escape */
			escape = true;
		} else if (ch < ' ') {
			/* Control character */
			running = do_key(w, ch + 0x40);
		}
	}

	/* Teardown */
	World_Destroy(w);
	endwin();

	return 0;
}
