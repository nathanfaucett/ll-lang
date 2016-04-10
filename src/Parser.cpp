#ifndef __LL_PARSER_CPP__
#define __LL_PARSER_CPP__


namespace ll {
    Parser::Parser(Lexer* lexer) :
        _lexer(lexer) {}

    ast::Node* Parser::parse(void) {
        Token* token;

        while ((token = _lexer->next()) != NULL) {
            std::cout << to_cstring(token->value) << std::endl;
        }

        return NULL;
    }
}


#endif
