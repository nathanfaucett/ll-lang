#ifndef __LL_LEXER_HPP__
#define __LL_LEXER_HPP__


namespace ll {
    class Token {
        public:
            String* value;
            uintsize row;
            uintsize column;
            Token(String* value, uintsize row, uintsize column);
    };

    class Lexer {
        private:
            std::istream* _stream;
            uintsize _index;
            uintsize _row;
            uintsize _column;
            uintsize _token_index;
            std::vector<Token*> _tokens;

            int32 _read(void);
            int32 _peek(void);
            int32 _peek(uintsize index);

            bool _is_syntax(int32 ch);
            bool _is_alpha_numeric(int32 ch);

            Token* _create_token(String* string, bool peek);
            Token* _create_token(int32 ch, bool peek);

            Token* _read_char(int32 ch, bool peek);
            Token* _read_string(int32 ch, bool peek);
            Token* _read_number(int32 ch, bool peek);
            Token* _read_identifier(int32 ch, bool peek);

            Token* _next(bool peek);

        public:
            Lexer(std::istream* stream);

            Token* peek(intsize index);
            Token* peek(void);

            Token* next(void);
    };
}


#endif
