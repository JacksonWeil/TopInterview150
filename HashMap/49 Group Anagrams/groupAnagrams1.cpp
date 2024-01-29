/*

First attempt: --- the most convoluted and likely redundant leetcode submission yet --- somehow it worked first try and actually has middle of the pack tc and sc
SPEED: 36 ms
 BEAT: 38.82%
  MEM: 21.18 MB
 BEAT: 49.87%
              

Jackson Weil 1/14/2024

DESC: given an array (vector here) called 'strs', group the anagrams together --- return answer as <vector<vector<string>> in any valid order


CREDIT: myself


INTUITION: make a new data structure so I can keep track of each string in str and its (OG) index
           make a vector of objects of this new data structure that contains all the strings of strs and their indices
           sort each string in the new vector, and then sort the vector itself according to the strings
           anagrams will be neighbors --- group them
           convert this grouping back to groupings of original strings according to indices w/in intermediate grouping
           


NOTES: rahulvarma5297 on leetcode makes use of an unordered_map<string, vector<string>> where the key is the sorted representation of a string in strs and he does push_back into the val vector
         if a string in strs has a sorted representation equaling an existing key. After doing that for each string, it is trivial to create final grouping (push_back map.second onto final grouping for each entry)
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// I'm going to use this data structure to keep track of the strings I'm messing with --- I want to be able to 
class idx_str {
    public:
        int idx;
        string str;

        // constructor
        idx_str() {}

        // constructor w/ params
        idx_str(int i, const string& s) : idx(i), str(s) {}


        // comparison fnct
        static bool comp(const idx_str& first, const idx_str& second) {
            return first.str < second.str;
        }

};




class Solution {

    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {

            // iterators
            int i, j;

            // idx_str obj
            idx_str is;

            // vector of all idx_str
            vector<idx_str> idx_strs;

            // grouping --- intermediate, track indices using idx_str objects before converting back to original strings
            vector<vector<idx_str>> g_i;

            // grouping --- final
            vector<vector<string>> g_f;

            // temp vector<idx_str>
            vector<idx_str> tmp_i;

            // temp vector<string>
            vector<string> tmp_f;

            idx_strs.resize(0);

            // create idx_str obj for each string in strs
            for (i = 0; i < strs.size(); i++) {
                is = idx_str(i, strs[i]);
                idx_strs.push_back(is);
            }
 

            // sort each string in idx_strs
            for (i = 0; i < idx_strs.size(); i++) {
                sort(idx_strs[i].str.begin(), idx_strs[i].str.end());
            }

            // sort idx_strs by its sorted strings (tongue twister)
            sort(idx_strs.begin(), idx_strs.end(), idx_str::comp);

            // at this point, we have possible anagrams as neighbors within idx_strs --- we know their indices so we can create the final grouping after the intermediate grouping

            // let's do the intermediate grouping
            g_i.resize(0);
            tmp_i.resize(0);

            if (strs.size() == 0) return {{""}};

            tmp_i.push_back(idx_strs[0]);

            for (i = 1; i < idx_strs.size(); i++) {

                // if the current string equals the last, add it to grouping, otherwise, finish off the current grouping and begin a new one
                if (idx_strs[i].str == idx_strs[i - 1].str) {
                    tmp_i.push_back(idx_strs[i]);
                } else {
                    g_i.push_back(tmp_i);
                    tmp_i.resize(0);
                    tmp_i.push_back(idx_strs[i]);
                }

            }

            // now we have one last tmp_i to add
            g_i.push_back(tmp_i);

            g_f.resize(0);

            // convert back to OG strings
            for (i = 0; i < g_i.size(); i++) {
                tmp_f.resize(0);
                for (j = 0; j < g_i[i].size(); j++) {
                    tmp_f.push_back(strs[g_i[i][j].idx]);
                }
                g_f.push_back(tmp_f);
            }

            return g_f;
        }

};