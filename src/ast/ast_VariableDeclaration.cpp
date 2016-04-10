#ifndef __LL_AST_VARIABLE_DECLARATION_CPP__
#define __LL_AST_VARIABLE_DECLARATION_CPP__


namespace ll {
    namespace ast {

        VariableDeclaration::VariableDeclaration(Identifier* type, Identifier* id) :
            type(type), id(id) {}

        VariableDeclaration::VariableDeclaration(Identifier* type, Identifier* id, ExpressionList* expressions) :
            type(type), id(id), expressions(expressions) {}
    }
}


#endif
