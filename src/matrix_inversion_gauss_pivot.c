#include <math.h>
#include <stdio.h>
#include "matrix_operation.h"

Matrix_double matrix_inversion_gauss_pivot(const Matrix_double a) {
    Matrix_double a_copy = matrix_copy(a);
    Matrix_double a_prime = {
        .n = a.n,
        .m = a.m,
        .content = identity_matrix(a.n, a.m)
    };

    int r = -1;
    double max = 0;
    int k = 0;
    double cancel_value = 0;

    for (int j = 0; j < a_copy.m; ++j) {
        max = 0;
        for (int i = r+1; i < a_copy.n; ++i) {
            if (max < fabs(a_copy.content[i][j])) {
                max = a_copy.content[i][j];
                k = i;
            }
        }
        if (a_copy.content[k][j] != 0) {
            r+=1;
            // divide the row k by a.content[k][j]
            for (int column = 0; column < a_copy.m; ++column) {
                a_copy.content[k][column] /= max;
                a_prime.content[k][column] /= max;
            }
            
            if (k != r) {
                double *temp = a_copy.content[k];
                a_copy.content[k] = a_copy.content[r];
                a_copy.content[r] = temp;

                temp = a_prime.content[k];
                a_prime.content[k] = a_prime.content[r];
                a_prime.content[r] = temp;
            }

            for (int i = 0; i < a_copy.n; ++i) {
                if (i != r) {
                    cancel_value = a_copy.content[i][j];
                    printf("cancelling at %i\n", i);
                    for (int column = 0; column < a_copy.m; ++column) {
                        a_copy.content[i][column] -= a_copy.content[r][column] * cancel_value;
                        printf("a_prime[%i, %i] = %f - cancel_val = %f * a_prime[%i, %i] = %f\t",
                        i, column, a_prime.content[i][column], cancel_value, r, column, a_prime.content[r][column]);
                        a_prime.content[i][column] -= a_prime.content[r][column] * cancel_value;
                        printf("%f\n",  a_prime.content[i][column]);
                    }
                }
            }
        }
        printf("matrix state at %i\n", j);
        print_matrix_content(a_prime);
    }
    return a_prime;
}
