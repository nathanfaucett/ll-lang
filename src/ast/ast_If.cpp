#ifndef __LL_AST_IF_CPP__
#define __LL_AST_IF_CPP__


namespace ll {
    namespace ast {

        If::If(ExpressionList* condition, ExpressionList* thenExpression) :
            condition(condition), thenExpression(thenExpression) {}

        If::If(ExpressionList* condition, ExpressionList* thenExpression, ExpressionList* elseExpression) :
            condition(condition), thenExpression(thenExpression), elseExpression(elseExpression) {}
    }
}


#endif
