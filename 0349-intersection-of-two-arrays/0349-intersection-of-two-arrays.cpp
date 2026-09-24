class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int freq1[1001] = {0};
        int freq2[1001] = {0};
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            freq1[nums1[i]] = 1;
        }

        for (int i = 0; i < nums2.size(); i++) {
            freq2[nums2[i]] = 1;
        }

        for (int i = 0; i <= 1000; i++) {
            if (freq1[i] && freq2[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};