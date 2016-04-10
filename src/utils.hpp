#ifndef __LL_UTILS_HPP__
#define __LL_UTILS_HPP__


namespace ll {
    bool is_whitespace(int32 ch);
    bool is_numeric(int32 ch);
    int32 escape(int32 ch);
    
    char* to_cstring(String* string);
}


#endif
