all:
	make clean;
	bison -dtv -o parser.cpp parser.y;
	flex -o lexer.cpp lexer.l;
	g++ -O3 -I . -o anial lexer.cpp

test:
	./anial

clean:
	rm -rf anial lexer.cpp parser.cpp parser.hpp parser.output location.hh parser.tab.cc parser.tab.hh lex.yy.cc location.hpp a.exe;
	clear;

