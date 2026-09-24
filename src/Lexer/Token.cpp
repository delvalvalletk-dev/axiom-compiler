
#include "axiom/Lexer/Token.hpp"

axiom::Token::Token(axiom::Token::Type type, std::string value){
    type_ = type;
    value_ = value;
}

axiom::Token::Type axiom::Token::getType(){
    return axiom::Token::type_;
}

std::string axiom::Token::tokenTypeToString(axiom::Token::Type type){
    
    switch (type)
    {
        case Type::Identifier:
            return "Identifier";

        case Type::Integer:
            return "Integer";

        case Type::Plus:
            return "Plus";

        case Type::Minus:
            return "Minus";

        case Type::Equal:
            return "Equal";

        case Type::Semicolon:
            return "Semicolon";

        case Type::EndOfLine:
            return "EndOfLine";
    }

    return "Unknown";
} 

std::string axiom::Token::getValue(){
    return axiom::Token::value_;
}