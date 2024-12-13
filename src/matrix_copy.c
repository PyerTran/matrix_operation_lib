#include "matrix_operation.h"

Matrix_double matrix_copy(const Matrix_double a) {
    Matrix_double copy = init(a.n, a.m);

    for (int i = 0; i < a.n; ++i) {
        for (int j = 0; j < a.m; ++j) {
            copy.content[i][j] = a.content[i][j];
        }
    }
    return copy;
}