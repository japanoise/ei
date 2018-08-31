progname=ei
LD_FLAGS=-lncursesw
objs=main.o keys.o

all: $(progname)

$(progname): $(objs)
	$(CC) $^ -o $@ $(LD_FLAGS)

cursetest: cursetest.c
	$(CC) $^ -o $@ $(LD_FLAGS)

clean:
	rm -rf $(progname) cursetest
	rm -rf *.o
