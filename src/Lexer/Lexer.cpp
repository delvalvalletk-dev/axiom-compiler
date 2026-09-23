#include "axiom/Lexer/Lexer.hpp"

#include <algorithm>

// implémentation du constructeur
axiom::Lexer::Lexer(std::string_view source){
    source_ = source;
}

std::string_view axiom::Lexer::getSource(){
    return source_;
}

std::size_t axiom::Lexer::getPosition(){
    return position_;
}

//====================================================================//
//=============== FONCTIONS DE RÉCUPÉRATION DES TOKENS ===============//
//====================================================================//

vector<axiom::Token> axiom::Lexer::fetchAllTokens(){

    // Initialisation du vecteur contenant les tokens
    std::vector<axiom::Token> tokens = {};

    // tant que nous ne sommes pas arrivés a la fin du code source
    while (!axiom::Lexer::isAtEnd()){

        // on ajoute à la liste le prochain token
        tokens.push_back(axiom::Lexer::nextToken());
    }

    return tokens;
}

axiom::Token axiom::Lexer::nextToken(){

    // Initialisation du tableau des operateurs et du caractère actuel
    std::vector<char> operators = {'+','-','='};
    char actualChar = axiom::Lexer::currentChar();

    // on skippe les espaces jusqu'à tomber sur un autre caractere
    axiom::Lexer::skipWhiteSpaces();

    // retourne le token de fin de code
    if (isAtEnd()) {
        string_view end = "";
        return axiom::Token(axiom::Token::Type::EndOfFile, end);
    }

    // Si le caractere actuel est un chiffre
    if (std::isdigit(actualChar)){

        // on retourne un token d'entier (pour l'instant)
        return axiom::Lexer::readNumber();
    }

    // Sinon, si le caractere actuel est une lettre de l'alphabet
    else if (std::isalpha(actualChar)){

        // on retourne un token d'identificateur (possible changement dans le futur)
        return axiom::Lexer::readIdentifier();
    }

    // Sinon, si le caractere actuel est un operateur (présent dans la liste operators)
    else if (std::find(operators.begin(), operators.end(), actualChar) != operators.end()){

        // on retourne un token d'opérateurs
        return axiom::Lexer::readOperator();        
    }

    // Sinon, on considere que c'est un élément spécial (possible changement dans le futur)
    else{
        return axiom::Lexer::readSpecialElement();         
    }


}


//====================================================================//
//========= FONCTIONS DE CRÉATION DES TOKENS DU CODE SOURCE ==========//
//====================================================================//

axiom::Token axiom::Lexer::readOperator(){
        
    // Initialisation du type
    axiom::Token::Type type;
    std::string value;

    // selon l'operateur, on retourne un token avec un type different
    switch (axiom::Lexer::currentChar())
    {
        case '+':
            type = axiom::Token::Type::Plus;
            value="+";
            break;
    
        case '-':
            type = axiom::Token::Type::Minus;
            value="-";
            break;

        case '=':
            type = axiom::Token::Type::Equal;
            value="=";
            break;            
    }

    // création d'un string_view sur la valeur trouvé
    std::string_view token_value = value;

    // on crée le token avec le type trouvé
    axiom::Token token = axiom::Token(type, token_value);

    // On passe au prochain caractere de la string view
    axiom::Lexer::nextChar();

    // On retourne le token
    return token;
}

axiom::Token axiom::Lexer::readIdentifier(){
    
    // Initialisation de la valeur et du type du token
    std::string value = "";
    axiom::Token::Type type = axiom::Token::Type::Identifier;

    // tant que le caractere actuel est une lettre de l'alphabet ([a-z] ou [A-Z])
    while (!axiom::Lexer::isAtEnd() && std::isalpha(axiom::Lexer::currentChar())){

        // ajoute le caractere à la valeur finale et passe au prochain
        value += source_[position_];
        axiom::Lexer::nextChar();    
    };

    // création d'un string_view sur la valeur trouvé
    std::string_view token_value = value;

    // on construit le token à l'aide du type, et de la valeur trouvé (ajouté au prochain commit)
    axiom::Token token = axiom::Token(type, token_value);
    
    // on passe au prochain caractere, une fois que l'identifier est terminé
    axiom::Lexer::nextChar();

    // on retourne le token contenant l'identifiant
    return token;

}

axiom::Token axiom::Lexer::readNumber(){
    
    // Initialisation de la valeur et du type du token
    std::string value = "";
    axiom::Token::Type type = axiom::Token::Type::Integer;

    // tant que le caractere actuel est un= chiffre
    while (!axiom::Lexer::isAtEnd() && std::isdigit(axiom::Lexer::currentChar())){

        // ajoute le caractere à la valeur finale et passe au prochain
        value += axiom::Lexer::currentChar();
        axiom::Lexer::nextChar();    
    };

    // création d'un string_view sur la valeur trouvé
    std::string_view token_value = value;

    // on construit le token à l'aide du type, et de la valeur trouvé (ajouté au prochain commit)
    axiom::Token token = axiom::Token(type, token_value);

    // on passe au prochain caractere, une fois que le nombre est terminé
    axiom::Lexer::nextChar();    
    
    // on retourne le token contenant le nombre
    return token;

}

axiom::Token axiom::Lexer::readSpecialElement(){

    // Initialisation du type, dependant de l'element spécial
    axiom::Token::Type type;
    std::string value;

    // selon le caractere actuel
    switch (axiom::Lexer::currentChar())
    {
        
        // si c'est un ; le type est semicolon
        case ';':
            type = axiom::Token::Type::Semicolon;
            value = ';';
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
                    value = '\n';
                    break;

                /* Implementation future d'autre caractère speciaux contenant '\' */
            
            }

            break;

    }

    // on passe au prochain caractere, une fois que l'identifier est terminé
    std::string_view token_value = value;

    // construction du token
    axiom::Token token = axiom::Token(type, token_value);

    // on passe au prochain caractere, une fois que le caractere spécial est terminé
    axiom::Lexer::nextChar();

    // on retourne le token du caractere spécial
    return token;

}


//====================================================================//
//===== FONCTIONS UTILITAIRES AU DEPLACEMENT DANS LE CODE SOURCE =====//
//====================================================================//

void axiom::Lexer::nextChar(){
    ++position_;
}

void axiom::Lexer::skipWhiteSpaces(){

    // tant que le caractere est un espace et que nous ne sommes pas a la fin
    while (!isAtEnd() && std::isspace(axiom::Lexer::currentChar())){

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