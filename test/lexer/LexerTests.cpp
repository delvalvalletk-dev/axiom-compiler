#include <iostream>
#include "Lexer.hpp"

int main()
{
    axiom::Lexer lexer("42 + 5;");

    auto tokens = lexer.fetchAllTokens();

    std::cout << "Nombre de tokens : " << tokens.size() << '\n';

    return 0;
}