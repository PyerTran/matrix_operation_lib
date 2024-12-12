#include <stdlib.h>
#include "matrix_operation.h"

Matrix_double *transpose(const Matrix_double a) {
    Matrix_double *res = malloc(sizeof(Matrix_double));
    res->n = a.m;
    res->m = a.n;
    res->content = fill_content(res->n, res->m);

    for (int i = 0; i < res->n; ++i) {
        for (int j = 0; j < res->m; ++j) {
            res->content[i][j] = a.content[j][i];
        }
    }

    return res;
}