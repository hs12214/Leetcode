/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *ans = (int *)malloc(numsSize * sizeof(int));

    int i = 0;
    int j = numsSize - 1;
    int k = numsSize - 1;
    while (i <= j) {
        int left = nums[i] * nums[i];
        int right = nums[j] * nums[j];

        if (left > right) {
            ans[k] = left;
            i++;
        } else {
            ans[k] = right;
            j--;
        }
        k--;
    }
    *returnSize = numsSize;
    return ans;
}