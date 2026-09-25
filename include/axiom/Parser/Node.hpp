#pragma once

#include <string>
#include <memory>

namespace axiom{

    class Node{

        public:
            virtual ~Node();

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

        public:

            enum class TypeOperator{
                ADD,
                SUBSTRACT,
                MULTIPLY,
                DIVIDE
            };

            explicit NodeOperator(TypeOperator type);

        private:
            TypeOperator type_;
            
    };    


    class NodeBinaryExpression : public Node {

        public:
            
            explicit NodeBinaryExpression(std::unique_ptr<Node> node_left, NodeOperator node_operator, std::unique_ptr<Node> node_right);

            NodeOperator getNodeOperator();
            std::unique_ptr<Node> getNodeLeft();
            std::unique_ptr<Node> getNodeRight();

        private:

            std::unique_ptr<Node> node_left_;
            NodeOperator node_operator_;
            std::unique_ptr<Node> node_right_;


    };


}