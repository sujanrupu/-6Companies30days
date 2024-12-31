// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/submissions/1493135309/

class Solution {
public:
    int makeDist(int a, int b, int c, int d) {
        int d1 = pow((a - c), 2);
        int d2 = pow((b - d), 2);
        int ans = sqrt(d1 + d2);
        return ans;
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        vector<pair<int, int>>v1;
        v1.push_back({x1, y1});
        v1.push_back({x1, y2});
        v1.push_back({x2, y2});
        v1.push_back({x2, y1});

        vector<pair<int, int>>v;
        for(int i = v1[0].second; i <= v1[1].second; i++)    v.push_back({x1, i});
        for(int i = v1[1].first; i <= v1[2].first; i++)    v.push_back({i, y2});
        for(int i = v1[2].second; i >= v1[3].second; i--)    v.push_back({x2, i});
        for(int i = v1[3].first; i >= v1[0].first; i--)    v.push_back({i, y1});

        for(int i = 0; i < v.size(); i++) {
            cout << v[i].first << " " << v[i].second << endl;
            int dist = makeDist(v[i].first, v[i].second, xCenter, yCenter);
            if(dist <= radius)  return true;
        }

        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].first <= (xCenter - radius) && v[i].second <= yCenter)  c1++;
            if(v[i].first >= (xCenter + radius) && v[i].second >= yCenter)  c2++;
            if(v[i].first >= xCenter && v[i].second >= (yCenter + radius))  c3++;
            if(v[i].first <= xCenter && v[i].second <= (yCenter - radius))  c4++;
        }
        if(c1 != 0 && c2 != 0 && c3 != 0 && c4 != 0)    return true;
        return false;

    }
};
