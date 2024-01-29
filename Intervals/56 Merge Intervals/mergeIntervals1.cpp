/*

First attempt: --- Wrong Answer | 168/170 --- I'm tired of this attempt for the moment --- I'm off on one of the two failed test cases by a single digit. Hard to tell why
SPEED: 
 BEAT: 
  MEM: 
 BEAT:  
              

Jackson Weil 1/20/2024

DESC: given array of intervals where intervals[i] = [start_index, end_index], merge all overlapping intervals and return array of non-overlapping intervals that cover all the intervals in the input


CREDIT:


INTUITION: have a map where the (key, value) pairs are (start, end) pairs
           for each element of intervals, make a call to lower_bound, passing the starting index
           if it returns m.end(), either this element can be merged with the last element of the map, or we need a new pair on our map
           if it returns an iterator to an actual map pair, check if mit->first is <= the end index
           if it is, we can merge! if not, we need a new element 
           ---
           just realized this probably only works if the intervals are sorted by the start index
           OR
           we could check the start index and end index to see if we bridge a gap (overlap with two previously non-overlapping intervals)


NOTES:

*/

#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {

    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {

            vector<vector<int>> ret;
            int i;
            int eater;
            vector<int> cur; // interval[i] --- just to keep code concise - not helping my sc
            map<int, int> m; // < start, end > pairs
            map<int, int>::iterator mit;
            map<int, int>::iterator last_pair;
            map<int, int>::iterator to_erase;

            if (intervals.size() == 0) return ret;

            // put first interval on map
            m.insert(make_pair(intervals[0][0], intervals[0][1]));

            // go through every other interval
            for (i = 0; i < intervals.size(); i++) {
                cur = intervals[i];

                // make lower_bound iterator --- returns pointer to map entry w/ first key greater than or equal to cur[0] --- our current start boundary
                mit = m.lower_bound(cur[0]);

                // if mit == m.end(), this element can either go with last element, or we need a new pair for it
                if (mit == m.end()) {
                    // check on last value in the map (right endpoint)
                    last_pair = m.end();
                    --last_pair;

                    // merge if end of the mapped interval is beyond or equal to the start of the cur interval
                    if (last_pair->second >= cur[0]) {
                        if (last_pair->second < cur[1]) {
                            last_pair->second = cur[1];
                        }
                    }
                    // make new pair if cur goes beyond our registered intervals
                    else {
                        m[cur[0]] = cur[1];
                    }
                }

                // if mit != m.end() --- i.e. mit now points to an entry w/ key gte our cur start boundary --- and if cur[1] >= mit->first, we need to merge!
                else {
                    if (cur[1] >= mit->first) {
                        // we need a new map entry keyed on cur[0] and val'd on either cur[1] or mit->second: whichever is greater
                        m[cur[0]] = mit->second;
                        // if cur[1] is higher than mit->second, update our new entry's end bound
                        if (cur[1] > mit->second) {
                            m[cur[0]] = cur[1];

                            // erase mit, which is no longer unique, but make a copy of it so we can look ahead for the next part
                            last_pair = mit;
                            last_pair++;
                            // actually, we only erase if cur[0] < mit->first --- if they are equal, we already overwrote mit
                            if (cur[0] < mit->first) {
                                m.erase(mit->first);
                            }

                            // let's reuse mit to point to the cur entry
                            mit = m.find(cur[0]);

                            if (mit == m.end()) {
                                cout << "Uh oh spaghettios" << endl;
                                return ret;
                            }

                            // MAKE A COPY OF mit->second BEFORE OVERWRITING IN CASE WE EAT MORE THAN 1 INTERVAL
                            eater = mit->second;

                            // here, it is possible that we leapt so far that we overlap with an interval past the original mit... let's check it out
                            while (last_pair != m.end()) {
                
                                // if the end boundary of cur is greater than or equal to last_pair->first, we need to do another merge
                                if (eater >= last_pair->first) {
                                    // we need to merge and then erase last_pair, but through a copy so we can continue the while loop
                                    mit->second = last_pair->second;

                                    // if eater > last_pair->second as well, we need to keep eater as the end boundary --- this becomes important at the global boundary
                                    // if we don't do this, we fall off the map with a possibly falsely low global end boundary
                                    if (eater > last_pair->second) {
                                        mit->second = eater;
                                    }

                                    to_erase = m.find(last_pair->first);
                                    last_pair++;
                                    m.erase(to_erase->first);
                                } else {
                                    break; // if mit->second < last_pair->first, no further merge is possible
                                }
                            }
                        }
                        // else block for the case in which cur[1] <= mit->second --- we simply erase the mit entry
                        else {
                            if (cur[0] < mit->first) {
                                m.erase(mit->first);
                            }
                        }
                    }
                    // else block for the case in which cur[1] < mit->first --- simply make a new entry
                    else {
                        m[cur[0]] = cur[1];
                    }
                }

            }

            // at this point, it is possible to end up w/ [  [2,3], [3,4]  ] if the [3,4] is processed last
            // I should be able to remedy this quickly knowing that my map is now in order
            // just check for each entry if the second overlaps with the next entry's first
            // if so, merge them into the first entry and erase the second

            for (mit = m.begin(); mit != m.end(); mit++) {
                last_pair = m.find(mit->first);
                last_pair++;
                while (last_pair != m.end()) {
                    if (mit->second >= last_pair->first) {
                        if (last_pair->second >= mit->second) {
                            mit->second = last_pair->second;
                        }
                        to_erase = m.find(last_pair->first);
                        last_pair++;
                        m.erase(to_erase);
                    } else {
                        break;
                    }
                }
            }



            // now let's clean up our map into a vector
            for (mit = m.begin(); mit != m.end(); mit++) {
                cur.resize(0);
                cur.push_back(mit->first);
                cur.push_back(mit->second);
                ret.push_back(cur);
            }

            return ret;
        }

};