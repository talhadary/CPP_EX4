#include "tree.hpp"


using namespace std;

template<typename T, int K>
Tree<T, K>::~Tree()
{
    // TODO recursively delete all nodes
}

template<typename T, int K>
void Tree<T, K>::add_root(Node<T> &root)
{
    if(root != nullptr)
    {
        this->root = root;
        cout << "Added root" << endl;
    }
}

template<typename T, int K>
void Tree<T, K>::add_sub_node(Node<T> &root, Node<T> &node)
{
    if(root == nullptr) return;

    auto children = root->getChildren;
    if(children.size() < K - 1 && node != nullptr)
    {
        root->addChild(node);
        cout << "Added sub-node to node" << endl;
    }
}

template<typename T, int K>
Node<T>* Tree<T, K>::begin_pre_order()
{
    return this->&root;
}

template<typename T, int K>
Node<T>* Tree<T, K>::end_pre_order()
{
    // TODO
}

template<typename T, int K>
Node<T>* Tree<T, K>::begin_post_order()
{
    return this->&root;
}

template<typename T, int K>
Node<T>* Tree<T, K>::end_post_order()
{
    // TODO
}

template<typename T, int K>
Node<T>* Tree<T, K>::begin_in_order()
{
    return this->&root;
}

template<typename T, int K>
Node<T>* Tree<T, K>::end_in_order()
{
    // TODO
}

template<typename T, int K>
Node<T>* Tree<T, K>::begin_bfs_scan()
{
    return this->&root;
}

template<typename T, int K>
Node<T>* Tree<T, K>::end_bfs_scan()
{
    // TODO
}

template<typename T, int K>
Node<T>* Tree<T, K>::begin_dfs_scan()
{
    return this->&root;
}

template<typename T, int K>
Node<T>* Tree<T, K>::end_dfs_scan()
{
    // TODO return right most subnode
}


