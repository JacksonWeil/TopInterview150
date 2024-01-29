/*

Second attempt --- beats 30.06% users in speed (5 ms)
               --- beats 98.80% users in mem  (9.30 MB) --- this varies greatly submission to submission

Jackson Weil 1/2/2024

merge 2 sorted arrays

CREDIT: all credit to amanrathore48 for code and its explanation via Leetcode

INTUITION:

since nums1 is already m+n elements long, it makes sense to start updating nums1
at the end (i.e. with the largest elements first) and working our way to the front.
In this way, once nums2 is exhausted, we know that nums1 contains our final answer,
as the elements originally native to nums1 will be right where they belong.

NOTES:

- using 'i--' in a subscript access is an interesting way to condense two lines to one
- the case of exhausting nums1 before nums2 is covered by the if clause --- once i
    is less than 0 (i.e. nums1 is exhausted) nums2's element's will always be inserted
- runtime is still underwhelming, but I'm moving on
*/

#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

// start copying into submission window here
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1;
        int j = n - 1;
        int comb = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && (nums1[i] > nums2[j])) {
                nums1[comb--] = nums1[i--];
            } else {
                nums1[comb--] = nums2[j--];
            }
        }
    }
};