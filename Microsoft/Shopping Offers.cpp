// Link: https://leetcode.com/problems/shopping-offers/submissions/1493808492/

class Solution {
public:
    map<vector<int>, int>mp;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = 0;
        for(int i = 0; i < price.size(); i++)   ans += (price[i] * needs[i]);

        if(mp.count(needs) != 0)
            return mp[needs];
        
        for(int i = 0; i < special.size(); i++) {
            bool isValidOffer = true;
            for(int j = 0; j < needs.size(); j++) {
                if(needs[j] < special[i][j])    {
                    isValidOffer = false;
                    break;
                }
            }
            if(isValidOffer) {
                for(int j = 0; j < needs.size(); j++)   needs[j] -= special[i][j];
                int ans1 = special[i].back() + shoppingOffers(price, special, needs);
                ans = min(ans, ans1);
                for(int j = 0; j < needs.size(); j++)   needs[j] += special[i][j];
            }
        }
        return mp[needs] = ans;
    }
};
