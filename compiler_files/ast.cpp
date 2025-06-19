#include <bits/stdc++.h>
#include "llvm/IR/Value.h"

using namespace std;

class CodeGenContext;  

class Node {
public:
    llvm::Value* codeGen(CodeGenContext& ctx);
        virtual ~Node () {}
};

class Statement: public Node {  
public:
    virtual ~Statement () {}     
};

class Expression: public Node {
public:
    virtual ~Expression () {}
};

int main () {
    return 0;
}