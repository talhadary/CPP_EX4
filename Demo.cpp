#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main()
{
    Node<double> root_node = Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "Pre-order traversal:" << endl;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it)
    {
        cout << (*it)->getValue() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    cout << "Post-order traversal:" << endl;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it)
    {
        cout << (*it)->getValue() << endl;
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

    cout << "In-order traversal:" << endl;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it)
    {
        cout << (*it)->getValue() << endl;
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

    cout << "BFS traversal:" << endl;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
    {
        cout << (*it)->getValue() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "DFS traversal:" << endl;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
    {
        cout << (*it)->getValue() << endl;
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    Tree<double, 3> three_ary_tree; // 3-ary tree.
    Node<double> root_node2 = Node(1.1);
    three_ary_tree.add_root(root_node2);
    Node<double> n6 = Node(1.2);
    Node<double> n7 = Node(1.3);
    Node<double> n8 = Node(1.4);
    Node<double> n9 = Node(1.5);
    Node<double> n10 = Node(1.6);

    three_ary_tree.add_sub_node(root_node2, n6);
    three_ary_tree.add_sub_node(root_node2, n7);
    three_ary_tree.add_sub_node(root_node2, n8);
    three_ary_tree.add_sub_node(n6, n9);
    three_ary_tree.add_sub_node(n7, n10);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */

    cout << "BFS traversal:" << endl;
    for (auto it = three_ary_tree.begin_bfs_scan(); it != three_ary_tree.end_bfs_scan(); ++it)
    {
        cout << (*it)->getValue() << endl;
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

    cout << "DFS traversal:" << endl;
    for (auto it = three_ary_tree.begin_dfs_scan(); it != three_ary_tree.end_dfs_scan(); ++it)
    {
        cout << (*it)->getValue() << endl;
    } // prints: 1.1, 1.2, 1.5, 1.3, 1.6, 1.4

    return 0;
}
