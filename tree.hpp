#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "iterators.hpp"
#include <iostream>
#include <algorithm>
#include <functional>

using std::size_t;

template <typename T, size_t K = 2>
class Tree
{
private:
    size_t numOfChildren;
    Node<T>* root;
    std::vector<T> min_heap;

    void heapify()
    {
        if(!min_heap.empty()) { min_heap.clear(); }

        for(auto it = this->begin_bfs_scan(); it != this->end_bfs_scan(); ++it)
        {
            min_heap.push_back((*it)->getValue());
        }

        std::make_heap(min_heap.begin(), min_heap.end(), std::greater<>{});
    }

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
    using MinHeapIterator = ::MinHeapIterator<T>;

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

    MinHeapIterator begin_heap_traversal() {
        heapify();
        return MinHeapIterator(min_heap.begin());
    }

    MinHeapIterator end_heap_traversal() {
        return MinHeapIterator(min_heap.end());
    }
};

#endif // TREE_HPP
