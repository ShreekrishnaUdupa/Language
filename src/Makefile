all:
	bison -dtv -o parser.cpp parser.y
	flex -o lexer.cpp lexer.l
	clang++ lexer.cpp ast.cpp -O3 $(shell llvm-config --cxxflags --ldflags --system-libs --libs core support irreader bitreader) -o anial

clean:
	rm anial lexer.cpp parser.cpp parser.hpp location.hpp parser.output;
	clear;

test:
	./anial file.anial;
