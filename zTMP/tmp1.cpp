// credit: user2085X on leetcode --- copy and pasted

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return create(nums, 0, dp);
    }
private:
    bool create(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx == nums.size() -1) return true;
        if(nums[idx] == 0) return false;
        
        if(dp[idx] != -1) return dp[idx]; //overlapping subproblems
        int reach = idx + nums[idx];
        for(int jump=idx + 1; jump <= reach; jump++) {
            if(jump < nums.size() && create(nums, jump, dp)) 
                return dp[idx] = true; //memoizing for particular index.
        }
        
        return dp[idx] = false; //memoizing for particular index.
    }
};