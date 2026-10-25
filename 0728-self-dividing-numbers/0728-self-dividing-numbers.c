/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left,int right,int* returnSize){
    int *a=(int*)malloc((right-left+1)*sizeof(int));
    int k=0;

    for(int i=left;i<=right;i++){
        int j=i,f=1;

        while(j){
            int d=j%10;
            if(d==0||i%d){
                f=0;
                break;
            }
            j/=10;
        }

        if(f) a[k++]=i;
    }

    *returnSize=k;
    return a;
}