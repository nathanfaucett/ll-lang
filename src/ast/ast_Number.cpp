#ifndef __LL_AST_NUMBER_CPP__
#define __LL_AST_NUMBER_CPP__


namespace ll {
    namespace ast {
        Number::Number(String* value, bool is_float) :
            value(value), is_float(is_float) {}
    }
}


#endif
