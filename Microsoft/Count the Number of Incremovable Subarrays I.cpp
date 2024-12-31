// Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/submissions/1493430331/

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n) {
                vector<int> v;
                for (int k = 0; k < i; k++) {
                    v.push_back(nums[k]);
                }
                for (int k = j + 1; k < n; k++) {
                    v.push_back(nums[k]);
                }
                if (v.size() == 0)
                    ans++;
                else {
                    int count = 0;
                    for (int i = 0; i < v.size() - 1; i++) {
                        if (v[i] >= v[i + 1])
                            count++;
                    }
                    if (count == 0)
                        ans++;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};
