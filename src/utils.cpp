#ifndef __LL_UTILS_CPP__
#define __LL_UTILS_CPP__


namespace ll {
    bool is_whitespace(int32 ch) {
        return (
            (ch >= 0x0009 && ch <= 0x000D) ||
            ch == 0x0020 ||
            ch == 0x0085 ||
            ch == 0x00A0 ||
            ch == 0x2028 ||
            ch == 0x2029
        );
    }

    bool is_numeric(int32 ch) {
        return ch >= 0x30 && ch <= 0x39;
    }

    int32  escape(int32 ch) {
        switch ((char) ch) {
            case 't':
                return '\t';
            case 'r':
                return '\r';
            case 'n':
                return '\n';
            case 'b':
                return '\b';
            case 'f':
                return '\f';
            default:
                return ch;
        }
    }

    char* to_cstring(String* string) {
        uintsize size = string->size();
        char* cstring = new char[size + 1];

        for (uintsize i = 0, il = size; i < il; i++) {
            cstring[i] = (char) (*string)[i];
        }
        cstring[size] = '\0';

        return cstring;
    }
}


#endif
