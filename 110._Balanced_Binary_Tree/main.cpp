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
// [1,2,2,3,null,null,3,4,null,null,4]
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int hl = 0;
        int hr = 0;
        if (!root) {
            return true;
        }
        
        if(root->left) { 
            hl = height(root->left);
        }

        if(root->right) { 
            hr = height(root->right);
        }

        if (abs(hl-hr) > 1) { 
            return false;
        }
        return true && hr != -1 && hl != -1;
    }

    int height(TreeNode *root) {
        int hl = 0;
        int hr = 0;
        if(root->left) { 
            hl = height(root->left);
        }

        if (hl == -1 ) { 
            return -1;
        } 

        if(root->right) { 
            hr = height(root->right);
        }

        if (hr == -1 ) { 
            return -1;
        } 

        if (abs(hl - hr) > 1){
            return -1;
        } 

        return max(hl, hr) + 1;
    }
};

int main()
{
}
