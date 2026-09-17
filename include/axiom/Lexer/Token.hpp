#pragma once

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
                EndOfFile
            };
            
            explicit Token(Type type);

        private:
            Type type_; 
    };
}