class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, int> mp;
        for (auto &v1: nums1) {
            mp[v1]++;
        }

        vector<int> ret;
        for (auto &v2: nums2) {
            if (mp.find(v2) != mp.end()) {
                ret.push_back(v2);
                mp[v2]--;  
                if (mp[v2] == 0) {
                    mp.erase(v2);
                }
            }
        }
        return ret;
    }
};