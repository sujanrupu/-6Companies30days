// Link: https://leetcode.com/problems/russian-doll-envelopes/submissions/1493151615/

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& ev) {
        sort(ev.begin(), ev.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> dp;
        for (auto& envelope : ev) {
            int height = envelope[1];
            auto it = lower_bound(dp.begin(), dp.end(), height);
            if (it == dp.end()) dp.push_back(height);
            else *it = height;
        }
        return dp.size();
    }
};
