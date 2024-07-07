#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "node.hpp"
#include <stack>
#include <queue>
#include <iterator>
#include <set>

template <typename T>
class PreOrderIterator : public std::iterator<std::input_iterator_tag, Node<T>> {
    std::stack<Node<T>*> nodes;
public:
    PreOrderIterator(Node<T>* root) {
        if (root != nullptr) nodes.push(root);
    }

    Node<T>* operator*() {
        return nodes.top();
    }

    PreOrderIterator& operator++() {
        Node<T>* node = nodes.top();
        nodes.pop();
        std::vector<Node<T>*> children = node->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            nodes.push(*it);
        }
        return *this;
    }

    bool operator!=(const PreOrderIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

template <typename T>
class PostOrderIterator : public std::iterator<std::input_iterator_tag, Node<T>> {
    std::stack<Node<T>*> nodes;
    std::set<Node<T>*> visited;
public:
    PostOrderIterator(Node<T>* root) {
        if (root != nullptr) {
            pushChildren(root);
        }
    }

    void pushChildren(Node<T>* node) {
        nodes.push(node);
        for (auto it = node->getChildren().rbegin(); it != node->getChildren().rend(); ++it) {
            pushChildren(*it);
        }
    }

    Node<T>* operator*() {
        return nodes.top();
    }

    PostOrderIterator& operator++() {
        visited.insert(nodes.top());
        nodes.pop();
        return *this;
    }

    bool operator!=(const PostOrderIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

template <typename T>
class InOrderIterator : public std::iterator<std::input_iterator_tag, Node<T>> {
    std::stack<Node<T>*> nodes;
    std::set<Node<T>*> visited;
public:
    InOrderIterator(Node<T>* root) {
        if (root != nullptr) pushLeft(root);
    }

    void pushLeft(Node<T>* node) {
        while (node != nullptr) {
            nodes.push(node);
            if (!node->getChildren().empty())
                node = node->getChildren().front();
            else
                node = nullptr;
        }
    }

    Node<T>* operator*() {
        return nodes.top();
    }

    InOrderIterator& operator++() {
        Node<T>* node = nodes.top();
        nodes.pop();
        if (!node->getChildren().empty()) {
            auto it = node->getChildren().begin();
            ++it;
            if (it != node->getChildren().end())
                pushLeft(*it);
        }
        return *this;
    }

    bool operator!=(const InOrderIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

template <typename T>
class BFSIterator : public std::iterator<std::input_iterator_tag, Node<T>> {
    std::queue<Node<T>*> nodes;
public:
    BFSIterator(Node<T>* root) {
        if (root != nullptr) nodes.push(root);
    }

    Node<T>* operator*() {
        return nodes.front();
    }

    BFSIterator& operator++() {
        Node<T>* node = nodes.front();
        nodes.pop();
        for (Node<T>* child : node->getChildren()) {
            nodes.push(child);
        }
        return *this;
    }

    bool operator!=(const BFSIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

template <typename T>
class DFSIterator : public std::iterator<std::input_iterator_tag, Node<T>> {
    std::stack<Node<T>*> nodes;
public:
    DFSIterator(Node<T>* root) {
        if (root != nullptr) nodes.push(root);
    }

    Node<T>* operator*() {
        return nodes.top();
    }

    DFSIterator& operator++() {
        Node<T>* node = nodes.top();
        nodes.pop();
        for (auto it = node->getChildren().rbegin(); it != node->getChildren().rend(); ++it) {
            nodes.push(*it);
        }
        return *this;
    }

    bool operator!=(const DFSIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

#endif // ITERATORS_HPP
