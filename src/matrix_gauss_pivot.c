#include <stdlib.h>
#include <math.h>
#include "matrix_operation.h"



// https://fr.wikipedia.org/wiki/Élimination_de_Gauss-Jordan
//
void matrix_gauss_pivot(Matrix_double *a) {
    int r = -1;
    double max = 0;
    int k = 0;
    double cancel_value = 0;

    for (int j = 0; j < a->m; ++j) {
        max = 0;
        for (int i = r+1; i < a->n; ++i) {
            if (max < fabs(a->content[i][j])) {
                max = a->content[i][j];
                k = i;
            }
        }
        if (a->content[k][j] != 0) {
            r+=1;
            // divide the row k by a.content[k][j]
            for (int column = 0; column < a->m; ++column) {
                a->content[k][column] /= max;
            }
            
            if (k != r) {
                double *temp = a->content[k];
                a->content[k] = a->content[r];
                a->content[r] = temp;
            }

            for (int i = 0; i < a->n; ++i) {
                if (i != r) {
                    cancel_value = a->content[i][j];
                    for (int column = 0; column < a->m; ++column) {
                        a->content[i][column] -= a->content[r][column] * cancel_value;
                    }
                }
            }
        }
    }

}