#pragma once

#include <string>

namespace axiom{

    class Node{

        public:
            ~Node();

        private:
            ;

    };

    class NodeIdentifier : public Node {
        
        public:

            explicit NodeIdentifier(std::string value);
            std::string getValue();

        private:

            std::string value_;
    
    };


    class NodeNumber : public Node {

        public:
            explicit NodeNumber(double value);    
            double getValue();

        private:

            double value_;
            
    };

    class NodeOperator : public Node {
        
        enum class TypeOperator{
            ADD,
            SUBSTRACT,
            MULTIPLY,
            DIVIDE
        };

        public:
            explicit NodeOperator(TypeOperator type);

        private:
            TypeOperator type_;
            
    };    


    class NodeBinaryExpression : public Node {

        public:
            
            explicit NodeBinaryExpression(Node node_left, NodeOperator node_operator, Node node_right);

            Node getNodeLeft();
            NodeOperator getNodeOperator();
            Node getNodeRight();

        private:

            Node node_left_;
            NodeOperator node_operator_;
            Node node_right_;


    };


}