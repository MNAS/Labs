libfoo.so : foo.o
	gcc -shared -Wall -o libfoo.so foo.o
foo.o : foo.c
	gcc -c -Wall -Werror -fpic foo.c

install : libfoo.so
	install -c libfoo.so /home/namatv/usr/lib/


clean : 
	rm -f *.so *.o

uninstall :
	rm -f /home/namatv/usr/lib/libfoo.so
