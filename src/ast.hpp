#pragma once

#include <bits/stdc++.h>

#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Value.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Linker/Linker.h"
#include "llvm/Support/Error.h"

using namespace std;
using namespace llvm;

static LLVMContext context;
static Module module ("main", context);
static IRBuilder<> builder (context);
static vector<map<string, Value*>> symbolTable;

class Node {
public:
    virtual Value* codeGen () = 0;
    virtual ~Node () {}
};

class Statement:  public Node {};
class Expression: public Node {};

class Integer_literal: public Expression {
public:
    long long n;

    Integer_literal (long long& n) : n(n) {}

    Value* codeGen ();
    virtual ~Integer_literal () {}
};

class Floating_literal: public Expression {
public:
    long double n;

    Floating_literal (long double& n) : n(n) {}

    Value* codeGen () override;
    virtual ~Floating_literal () {}
};

class String_literal: public Expression {
public:
    string s;

    String_literal (string& s) : s(s) {}

    Value* codeGen () override;
    virtual ~String_literal () {}
};

class Identifier: public Expression {
public:
    string name;

    Identifier (string& name) : name(name) {}

    Value* codeGen () override;
    virtual ~Identifier () {}
};

class BinaryExpression: public Expression {
public:
    int op;
    Expression& lhs;
    Expression& rhs;

    BinaryExpression (Expression& lhs, int& op, Expression& rhs) : lhs(lhs), op(op), rhs(rhs) {}

    Value* codeGen () override;
    virtual ~BinaryExpression () {}
};

class AssignmentExpression: public Expression {
public:
    int& op;
    Identifier& lhs;
    Expression& rhs;

    AssignmentExpression (Identifier& lhs, int& op, Expression& rhs) : lhs(lhs), op(op), rhs(rhs) {}

    Value* codeGen () override;
    virtual ~AssignmentExpression () {}
};

class UnaryExpression: public Expression {
public:
    int& op;
    Expression& lhs;

    UnaryExpression (int& op, Expression& lhs) : op(op), lhs(lhs) {} 
    
    Value* codeGen () override;
    virtual ~UnaryExpression () {}    
};

class FunctionCall: public Expression {
public:
    string& name;
    vector<Expression*> args;

    FunctionCall (string& name, vector<Expression*>& args) : name(name), args(args) {}

    Value* codeGen () override;
    virtual ~FunctionCall () {}
};
