int countDominantElements(int* nums, int numsSize) {
    if (numsSize == 1)
        return 1;

    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            if (nums[i] >= nums[i + 1])
                count++;
        }
        else if (i == numsSize - 1) {
            if (nums[i] >= nums[i - 1])
                count++;
        }
        else {
            if (nums[i] * 2 >= nums[i - 1] + nums[i + 1])
                count++;
        }
    }
    return count;
}