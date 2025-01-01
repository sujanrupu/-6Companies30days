// Link: https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/submissions/1494171133/

class Solution {
    vector<vector<int>> rects;
    vector<int> prefixAreas;
    int totalArea;

public:
    Solution(vector<vector<int>>& rects) : rects(rects), totalArea(0) {
        for (const auto& rect : rects) {
            int width = rect[2] - rect[0] + 1;
            int height = rect[3] - rect[1] + 1;
            totalArea += width * height;
            prefixAreas.push_back(totalArea);
        }
    }
    
    vector<int> pick() {
        int randomArea = rand() % totalArea;
        int rectIndex = lower_bound(prefixAreas.begin(), prefixAreas.end(), randomArea + 1) - prefixAreas.begin();
        
        const auto& rect = rects[rectIndex];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        
        return {x, y};
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
