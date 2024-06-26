#include "node.hpp"

template<typename T>
Node<T>::Node(T value)
{
    this->value = value;
}

template<typename T>
T Node<T>::getValue() const
{
    return this->value;
}

template<typename T>
Node<T>* Node<T>::getParent() const
{
    return this->parent;
}

template<typename T>
vector<Node<T>*> Node<T>::getChildren() const
{
    return this->children;
}

template<typename T>
void Node<T>::addChild(Node<T> &node)
{
    this->children.push_back(node);
}
