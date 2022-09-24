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
    bool isSymmetric(TreeNode* root) {
        return areSymmetric(root->left, root->right);
    }

    bool areSymmetric(TreeNode *t1, TreeNode *t2) {

        if (!t1 && !t2) { 
            return true;
        }
        
        return (t1 && t2) && (t1->val == t2->val) && 
                areSymmetric(t1->left, t2->right) && 
                areSymmetric(t1->right, t2->left);
    }
};

int main()
{
}
