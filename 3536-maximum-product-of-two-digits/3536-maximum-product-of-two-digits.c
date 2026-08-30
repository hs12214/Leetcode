int maxProduct(int n) {
    int digits[10], size = 0;
    while (n > 0) {
        digits[size++] = n % 10;
        n /= 10;
    }
    int prod = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int k = digits[i] * digits[j];
            if (k > prod) prod = k;
        }
    }
    return prod;
}
