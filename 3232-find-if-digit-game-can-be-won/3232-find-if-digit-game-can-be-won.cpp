class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0, totalSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];

            if (nums[i] < 10)
                singleSum += nums[i];
        }

        return 2 * singleSum != totalSum;
    }
};