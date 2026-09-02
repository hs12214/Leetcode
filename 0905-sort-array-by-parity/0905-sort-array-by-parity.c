/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int i,j=numsSize-1;
    while(i<j){
        if(nums[i]%2==0) i++;
        else if(nums[j]%2==1) j--;
        else{
            int temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }
    *returnSize=numsSize;
    return nums;
}

