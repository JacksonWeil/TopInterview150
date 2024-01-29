/*

Second attempt: --- using deleted_user's solution --- turn input into vector of pairs, sort the vector, merge or insert as needed
SPEED: 22 ms
 BEAT: 97.89%
  MEM: 23.39 MB
 BEAT: 6.09%  --- maybe I could define a sorting function to just sort a vector of vectors based on the first element of each subvector and not make a copy of the whole thing
              

Jackson Weil 1/21/2024

DESC:


CREDIT: deleted_user on leetcode --- basically the bottom 15 lines of my previous code but he sorts first and uses a pair data structure rather than map (good idea)


INTUITION: turn inputs into a vector of 2-integer pairs
           sort that vector of pairs
           for i = 0 to i = pairs.size() - 1
           if the current pair's second >= next pair's first:
                the new second = max(current second, new pair's second)
           else:
                no merges are possible with this one, so make a 2-element subanswer vector to push_back on the answer, and increment first and second pointers
           push_back the final first and second


NOTES:

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {

    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {

            int i;
            int f, s;
            vector<pair<int, int>> p;
            vector<int> a(2);
            vector<vector<int>> ret;

            for (i = 0; i < intervals.size(); i++) {
                p.push_back({intervals[i][0], intervals[i][1]});
            }

            // sort
            sort(p.begin(), p.end());

            f = p[0].first;
            s = p[0].second;

            // go through each pair, merging or inserting into the answer as needed
            for (i = 0; i < p.size() - 1; i++) {
                if (s >= p[i+1].first) {
                    s = max(s, p[i+1].second);
                }
                else {
                    a[0] = f;
                    a[1] = s;
                    f = p[i+1].first;
                    s = p[i+1].second;
                    ret.push_back(a);
                }
            }

            ret.push_back({f, s});

            return ret;
        }


};