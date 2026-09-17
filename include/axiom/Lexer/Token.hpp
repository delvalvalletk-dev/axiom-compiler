#pragma once
#include <string_view>

using namespace std;

namespace axiom{

    class Token{

        public:

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
            
            explicit Token(Type type, std::string_view value);

        private:
            Type type_; 
            std::string_view value_; 
    };
}