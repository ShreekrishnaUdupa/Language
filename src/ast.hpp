#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

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

class ClassMember: public Node {};
class Statement: public Node {};
class Expression: public Node {};

class Parameter: public Node {
public:
    string type;
    string name;
    
    Parameter (string& type, string& name) : type(type), name(name) {}
};

class FunctionDeclaration: public ClassMember {
public:
    string returnType;
    string name;
    vector<unique_ptr<Parameter>> parameters;
    vector<unique_ptr<Statement>> body;
    
    FunctionDeclaration (string& returnType, string& name, vector<unique_ptr<Parameter>> parameters, vector<unique_ptr<Statement>> body) :
        returnType(returnType), name(name), parameters(move(parameters)), body(move(body)) {}

    Value* codeGen () override;
};

class ConstructorDeclaration: public ClassMember {
public:
    vector<unique_ptr<Parameter>> parameters;
    vector<unique_ptr<Statement>> body;

    ConstructorDeclaration (vector<unique_ptr<Parameter>> parameters, vector<unique_ptr<Statement>> body) :
        parameters(move(parameters)), body(move(body)) {}
        
    Value* codeGen () override;
};

class DestructorDeclaration: public ClassMember {
public:
    vector<Statement*> body;

    DestructorDeclaration (vector<Statement*>& body) : body(body) {}

    Value* codeGen () override;
};

class VariableDeclaration: public ClassMember {
    string type;
    string name;
    Expression* initializer;

    VariableDeclaration (string& type, string& name, Expression*& initializer) :
        type(type), name(name), initializer(initializer) {}

    Value* codeGen () override;
};

class ClassDeclarations: public Node {
public:
    string name;
    vector<ClassMember*> members;

    ClassDeclarations (string& name, vector<ClassMember*> members) : name(name), members(members) {}

    Value* codeGen () override;
};

class IntegerLiteralExpression: public Expression {
public:
    long long val;

    IntegerLiteralExpression (long long& val) : val(val) {}

    Value* codeGen () override;
};

class FloatingLiteralExpression: public Expression {
public:
    long double val;

    FloatingLiteralExpression (long double& n) : val(val) {}

    Value* codeGen () override;
};

class BooleanLiteralExpression: public Expression {
public:
    bool val;

    BooleanLiteralExpression (bool val) : val(val) {}

    Value* codeGen () override;
};

class StringLiteralExpression: public Expression {
public:
    string s;

    StringLiteralExpression (string& s) : s(s) {}

    Value* codeGen () override;
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
    Expression* lhs;
    Expression* rhs;

    BinaryExpression (Expression*& lhs, int op, Expression*& rhs) : lhs(lhs), op(op), rhs(rhs) {}

    Value* codeGen () override;
    virtual ~BinaryExpression () {}
};

class AssignmentExpression: public Expression {
public:
    int op;
    Identifier* lhs;
    Expression* rhs;

    AssignmentExpression (Identifier*& lhs, int op, Expression*& rhs) : lhs(lhs), op(op), rhs(rhs) {}

    Value* codeGen () override;

    virtual ~AssignmentExpression () {
        delete lhs;
        delete rhs;
    }
};

class UnaryExpression: public Expression {
public:
    int op;
    Expression* lhs;

    UnaryExpression (int& op, Expression*& lhs) : op(op), lhs(lhs) {} 
    
    Value* codeGen () override;
};

class FunctionCall: public Expression {
public:
    string name;
    vector<Expression*> args;

    FunctionCall (string& name, vector<Expression*>& args) : name(name), args(args) {}

    Value* codeGen () override;
};