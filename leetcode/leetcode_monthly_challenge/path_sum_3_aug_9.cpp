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
    
    map<int, int> psum;
    int ans;
    
    void preorder(TreeNode* root, int target, int csum) {
        if(root == NULL) return;
        csum = root->val + csum;
        if(csum == target) {
            ++ans;
        }
        ans += psum[csum - target];
        psum[csum] += 1;
        preorder(root->left, target, csum);
        preorder(root->right, target, csum);
        psum[csum] -= 1;
    }
    
    int pathSum(TreeNode* root, int sum) {
        ans=0;
        psum = map<int, int>();
        preorder(root, sum, 0);
        return ans;
    }
};
