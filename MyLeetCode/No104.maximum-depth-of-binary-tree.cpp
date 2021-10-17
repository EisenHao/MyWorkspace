/** 题目描述：
 * 104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

 *
 * Encoding：utf-8
 * Programming language：c++
 * Coder：eisenhao
 * 20190303
 * */
#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int L_Depth = maxDepth(root->left);
        int R_Depth = maxDepth(root->right);
        if (L_Depth > R_Depth) {
            return L_Depth+1;
        } else {
            return R_Depth+1;
        }
    }
};
