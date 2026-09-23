#include <cassert>
#include <iostream>

#include "axiom/lexer/Lexer.hpp"

// implémentation de nextToken nécéssaire - reprobleme de merge pour les methodes get

void testIdentifier()
{
    axiom::Lexer lexer("hello");

    axiom::Token token = lexer.nextToken();

    assert(token.getType() == axiom::Token::Type::Identifier);
    assert(token.getValue() == "hello");

    assert(lexer.getSource() == "hello");
    assert(lexer.getPosition() == 5);
}


void testInteger()
{
    axiom::Lexer lexer("12345");

    axiom::Token token = lexer.nextToken();

    assert(token.getType() == axiom::Token::Type::Integer);
    assert(token.getValue() == "12345");

    assert(lexer.getPosition() == 5);
}


void testPlus()
{
    axiom::Lexer lexer("+");

    axiom::Token token = lexer.nextToken();

    assert(token.getType() == axiom::Token::Type::Plus);
    assert(token.getValue() == "+");

    assert(lexer.getPosition() == 1);
}


void testMinus()
{
    axiom::Lexer lexer("-");

    axiom::Token token = lexer.nextToken();

    assert(token.getType() == axiom::Token::Type::Minus);
    assert(token.getValue() == "-");

    assert(lexer.getPosition() == 1);
}


void testEqual()
{
    axiom::Lexer lexer("=");

    axiom::Token token = lexer.nextToken();

    assert(token.getType() == axiom::Token::Type::Equal);
    assert(token.getValue() == "=");

    assert(lexer.getPosition() == 1);
}


void testSemicolon()
{
    axiom::Lexer lexer(";");

    axiom::Token token = lexer.nextToken();

    assert(token.getType() == axiom::Token::Type::Semicolon);
    assert(token.getValue() == ";");

    assert(lexer.getPosition() == 1);
}


void testWhitespace()
{
    axiom::Lexer lexer("   hello");

    axiom::Token token = lexer.nextToken();

    assert(token.getType() == axiom::Token::Type::Identifier);
    assert(token.getValue() == "hello");

    assert(lexer.getPosition() == 8);
}


void testMultipleTokens()
{
    axiom::Lexer lexer("hello 123 +");

    axiom::Token identifier = lexer.nextToken();
    axiom::Token number = lexer.nextToken();
    axiom::Token plus = lexer.nextToken();

    assert(identifier.getType() == axiom::Token::Type::Identifier);
    assert(identifier.getValue() == "hello");

    assert(number.getType() == axiom::Token::Type::Integer);
    assert(number.getValue() == "123");

    assert(plus.getType() == axiom::Token::Type::Plus);
    assert(plus.getValue() == "+");

    assert(lexer.getPosition() == 11);
}


void testFetchAllTokens()
{
    axiom::Lexer lexer("hello 123 +");

    std::vector<axiom::Token> tokens = lexer.fetchAllTokens();

    assert(tokens.size() == 3);

    assert(tokens[0].getType() == axiom::Token::Type::Identifier);
    assert(tokens[0].getValue() == "hello");

    assert(tokens[1].getType() == axiom::Token::Type::Integer);
    assert(tokens[1].getValue() == "123");

    assert(tokens[2].getType() == axiom::Token::Type::Plus);
    assert(tokens[2].getValue() == "+");
}


int main()
{
    testIdentifier();
    testInteger();
    testPlus();
    testMinus();
    testEqual();
    testSemicolon();
    testWhitespace();
    testMultipleTokens();
    testFetchAllTokens();

    std::cout << "All lexer tests passed!\n";

    return 0;
}