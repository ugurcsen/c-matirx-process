#include <stdio.h>

#define maxH 5
#define maxW 5

int borderFixer(int val, int max) {
    if (val < 0) {
        return max - 1;
    } else if (val > max) {
        return 0;
    } else {
        return val;
    }

}

void matrixYaz(int h, int w, int matrix[h][w]) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            printf("%-+5d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int imageMatrix[maxH][maxW] = {
            {105, 102, 100, 97,  96},
            {103, 99,  103, 101, 102},
            {101, 98,  104, 102, 100},
            {99,  101, 106, 104, 99},
            {104, 104, 104, 100, 98}
    };
    int kernelMatrix[3][3] = {
            {0,  -1, 0},
            {-1, 5,  -1},
            {0,  -1, 0}
    };
    int resultMatrix[5][5];
    int h = 0;
    int w = 0;
    //First part
    /*
    while (h < 5-2){
        while (w < 5-2) {
            resultMatrix[h][w] =
                    imageMatrix[h][w] * kernelMatrix[0][0] +
                    imageMatrix[h][w + 1] * kernelMatrix[0][1] +
                    imageMatrix[h][w + 2] * kernelMatrix[0][2] +

                    imageMatrix[h + 1][w] * kernelMatrix[1][0] +
                    imageMatrix[h + 1][w + 1] * kernelMatrix[1][1] +
                    imageMatrix[h + 1][w + 2] * kernelMatrix[1][2] +

                    imageMatrix[h + 2][w] * kernelMatrix[2][0] +
                    imageMatrix[h + 2][w + 1] * kernelMatrix[2][1] +
                    imageMatrix[h + 2][w + 2] * kernelMatrix[2][2];
            printf("%-5d",resultMatrix[h][w]);
            w++;
        }
        printf("\n");
        w = 0;
        h++;
    }
    //printf("%d",resultMatrix[0][0]);
*/
    //Scond part
    while (h < maxH) {
        while (w < maxW) {
            resultMatrix[h][w] =
                    imageMatrix[borderFixer(h - 1, maxH)][borderFixer(w - 1, maxW)] * kernelMatrix[0][0] +
                    imageMatrix[borderFixer(h - 1, maxH)][w] * kernelMatrix[0][1] +
                    imageMatrix[borderFixer(h - 1, maxH)][borderFixer(w + 1, maxW)] * kernelMatrix[0][2] +

                    imageMatrix[h][borderFixer(w - 1, maxW)] * kernelMatrix[1][0] +
                    imageMatrix[h][w] * kernelMatrix[1][1] +
                    imageMatrix[h][borderFixer(w + 1, maxW)] * kernelMatrix[1][2] +

                    imageMatrix[borderFixer(h + 1, maxH)][borderFixer(w - 1, maxW)] * kernelMatrix[2][0] +
                    imageMatrix[borderFixer(h + 1, maxH)][w] * kernelMatrix[2][1] +
                    imageMatrix[borderFixer(h + 1, maxH)][borderFixer(w + 1, maxW)] * kernelMatrix[2][2];
            w++;
        }
        printf("\n");
        w = 0;
        h++;
    }
    int okunanA, okunanB;
    printf("Enter the matrix adresses (Format: Number Number):");
    scanf(" %d %d", &okunanA, &okunanB);
    h = okunanA;
    w = okunanB;
    printf("Result: %d\n", resultMatrix[okunanA][okunanB]);
    printf("\n-----------------------------------------------\n");
    printf("Matrix which the result is generated:\n");
    printf("%-5d", imageMatrix[borderFixer(h - 1, maxH)][borderFixer(w - 1, maxW)]);
    printf("%-5d", imageMatrix[borderFixer(h - 1, maxH)][w]);
    printf("%-5d", imageMatrix[borderFixer(h - 1, maxH)][borderFixer(w + 1, maxW)]);
    printf("\n");
    printf("%-5d", imageMatrix[h][borderFixer(w - 1, maxW)]);
    printf("%-5d", imageMatrix[h][w]);
    printf("%-5d", imageMatrix[h][borderFixer(w + 1, maxW)]);
    printf("\n");
    printf("%-5d", imageMatrix[borderFixer(h + 1, maxH)][borderFixer(w - 1, maxW)]);
    printf("%-5d", imageMatrix[borderFixer(h + 1, maxH)][w]);
    printf("%-5d", imageMatrix[borderFixer(h + 1, maxH)][borderFixer(w + 1, maxW)]);
    printf("\n-----------------------------------------------\n");
    printf("\nImage Matrix: \n");
    matrixYaz(5, 5, imageMatrix);

    printf("-----------------------------------------------\n");
    printf("\nKernel Matrix: \n");
    matrixYaz(3, 3, kernelMatrix);
    printf("-----------------------------------------------\n");
    printf("\nResult Matrix: \n");
    matrixYaz(5, 5, resultMatrix);
    scanf("%s");
    return 0;
}
