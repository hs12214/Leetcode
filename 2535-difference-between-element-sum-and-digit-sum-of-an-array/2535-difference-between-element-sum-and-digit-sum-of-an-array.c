int differenceOfSum(int* nums, int numsSize) {
    int elem=0, digit=0;
    for(int i=0;i<numsSize;i++){
        elem+=nums[i];
        int x=nums[i];
        while(x>0){
            digit+=x%10;
            x/=10;
        }
    }
    return elem>digit?elem-digit:digit-elem;
}
