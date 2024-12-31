// Link: https://leetcode.com/problems/repeated-dna-sequences/submissions/1493183657/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};
        unordered_map<string, int> freq;
        vector<string> result;

        for (int i = 0; i <= s.length() - 10; i++) {
            string sequence = s.substr(i, 10);
            freq[sequence]++;
        }

        for (auto& it : freq) {
            if (it.second > 1) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};
