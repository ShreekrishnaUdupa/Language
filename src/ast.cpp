#include "ast.hpp"
#include "parser.hpp"

Value* Integer_literal::codeGen () {
    return ConstantInt::get(Type::getInt64Ty(context), n, true);
}

Value* Floating_literal::codeGen () {
    return llvm::ConstantFP::get(context, APFloat(APFloat::IEEEquad(), to_string(n)));
}

Value* BinaryExpression::codeGen () {

    using token = yy::parser::token;
    
    Value *l = lhs.codeGen();
    Value *r = rhs.codeGen();
    
    if (!l || !r)
        return nullptr;

    switch (op) {

        case token::PLUS:           return builder.CreateFAdd(l, r);
        case token::MINUS:          return builder.CreateFSub(l, r);
        case token::MULTIPLY:       return builder.CreateFMul(l, r);
        case token::DIVIDE:         return builder.CreateFDiv(l, r);
        case token::MODULO:         return builder.CreateFRem(l, r);

        case token::BIT_OR:         return builder.CreateOr(l, r);
        case token::BIT_AND:        return builder.CreateAnd(l, r);
        case token::BIT_XOR:        return builder.CreateXor(l, r);
        case token::LEFT_SHIFT:     return builder.CreateShl(l, r);
        case token::RIGHT_SHIFT:    return builder.CreateLShr(l, r);

        case token::GREATER:        return builder.CreateUIToFP(builder.CreateFCmpUGT(l, r), Type::getDoubleTy(context));
        case token::LESSER:         return builder.CreateUIToFP(builder.CreateFCmpULT(l, r), Type::getDoubleTy(context));
        case token::GE:             return builder.CreateUIToFP(builder.CreateFCmpUGE(l, r), Type::getDoubleTy(context));
        case token::LE:             return builder.CreateUIToFP(builder.CreateFCmpULE(l, r), Type::getDoubleTy(context));
        case token::E:              return builder.CreateUIToFP(builder.CreateFCmpUEQ(l, r), Type::getDoubleTy(context));
        case token::NE:             return builder.CreateUIToFP(builder.CreateFCmpUNE(l, r), Type::getDoubleTy(context));

        case token::LOGICAL_OR:
            l = builder.CreateFCmpONE(l, ConstantFP::get(context, APFloat(0.0)));
            r = builder.CreateFCmpONE(r, ConstantFP::get(context, APFloat(0.0)));
            return builder.CreateUIToFP(builder.CreateOr(l, r), Type::getDoubleTy(context));

        case token::LOGICAL_AND:
            l = builder.CreateFCmpONE(l, ConstantFP::get(context, APFloat(0.0)));
            r = builder.CreateFCmpONE(r, ConstantFP::get(context, APFloat(0.0)));
            return builder.CreateUIToFP(builder.CreateAnd(l, r), Type::getDoubleTy(context));

        default:
            return nullptr;
    }
}