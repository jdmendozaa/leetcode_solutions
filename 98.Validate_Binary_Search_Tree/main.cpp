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
// Space: O(N)
// class Solution
// {
// public:
//     std::forward_list<int> list;
//     int size;
//     bool isValidBST(TreeNode *root)
//     {
//         inOrder(root);
//         int prev = list.front();
//         list.pop_front();
        
//         if (list.empty()) { 
//             return true;
//         }

//         for (auto elem : list) {
//             if (elem >= prev ) {
//                 return false;
//             }
//             prev = elem;
//         }
//         return true;
//     }

//     void inOrder(TreeNode *root) {
//         if (root->left) {
//             inOrder(root->left);
//         }
//         list.push_front(root->val);
//         size++;
//          if (root->right) {
//             inOrder(root->right);

//         }
//     }
// };

// Space: O(1)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return inOrder(root);
    }

    int size = 0;
    int prev;
     bool inOrder(TreeNode *root) {
        if (root->left) {
            if (!inOrder(root->left)) {
                return false;
            };
        }
        if (size != 0 ){
            if (root->val <= prev) { 
                return false;
            }
        }
        cout << root->val << " ";
        prev = root->val;
        size++;

         if (root->right) {
            if (!inOrder(root->right)) { 
                return false;
            };
        }

        return true;
    }
};

int main()
{
}
