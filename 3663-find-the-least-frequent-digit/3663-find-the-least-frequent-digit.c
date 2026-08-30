int getLeastFrequentDigit(int n) {
    int freq[10] = {0};

    while (n > 0) {
        freq[n % 10]++;
        n /= 10;
    }
    int result = -1;
    for (int d = 0; d < 10; d++) {
        if (freq[d] > 0) {
            if (result == -1 || freq[d] < freq[result] || 
               (freq[d] == freq[result] && d < result)) {
                result = d;
            }
        }
    }
    return result;
}

