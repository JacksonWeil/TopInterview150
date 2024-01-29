/*

Third attempt: --- slower than second way using O(n) extra mem (copy of nums), but we did do it in place with O(1) extra mem (tmp variables for swapping)
SPEED: 24 ms
 BEAT: 53.28%
  MEM: 25.24 MB
 BEAT: 84.20% 
              

Jackson Weil 1/6/2024

rotate an array (vector here) 'nums' by k places
try doing it in place and with O(1) extra space... seems like the time complexity will be O(kn) where n is the size of the vector
*** In my first solution, I exceeded the time limit.
    In my second,         I was inefficient with mem.

CREDIT: yashsiwach on leetcode for code
        kvardekkvar on leetcode comments for linking to wiki and saying "a rotation is a composition of two reflections (along a line)"


INTUION: reflect the first n-k elements
         reflect the last k elements
         reflect all elements
         you are left with the equivalent of a k rotation

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int i, n, tmp; // n will be the size of nums now rather than s

            n = nums.size();

            k = k % n;

            // reflect first n-k

            for (i = 0; i < (n - k) / 2; i++) {
                tmp = nums[i];
                nums[i] = nums[n - k - 1 - i];
                nums[n - k - 1 - i] = tmp;
            }

            // reflect last k

            for (i = 0; i < k / 2; i++) {
                tmp = nums[i + n - k];
                nums[i + n - k] = nums[n - 1 - i]; // n - 1 - i + n - k
                nums[n - 1 - i] = tmp;
            }


            // reflect all
            for (i = 0; i < n/2; i++) {
                tmp = nums[i];
                nums[i] = nums[n - 1 - i];
                nums[n - 1 - i] = tmp;
            }


            return;
        }
};


int main() {

    vector<int> test = {1, 2, 3, 4, 5, 6, 7};

    Solution s;

    s.rotate(test, 3);

    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }

    cout << endl;
    return 0;


}