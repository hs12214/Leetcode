int cmp(const void *a,const void *b){
    return (*(int *)a)-(*(int *)b);
}

int longestSquareStreak(int* nums,int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);

    int maxVal=100000;
    int *dp=calloc(maxVal+1,sizeof(int));

    int ans=1;

    for(int i=0;i<numsSize;i++){
        int x=nums[i];
        int root=sqrt(x);

        if(root*root==x && dp[root]){
            dp[x]=dp[root]+1;
        }else{
            dp[x]=1;
        }

        if(dp[x]>ans) ans=dp[x];
    }

    free(dp);

    return ans<2?-1:ans;
}