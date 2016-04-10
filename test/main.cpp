#include <iostream>
#include <fstream>

#include "lib.hpp"
using namespace ll;


int main(void) {
    std::ifstream filestream("./example/main.ll");

    Lexer lexer(&filestream);
    Parser parser(&lexer);

    ast::Node* node = parser.parse();

    filestream.close();

    return 0;
}
