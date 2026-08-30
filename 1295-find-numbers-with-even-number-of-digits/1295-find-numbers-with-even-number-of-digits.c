int findNumbers(int* nums, int numsSize) {
    int cnt=0;
    for(int i=0;i<numsSize;i++){
        int x=nums[i], d=0;
        while(x>0){
            d++;
            x/=10;
        }
        if(d%2==0) cnt++;
    }
    return cnt;
}

