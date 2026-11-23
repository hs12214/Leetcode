typedef struct {
    int *pre;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = malloc(sizeof(NumArray));

    obj->pre = malloc((numsSize + 1) * sizeof(int));

    obj->pre[0] = 0;

    for (int i = 0; i < numsSize; i++)
        obj->pre[i + 1] = obj->pre[i] + nums[i];

    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->pre[right + 1] - obj->pre[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->pre);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/