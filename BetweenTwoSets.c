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

void main()
{
    int s[LENGTH] = { 1, 2, 1, 3, 2 };
    int m, d, result;
    m = 3;
    d = 2;

    result = birthday(LENGTH, s[], d, m);

    printf("Expected Result: 2\nActual Result: [%d]\n", result);

}

int birthday(int s_count, int* s, int d, int m) {

    int* mask, * cc;
    int i, k, j, tmp, res;
    mask = (int*)malloc(sizeof(int) * s_count);
    cc = (int*)malloc(sizeof(int) * (2 * s_count - 1));
    res = 0;

    for (k = 0; k < s_count; k++)
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