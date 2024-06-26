#include <vector>

using namespace std;

template <typename T>
class Node
{
    private:
    T value;
    Node* parent;
    vector<Node*> children;

    public:
    Node(T value);
    ~Node() {}
    T getValue() const;
    Node* getParent() const;
    vector<Node*> getChildren() const;
    void addChild(Node<T> &node);
};