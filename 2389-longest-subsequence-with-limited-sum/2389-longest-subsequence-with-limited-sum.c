/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    return (*(int *)a)-(*(int *)b);
}

int upperBound(long long *pre,int n,int target){
    int l=0,r=n;

    while(l<r){
        int mid=l+(r-l)/2;

        if(pre[mid]<=target)
            l=mid+1;
        else
            r=mid;
    }

    return l;
}

int* answerQueries(int* nums,int numsSize,int* queries,int queriesSize,int* returnSize){
    qsort(nums,numsSize,sizeof(int),cmp);

    long long *pre=malloc(sizeof(long long)*numsSize);

    pre[0]=nums[0];

    for(int i=1;i<numsSize;i++)
        pre[i]=pre[i-1]+nums[i];

    int *ans=malloc(sizeof(int)*queriesSize);

    for(int i=0;i<queriesSize;i++)
        ans[i]=upperBound(pre,numsSize,queries[i]);

    free(pre);

    *returnSize=queriesSize;
    return ans;
}