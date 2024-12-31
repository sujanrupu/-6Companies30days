// Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/submissions/1493149442/

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i = 1; i <= n; i++) arr.push_back(i);
        int ind = 0, count = 1;
        while(arr.size() > 1) {
            ind = (ind + k - 1) % arr.size();
            arr.erase(arr.begin() + ind);
        }
        return arr[0];
    }
};
