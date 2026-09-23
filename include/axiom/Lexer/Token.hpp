#pragma once
#include <string_view>

using namespace std;

namespace axiom{

    // classe d'un Token, representant un élément logique du code fournit
    class Token{

        // methodes publiques
        public:

            // enumération des differents types de tokens
            enum class Type {
                Identifier,
                Integer,
                Plus,
                Minus,
                Equal,
                Semicolon,
                EndOfLine,
                EndOfFile
            };
            
            //constructeur
            explicit Token(Type type, std::string_view value);

            // methodes de récupération des valeurs privées
            Type getType();
            std::string_view getValue();


        private:

            // le type du token
            Type type_; 

            // le contenu du token (partie du code)
            std::string_view value_; 
    };
}