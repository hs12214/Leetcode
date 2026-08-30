int sumOfEncryptedInt(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i], max = 0, len = 0;
        while (x > 0) {
            int d = x % 10;
            if (d > max) max = d;
            x /= 10;
            len++;
        }
        int enc = 0;
        for (int j = 0; j < len; j++) enc = enc * 10 + max;
        sum+= enc;
    }
    return sum;
}

