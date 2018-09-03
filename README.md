# ei - the editor for immortals

I've played with every editor out there, have used just about every 
ersatz-emacs, even written my own. Now it's time for something new.

This is a new, gap-buffer editor that takes what I've learned from Gomacs and
splices it with some new concepts and ideas.

## building & installing

I strongly dislike autohell, cmake, ninja, waf, etc etc, so installation works
through a nice GNU Makefile. Replace `make` with `gmake` if you're on BSD.

    make
    sudo make install

Options she'll accept for customisation:

- Keyboard layout (defaults to dvorak; see below)
- CFLAGS, LDFLAGS, etc: `make CFLAGS=-I/usr/include/curses LDFLAGS=-lpdcurses`
- PREFIX (defaults to /usr/local): `sudo make install PREFIX=/usr`
- progname (defaults to ei): `make progname=vim; sudo make install programe=vim`

## keys

See the file KEYS.md. In standard configuration, the bindings are optimised for
the dvorak keyboard - you can pass an option to build it for the qwerty
keyboard at compile time as such:

    make CFLAGS="$CFLAGS -DQWERTY"

If you use another layout (such as coleman, workman, or azerty) please tell me
and let's work together on porting ei to that layout.

## caveats

Like many smaller text editors, ei is opinionated, or "religious" if you will.
It will always assume buffers are UTF-8 encoded, and will seriously mess up if
input is not also formatted in ASCII or some extension thereof (i.e. UTF-8).
For almost all computer users this won't be a problem, but if you're using an
EBCDIC system for some god-forsaken reason, it will not end well. You're
strongly advised to either stop using EBCDIC, or fork and patch it yourself.

## name

The original standard unix text editor was Ed. An extended version called Em,
the Editor for Mortals, was written. Now as a riff on that, and because I like
two-letter names, we have ei - the Editor for Immortals!

## credits

- Craig A. Finseth, whose book ["The Craft of Text Editing"][craft] describes
  many of the high-level interfaces used for ei.

[craft]: http://www.finseth.com/craft/
