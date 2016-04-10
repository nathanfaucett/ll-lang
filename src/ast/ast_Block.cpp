#ifndef __LL_AST_BLOCK_CPP__
#define __LL_AST_BLOCK_CPP__


namespace ll {
    namespace ast {
        Block::Block() {}
        Block::Block(ExpressionList* expressions) :
            expressions(expressions) {}
    }
}


#endif
