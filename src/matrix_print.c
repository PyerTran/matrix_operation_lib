#include <stdio.h>
#include "matrix_operation.h"

void print_matrix_content(const Matrix_double a) {
    for (int i = 0; i < a.n; ++i) {
        for (int j = 0; j < a.m; ++j) {
            //a.content[i][j];
            printf("%f\t", a.content[i][j]);
        }
        printf("\n");
    }
}