PROGNAME=ei
CFLAGS=-W -Wall -O2
LD_FLAGS=-lncursesw
PREFIX=/usr/local
INSTALL_PROGRAM=install -m 0755 -s
INSTALL_FILE=install -m 0644
OBJS=main.o keys.o modes.o buffer.o

all: $(PROGNAME)

debug: CFLAGS+=-g -O0 -v -Q
debug: $(PROGNAME)

$(PROGNAME): $(OBJS)
	$(CC) $^ -o $@ $(LD_FLAGS)

cursetest: cursetest.c
	$(CC) $^ -o $@ $(LD_FLAGS)

install: $(PROGNAME)
	$(INSTALL_PROGRAM) $(PROGNAME) "$(PREFIX)/$(PROGNAME)"

clean:
	rm -rf $(PROGNAME) cursetest
	rm -rf *.o *.exe
