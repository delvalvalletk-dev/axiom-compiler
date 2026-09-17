#include "Lexer.hpp"

axiom::Lexer::Lexer(std::string_view source){
    source_ = source;
}

axiom::Token axiom::Lexer::nextToken(){
    ;
}

axiom::Token axiom::Lexer::readOperator(){
        
    // Initialisation du type
    axiom::Token::Type type;

    // selon l'operateur, on retourne un token avec un type different
    switch (axiom::Lexer::currentChar())
    {
        case '+':
            enum axiom::Token::Type type = axiom::Token::Type::Plus;
            break;
    
        case '-':
            enum axiom::Token::Type type = axiom::Token::Type::Minus;
            break;

        case '=':
            enum axiom::Token::Type type = axiom::Token::Type::Equal;
            break;            
    }

    // on crée le token avec le type trouvé
    axiom::Token token = axiom::Token(type);

    // On passe au prochain caractere de la string view
    axiom::Lexer::nextChar();

    // On retourne le token
    return token;
}

axiom::Token axiom::Lexer::readIdentifier(){
    
    // Initialisation de la valeur et du type du token
    std::string token_value = "";
    axiom::Token::Type type = axiom::Token::Type::Identifier;

    // tant que le caractere actuel est une lettre de l'alphabet ([a-z] ou [A-Z])
    while (std::isalpha(axiom::Lexer::currentChar())){

        // ajoute le caractere à la valeur finale et passe au prochain
        token_value += source_[position_];
        axiom::Lexer::nextChar();    
    };

    // on construit le token à l'aide du type, et de la valeur trouvé (ajouté au prochain commit)
    axiom::Token token = axiom::Token(type);
    
    // on passe au prochain caractere, une fois que l'identifier est terminé
    axiom::Lexer::nextChar();

    // on retourne le token contenant l'identifiant
    return token;

}

axiom::Token axiom::Lexer::readNumber(){
    
    // Initialisation de la valeur et du type du token
    std::string token_value = "";
    axiom::Token::Type type = axiom::Token::Type::Integer;

    // tant que le caractere actuel est un= chiffre
    while (std::isdigit(source_[position_])){

        // ajoute le caractere à la valeur finale et passe au prochain
        token_value += source_[position_];
        axiom::Lexer::nextChar();    
    };

    // on construit le token à l'aide du type, et de la valeur trouvé (ajouté au prochain commit)
    axiom::Token token = axiom::Token(type);

    // on passe au prochain caractere, une fois que le nombre est terminé
    axiom::Lexer::nextChar();    
    
    // on retourne le token contenant le nombre
    return token;

}

axiom::Token axiom::Lexer::readSpecialElement(){

    // Initialisation du type, dependant de l'element spécial
    axiom::Token::Type type;
    std::string token_value;

    // selon le caractere actuel
    switch (axiom::Lexer::currentChar())
    {
        
        // si c'est un ; le type est semicolon
        case ';':
            type = axiom::Token::Type::Semicolon;
            token_value = ';';
            break;
        
        // sinon, le type depend du caractere suivant
        case '\\':

            // on regarde le prochain caractere
            axiom::Lexer::nextChar();

            // selon le prochain caractere
            switch (axiom::Lexer::currentChar())
            {
                // si le caractere est un 'n', alors c'ets un retour a la ligne
                case 'n':
                    type = axiom::Token::Type::EndOfLine;
                    token_value = '\n';
                    break;

                /* Implementation future d'autre caractère speciaux contenant '\' */
            
            }

            break;

    }

    // construction du token
    axiom::Token token = axiom::Token(type);

    // on passe au prochain caractere, une fois que le caractere spécial est terminé
    axiom::Lexer::nextChar();

    // on retourne le token du caractere spécial
    return token;

}

void axiom::Lexer::nextChar(){
    ++position_;
}

void axiom::Lexer::skipWhiteSpaces(){

    // tant que le caractere est un espace et que nous ne sommes pas a la fin
    while (!isAtEnd() && std::isspace(source_[position_])){

        // incremente la position
        position_++;
    };
}

char axiom::Lexer::currentChar(){

    // retourne le caractere à la position actuelle
    return source_[position_];
}

bool axiom::Lexer::isAtEnd(){
    // retourne true si la position est superieure ou égale à la taille de la string_view, non sinon
    return position_ >= source_.size();
}