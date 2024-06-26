#include "node.hpp"

using namespace std;

template <typename T, int K = 2>
class Tree
{
private:
    T type;
    int numOfChildren;
    Node<T>* root;

    public:
    Tree() : numOfChildren(K), root(nullptr) {}
    ~Tree();

    void add_root(Node<T> &root);
    void add_sub_node(Node<T> &root, Node<T> &node);
    Node<T>* begin_pre_order();
    Node<T>* end_pre_order();
    Node<T>* begin_post_order();
    Node<T>* end_post_order();
    Node<T>* begin_in_order();
    Node<T>* end_in_order();
    Node<T>* begin_bfs_scan();
    Node<T>* end_bfs_scan();
    Node<T>* begin_dfs_scan();
    Node<T>* end_dfs_scan();
    // TODO add myHeap method
    // TODO add GUI method
};