/*

First attempt --- beats 5.31% users in speed (6 ms)
              --- beats 76.85% users in mem  (9.34 MB)

Jackson Weil 1/2/2024

merge 2 sorted arrays

*/

#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

// start copying into submission window here
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // create a copy of the first m elements of nums1
        vector<int> v1;
        int i, l, r;

        for (i = 0; i < m; i++) {
            v1.push_back(nums1[i]);
        }

        // merge v1 and nums2 into nums1 in non-decreasing order
        l = 0;
        r = 0;

        // while neither vector is exhausted, compare the smallest elements of both vectors and add the smaller of the two to nums1
        while ((l < m) && (r < n)) {
            if (v1[l] < nums2[r]) {
                nums1[l+r] = v1[l];
                l++;
            } else {
                nums1[l+r] = nums2[r];
                r++;
            }
        }

        // once one vector is ran through, we simply copy the remaining elements into the remaining slots
        while (l < m) {
            nums1[l+r] = v1[l];
            l++;
        }
        while (r < n) {
            nums1[l+r] = nums2[r];
            r++;
        }
        return;
    }
};