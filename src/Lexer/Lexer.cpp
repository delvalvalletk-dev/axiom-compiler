#include "Lexer.hpp"

axiom::Lexer::Lexer(std::string_view source){
    source_ = source;
}

axiom::Token axiom::Lexer::nextToken(){
    ;
}

axiom::Token axiom::Lexer::readIdentifier(){
    
    std::string token_value = "";

    while (std::isalpha(source_[position_])){
        token_value += source_[position_];
        axiom::Lexer::nextChar();    
    };

    axiom::Lexer::nextChar();

}

axiom::Token axiom::Lexer::readNumber(){
    
    std::string token_value = "";

    while (std::isdigit(source_[position_])){
        token_value += source_[position_];
        axiom::Lexer::nextChar();    
    };

    axiom::Lexer::nextChar();    

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