#ifndef __LL_AST_FUNCTION_DECLARATION_CPP__
#define __LL_AST_FUNCTION_DECLARATION_CPP__


namespace ll {
    namespace ast {
        FunctionDeclaration::FunctionDeclaration(
            Identifier* type, Identifier* id, VariableList* arguments, Block* block
        ) : type(type), id(id), arguments(arguments), block(block) {}
    }
}


#endif
