/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes,int aliceSize,
                   int* bobSizes,int bobSize,
                   int* returnSize) {

    int sumA=0,sumB=0;

    for(int i=0;i<aliceSize;i++)
        sumA+=aliceSizes[i];

    for(int i=0;i<bobSize;i++)
        sumB+=bobSizes[i];

    int diff=(sumA-sumB)/2;

    int *ans=malloc(2*sizeof(int));

    for(int i=0;i<aliceSize;i++){
        for(int j=0;j<bobSize;j++){

            if(aliceSizes[i]-bobSizes[j]==diff){
                ans[0]=aliceSizes[i];
                ans[1]=bobSizes[j];
                *returnSize=2;
                return ans;
            }
        }
    }
    return ans;
}