#include <iostream>
#include <fstream>
#include <cmath>
#include "Matrix.h"

using namespace std;
exception ERROR_INVERTING_MESSAGE = (const exception &) "error inverting";
exception ERROR_SIZE_MESSAGE = (const exception &) "error: sizes of matrix are not equals";

int Matrix::count = 0;

Matrix::Matrix() {
    Matrix::count++;
    matrixIndex = 0;
    matrixValues = nullptr;
}

Matrix::Matrix(int index, double **values) {
    Matrix::count++;
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
    Matrix::count--;
    for (int i = 0; i < this->matrixIndex; i++) {
        delete[] matrixValues[i];
    }
    delete[] matrixValues;
}

Matrix::Matrix(const Matrix &copyMatrix) {
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

Matrix Matrix::operator+(Matrix &matrix) {
    return this->sumWith(matrix);
}

Matrix Matrix::operator-(Matrix &matrix) {
    return this->diffWith(matrix);
}

Matrix Matrix::operator*(Matrix &matrix) {
    return this->multiplyWith(matrix);
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

Matrix &Matrix::transpose() {
    double value;
    for (int i = 0; i < matrixIndex; ++i) {
        for (int j = i; j < matrixIndex; ++j) {
            value = matrixValues[i][j];
            matrixValues[i][j] = matrixValues[j][i];
            matrixValues[j][i] = value;
        }
    }
    return *this;
}

Matrix Matrix::sumWith(Matrix &otherMatrix) {
    if (otherMatrix.matrixIndex == matrixIndex) {
        Matrix sumMatrix;
        sumMatrix.matrixIndex = this->matrixIndex;
        sumMatrix.matrixValues = new double *[sumMatrix.matrixIndex];
        memoryExpansion(sumMatrix);
        for (int i = 0; i < matrixIndex; i++)
            for (int j = 0; j < matrixIndex; j++)
                sumMatrix.matrixValues[i][j] = matrixValues[i][j] + otherMatrix.matrixValues[i][j];
        return sumMatrix;
    } else {
        throw exception(ERROR_SIZE_MESSAGE);
    }
}

Matrix Matrix::diffWith(Matrix &otherMatrix) {
    if (otherMatrix.matrixIndex == matrixIndex) {
        Matrix sumMatrix;
        sumMatrix.matrixIndex = this->matrixIndex;
        sumMatrix.matrixValues = new double *[sumMatrix.matrixIndex];
        memoryExpansion(sumMatrix);
        for (int i = 0; i < matrixIndex; i++)
            for (int j = 0; j < matrixIndex; j++)
                sumMatrix.matrixValues[i][j] = matrixValues[i][j] - otherMatrix.matrixValues[i][j];
        return sumMatrix;
    } else {
        throw exception(ERROR_SIZE_MESSAGE);
    }
}

Matrix Matrix::multiplyWith(Matrix &otherMatrix) {
    if (otherMatrix.matrixIndex == matrixIndex) {
        Matrix multMatrix;
        multMatrix.matrixIndex = this->matrixIndex;
        multMatrix.matrixValues = new double *[multMatrix.matrixIndex];
        memoryExpansion(multMatrix);
        for (int i = 0; i < this->matrixIndex; i++) {
            for (int j = 0; j < this->matrixIndex; j++) {
                matrixValues[i][j] = 0;
                for (int k = 0; k < this->matrixIndex; k++)
                    multMatrix.matrixValues[i][j] += matrixValues[i][k] * otherMatrix.matrixValues[k][j];
            }
        }
        return multMatrix;
    } else {
        throw exception(ERROR_SIZE_MESSAGE);
    }
}

Matrix &Matrix::invert() noexcept(false) {
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
        return *this;
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



void Matrix::memoryExpansion(Matrix &matrix) {
    for (int i = 0; i < matrix.matrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.matrixIndex];
        for (int j = 0; j < matrix.matrixIndex; j++) {
            matrix.matrixValues[i][j] = 0;
        }
    }
}

Matrix &Matrix::resize(int newIndex) {
    Matrix newMatrix;
    newMatrix.matrixIndex = newIndex;
    newMatrix.matrixValues = new double *[newMatrix.matrixIndex];
    for (int i = 0; i < newMatrix.matrixIndex; i++) {
        newMatrix.matrixValues[i] = new double[newMatrix.matrixIndex];
        for (int j = 0; j < newMatrix.matrixIndex; j++) {
            if (i < this->matrixIndex && j < this->matrixIndex) {
                newMatrix.matrixValues[i][j] = this->matrixValues[i][j];
            } else {
                newMatrix.matrixValues[i][j] = 0;
            }
        }
    }
    *this = newMatrix;
    return *this;
}

Matrix::Row Matrix::operator[](int i) {
    Row row(matrixValues[i]);
    return row;
}

void Matrix::outputInBinaryFile(ofstream &file) {
    int index = matrixIndex;
    double **values = matrixValues;
    file.write((char *) &index, sizeof(int));
    for (int i = 0; i < index; i++) {
        file.write((char *) values[i], sizeof(double) * index);
    }
}

Matrix Matrix::inputFromBinaryFile(ifstream &file) {
    int index;
    file.read((char *) &index, sizeof(int));
    auto **values = new double *[index];
    for (int i = 0; i < index; i++) {
        values[i] = new double[index];
        file.read((char *) values[i], sizeof(double) * index);
    }
    return Matrix(index, values);
}


Matrix::Row::Row(double *rows) {
    this->rows = rows;
}

double &Matrix::Row::operator[](int j) {
    return this->rows[j];
}
