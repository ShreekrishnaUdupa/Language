all:
	make clean;
	bison -tv -o parser.cpp parser.y;
	flex -o lexer.cpp lexer.l;
	g++ -O3 -I . -o anial lexer.cpp;

test:
	./anial < file.anial || (Get-Content file.anial | ./anial )

clean:
	rm -rf anial lexer.cpp parser.cpp parser.hpp parser.output;
	clear;

