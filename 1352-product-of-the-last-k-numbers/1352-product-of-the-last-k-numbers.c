typedef struct {
    int pre[40001];
    int size;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = malloc(sizeof(ProductOfNumbers));
    obj->pre[0] = 1;
    obj->size = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num == 0) {
        obj->size = 1;
        obj->pre[0] = 1;
    } else {
        obj->pre[obj->size] = obj->pre[obj->size - 1] * num;
        obj->size++;
    }
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (k >= obj->size)
        return 0;

    return obj->pre[obj->size - 1] /
           obj->pre[obj->size - k - 1];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}
/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/