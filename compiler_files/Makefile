all:
	make clean;
	bison -dtv -o parser.cpp parser.y;
	flex++ -o lexer.cpp lexer.l;
	g++ -Wno-register -O3 -o program lexer.cpp parser.cpp

test:
	./program < file.anial;

clean:
	rm -rf lexer.cpp parser.cpp parser.hpp parser.output position.hh location.hh stack.hh program
	clear;