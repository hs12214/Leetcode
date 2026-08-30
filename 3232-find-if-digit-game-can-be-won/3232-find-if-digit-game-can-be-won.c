bool canAliceWin(int* nums, int numsSize) {
    int single=0,doub=0,total=0;
    for(int i=0;i<numsSize;i++){
        total+=nums[i];
        if(nums[i]<10) single+=nums[i];
        else if(nums[i]<100) doub+=nums[i];
    }
    return (single>total-single)||(doub>total-doub);
}

