char* firstPalindrome(char** words, int wordsSize) {
    for(int i=0;i<wordsSize;i++){
        int j=0,r=strlen(words[i])-1;
        while(j<r && words[i][j]==words[i][r]){
            j++; r--;
        }
        if(j>=r) return words[i];
    }
    return "";
}

