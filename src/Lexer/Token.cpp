
#include "axiom/Lexer/Token.hpp"

axiom::Token::Token(axiom::Token::Type type, std::string_view value){
    type_ = type;
    value_ = value;
}