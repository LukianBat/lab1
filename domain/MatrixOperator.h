
#ifndef LAB1_MATRIXOPERATOR_H
#define LAB1_MATRIXOPERATOR_H


#include "Matrix.h"

class MatrixOperator {
private:
    Matrix *firstMatrix;
    Matrix *secondMatrix;
public:

    MatrixOperator();

    void setMatrix(int index, int **values);

    void transposeMatrix();

    int **getMatrix();

    void sumMatrix(int **otherValues);

    ~MatrixOperator();
};


#endif
