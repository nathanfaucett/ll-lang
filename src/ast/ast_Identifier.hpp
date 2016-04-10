#ifndef __LL_AST_IDENTIFIER_HPP__
#define __LL_AST_IDENTIFIER_HPP__


namespace ll {
    namespace ast {
        class Identifier : public Expression {
            public:
                String* value;

                Identifier(String* value);
        };
    }
}


#endif
