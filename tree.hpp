#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "iterators.hpp"

template <typename T, int K = 2>
class Tree
{
private:
    int numOfChildren;
    Node<T>* root;


public:
    Tree() : numOfChildren(K), root(nullptr) {}
    ~Tree() = default;

    void add_root(Node<T>& root);
    void add_sub_node(Node<T>& root, Node<T>& node);

    using PreOrderIterator = ::PreOrderIterator<T>;
    using PostOrderIterator = ::PostOrderIterator<T>;
    using InOrderIterator = ::InOrderIterator<T>;
    using BFSIterator = ::BFSIterator<T>;
    using DFSIterator = ::DFSIterator<T>;

    PreOrderIterator begin_pre_order();
    PreOrderIterator end_pre_order();
    PostOrderIterator begin_post_order();
    PostOrderIterator end_post_order();
    InOrderIterator begin_in_order();
    InOrderIterator end_in_order();
    BFSIterator begin_bfs_scan();
    BFSIterator end_bfs_scan();
    DFSIterator begin_dfs_scan();
    DFSIterator end_dfs_scan();
};

#endif // TREE_HPP
