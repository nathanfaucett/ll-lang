#ifndef __LL_AST_BLOCK_HPP__
#define __LL_AST_BLOCK_HPP__


namespace ll {
    namespace ast {
        class Block : public Expression {
            public:
                ExpressionList* expressions;
                Block();
                Block(ExpressionList* expressions);
        };
    }
}


#endif
