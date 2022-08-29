#include <iostream>
#include <forward_list>

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
    int maxDepth(TreeNode* root) {
        return depth(root , 1);
    }

    int depth(TreeNode *root, int d) { 
        if (!root) { 
            return d - 1;
        }
        int dr = depth(root->right, d + 1);
        int dl = depth(root->left, d+ 1);

        return max(dr, dl);
    }
};

int main()
{
}
