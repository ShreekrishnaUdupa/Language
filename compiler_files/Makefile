all:
	bison -tv -o parser.cpp parser.y
	flex -o lexer.cpp lexer.l
	clang++ lexer.cpp -O3 -I D:/llvm/include -I . -lLLVMCore -lLLVMSupport -o anial

clean:
	rm anial lexer.cpp parser.cpp location.hpp parser.output;
	clear;

test:
	./anial;