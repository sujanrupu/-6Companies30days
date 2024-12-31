// Link: https://leetcode.com/problems/bulls-and-cows/submissions/1493174678/

class Solution {
public:
    string getHint(string secret, string guess) {
        int c1 = 0, c2 = 0;
        string a = secret, b = guess;
        int i = 0, j = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while(i < a.length() && j < b.length()) {
            if(a[i] == b[j]) {
                i++;    j++;    c2++;
            }
            else if((int)a[i] > (int)b[j])  j++;
            else    i++;
        }
        a = secret, b = guess;
        for(int i = 0; i < min(a.length(), b.length()); i++) {
            if(a[i] == b[i])    c1++;
        }
        c2 = c2 - c1;
        string ans = "";
        ans += to_string(c1);
        ans.push_back('A');
        ans += to_string(c2);
        ans.push_back('B');
        return ans;
    }
};
