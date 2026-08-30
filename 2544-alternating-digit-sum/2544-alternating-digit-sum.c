int alternateDigitSum(int n) {
    char s[20];
    sprintf(s, "%d", n);
    int sum = 0;
    for (int i = 0; s[i]; i++) {
        int d = s[i]-'0';
        if (i % 2 == 0) sum += d;
        else sum -= d;
    }
    return sum;
}
