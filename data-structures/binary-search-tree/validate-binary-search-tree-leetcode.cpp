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
    bool solve (TreeNode* root,long long mini , long long maxi){
        if(root==NULL)
            return true;
        
        if(root->val>mini && root->val<maxi){
            bool left = solve(root->left,mini , root->val);
            bool right = solve(root->right, root->val,maxi);
            return left && right ;
            
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,LONG_MIN,LONG_MAX);
    }
};

class Solution2 {
public:
    vector<int> v;
    void InorderTraverse(TreeNode *root) {
        if(root) {
            InorderTraverse(root->left);
            v.push_back(root->val);
            InorderTraverse(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        InorderTraverse(root);
        for(int i=1; i<v.size(); i++) {
            if(v[i-1] >= v[i]) return false;
        }
        return true;
    }
};
