#ifndef __LL_AST_BINARY_OPERATOR_CPP__
#define __LL_AST_BINARY_OPERATOR_CPP__


namespace ll {
    namespace ast {
        BinaryOperator::BinaryOperator(ExpressionList* lhs, int32 op, ExpressionList* rhs) :
            op(op), lhs(lhs), rhs(rhs) {}
    }
}


#endif
