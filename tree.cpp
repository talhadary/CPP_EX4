#include "tree.hpp"
#include <iostream>

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
    std::cout << "Added root" << std::endl;
}

template <typename T, int K>
void Tree<T, K>::add_sub_node(Node<T>& root, Node<T>& node)
{
    const auto& children = root.getChildren();
    if (children.size() < K)
    {
        root.addChild(&node);
        std::cout << "Added sub-node to node" << std::endl;
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
template class Tree<std::string>;
template class Tree<double, 3>;
