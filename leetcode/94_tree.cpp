#include <iostream>
#include <vector>

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

void inorder(TreeNode* root, vector<int>& result)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr)
    {
        inorder(root->left, result);
    }
    result.push_back(root->val);
    if (root->right != nullptr)
    {
        inorder(root->right, result);
    }
}

std::vector<int> inorderTraversal(TreeNode* root)
{
    std::vector<int> result;
    inorder(root, result);
    return result;
}

void show(const vector<int>& vec)
{
    for (auto i : vec)
    {
        cout << i << ",";
    }
    cout << endl;
}

int main (int argc, char* argv[])
{
    TreeNode* root = new TreeNode(1);
    auto* l2 = root->InsertLeft(2);
    l2->InsertLeft(3);
    l2->InsertRight(4);
    root->InsertRight(5)->InsertLeft(6);
    auto vec = inorderTraversal(root);
    show(vec);
    return 0;
}
