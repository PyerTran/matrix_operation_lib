#include <stddef.h>
#include <stdlib.h>
#include "matrix_operation.h"

// matrix addition, substraction, scalar multiplication and multiplication

Matrix_double *addition(const Matrix_double a, const Matrix_double b) {
    if (a.n != b.n || a.m != b.m) {
        return NULL;
    }

    Matrix_double *res = malloc(sizeof(Matrix_double));
    res->n = a.n;
    res->m = a.m;
    res->content = fill_content(res->n, res->m);

    for (int i = 0; i < a.n; ++i) {
        for (int j = 0; j < a.m; ++j) {
            res->content[i][j] = a.content[i][j] + b.content[i][j];
        }
    }

    return res;
}

Matrix_double *substraction(const Matrix_double a, const Matrix_double b) {
    if (a.n != b.n || a.m != b.m) {
        return NULL;
    }

    Matrix_double *res = malloc(sizeof(Matrix_double));
    res->n = a.n;
    res->m = a.m;
    res->content = fill_content(res->n, res->m);

    for (int i = 0; i < a.n; ++i) {
        for (int j = 0; j < a.m; ++j) {
            res->content[i][j] = a.content[i][j] - b.content[i][j];
        }
    }

    return res;
}

void scalar_multiplation(double scalar, Matrix_double *a) {
    for (int i = 0; i < a->n; ++i) {
        for (int j = 0; j < a->m; ++j) {
            a->content[i][j] *= scalar;
        }
    }
}

Matrix_double *multiplication(const Matrix_double a, const Matrix_double b) {
    if (a.m != b.n) {
        return NULL;
    }

    Matrix_double *res = malloc(sizeof(Matrix_double));
    res->n = a.n;
    res->m = b.m;
    res->content = fill_content(res->n, res->m);

    for (int i = 0; i < res->n; ++i) {
        for (int j = 0; j < res->m; ++j) {
            res->content[i][j] += a.content[i][j] * b.content[j][i];
        }
    }

    return res;
}