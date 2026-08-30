bool isFascinating(int n) {
    char s[20];
    sprintf(s, "%d%d%d", n, 2*n, 3*n);
    int seen[10] = {0};
    for (int i = 0; s[i]; i++) {
        int d = s[i]-'0';
        if (d==0 || seen[d]) return false;
        seen[d] = 1;
    }
    for (int d=1; d<=9; d++) if (!seen[d]) return false;
    return true;
}


