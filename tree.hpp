#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "iterators.hpp"
#include <queue>

template <typename T, int K = 2>
class Tree
{
private:
    int numOfChildren;
    Node<T>* root;

    void deleteNodes(Node<T>* node);

public:
    Tree() : numOfChildren(K), root(nullptr) {}
    ~Tree();

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

template <typename T, int K>
void Tree<T, K>::deleteNodes(Node<T>* node)
{
    if (node == nullptr) return;
    for (Node<T>* child : node->getChildren())
    {
        deleteNodes(child);
    }
    delete node;
}

template <typename T, int K>
Tree<T, K>::~Tree()
{
    deleteNodes(root);
}

template <typename T, int K>
void Tree<T, K>::add_root(Node<T>& root)
{
    this->root = &root;
    cout << "Added root" << endl;
}

template <typename T, int K>
void Tree<T, K>::add_sub_node(Node<T>& root, Node<T>& node)
{
    if (&root == nullptr) return;

    auto children = root.getChildren();
    if (children.size() < K && &node != nullptr)
    {
        root.addChild(node);
        cout << "Added sub-node to node" << endl;
    }
}

template <typename T, int K>
typename Tree<T, K>::PreOrderIterator Tree<T, K>::begin_pre_order() {
    return PreOrderIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::PreOrderIterator Tree<T, K>::end_pre_order() {
    return PreOrderIterator(nullptr);
}

template <typename T, int K>
typename Tree<T, K>::PostOrderIterator Tree<T, K>::begin_post_order() {
    return PostOrderIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::PostOrderIterator Tree<T, K>::end_post_order() {
    return PostOrderIterator(nullptr);
}

template <typename T, int K>
typename Tree<T, K>::InOrderIterator Tree<T, K>::begin_in_order() {
    return InOrderIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::InOrderIterator Tree<T, K>::end_in_order() {
    return InOrderIterator(nullptr);
}

template <typename T, int K>
typename Tree<T, K>::BFSIterator Tree<T, K>::begin_bfs_scan() {
    return BFSIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::BFSIterator Tree<T, K>::end_bfs_scan() {
    return BFSIterator(nullptr);
}

template <typename T, int K>
typename Tree<T, K>::DFSIterator Tree<T, K>::begin_dfs_scan() {
    return DFSIterator(root);
}

template <typename T, int K>
typename Tree<T, K>::DFSIterator Tree<T, K>::end_dfs_scan() {
    return DFSIterator(nullptr);
}

// Explicit instantiation
template class Tree<int>;
template class Tree<double>;
template class Tree<string>;

#endif // TREE_HPP
