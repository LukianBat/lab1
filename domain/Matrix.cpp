#include <iostream>
#include "Matrix.h"


void Matrix::transpose() {
    double t;
    for (int i = 0; i < matrixIndex; ++i) {
        for (int j = i; j < matrixIndex; ++j) {
            t = matrixValues[i][j];
            matrixValues[i][j] = matrixValues[j][i];
            matrixValues[j][i] = t;
        }
    }
}

double **Matrix::getValues() {
    return matrixValues;
}

void Matrix::sumWith(Matrix *otherMatrix) {
    double **otherValues = otherMatrix->matrixValues;
    for (int i = 0; i < matrixIndex; i++)
        for (int j = 0; j < matrixIndex; j++)
            matrixValues[i][j] = matrixValues[i][j] + otherValues[i][j];
}

void Matrix::setIndex(int index) {
    matrixIndex = index;
}

void Matrix::setValues(double **values) {
    matrixValues = values;
}

Matrix::~Matrix() {
    delete matrixValues;
    matrixIndex = NULL;
}

void Matrix::multiplyWith(Matrix *otherMatrix) {
    double **otherValues = otherMatrix->matrixValues;
    double **copyValues = new double *[matrixIndex];
    for (int i = 0; i < matrixIndex; i++) {
        copyValues[i] = new double[matrixIndex];
    }
    for (int i = 0; i < matrixIndex; i++) {
        for (int j = 0; j < matrixIndex; j++)
            copyValues[i][j] = matrixValues[i][j];
    }
    for (int i = 0; i < matrixIndex; i++) {
        for (int j = 0; j < matrixIndex; j++) {
            matrixValues[i][j] = 0;
            for (int k = 0; k < matrixIndex; k++)
                matrixValues[i][j] += copyValues[i][k] * otherValues[k][j];
        }
    }
}

void Matrix::invert() {
    double **matrix = matrixValues;
    int index = matrixIndex;
    double **invertValues = new double *[index];
    // инициализация
    for (int i = 0; i < index; i++)
        invertValues[i] = new double[index];
    for (int i = 0; i < index; i++)
        for (int j = 0; j < index; j++)
            invertValues[i][j] = (i == j ? 1 : 0);
    // converting matrix to invertValues
    for (int i = 0; i < index; i++) {
        // normalizing row (making first value =1)
        double value = matrix[i][i];
        for (int j = index - 1; j >= 0; j--) {
            invertValues[i][j] /= value;
            matrix[i][j] /= value;
        }
        // excluding i-th value from each row except i-th one
        for (int j = 0; j < index; j++)
            if (j != i) {
                value = matrix[j][i];
                for (int k = index - 1; k >= 0; k--) {
                    invertValues[j][k] -= invertValues[i][k] * value;
                    matrix[j][k] -= matrix[i][k] * value;
                }
            }
    }
    // now invertValues contains inverted matrix so we need only to copy invertValues to matrix
    for (int i = 0; i < index; i++)
        for (int j = 0; j < index; j++)
            matrix[i][j] = invertValues[i][j];
}
