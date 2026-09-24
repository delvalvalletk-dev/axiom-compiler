#pragma once
#include <string>

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
            explicit Token(Type type, std::string value);

            // methodes de récupération des valeurs privées
            Type getType();
            std::string getValue();

            // fonction de test, retourne le nom du type en tant que string
            static std::string tokenTypeToString(Type type);

        private:

            // le type du token
            Type type_; 
            // le contenu du token (partie du code)
            std::string value_; 

    };
}