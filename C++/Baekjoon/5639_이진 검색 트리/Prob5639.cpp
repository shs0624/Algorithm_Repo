#include <iostream>
#include <map>
using namespace std;

struct Node
{
    int item;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinaryTree
{
public:
    Node* RootNode;
    BinaryTree();
    void Insert(int num);
    void PostOrder(Node* node);
};

BinaryTree::BinaryTree()
{
    RootNode = nullptr;
}

void BinaryTree::Insert(int num)
{
    if (nullptr == RootNode)
    {
        Node* node = new Node;
        node->item = num;
        RootNode = node;
    }
    else
    {
        Node* target = RootNode;
        Node* node = new Node;
        node->item = num;
        while (1)
        {
            if (target->item > num)
            {
                if (target->left == nullptr)
                {
                    target->left = node;
                    target = RootNode;
                    break;
                }
                else
                {
                    target = target->left;
                }
            }
            else
            {
                if (target->right == nullptr)
                {
                    target->right = node;
                    target = RootNode;
                    break;
                }
                else
                {
                    target = target->right;
                }
            }
        }
    }
}

void BinaryTree::PostOrder(Node* node)
{
    if (node->left != nullptr)
    {
        PostOrder(node->left);
    }
    if (node->right != nullptr)
    {
        PostOrder(node->right);
    }
    cout << node->item << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    BinaryTree bt;

    while (cin >> num)
    {
        bt.Insert(num);
    }

    bt.PostOrder(bt.RootNode);
}