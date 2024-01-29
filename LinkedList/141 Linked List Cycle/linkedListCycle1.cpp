/*

First attempt: --- naive --- unordered_set<ListNode *> as visited field
SPEED: 15 ms
 BEAT: 19.41%
  MEM: 14.21 MB
 BEAT: 5.45% --- subpar in both regards, but this was easy and readable --- I may look at Solutions later
              

Jackson Weil 1/28/2024

DESC:
 *
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

given head, the head of a linked list, return whether the linked list has a cycle



CREDIT:


INTUITION: go through the nodes, and maintain a visited vector --- I'm assuming right now that entries are unique
           leetcode also asks for a O(1) memory usage solution --- I imagine for this I could keep a count of how many nodes I've visited and if the count
           exceeds the max length, I return true --- this is almost certainly slower, but would not require a visited vector


NOTES:

*/

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {

    public:
        bool hasCycle(ListNode *head) {

            ListNode *cur;
            unordered_set<ListNode *> visited; /* I guess I can actually just track the pointer values to avoid uniqueness dependency for elements */

            cur = head;

            /* go until cur == NULL, meaning we fell off the tail */
            while (cur != NULL) {
                /* see if we have visited cur */
                if (visited.find(cur) != visited.end()) {
                    return true;
                } else {
                    visited.insert(cur);
                    cur = cur->next;
                }
            }
            return false;
        }

};