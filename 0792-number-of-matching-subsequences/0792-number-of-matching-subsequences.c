int lowerBound(int *arr,int n,int x){
    int l=0,r=n;
    while(l<r){
        int m=l+(r-l)/2;
        if(arr[m]<x)
            l=m+1;
        else
            r=m;
    }
    return l;
}
int numMatchingSubseq(char* s,char** words,int wordsSize){
    int pos[26][50001];
    int cnt[26]={0};
    for(int i=0;s[i];i++){
        int c=s[i]-'a';
        pos[c][cnt[c]++]=i;
    }
    int ans=0;
    for(int i=0;i<wordsSize;i++){
        int prev=-1;
        int ok=1;
        for(int j=0;words[i][j];j++){
            int c=words[i][j]-'a';
            int idx=lowerBound(pos[c],cnt[c],prev+1);
            if(idx==cnt[c]){
                ok=0;
                break;
            }
            prev=pos[c][idx];
        }
        if(ok)
            ans++;
    }
    return ans;
}