

char * mergeAlternately(char * word1, char * word2){
    int i = 0, j = 0, k = 0;
    int n1 = strlen(word1), n2 = strlen(word2);
    char* res = malloc(n1 + n2 + 1);

    while (i < n1 || j < n2) {
        if (i < n1) res[k++] = word1[i++];
        if (j < n2) res[k++] = word2[j++];
    }
    res[k] = '\0';
    return res;
}
