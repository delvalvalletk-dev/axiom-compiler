// Ce fichier ne doit être inclus qu'une seule fois à la compilation
#pragma once

/* Classe de std permettant de faire une vue vers un string,
une référence vers son emplacement mémoire*/

#include <string_view>
#include <iostream>
#include <cstddef>
#include <cctype>

// classe de génération de token à réaliser
#include "Token.hpp"

namespace axiom{
    class Lexer{
        public:
            explicit Lexer(std::string_view source);

            Token nextToken();

        private:

            /* fonction qui a pour but de lire un identifiant, que ce soit INTEGER, LET, etc...
             LET, etc... et le retourne sous forme de TOKEN */
            Token readIdentifier(){
                ;
            }

            // fonction qui a pour but de lire un nombre, et le retourne en forme de token
            Token readNumber(){
                ;
            }

            // fonction de passage au prochain caractere
            void nextChar(){
                ;
            }

            // fonction qui passe tous les espace, jusqu'a tomber sur un caractère
            void skipWhiteSpaces(){
                while (!isAtEnd() && std::isblank(source_[position_])){
                    std::cout << "Removing whitespace.." << std::endl;
                    position_++;
                };
            }

            // fonction qui retourne le caractere à la position actuelle
            char currentChar(){
                return source_[position_];
            }

            // fonction permettant de verifier si l'on est à la fin de la string view
            bool isAtEnd(){
                if (source_.size()==position_){
                    return true;
                };

                return false;
            }



        private:

            /*vue d'une chaine de caractere, utilisant la position initiale et la longueur
            de la chaine de caractere dans la mémoire*/ 
            std::string_view source_;

            // position actuelle dans la string view, limité par isAtEnd()
            std::size_t position_ = 0;


    };
}

