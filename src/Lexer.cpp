#ifndef __LL_LEXER_CPP__
#define __LL_LEXER_CPP__


namespace ll {
    Token::Token(String* value, uintsize row, uintsize column) :
        value(value), row(row), column(column) {}

    Lexer::Lexer(std::istream* stream) : _stream(stream) {
        _index = 0;
        _row = 1;
        _column = 1;
        _token_index = 0;
    }

    bool Lexer::_is_syntax(int32 ch) {
        switch (ch) {
            case '(':
            case ')':
            case '{':
            case '}':
            case '<':
            case '>':
            case ':':
            case ';':
            case '?':
            case '*':
            case '&':
            case '^':
            case '%':
            case '~':
            case '!':
            case '-':
            case '/':
            case '|':
            case '=':
            case ',':
                return true;
            default:
                return false;
        }
    }

    bool Lexer::_is_alpha_numeric(int32 ch) {
        return (
            ch != EOF &&
            !is_whitespace(ch) &&
            !_is_syntax(ch)
        );
    }

    int32 Lexer::_read(void) {
        int32 ch = _stream->peek();

        if (ch != EOF || ch != '\0') {
            _index++;

            switch (ch) {
                case '\n':
                case '\r':
                    _row = 1;
                    _column++;
                    break;
                default:
                    _row++;
                    break;
            }

            return _stream->get();
        } else {
            return EOF;
        }
    }

    int32 Lexer::_peek(void) {
        char ch = _stream->peek();

        if (ch == EOF) {
            return ch;
        } else {
            return ch;
        }
    }
    int32 Lexer::_peek(uintsize index) {
        _stream->seekg(_index + (index - 1));
        char ch = _stream->peek();
        _stream->seekg(_index);

        if (ch == EOF || ch == '\0') {
            return ch;
        } else {
            return ch;
        }
    }

    Token* Lexer::_create_token(String* string, bool peek) {
        Token* token = new Token(string, _row, _column);
        _tokens.push_back(token);
        if (!peek) {
            _token_index++;
        }
        return token;
    }
    Token* Lexer::_create_token(int32 ch, bool peek) {
        String* string = new String();
        string->push_back(ch);
        return _create_token(string, peek);
    }

    Token* Lexer::_read_char(int32 ch, bool peek) {
        String* string = new String();
        int32 prev_ch;

        string->push_back(ch);

        while (true) {
            ch = _read();
            prev_ch = ch;

            if (ch == '\\') {
                ch = _read();
            }

            string->push_back(ch);

            if ((prev_ch != '\\' && ch == '\'') || ch == EOF) {
                break;
            }
        }

        return _create_token(string, peek);
    }
    Token* Lexer::_read_string(int32 ch, bool peek) {
        String* string = new String();
        int32 prev_ch;

        string->push_back(ch);

        while (true) {
            ch = _read();
            prev_ch = ch;

            if (ch == '\\') {
                ch = _read();
            }

            string->push_back(ch);

            if ((prev_ch != '\\' && ch == '"') || ch == EOF) {
                break;
            }
        }

        return _create_token(string, peek);
    }
    Token* Lexer::_read_number(int32 ch, bool peek) {
        String* string = new String();

        string->push_back(ch);

        while (true) {
            ch = _peek();

            if (is_numeric(ch) || (ch == '.' || ch == 'x')) {
                string->push_back(ch);
                _read();
            } else {
                break;
            }
        }

        return _create_token(string, peek);
    }
    Token* Lexer::_read_identifier(int32 ch, bool peek) {
        String* string = new String();

        string->push_back(ch);

        while (true) {
            ch = _peek();

            if (_is_alpha_numeric(ch)) {
                string->push_back(ch);
                _read();
            } else {
                break;
            }
        }

        return _create_token(string, peek);
    }

    Token* Lexer::_next(bool peek) {
        int32 ch;

        while (true) {
            ch = _read();

            while (is_whitespace(ch)) {
                ch = _read();
            }

            if (ch == EOF) {
                return NULL;
            }

            if (ch == '\'') {
                return _read_char(ch, peek);
            } else if (ch == '"') {
                return _read_string(ch, peek);
            } else if (_is_syntax(ch)) {
                return _create_token(ch, peek);
            } else if (is_numeric(ch) || (ch == '-' && is_numeric(_peek()))) {
                return _read_number(ch, peek);
            } else {
                return _read_identifier(ch, peek);
            }
        }
    }

    Token* Lexer::peek(intsize index) {
        Token* token = NULL;
        intsize dif = (_tokens.size() + index) - _token_index;

        if (dif > 0) {
            while (dif--) {
                token = _next(true);
            }
            return token;
        } else {
            intsize i = _token_index - dif;
            return _tokens[i > 0 ? i : 0];
        }
    }
    Token* Lexer::peek(void) {
        return peek(0);
    }

    Token* Lexer::next(void) {
        if (_token_index < _tokens.size()) {
            return _tokens[_token_index++];
        } else {
            return _next(false);
        }
    }
}


#endif
