# Tree Container with GUI Visualization

This project implements a generic tree container in C++ that supports various traversal methods and visualizes the tree using a GUI.

## Project Overview

A tree is a tree in which each node has at most k children. This project includes a tree container that supports nodes containing any data type. The tree can be traversed using several standard methods, and the tree structure can be visualized using a GUI built with the SFML library.

### Features

- **Generic Tree Container**: Supports nodes of any data type.
- **Tree Traversal**: Includes pre-order, post-order, in-order, BFS, and DFS traversals.
- **Min-Heap Conversion**: Converts a binary tree into a min-heap.
- **GUI Visualization**: Visualizes the tree structure using SFML.

## Project Structure

- `Demo.cpp`: The main file that demonstrates the functionality of the tree and GUI.
- `tree.hpp`: Contains the implementation of the `Tree` class.
- `node.hpp`: Contains the implementation of the `Node` class.
- `iterators.hpp`: Contains implementations for various tree iterators.
- `gui.hpp`: Contains the implementation of the GUI class that visualizes the tree using SFML.
- `test.cpp`: Contains unit tests for the tree and GUI using `doctest`.
- `TestCounter.cpp`: Additional test file for testing tree operations.
- `doctest.h`: The `doctest` library header for unit testing.
- `Makefile`: The makefile for building the project and running tests.

## Implementation Details

### Tree Class

The `tree` class template represents a tree. It contains methods for adding a root, adding child nodes, and various traversal methods.

- **Methods**:
  - `add_root(const T& value)`: Adds a root node to the tree.
  - `add_sub_node(Node<T>* parent, const T& value)`: Adds a child node to the given parent node.
  - `begin_pre_order()`, `end_pre_order()`: Returns iterators for pre-order traversal.
  - `begin_post_order()`, `end_post_order()`: Returns iterators for post-order traversal.
  - `begin_in_order()`, `end_in_order()`: Returns iterators for in-order traversal.
  - `begin_bfs_scan()`, `end_bfs_scan()`: Returns iterators for BFS traversal.
  - `begin_dfs_scan()`, `end_dfs_scan()`: Returns iterators for DFS traversal.
  - `begin_heap_traversal()`, `end_heap_traversal()`: returns iterators for traversal of the min heap representation.

### Node Class

The `Node` class template represents a node in the tree. Each node contains a value and a vector of child nodes.

### Iterators

The project includes several iterators for tree traversal:
- **Pre-order Iterator**: Traverses the tree in pre-order.
- **Post-order Iterator**: Traverses the tree in post-order.
- **In-order Iterator**: Traverses the tree in in-order (for binary trees).
- **BFS Iterator**: Traverses the tree in breadth-first order.
- **DFS Iterator**: Traverses the tree in depth-first order.
- **Min-Heap Iterator**: Converts the tree into a min-heap and traverses it.

### GUI Class

The `GUI` class template visualizes the tree using SFML. It takes a `Tree` object and displays it in a window, with nodes represented as circles and edges as lines connecting the circles.

- **Methods**:
  - `GUI(Tree<T, K>& t)`: Constructor that initializes the GUI with the given tree.
  - `void run()`: Runs the GUI event loop, rendering the tree.

### Tests

The project uses the `doctest` library for unit testing. Tests are included in `test.cpp` and `TestCounter.cpp`.

## Owner

this project is owned by `Tal Hadary`
