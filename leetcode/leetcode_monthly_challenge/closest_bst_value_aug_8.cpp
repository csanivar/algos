/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    double md;
    int ans;
    int closestValue(TreeNode* root, double target) {
        md = (double) root->val - target;
        ans = root->val;
        while(root != NULL) {
            double cd = (double) root->val - target;
            if(abs(cd) < abs(md)) {
                md = cd;
                ans = root->val;
            }
            if(cd > 0.0) {
                root = root->left;
            } else if (cd < 0.0) {
                root = root->right;
            } else {
                return root->val;
            }
        }
        
        return ans;
    }
};
