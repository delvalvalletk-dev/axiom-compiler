
#include "axiom/Lexer/Token.hpp"

axiom::Token::Token(axiom::Token::Type type, std::string value){
    type_ = type;
    value_ = value;
}

axiom::Token::Type axiom::Token::getType(){
    return axiom::Token::type_;
}

std::string axiom::Token::getValue(){
    return axiom::Token::value_;
}