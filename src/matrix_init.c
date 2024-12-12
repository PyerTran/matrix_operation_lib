#include <stdlib.h>
#include "matrix_operation.h"

double **fill_content(int n, int m) {
    double **content = malloc(n * sizeof(double*));

    for (int i = 0; i < n; ++i) {
        content[i] = calloc(m, sizeof(double));
    }

    return content;
}

Matrix_double init (int n, int m) {
    Matrix_double res = {
        .n = n,
        .m = m,
        .content= fill_content(n, m)
    };

    return res;
}