all: wrapper.so

wrapper.so: wrapper.c
	gcc -shared -fPIC wrapper.c -o wrapper.so -ldl

test: wrapper.so
	touch file FIX_file
	rm file FIX_file ; echo "Exit code $$?"
	touch file FIX_file
	LD_PRELOAD=./wrapper.so rm FIX_file ; echo "Exit code $$?"
	LD_PRELOAD=./wrapper.so rm file ; echo "Exit code $$?"

clean:
	rm -f wrapper.so file FIX_file
