int getFreq(char *s){
    char small='z';
    int count=0;

    for(int i=0;s[i];i++){
        if(s[i]<small){
            small=s[i];
            count=1;
        }
        else if(s[i]==small){
            count++;
        }
    }
    return count;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numSmallerByFrequency(char** queries,int queriesSize,
                           char** words,int wordsSize,
                           int* returnSize) {

    int wordFreq[2000];

    for(int i=0;i<wordsSize;i++)
        wordFreq[i]=getFreq(words[i]);

    int *ans=malloc(queriesSize*sizeof(int));

    for(int i=0;i<queriesSize;i++){
        int q=getFreq(queries[i]);
        int count=0;

        for(int j=0;j<wordsSize;j++){
            if(wordFreq[j]>q)
                count++;
        }

        ans[i]=count;
    }
    *returnSize=queriesSize;
    return ans;
}