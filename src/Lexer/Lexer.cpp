#include "Lexer.hpp"

axiom::Lexer::Lexer(std::string_view source){
    source_ = source;
}

axiom::Token axiom::Lexer::nextToken(){
    ;
}

axiom::Token axiom::Lexer::readIdentifier(){
    ;
}

axiom::Token axiom::Lexer::readNumber(){
    ;
}

void axiom::Lexer::nextChar(){
    ++position_;
}

void axiom::Lexer::skipWhiteSpaces(){
    while (!isAtEnd() && std::isspace(source_[position_])){
        position_++;
    };
}

char axiom::Lexer::currentChar(){
    return source_[position_];
}

bool axiom::Lexer::isAtEnd(){
    // simplification
    return position_ >= source_.size();
}