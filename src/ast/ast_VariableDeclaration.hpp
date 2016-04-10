#ifndef __LL_AST_VARIABLE_DECLARATION_HPP__
#define __LL_AST_VARIABLE_DECLARATION_HPP__


namespace ll {
    namespace ast {
        class VariableDeclaration : public Expression {
            public:
                Identifier* type;
                Identifier* id;
                ExpressionList* expressions;

                VariableDeclaration(Identifier* type, Identifier* id);
                VariableDeclaration(Identifier* type, Identifier* id, ExpressionList* expressions);
        };

        typedef std::vector<VariableDeclaration*> VariableList;
    }
}


#endif
