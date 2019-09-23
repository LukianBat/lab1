#include <iostream>
#include "Matrix.h"


void Matrix::transpose() {
    int t;
    for (int i = 0; i < matrixIndex; ++i) {
        for (int j = i; j < matrixIndex; ++j) {
            t = matrixValues[i][j];
            matrixValues[i][j] = matrixValues[j][i];
            matrixValues[j][i] = t;
        }
    }
}

int **Matrix::getValues() {
    return matrixValues;
}

void Matrix::sumWith(Matrix *otherMatrix) {
    int **otherValues = otherMatrix->matrixValues;
    for (int i = 0; i < matrixIndex; i++)
        for (int j = 0; j < matrixIndex; j++)
            matrixValues[i][j] = matrixValues[i][j] + otherValues[i][j];
}

void Matrix::setIndex(int index) {
    matrixIndex = index;
}

void Matrix::setValues(int **values) {
    matrixValues = values;
}

Matrix::~Matrix() {
    delete matrixValues;
    matrixIndex = NULL;
}
