int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int heightChecker(int* heights,int heightsSize){
    int *arr=malloc(heightsSize*sizeof(int));   
    for(int i=0;i<heightsSize;i++)
        arr[i]=heights[i];
    qsort(arr,heightsSize,sizeof(int),cmp);
    int count=0;
    for(int i=0;i<heightsSize;i++){
        if(heights[i]!=arr[i])
            count++;
    }
    free(arr);
    return count;
}