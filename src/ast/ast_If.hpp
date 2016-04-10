#ifndef __LL_AST_IF_HPP__
#define __LL_AST_IF_HPP__


namespace ll {
    namespace ast {
        class If : public Expression {
            public:
                ExpressionList* condition;
                ExpressionList* thenExpression;
                ExpressionList* elseExpression;

                If(ExpressionList* condition, ExpressionList* thenExpression);
                If(ExpressionList* condition, ExpressionList* thenExpression, ExpressionList* elseExpression);
        };
    }
}


#endif
