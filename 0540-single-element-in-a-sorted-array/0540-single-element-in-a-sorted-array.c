int singleNonDuplicate(int* nums,int numsSize){
    int l=0,r=numsSize-1;

    while(l<r){
        int m=(l+r)/2;
        if(m%2==1)
            m--;
        if(nums[m]==nums[m+1])
            l=m+2;
        else
            r=m;
    }
    return nums[l];
}