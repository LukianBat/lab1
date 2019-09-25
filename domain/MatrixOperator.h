
#ifndef LAB1_MATRIXOPERATOR_H
#define LAB1_MATRIXOPERATOR_H


#include "Matrix.h"

class MatrixOperator {
private:
    Matrix *baseMatrix;
    Matrix *operationMatrix;
public:

    MatrixOperator();

    void baseMatrixInit(Matrix *matrix);

    void setMatrixParameters(int index, double **values);

    void transposeMatrix();

    double **getMatrixValues();

    void sumMatrix(double **values);

    void multiplyMatrix(double **values);

    void invertMatrix() noexcept(false);

    double getMatrixDeterminant();

    ~MatrixOperator();
};


#endif
