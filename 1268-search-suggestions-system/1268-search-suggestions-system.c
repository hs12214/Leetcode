/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    return strcmp(*(char **)a,*(char **)b);
}

char*** suggestedProducts(char** products,int productsSize,
                          char* searchWord,
                          int* returnSize,
                          int** returnColumnSizes){

    qsort(products,productsSize,sizeof(char *),cmp);

    int n=strlen(searchWord);

    char ***ans=malloc(n*sizeof(char **));
    *returnColumnSizes=malloc(n*sizeof(int));

    for(int i=0;i<n;i++){

        ans[i]=malloc(3*sizeof(char *));
        (*returnColumnSizes)[i]=0;

        for(int j=0;j<productsSize;j++){

            if(strncmp(products[j],searchWord,i+1)==0){

                ans[i][(*returnColumnSizes)[i]]=products[j];
                (*returnColumnSizes)[i]+=1;

                if((*returnColumnSizes)[i]==3)
                    break;
            }
        }
    }
    *returnSize=n;
    return ans;
}
