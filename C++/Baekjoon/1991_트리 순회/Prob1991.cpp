#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode
{
    char item;
    TreeNode* leftNode;
    TreeNode* rightNode;
};

void Preorder(TreeNode* node)
{
    cout << node->item;
    if(node->leftNode != NULL)
    {
        Preorder(node->leftNode);
    }
    if(node->rightNode != NULL)
    {
        Preorder(node->rightNode);
    }
}

void Inorder(TreeNode* node)
{
    if(node->leftNode != NULL)
    {
        Inorder(node->leftNode);
    }
    cout << node->item;
    if(node->rightNode != NULL)
    {
        Inorder(node->rightNode);
    }
}

void Postorder(TreeNode* node)
{
    if(node->leftNode != NULL)
    {
        Postorder(node->leftNode);
    }
    if(node->rightNode != NULL)
    {
        Postorder(node->rightNode);
    }
    cout << node->item;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<TreeNode> treeNodeVec;
    map<char,TreeNode> trees;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        char c, left, right;
        cin >> c >> left >> right;

        trees[c].item = c;
        if(left != '.') trees[c].leftNode = &trees[left];
        if(right != '.') trees[c].rightNode = &trees[right];
    }

    Preorder(&trees['A']);
    cout << "\n";
    Inorder(&trees['A']);
    cout << "\n";
    Postorder(&trees['A']);
}