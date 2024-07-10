#include "tree.hpp"
#include "node.hpp"
#include "gui.hpp"

int main() {
    Tree<int, 3> myTree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);
    Node<int> child5(6);

    myTree.add_root(root);
    myTree.add_sub_node(root, child1);
    myTree.add_sub_node(root, child2);
    myTree.add_sub_node(root, child3);
    myTree.add_sub_node(child1, child4);
    myTree.add_sub_node(child3, child5);

    GUI gui(myTree);
    gui.run();

    return 0;
}
