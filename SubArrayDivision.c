#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 5

int birthday(int s_count, int* s, int d, int m);
void initTestArray(int* s);
void initMask(int* mask, int n, int m);

void main()
{
    int* s;
    s = (int*)malloc(sizeof(int) * LENGTH);
    int m, d, result;
    m = 2;
    d = 3;
    initTestArray(s);

    result = birthday(LENGTH, s, d, m);

    printf("Expected Result: 2\nActual Result: [%d]\n", result);

}

int birthday(int s_count, int* s, int d, int m) {

    int* mask, * cc;
    int i, k, j, tmp, res;
    mask = (int*)malloc(sizeof(int) * s_count);
    cc = (int*)malloc(sizeof(int) * (2 * s_count - 1));
    res = 0;
    initMask(mask, s_count, m); // an m-length sequence of ons padded to the length n;

    for (i = 0; i < (2 * s_count - 1); i++)
    {
        tmp = 0;
        for (j = 0; j < s_count; j++)
        {
            tmp += *(s + (j + i)) * (*(mask + j));
        }
        if (tmp == d)
        {
            res++;
        }
    }

    *(cc + i) = tmp; // cc is a vector to show the use of correlation with masks as a mean of calculating sums in variable lengths

    return res;
}
void initTestArray(int* s)
{
    *s = 1;
    *(s + 1) = 2;
    *(s + 2) = 1;
    *(s + 3) = 3;
    *(s + 4) = 2;
}
void initMask(int* mask, int n, int m)
{
    int k;
    for (k = 0; k < n; k++)
    {
        if (k < m)
        {
            *(mask + k) = 1;
        }
        else
        {
            *(mask + k) = 0;
        }
    }
}