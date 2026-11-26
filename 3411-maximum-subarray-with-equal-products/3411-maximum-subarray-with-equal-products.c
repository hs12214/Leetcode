long long gcd(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int maxLength(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        long long p = 1, g = 0, l = 1;

        for (int j = i; j < numsSize; j++) {

            if (p > 1000000000000000000LL / nums[j])
                break;

            p *= nums[j];
            g = g ? gcd(g, nums[j]) : nums[j];
            l = l / gcd(l, nums[j]) * nums[j];

            if (p == g * l)
                ans = (j - i + 1 > ans) ? (j - i + 1) : ans;
        }
    }

    return ans;
}