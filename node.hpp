#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

template <typename T>
class Node {
    T value;
    std::vector<Node<T>*> children;

public:
    Node(const T& val) : value(val) {}

    const T& getValue() const { return value; }
    void addChild(Node<T>* child) { children.push_back(child); }
    const std::vector<Node<T>*>& getChildren() const { return children; }

    ~Node() {
        for (Node<T>* child : children) {
            delete child;
        }
    }
};

#endif // NODE_HPP
