#include "matrix_operation.h"

//using Laplace expansion

// Exclude first row and current column. 
static void laplace_exclude(Matrix_double *temp, const Matrix_double a, int index) {
    for (int i = 1; i < a.n; ++i) {
        for (int j = 0; j < a.m; ++j) {
            if (j < index)
                temp->content[i - 1][j] = a.content[i][j];
            if (j > index)
                temp->content[i - 1][j - 1] = a.content[i][j];
        }
    }
}

double recursive_laplace_expansion(const Matrix_double a) {
    if (a.n == 1 && a.m == 1) {
        return a.content[0][0];
    }

    Matrix_double temp = {
        .n = a.n-1,
        .m = a.m-1,
        .content = fill_content(temp.n, temp.m)
    };

    double total = 0;
    double sign = 1;

    for (int column = 0; column < a.m; ++column) {
        laplace_exclude(&temp, a, column);
        if (column % 2) {
            sign = -1;
        } else {
            sign = 1;
        }
        total += sign * a.content[0][column] * recursive_laplace_expansion(temp);
    }

    return total;
}