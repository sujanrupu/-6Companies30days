// Link: https://leetcode.com/problems/image-smoother/submissions/1493498209/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>>ans;
        for(int i = 0; i < n; i++) {
            vector<int>v;
            for(int j = 0; j < m; j++) {
                vector<int>arr;
                arr.push_back(img[i][j]);
                if(i-1 >= 0 && i-1 < n) arr.push_back(img[i-1][j]);
                if(i+1 >= 0 && i+1 < n) arr.push_back(img[i+1][j]);
                if(j-1 >= 0 && j-1 < m) arr.push_back(img[i][j-1]);
                if(j+1 >= 0 && j+1 < m) arr.push_back(img[i][j+1]);
                if((i-1 >= 0 && i-1 < n) && (j-1 >= 0 && j-1 < m)) arr.push_back(img[i-1][j-1]);
                if((i-1 >= 0 && i-1 < n) && (j+1 >= 0 && j+1 < m)) arr.push_back(img[i-1][j+1]);
                if((i+1 >= 0 && i+1 < n) && (j-1 >= 0 && j-1 < m)) arr.push_back(img[i+1][j-1]);
                if((i+1 >= 0 && i+1 < n) && (j+1 >= 0 && j+1 < m)) arr.push_back(img[i+1][j+1]);
                int sum = 0;
                for(int k = 0; k < arr.size(); k++) {
                    sum += arr[k];
                }
                cout << endl;
                v.push_back(sum/arr.size());
            }
            ans.push_back(v);
        }
        return ans;
    }
};
