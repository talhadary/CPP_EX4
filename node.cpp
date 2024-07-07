#include "node.hpp"

template<typename T>
Node<T>::Node(T value)
{
    this->value = value;
    this->parent = nullptr;
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
void Node<T>::addChild(Node<T>& node)
{
    node.parent = this;
    this->children.push_back(&node);
}

// Explicit instantiation
template class Node<int>;
template class Node<double>;
template class Node<string>;
