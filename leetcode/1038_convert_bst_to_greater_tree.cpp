#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

    TreeNode* InsertLeft(int x)
    {
        left = new TreeNode(x);
        return left;
    }
    TreeNode* InsertRight(int x)
    {
        right = new TreeNode(x);
        return right;
    }

};

int setGreater(TreeNode* root, int max)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->right != nullptr)
    {
        max = setGreater(root->right, max);
    }
    root->val += max;
    max = root->val;
    if (root->left != nullptr)
    {
        max = setGreater(root->left, max);
    }
    return max;
}

TreeNode* bstToGst(TreeNode* root)
{
    setGreater(root, 0);
    return root;
}

int main (int argc, char* argv[])
{
    ;
    return 0;
}
