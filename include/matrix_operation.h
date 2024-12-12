#ifndef MATRIX_OPERATIONS_H_
#define MATRIX_OPERATIONS_H_

double **fill_content(int n, int m);


typedef struct struct_matrix_double {
    int n;
    int m;
    double **content;
} Matrix_double;

Matrix_double init (int n, int m);

Matrix_double *addition(const Matrix_double a, const Matrix_double b);

Matrix_double *substraction(const Matrix_double a, const Matrix_double b);

void scalar_multiplation(double scalar, Matrix_double *a);

Matrix_double *transpose(const Matrix_double a);

Matrix_double *multiplication(const Matrix_double a, const Matrix_double b);

double recursive_laplace_expansion(const Matrix_double a);

Matrix_double *inversion(const Matrix_double a);


#endif