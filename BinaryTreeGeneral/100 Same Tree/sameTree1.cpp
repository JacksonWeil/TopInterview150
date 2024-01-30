/*

First attempt: --- naive --- run a dfs and check for sameness at each point
SPEED: 3 ms
 BEAT: 31.99% 
  MEM: 11.61 
 BEAT: 7.49% --- kinda crappy... the recursion could certainly be undone
              

Jackson Weil 1/30/2024

DESC: given two trees (with pointers to their root nodes passed) return whether the trees are the same
      i.e. they have the same structure and the same values at each node in the structure


CREDIT:


INTUITION: do a DFS and check sameness at the start of each call


NOTES:

*/

#include <vector>
#include <iostream>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {

    public:

        bool parallel_DFS(TreeNode *p, TreeNode *q) {

            bool left_result, right_result;
            left_result = true;
            right_result = true;

            /* if p or q == NULL, the other better be NULL too */
            if (p == NULL) {
                if (q == NULL) {
                    return true;
                } else {
                    return false;
                } 
            } else {
                if (q == NULL) return false; /* if p is not NULL and q is, return false */
            }

            /* first, ensure values are equal --- if either are NULL, this will likely seg fault */
            if (p->val != q->val) return false;

            /* recurse on left child --- p->left may be NULL, in which case q->left better be NULL too */
            if (p->left != NULL) { 
                left_result = parallel_DFS(p->left, q->left);
            } else {
                if (q->left != NULL) return false;
            }

            /* recurse on right child */
            if (p->right != NULL) { 
                right_result = parallel_DFS(p->right, q->right);
            } else {
                if (q->right != NULL) return false;
            }

            /* I think I covered all cases, but I'll put this here to be safe */
            return (left_result && right_result);
        }

        bool isSameTree(TreeNode *p, TreeNode *q) {

            /* empty tree check */
            if (p == NULL) {
                if (q == NULL) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (q == NULL) return false;
            }

            return parallel_DFS(p, q);
        }

};