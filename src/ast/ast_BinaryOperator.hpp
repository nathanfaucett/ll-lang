#ifndef __LL_AST_BINARY_OPERATOR_HPP__
#define __LL_AST_BINARY_OPERATOR_HPP__


namespace ll {
    namespace ast {
        class BinaryOperator : public Expression {
            public:
                int32 op;
                ExpressionList* lhs;
                ExpressionList* rhs;

                BinaryOperator(ExpressionList* lhs, int32 op, ExpressionList* rhs);
        };
    }
}


#endif
