/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int **image, int i, int j, int old, int color,
         int rows, int cols)
{
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return;

    if(image[i][j] != old)
        return;

    image[i][j] = color;
    dfs(image, i+1, j, old, color, rows, cols);
    dfs(image, i-1, j, old, color, rows, cols);
    dfs(image, i, j+1, old, color, rows, cols);
    dfs(image, i, j-1, old, color, rows, cols);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes)
{
    int old = image[sr][sc];

    if(old != color)
        dfs(image, sr, sc, old, color,
            imageSize, imageColSize[0]);

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}