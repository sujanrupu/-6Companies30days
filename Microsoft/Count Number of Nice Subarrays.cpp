// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/submissions/1493176016/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int>mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sum += (nums[i] % 2);
            if(mp.find(sum - k) != mp.end())
                ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};
