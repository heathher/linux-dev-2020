GENERATES = prog README prog-a prog-so
TRASH = *.o *~ o.* *.a *.so *.txt
CFLAGS = -Wall -fPIC

all:    README prog prog-a prog-so

prog:   const.o fun.o prog.o

liboutput_static.a: fun.o const.o
	ar -rcs $@ $^

liboutput.so: fun.o const.o
	cc -shared $^ -o $@

prog-a: prog.o liboutput_static.a
	cc -L. prog.o -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc -L. prog.o -loutput -o $@

test_%: %
	./$<                >  $<.txt 2>/dev/null
	./$< arg1           >> $<.txt
	./$< arg1 arg2 arg3 >> $<.txt

test: test_prog test_prog-a test_prog-so
	-cmp prog.txt prog-a.txt
	-cmp prog.txt prog-so.txt
	make distclean

fun.o:  outlib.h

README:	prog
	./$< 2> $@

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)
