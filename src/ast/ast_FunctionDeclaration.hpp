#ifndef __LL_AST_FUNCTION_DECLARATION_HPP__
#define __LL_AST_FUNCTION_DECLARATION_HPP__


namespace ll {
    namespace ast {
        class FunctionDeclaration : public Expression {
            public:
                Identifier* type;
                Identifier* id;
                VariableList* arguments;
                Block* block;

                FunctionDeclaration(Identifier* type, Identifier* id, VariableList* arguments, Block* block);
        };
    }
}


#endif
