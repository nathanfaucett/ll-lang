#ifndef __LL_PARSER_HPP__
#define __LL_PARSER_HPP__


namespace ll {
    class Parser {
        private:
            Lexer* _lexer;

        public:
            Parser(Lexer* lexer);

            ast::Node* parse(void);
    };
}


#endif
