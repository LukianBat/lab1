//
// Created by lukia on 19.10.2019.
//
#include <iostream>
#include <fstream>
#include "SingleMatrix.h"

SingleMatrix::SingleMatrix(int index) {
    Matrix::count++;
    matrixIndex = index;
    matrixValues = new double *[matrixIndex];
    for (int i = 0; i < matrixIndex; i++) {
        matrixValues[i] = new double[matrixIndex];
        for (int j = 0; j < matrixIndex; j++) {
            if (i == j) {
                matrixValues[i][j] = 1;
            } else {
                matrixValues[i][j] = 0;
            }
        }
    }
}

SingleMatrix::SingleMatrix(const SingleMatrix &copyMatrix) {
    Matrix::count++;
    matrixIndex = copyMatrix.matrixIndex;
    matrixValues = new double *[matrixIndex];
    for (int i = 0; i < matrixIndex; i++) {
        matrixValues[i] = new double[matrixIndex];
        for (int j = 0; j < matrixIndex; j++) {
            matrixValues[i][j] = copyMatrix.matrixValues[i][j];
        }
    }
}

SingleMatrix::SingleMatrix() {
    Matrix::count++;
    matrixIndex = 0;
    matrixValues = nullptr;
}

istream &operator>>(istream &is, SingleMatrix &matrix) {
    is >> matrix.matrixIndex;
    matrix.matrixValues = new double *[matrix.matrixIndex];
    for (int i = 0; i < matrix.matrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.matrixIndex];
        for (int j = 0; j < matrix.matrixIndex; j++) {
            if (i == j) {
                matrix.matrixValues[i][j] = 1;
            } else {
                matrix.matrixValues[i][j] = 0;
            }
        }
    }
    return is;
}

ifstream &operator>>(ifstream &is, SingleMatrix &matrix) {
    is >> matrix.matrixIndex;
    matrix.matrixValues = new double *[matrix.matrixIndex];
    for (int i = 0; i < matrix.matrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.matrixIndex];
        for (int j = 0; j < matrix.matrixIndex; j++) {
            if (i == j) {
                matrix.matrixValues[i][j] = 1;
            } else {
                matrix.matrixValues[i][j] = 0;
            }
        }
    }
    return is;
}

SingleMatrix SingleMatrix::inputFromBinaryFile(ifstream &file) {
    int index;
    file.read((char *) &index, sizeof(int));
    return SingleMatrix(index);
}

SingleMatrix::~SingleMatrix() {
    Matrix::count--;
    for (int i = 0; i < this->matrixIndex; i++) {
        delete[] matrixValues[i];
    }
    delete[] matrixValues;
}
