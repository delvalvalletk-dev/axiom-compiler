// Ce fichier ne doit être inclus qu'une seule fois à la compilation
#pragma once

#include <iostream>
#include <string_view>
#include <cstddef>
#include <cctype>

/* Classe de std permettant de faire une vue vers un string,
une référence vers son emplacement mémoire*/

// classe de génération de token à réaliser
#include "Token.hpp"

namespace axiom{

    class Lexer{
        public:
            explicit Lexer(std::string_view source);

            // fonction retournant le prochain token de la source
            Token nextToken();

        private:

            /* fonction qui a pour but de lire un identifiant, que ce soit INTEGER, LET, etc...
             LET, etc... et le retourne sous forme de TOKEN */
            Token readIdentifier();


            // fonction qui a pour but de lire un nombre, et le retourne en forme de token
            Token readNumber();

            // fonction de passage au prochain caractere
            void nextChar();

            // fonction qui passe tous les espace, jusqu'a tomber sur un caractère
            void skipWhiteSpaces();

            // fonction qui retourne le caractere à la position actuelle
            char currentChar();

            // fonction permettant de verifier si l'on est à la fin de la string view
            bool isAtEnd();



        private:

            /*vue d'une chaine de caractere, utilisant la position initiale et la longueur
            de la chaine de caractere dans la mémoire*/ 
            std::string_view source_;

            // position actuelle dans la string view, limité par isAtEnd()
            std::size_t position_ = 0;


    };
}

