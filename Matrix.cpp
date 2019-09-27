#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;
const char *ERROR_INVERTING_MESSAGE = "error inverting";
const char *ERROR_SIZE_MESSAGE = "error: sizes of matrix are not equals";

Matrix::Matrix() {
    matrixIndex = 0;
    matrixValues = nullptr;
}


Matrix::Matrix(int index) {
    matrixIndex = index;
    matrixValues = new double *[matrixIndex];
    for (int i = 0; i < matrixIndex; i++) {
        matrixValues[i] = new double[matrixIndex];
        for (int j = 0; j < matrixIndex; j++) {
            matrixValues[i][j] = 1;
        }
    }
}

Matrix::Matrix(int index, double **values) {
    matrixIndex = index;
    matrixValues = new double *[matrixIndex];
    for (int i = 0; i < matrixIndex; i++) {
        matrixValues[i] = new double[matrixIndex];
        for (int j = 0; j < matrixIndex; j++) {
            matrixValues[i][j] = values[i][j];
        }
    }
}

Matrix::~Matrix() {
    delete matrixValues;
}

Matrix::Matrix(const Matrix &copyMatrix) {
    matrixIndex = copyMatrix.matrixIndex;
    matrixValues = new double *[matrixIndex];
    for (int i = 0; i < matrixIndex; i++) {
        matrixValues[i] = new double[matrixIndex];
        for (int j = 0; j < matrixIndex; j++) {
            matrixValues[i][j] = copyMatrix.matrixValues[i][j];
        }
    }
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix)
        return *this;
    matrixIndex = matrix.matrixIndex;
    delete[] matrixValues;
    matrixValues = new double *[matrixIndex];
    for (int i = 0; i < matrixIndex; i++) {
        matrixValues[i] = new double[matrixIndex];
        for (int j = 0; j < matrixIndex; j++) {
            matrixValues[i][j] = matrix.matrixValues[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix &matrix) noexcept(false) {
    if (matrix.getIndex() == this->getIndex()) {
        Matrix sumMatrix;
        sumMatrix.matrixIndex = this->matrixIndex;
        sumMatrix.matrixValues = new double *[sumMatrix.matrixIndex];
        memoryExpansion(sumMatrix);
        sumMatrix.sumWith(*this);
        sumMatrix.sumWith(matrix);
        return sumMatrix;
    } else {
        throw exception(ERROR_SIZE_MESSAGE);
    }
}

Matrix Matrix::operator-(Matrix &matrix) noexcept(false) {
    if (matrix.getIndex() == this->getIndex()) {
        Matrix diffMatrix;
        diffMatrix.matrixIndex = this->matrixIndex;
        diffMatrix.matrixValues = new double *[diffMatrix.matrixIndex];
        memoryExpansion(diffMatrix);
        diffMatrix.sumWith(*this);
        diffMatrix.diffWith(matrix);
        return Matrix();
    } else {
        throw exception(ERROR_SIZE_MESSAGE);
    }
}

Matrix Matrix::operator*(Matrix &matrix) noexcept(false) {
    if (matrix.getIndex() == this->getIndex()) {
        Matrix multMatrix;
        multMatrix.matrixIndex = this->matrixIndex;
        multMatrix.matrixValues = new double *[multMatrix.matrixIndex];
        memoryExpansion(multMatrix);
        multMatrix.sumWith(*this);
        multMatrix.multiplyWith(matrix);
        return multMatrix;
    } else {
        throw exception(ERROR_SIZE_MESSAGE);
    }
}

const double *Matrix::operator[](int index) const {
    return matrixValues[index];
}

double *Matrix::operator[](int index) {
    return matrixValues[index];
}

double Matrix::operator()() {
    return getDeterminant();
}

ostream &operator<<(ostream &os, Matrix &matrix) {
    os << matrix.matrixIndex << endl;
    int index = matrix.matrixIndex;
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index; j++) {
            os << matrix.matrixValues[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &is, Matrix &matrix) {
    is >> matrix.matrixIndex;
    matrix.matrixValues = new double *[matrix.matrixIndex];
    for (int i = 0; i < matrix.matrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.matrixIndex];
    }
    for (int i = 0; i < matrix.matrixIndex; i++)
        for (int j = 0; j < matrix.matrixIndex; j++) {
            is >> matrix.matrixValues[i][j];
        }
    return is;
}

ofstream &operator<<(ofstream &os, Matrix &matrix) {
    os << matrix.matrixIndex << endl;
    int index = matrix.matrixIndex;
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index; j++) {
            os << matrix.matrixValues[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

ifstream &operator>>(ifstream &is, Matrix &matrix) {
    is >> matrix.matrixIndex;
    matrix.matrixValues = new double *[matrix.matrixIndex];
    for (int i = 0; i < matrix.matrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.matrixIndex];
    }
    for (int i = 0; i < matrix.matrixIndex; i++)
        for (int j = 0; j < matrix.matrixIndex; j++) {
            is >> matrix.matrixValues[i][j];
        }
    return is;
}

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

void Matrix::sumWith(Matrix &otherMatrix) {
    for (int i = 0; i < matrixIndex; i++)
        for (int j = 0; j < matrixIndex; j++)
            matrixValues[i][j] = matrixValues[i][j] + otherMatrix.matrixValues[i][j];
}

void Matrix::diffWith(Matrix &otherMatrix) {
    for (int i = 0; i < matrixIndex; i++)
        for (int j = 0; j < matrixIndex; j++)
            matrixValues[i][j] = matrixValues[i][j] - otherMatrix.matrixValues[i][j];
}

void Matrix::multiplyWith(Matrix &otherMatrix) {

    double **otherValues = otherMatrix.matrixValues;
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

void Matrix::invert() noexcept(false) {
    if (getDeterminant() != 0) {
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
    } else {
        throw std::exception(ERROR_INVERTING_MESSAGE);
    }
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

int Matrix::getIndex() {
    return matrixIndex;
}

void Matrix::memoryExpansion(Matrix &matrix) {
    for (int i = 0; i < matrix.matrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.matrixIndex];
        for (int j = 0; j < matrix.matrixIndex; j++) {
            matrix.matrixValues[i][j] = 0;
        }
    }
}