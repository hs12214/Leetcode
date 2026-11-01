int cmp(const void *a,const void *b){
    return (*(int *)a)-(*(int *)b);
}

int countElements(int* nums,int numsSize,int k){
    if(k==0) return numsSize;

    qsort(nums,numsSize,sizeof(int),cmp);
    int ans=0;
    for(int i=0;i<numsSize;i++){
        int l=i+1,r=numsSize;
        while(l<r){
            int mid=l+(r-l)/2;

            if(nums[mid]<=nums[i])
                l=mid+1;
            else
                r=mid;
        }
        if(numsSize-l>=k)
            ans++;
    }
    return ans;
}