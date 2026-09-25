#pragma once

#include "Node.hpp"
#include "Token.hpp"

#include <memory>
#include <vector>

namespace axiom{
    class Ast{
        
        public:
        
            explicit Ast(std::vector<Token> tokens);

            std::unique_ptr<Node> getPrincipalNode();
            std::vector<axiom::Token> getTokens();
        ;
        
        private:
            std::unique_ptr<Node> node_principal_ ;
            std::vector<Token> tokens_;

            void createPrincipalNode();
            std::unique_ptr<Node> createBinaryExpression(std::unique_ptr<Node> node_left, NodeOperator node_operator, std::unique_ptr<Node> node_right);
    };
}