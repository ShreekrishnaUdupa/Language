all:
	bison -tv -o parser.cpp parser.y;
	flex -o lexer.cpp lexer.l;
	clang++ -O3 -I . -I D:/llvm/include -L D:/llvm/lib -l LLVMCore -l LLVMSupport -o anial lexer.cpp

test:
	./anial

clean:
	rm -rf anial.exe lexer.cpp parser.cpp parser.output location.hpp;
	clear;