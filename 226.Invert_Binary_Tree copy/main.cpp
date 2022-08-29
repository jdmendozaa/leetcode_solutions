#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> s;
    vector<string> binaryTreePaths(TreeNode* root) {
        printPaths(root, std::to_string(root->val));
        return s;
    }

    void printPaths(TreeNode* root, string currentPath) {
        if (!root->left && !root->right) { 
            s.push_back(currentPath);
            return;
        }
        
        if(root->left) { 
            printPaths(root->left, currentPath + "->" + std::to_string(root->left->val));
        }

        if(root->right) { 
            printPaths(root->right, currentPath + "->" + std::to_string(root->right->val));
        }
    }
};

int main()
{
}
