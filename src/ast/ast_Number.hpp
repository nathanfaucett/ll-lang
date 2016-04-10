#ifndef __LL_AST_NUMBER_HPP__
#define __LL_AST_NUMBER_HPP__


namespace ll {
    namespace ast {
        class Number : public Expression {
            public:
                String* value;
                bool is_float;

                Number(String* value, bool is_float);
        };
    }
}


#endif
