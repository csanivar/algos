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
using pi = pair<int, int>;

class Solution {
public:
    map<int, vector<pi>> mp;
    set<int> keys;
    
    void preorder(TreeNode*root, int x, int y) {
        if(root == NULL) return;
        keys.insert(x);
        if(mp.find(x) == mp.end()) mp.insert({x, vector<pi>()});
        mp[x].push_back({y, root->val});
        preorder(root->left, x-1, y+1);
        preorder(root->right, x+1, y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // mp = new vector<int, vector<int>>();
        preorder(root, 0, 0);
        vector<vector<int>> ans;
        for(auto key: keys) {
            sort(mp[key].begin(), mp[key].end());
            vector<int> t;
            for(auto item: mp[key]) t.push_back(item.second);
            ans.push_back(t);
        }
        return ans;
    }
};
