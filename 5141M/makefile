hello : main.o libfoo/libfoo.so
	gcc -L/home/namatv/My/git/MNAS/Labs/5141M/libfoo -Wall -o hello main.o -lfoo

main.o : main.c libfoo/foo.h
	gcc -c main.c

libfoo/libfoo.so:
	cd libfoo && $(MAKE)


install : hello 
	install -c hello /home/namatv/usr/bin/
	cd libfoo && $(MAKE) install

clean : 
	rm -f hello *o.so *.o
	cd libfoo && $(MAKE) clean

uninstall :
	rm -f /home/namatv/usr/bin/hello
	cd libfoo && $(MAKE) uninstall

