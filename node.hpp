// node.hpp
#pragma once
#include <vector>

template <typename T>
class Node {
public:
    Node(const T &value);
    const T &getValue() const;
    void addChild(Node<T> *child);
    const std::vector<Node<T> *> &getChildren() const;
    bool operator==(Node<T> &other) const;

private:
    T value;
    std::vector<Node<T> *> children;
};

// Definitions in header file
template <typename T>
Node<T>::Node(const T &value) : value(value) {}

template <typename T>
const T &Node<T>::getValue() const {
    return value;
}

template <typename T>
void Node<T>::addChild(Node<T> *child) {
    if(child == nullptr) { return; }
    children.push_back(child);
}

template <typename T>
const std::vector<Node<T> *> &Node<T>::getChildren() const {
    return children;
}

template <typename T>
inline bool Node<T>::operator==(Node<T> &other) const
{
    return this == &other;
}
