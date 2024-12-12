#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrix_operation.h"



// https://fr.wikipedia.org/wiki/Élimination_de_Gauss-Jordan
//
void matrix_gauss_pivot(Matrix_double *a) {
    int r = 0;
    double max = 0;
    int k = 0;

    for (int j = 1; j < a->m; ++j) {
        for (int i = r+1; i < a->n; ++i) {
            if (max < fabs(a->content[i][j])) {
                max = a->content[i][j];
                k = i;
            }
        }
        if (a->content[k][j] != 0) {
            r+=1;

            if (k != r) {
                double *temp = a->content[k];
                a->content[k] = a->content[r];
                a->content[r] = temp;
            }

            // divide the row k by a.content[k][j]
            for (int column = 0; column < a->m; ++column) {
                a->content[k][column] /= a->content[k][j];
            }

            for (int i = 1; i < a->n; ++i) {
                if (i != r) {
                    for (int column = 0; column < a->m; ++column) {
                        a->content[i][column] -= a->content[r][column] * a->content[i][j];
                    }
                }
            }
        }
    }

}