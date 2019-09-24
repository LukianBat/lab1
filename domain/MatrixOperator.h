
#ifndef LAB1_MATRIXOPERATOR_H
#define LAB1_MATRIXOPERATOR_H


#include "Matrix.h"

class MatrixOperator {
private:
    Matrix *firstMatrix;
    Matrix *secondMatrix;
public:

    MatrixOperator();

    void setMatrix(int index, double **values);

    void transposeMatrix();

    double **getMatrix();

    void sumMatrix(double **otherValues);

    void multiplyMatrix(double **otherValues);

    void invertMatrix();

    ~MatrixOperator();
};


#endif
