#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "iterators.hpp"
#include <iostream>

using std::size_t;

template <typename T, size_t K = 2>
class Tree
{
private:
    size_t numOfChildren;
    Node<T>* root;

public:
    Tree() : numOfChildren(K), root(nullptr) {}
    ~Tree() = default;

    void add_root(Node<T>& root) {
        this->root = &root;
        std::cout << "Added root" << std::endl;
    }

    const Node<T> *get_root() const { return this->root; }

    void add_sub_node(Node<T>& root, Node<T>& node) {
        const auto& children = root.getChildren();
        if (children.size() < K) {
            root.addChild(&node);
            std::cout << "Added sub-node to node" << std::endl;
        } else {
            std::cout << "Maximum number of sub-nodes reached!" << std::endl;
        }
    }

    using PreOrderIterator = ::PreOrderIterator<T>;
    using PostOrderIterator = ::PostOrderIterator<T>;
    using InOrderIterator = ::InOrderIterator<T>;
    using BFSIterator = ::BFSIterator<T, K>;
    using DFSIterator = ::DFSIterator<T, K>;

    PreOrderIterator begin_pre_order() {
        return PreOrderIterator(root);
    }

    PreOrderIterator end_pre_order() {
        return PreOrderIterator(nullptr);
    }

    PostOrderIterator begin_post_order() {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order() {
        return PostOrderIterator(nullptr);
    }

    InOrderIterator begin_in_order() {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order() {
        return InOrderIterator(nullptr);
    }

    BFSIterator begin_bfs_scan() {
        return BFSIterator(root);
    }

    BFSIterator end_bfs_scan() {
        return BFSIterator(nullptr);
    }

    DFSIterator begin_dfs_scan() {
        return DFSIterator(root);
    }

    DFSIterator end_dfs_scan() {
        return DFSIterator(nullptr);
    }
};

#endif // TREE_HPP
