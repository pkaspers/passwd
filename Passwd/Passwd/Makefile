CPPFLAGS=-pedantic -Wall -Iinc 
LDFLAGS=-Wall 

__start__: obj uzytkownicy
	./uzytkownicy

obj:
	mkdir obj

uzytkownicy: obj/modul.o
	g++ ${LDFLAGS} -o uzytkownicy obj/modul.o -L/lib/main

obj/modul.o: src/modul.cpp
	g++ -c ${CPPFLAGS} -o obj/modul.o  src/modul.cpp

clean:
	rm -f uzytkownicy core obj/*
	