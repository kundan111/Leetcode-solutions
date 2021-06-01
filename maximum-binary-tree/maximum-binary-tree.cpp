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

// This is O(n^2) time solution --> NOT OPTIMAL
// Space: O(logn)
class Solution {
    using It = std::vector<int>::const_iterator;
    
    TreeNode* traverse(It from, It to) {
        auto it = std::max_element(from, to);
        if (it == to) 
            return nullptr;
        return new TreeNode(*it, traverse(from, it), traverse(it + 1, to));
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traverse(nums.begin(), nums.end());
    }
};