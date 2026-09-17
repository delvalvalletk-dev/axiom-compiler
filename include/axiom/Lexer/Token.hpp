#pragma once

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
            
            explicit Token(Type type, std::string_view value);

        private:
            Type type_; 
            std::string_view value_; 
    };
}