#ifndef __LL_AST_EXPRESSION_HPP__
#define __LL_AST_EXPRESSION_HPP__


namespace ll {
    namespace ast {
        class Expression : public Node {};

        typedef std::vector<Expression*> ExpressionList;
    }
}


#endif
