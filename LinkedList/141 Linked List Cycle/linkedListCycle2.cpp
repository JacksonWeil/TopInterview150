/*

Second attempt: --- try to improve tc and sc
SPEED: 7 ms
 BEAT: 88.73%
  MEM: 10.40 MB
 BEAT: 29.16%
              

Jackson Weil 1/29/2024

DESC:
 *
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

given head, the head of a linked list, return whether the linked list has a cycle



CREDIT: KnockCat --- tortoise and hare explanation --- beautiful diagram and analogy to runners on a track --- faster runner will overtake slower runner if track is cyclical


INTUITION: maintain two pointers --- one is the tortoise, the other the hare.
           start them at the head, and so long we don't run off the end (reach NULL) move the hare forward two nodes and the hare only one
           if tortoise == hare, there is a cycle
           if hare reaches NULL w/o ever overtaking the tortoise, there is no cycle


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

            ListNode *tortoise, *hare;

            /* they both start at the head */
            tortoise = head;
            hare = head;

            /* if we just jumped off the end with hare or if we are at risk of jumping off the end with a double jump, stop the loop */
            while (hare != NULL && hare->next != NULL) {
                hare = hare->next->next;
                tortoise = tortoise->next;

                /* if hare reaches the tortoise, there is a cycle! In other words, the track is cyclical */
                if (hare == tortoise) return true;
            }

            return false;
        }

};