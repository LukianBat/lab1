#include <iostream>
#include "Matrix.h"


void Matrix::transpose() {

    double value;
    for (int i = 0; i < matrixIndex; ++i) {
        for (int j = i; j < matrixIndex; ++j) {
            value = matrixValues[i][j];
            matrixValues[i][j] = matrixValues[j][i];
            matrixValues[j][i] = value;
        }
    }

}

double **Matrix::getValues() {
    return matrixValues;
}

void Matrix::sumWith(Matrix *otherMatrix) {
    for (int i = 0; i < matrixIndex; i++)
        for (int j = 0; j < matrixIndex; j++)
            matrixValues[i][j] = matrixValues[i][j] + otherMatrix->matrixValues[i][j];
}

void Matrix::setIndex(int index) {
    matrixIndex = index;
}

void Matrix::setValues(double **values) {
    matrixValues = values;
}

Matrix::~Matrix() {
    delete matrixValues;
}

void Matrix::multiplyWith(Matrix *otherMatrix) {

    double **otherValues = otherMatrix->matrixValues;
    auto **copyValues = new double *[matrixIndex];
    for (int i = 0; i < this->matrixIndex; i++) {
        copyValues[i] = new double[matrixIndex];
    }
    for (int i = 0; i < this->matrixIndex; i++) {
        for (int j = 0; j < this->matrixIndex; j++)
            copyValues[i][j] = this->matrixValues[i][j];
    }
    for (int i = 0; i < this->matrixIndex; i++) {
        for (int j = 0; j < this->matrixIndex; j++) {
            matrixValues[i][j] = 0;
            for (int k = 0; k < this->matrixIndex; k++)
                this->matrixValues[i][j] += copyValues[i][k] * otherValues[k][j];
        }
    }
    delete[] copyValues;

}

void Matrix::invert() {
    double **matrix = matrixValues;
    int index = matrixIndex;
    auto **invertValues = new double *[index];
    for (int i = 0; i < index; i++)
        invertValues[i] = new double[index];
    for (int i = 0; i < index; i++)
        for (int j = 0; j < index; j++)
            invertValues[i][j] = (i == j ? 1 : 0);
    for (int i = 0; i < index; i++) {
        double value = matrix[i][i];
        for (int j = index - 1; j >= 0; j--) {
            invertValues[i][j] /= value;
            matrix[i][j] /= value;
        }
        for (int j = 0; j < index; j++)
            if (j != i) {
                value = matrix[j][i];
                for (int k = index - 1; k >= 0; k--) {
                    invertValues[j][k] -= invertValues[i][k] * value;
                    matrix[j][k] -= matrix[i][k] * value;
                }
            }
    }
    for (int i = 0; i < index; i++)
        for (int j = 0; j < index; j++)
            matrix[i][j] = invertValues[i][j];
    delete[] invertValues;

}

double Matrix::getDeterminant() {
    return calculateDeterminant(matrixValues, matrixIndex);
}

double Matrix::calculateDeterminant(double **values, int index) {

    int i, j;
    double determinant = 0;
    double **matrix;
    if (index == 1) {
        determinant = values[0][0];
    } else if (index == 2) {
        determinant = values[0][0] * values[1][1] - values[0][1] * values[1][0];
    } else {
        matrix = new double *[index - 1];
        for (i = 0; i < index; ++i) {
            for (j = 0; j < index - 1; ++j) {
                if (j < i)
                    matrix[j] = values[j];
                else
                    matrix[j] = values[j + 1];
            }
            determinant +=
                    pow((double) -1, (i + j)) * calculateDeterminant(matrix, index - 1) * values[i][index - 1];
        }
        delete[] matrix;
    }
    return determinant;

}

Matrix::Matrix(int index, double **values) {
    matrixIndex = index;
    matrixValues = values;
}

int Matrix::getIndex() {
    return matrixIndex;
}

Matrix::Matrix() {

}

