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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        DFS(root,res);
        return res;
    }
private:
    void DFS(TreeNode* r, vector<int>& res)
    {
        if(r==NULL)
        return;
        DFS(r->left,res);
        res.push_back(r->val);
        DFS(r->right,res);
    }
};