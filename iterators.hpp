#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "node.hpp"
#include <stack>
#include <queue>
#include <iterator>
#include <set>
#include <iostream>

// Pre-order Iterator: Visits the root node first, then recursively visits each subtree
template <typename T>
class PreOrderIterator {
    std::stack<Node<T>*> nodes; // Stack to manage nodes for traversal
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = Node<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    PreOrderIterator(Node<T>* root) {
        if (root != nullptr) nodes.push(root);
    }

    Node<T>* operator*() {
        return nodes.top();
    }

    PreOrderIterator& operator++() {
        Node<T>* node = nodes.top();
        nodes.pop();
        const auto& children = node->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            nodes.push(*it); // Push children in reverse order to process them in correct order
        }
        return *this;
    }

    bool operator!=(const PreOrderIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

// Post-order Iterator: Visits all subtrees first, then the root node
template <typename T>
class PostOrderIterator {
    std::stack<Node<T>*> nodes; // Stack to manage nodes for traversal
    std::set<Node<T>*> visited; // Set to keep track of visited nodes
    void pushChildren(Node<T>* node) {
        const auto& children = node->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            nodes.push(*it); // Push children in reverse order to process them in correct order
        }
    }
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = Node<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    PostOrderIterator(Node<T>* root) {
        if (root != nullptr) {
            nodes.push(root);
        }
    }

    Node<T>* operator*() {
        while (!nodes.empty()) {
            Node<T>* node = nodes.top();
            if (visited.find(node) == visited.end()) {
                pushChildren(node);
                visited.insert(node);
            } else {
                return node;
            }
        }
        return nullptr;
    }

    PostOrderIterator& operator++() {
        nodes.pop();
        return *this;
    }

    bool operator!=(const PostOrderIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

// Revised In-order Iterator: Visits the left subtree, then the root, then the right subtree
template <typename T>
class InOrderIterator {
    std::stack<Node<T>*> nodes; // Stack to manage nodes for traversal

    // Helper function to push all left children of the given node onto the stack
    void pushLeft(Node<T>* node) {
        while (node) {
            std::cout << "Pushing node with value: " << node->getValue() << std::endl;
            nodes.push(node);
            const auto& children = node->getChildren();
            if (!children.empty()) {
                node = children.front(); // Move to the leftmost child
            } else {
                break;
            }
        }
    }

public:
    using iterator_category = std::input_iterator_tag;
    using value_type = Node<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    // Constructor: Initialize the stack with the leftmost nodes starting from the root
    InOrderIterator(Node<T>* root) {
        if (root != nullptr) pushLeft(root);
    }

    // Dereference operator: Returns the current node
    Node<T>* operator*() {
        return nodes.top();
    }

    // Increment operator: Moves to the next node in in-order
    InOrderIterator& operator++() {
        if (nodes.empty()) return *this;

        Node<T>* node = nodes.top();
        nodes.pop();
        std::cout << "Visiting node with value: " << node->getValue() << std::endl;

        const auto& children = node->getChildren();
        if (children.size() > 1) { // Check if there is a right child
            pushLeft(children[1]); // Push all left children of the right child
        }

        return *this;
    }

    // Comparison operator: Checks if the stack is empty
    bool operator!=(const InOrderIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

// Breadth-First Search (BFS) Iterator: Visits nodes level by level
template <typename T>
class BFSIterator {
    std::queue<Node<T>*> nodes; // Queue to manage nodes for traversal
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = Node<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    // Constructor: Initialize the queue with the root node
    BFSIterator(Node<T>* root) {
        if (root != nullptr) nodes.push(root);
    }

    // Dereference operator: Returns the current node
    Node<T>* operator*() {
        return nodes.front();
    }

    // Increment operator: Moves to the next node in BFS order
    BFSIterator& operator++() {
        Node<T>* node = nodes.front();
        nodes.pop();
        for (Node<T>* child : node->getChildren()) {
            nodes.push(child); // Push all children to the queue
        }
        return *this;
    }

    // Comparison operator: Checks if the queue is empty
    bool operator!=(const BFSIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

// Revised Depth-First Search (DFS) Iterator: Visits nodes depth-wise
template <typename T>
class DFSIterator {
    std::stack<Node<T>*> nodes; // Stack to manage nodes for traversal
public:
    using iterator_category = std::input_iterator_tag;
    using value_type = Node<T>;
    using difference_type = std::ptrdiff_t;
    using pointer = Node<T>*;
    using reference = Node<T>&;

    // Constructor: Initialize the stack with the root node
    DFSIterator(Node<T>* root) {
        if (root != nullptr) nodes.push(root);
    }

    // Dereference operator: Returns the current node
    Node<T>* operator*() {
        return nodes.top();
    }

    // Increment operator: Moves to the next node in DFS order
    DFSIterator& operator++() {
        Node<T>* node = nodes.top();
        nodes.pop();
        const auto& children = node->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            nodes.push(*it); // Push children in reverse order to process them in correct order
        }
        return *this;
    }

    // Comparison operator: Checks if the stack is empty
    bool operator!=(const DFSIterator& other) const {
        return !nodes.empty() || !other.nodes.empty();
    }
};

#endif // ITERATORS_HPP
