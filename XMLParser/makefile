all: run

run: XMLParser.exe
	./XMLParser.exe

XMLParser.exe: XMLParser.o
	gcc -o XMLParser.exe XMLParser.o -I/usr/include/libxml2 -lxml2

XMLParser.o: XMLParser.c
	gcc -c XMLParser.c -I/usr/include/libxml2 -lxml2

clean:
	rm XMLParser.o
