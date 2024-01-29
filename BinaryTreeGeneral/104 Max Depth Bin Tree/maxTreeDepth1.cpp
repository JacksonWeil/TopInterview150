/*

First attempt: --- naive DFS w/ helper function
SPEED: 3 ms
 BEAT: 92.84%
  MEM: 17.71 MB
 BEAT: 84.11%
              

Jackson Weil 1/29/2024

DESC: given a tree, return the length of the longest branch (# nodes from root to leaf of longest branch)


CREDIT:


INTUITION: do a DFS, track the depth by adding one with each recurisve call and then taking the max of the left and right depth as the return val


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

int DFS(TreeNode n, int depth) {

    int ret, lcd, rcd; /* return value (depth of this node), left-child depth, right-child depth*/

    /* base case --- no children */
    if (n.left == NULL && n.right == NULL) return depth;

    /* recurse on left */
    if (n.left != NULL) {
        lcd = DFS(*(n.left), depth + 1);
    } else {
        lcd = 0;
    }

    /* " " on right */
    if (n.right != NULL) {
        rcd = DFS(*(n.right), depth + 1);
    } else {
        rcd = 0;
    }

    ret = lcd > rcd ? lcd : rcd; /* make the return value the maximum depth between this node's two children... */

    return ret;
}
  
class Solution {

    public:
        int maxDepth(TreeNode* root) {

            /* make sure root is not NULL */
            if (root == NULL) return 0;

            return DFS(*root, 1);
        }

};