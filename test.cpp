#include "doctest.h"
#include "tree.hpp"
#include "node.hpp"
#include "iterators.hpp"

// Basic tests for the tree structure
TEST_CASE("Testing tree creation and node addition") {
    // Create a binary tree and add root node
    Tree<int> myTree;
    Node<int> root(1);
    myTree.add_root(root);

    CHECK(*myTree.get_root() == root);

    // Add children to the root node
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(0);

    myTree.add_sub_node(root, child1);
    myTree.add_sub_node(root, child2);
    myTree.add_sub_node(root, child3); // Should not be added

    CHECK(root.getChildren().size() == 2); // Meaning third child wasn't added
    CHECK(root.getChildren()[0] == &child1);
    CHECK(root.getChildren()[1] == &child2);
}

// Test Pre-Order traversal
TEST_CASE("Testing Pre-Order Traversal") {
    Tree<int> myTree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);
    Node<int> child5(6);

    myTree.add_root(root);
    myTree.add_sub_node(root, child1);
    myTree.add_sub_node(child1, child2);
    myTree.add_sub_node(child1, child3);
    myTree.add_sub_node(root, child4);
    myTree.add_sub_node(child4, child5);

    std::vector<Node<int>*> expected_pre_order = {&root, &child1, &child2, &child3, &child4, &child5};
    std::vector<Node<int>*> result_pre_order;

    for(auto it = myTree.begin_pre_order(); it != myTree.end_pre_order(); ++it) {
        auto node = *it;
        result_pre_order.push_back(node);
    }

    for(uint i = 0; i < expected_pre_order.size(); i++)
    {
        CHECK(*expected_pre_order[i] == *result_pre_order[i]);
    }
}

// Test Post-Order traversal
TEST_CASE("Testing Post-Order Traversal") {
    Tree<int> myTree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);
    Node<int> child5(6);

    myTree.add_root(root);
    myTree.add_sub_node(root, child1);
    myTree.add_sub_node(child1, child2);
    myTree.add_sub_node(child1, child3);
    myTree.add_sub_node(root, child4);
    myTree.add_sub_node(child4, child5);

    std::vector<Node<int>*> expected_post_order = {&child2, &child3, &child1, &child5, &child4, &root};
    std::vector<Node<int>*> result_post_order;

    for(auto it = myTree.begin_post_order(); it != myTree.end_post_order(); ++it) {
        auto node = *it;
        result_post_order.push_back(node);
    }

    for(uint i = 0; i < expected_post_order.size(); i++)
    {
        CHECK(*expected_post_order[i] == *result_post_order[i]);
    }
}

// Test In-Order traversal
TEST_CASE("Testing In-Order Traversal") {
    Tree<int> myTree;
    Node<int> root(1);
    Node<int> child1(2);
    Node<int> child2(3);
    Node<int> child3(4);
    Node<int> child4(5);
    Node<int> child5(6);

    myTree.add_root(root);
    myTree.add_sub_node(root, child1);
    myTree.add_sub_node(child1, child2);
    myTree.add_sub_node(child1, child3);
    myTree.add_sub_node(root, child4);
    myTree.add_sub_node(child4, child5);

    std::vector<Node<int>*> expected_in_order = {&child2, &child1, &child3, &root, &child5, &child4};
    std::vector<Node<int>*> result_in_order;

    for(auto it = myTree.begin_in_order(); it != myTree.end_in_order(); ++it) {
        auto node = *it;
        result_in_order.push_back(node);
    }

    for(uint i = 0; i < expected_in_order.size(); i++)
    {
        CHECK(*expected_in_order[i] == *result_in_order[i]);
    }
}

// Test BFS traversal
TEST_CASE("Testing BFS Traversal") {
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

    std::vector<Node<int>*> expected_bfs = {&root, &child1, &child2, &child3, &child4, &child5};
    std::vector<Node<int>*> result_bfs;

    for(auto it = myTree.begin_bfs_scan(); it != myTree.end_bfs_scan(); ++it) {
        auto node = *it;
        result_bfs.push_back(node);
    }

    for(uint i = 0; i < expected_bfs.size(); i++)
    {
        CHECK(*expected_bfs[i] == *result_bfs[i]);
    }
}

// Test DFS traversal
TEST_CASE("Testing DFS Traversal") {
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

    std::vector<Node<int>*> expected_dfs = {&root, &child1, &child4, &child2, &child3, &child5};
    std::vector<Node<int>*> result_dfs;

    for(auto it = myTree.begin_dfs_scan(); it != myTree.end_dfs_scan(); ++it) {
        auto node = *it;
        result_dfs.push_back(node);
    }

    for(uint i = 0; i < expected_dfs.size(); i++)
    {
        CHECK(*expected_dfs[i] == *result_dfs[i]);
    }
}

TEST_CASE("Testing Heap Traversal") {
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

    std::vector<int> expectedMinHeap = {1, 2, 3, 4, 5, 6};
    std::vector<int> resultMinHeap;

    for(auto it = myTree.begin_heap_traversal(); it != myTree.end_heap_traversal(); ++it)
    {
        resultMinHeap.push_back(*it);
    }

    for(size_t i = 0; i < resultMinHeap.size(); ++i)
    {
        CHECK(resultMinHeap[i] == expectedMinHeap[i]);
    }
}
