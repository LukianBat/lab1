#include <iostream>
#include <fstream>
#include <cmath>
#include "Matrix.h"

using namespace std;

#include "RectangleMatrix.h"

RectangleMatrix::RectangleMatrix(int columnIndex, int rowIndex, double **values) {
    Matrix::count++;
    this->rowMatrixIndex = columnIndex;
    this->columnsMatrixIndex = rowIndex;
    matrixValues = new double *[columnIndex];
    for (int i = 0; i < columnIndex; i++) {
        matrixValues[i] = new double[rowIndex];
        for (int j = 0; j < rowIndex; j++) {
            matrixValues[i][j] = values[i][j];
        }
    }
}

RectangleMatrix::~RectangleMatrix() {
    Matrix::count--;
    for (int i = 0; i < this->rowMatrixIndex; i++) {
        delete[] matrixValues[i];
    }
    delete[] matrixValues;
}

RectangleMatrix::RectangleMatrix() {
    Matrix::count++;
    rowMatrixIndex = 0;
    columnsMatrixIndex = 0;
    matrixValues = nullptr;
}

RectangleMatrix::RectangleMatrix(const RectangleMatrix &copyMatrix) {
    Matrix::count++;
    rowMatrixIndex = copyMatrix.rowMatrixIndex;
    columnsMatrixIndex = copyMatrix.columnsMatrixIndex;
    matrixValues = new double *[rowMatrixIndex];
    for (int i = 0; i < rowMatrixIndex; i++) {
        matrixValues[i] = new double[columnsMatrixIndex];
        for (int j = 0; j < columnsMatrixIndex; j++) {
            matrixValues[i][j] = copyMatrix.matrixValues[i][j];
        }
    }
}

RectangleMatrix &RectangleMatrix::operator=(const RectangleMatrix &matrix) {
    if (this == &matrix)
        return *this;
    rowMatrixIndex = matrix.rowMatrixIndex;
    columnsMatrixIndex = matrix.columnsMatrixIndex;
    delete[] matrixValues;
    matrixValues = new double *[rowMatrixIndex];
    for (int i = 0; i < rowMatrixIndex; i++) {
        matrixValues[i] = new double[columnsMatrixIndex];
        for (int j = 0; j < columnsMatrixIndex; j++) {
            matrixValues[i][j] = matrix.matrixValues[i][j];
        }
    }
    return *this;
}

RectangleMatrix RectangleMatrix::operator+(RectangleMatrix &matrix) {
    return this->sumWith(matrix);
}

RectangleMatrix RectangleMatrix::operator-(RectangleMatrix &matrix) {
    return this->diffWith(matrix);
}

RectangleMatrix RectangleMatrix::operator*(RectangleMatrix &matrix) {
    return this->multiplyWith(matrix);
}

istream &operator>>(istream &is, RectangleMatrix &matrix) {
    is >> matrix.rowMatrixIndex >> matrix.columnsMatrixIndex;
    matrix.matrixValues = new double *[matrix.rowMatrixIndex];
    for (int i = 0; i < matrix.rowMatrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.columnsMatrixIndex];
    }
    for (int i = 0; i < matrix.rowMatrixIndex; i++)
        for (int j = 0; j < matrix.columnsMatrixIndex; j++) {
            is >> matrix.matrixValues[i][j];
        }
    return is;
}

ostream &operator<<(ostream &os, RectangleMatrix &matrix) {
    os << matrix.rowMatrixIndex << " " << matrix.columnsMatrixIndex << endl;;
    for (int i = 0; i < matrix.rowMatrixIndex; i++) {
        for (int j = 0; j < matrix.columnsMatrixIndex; j++) {
            os << matrix.matrixValues[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

ofstream &operator<<(ofstream &os, RectangleMatrix &matrix) {
    os << matrix.rowMatrixIndex << " " << matrix.columnsMatrixIndex << endl;
    for (int i = 0; i < matrix.rowMatrixIndex; i++) {
        for (int j = 0; j < matrix.columnsMatrixIndex; j++) {
            os << matrix.matrixValues[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

ifstream &operator>>(ifstream &is, RectangleMatrix &matrix) {
    is >> matrix.rowMatrixIndex >> matrix.columnsMatrixIndex;
    matrix.matrixValues = new double *[matrix.rowMatrixIndex];
    for (int i = 0; i < matrix.rowMatrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.columnsMatrixIndex];
    }
    for (int i = 0; i < matrix.rowMatrixIndex; i++)
        for (int j = 0; j < matrix.columnsMatrixIndex; j++) {
            is >> matrix.matrixValues[i][j];
        }
    return is;
}

RectangleMatrix &RectangleMatrix::transpose() {
    RectangleMatrix matrix;
    matrix.rowMatrixIndex = columnsMatrixIndex;
    matrix.columnsMatrixIndex = rowMatrixIndex;
    matrix.matrixValues = new double *[matrix.rowMatrixIndex];
    for (int i = 0; i < matrix.rowMatrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.columnsMatrixIndex];
        for (int j = 0; j < matrix.columnsMatrixIndex; j++) {
            matrix.matrixValues[i][j] = matrixValues[j][i];
        }
    }
    *this = matrix;
    return *this;
}

RectangleMatrix &RectangleMatrix::resize(int newColumn, int newRow) {
    RectangleMatrix newMatrix;
    newMatrix.rowMatrixIndex = newColumn;
    newMatrix.columnsMatrixIndex = newRow;
    newMatrix.matrixValues = new double *[newMatrix.rowMatrixIndex];
    for (int i = 0; i < newMatrix.rowMatrixIndex; i++) {
        newMatrix.matrixValues[i] = new double[newMatrix.columnsMatrixIndex];
        for (int j = 0; j < newMatrix.columnsMatrixIndex; j++) {
            if (i < this->rowMatrixIndex && j < this->columnsMatrixIndex) {
                newMatrix.matrixValues[i][j] = this->matrixValues[i][j];
            } else {
                newMatrix.matrixValues[i][j] = 0;
            }
        }
    }
    *this = newMatrix;
    return *this;
}

void RectangleMatrix::outputInBinaryFile(ofstream &file) {
    int column = rowMatrixIndex;
    int row = columnsMatrixIndex;
    double **values = matrixValues;
    file.write((char *) &column, sizeof(int));
    file.write((char *) &row, sizeof(int));
    for (int i = 0; i < column; i++) {
        file.write((char *) values[i], sizeof(double) * row);
    }
}

RectangleMatrix RectangleMatrix::inputFromBinaryFile(ifstream &file) {
    int column;
    int row;
    file.read((char *) &column, sizeof(int));
    file.read((char *) &row, sizeof(int));
    auto **values = new double *[column];
    for (int i = 0; i < column; i++) {
        values[i] = new double[row];
        file.read((char *) values[i], sizeof(double) * row);
    }
    return RectangleMatrix(column, row, values);
}

RectangleMatrix RectangleMatrix::sumWith(RectangleMatrix &otherMatrix) noexcept(false) {
    if (otherMatrix.columnsMatrixIndex == columnsMatrixIndex && otherMatrix.rowMatrixIndex == rowMatrixIndex) {
        RectangleMatrix sumMatrix;
        sumMatrix.rowMatrixIndex = rowMatrixIndex;
        sumMatrix.columnsMatrixIndex = columnsMatrixIndex;
        sumMatrix.matrixValues = new double *[rowMatrixIndex];
        memoryExpansion(sumMatrix);
        for (int i = 0; i < rowMatrixIndex; i++)
            for (int j = 0; j < columnsMatrixIndex; j++)
                sumMatrix.matrixValues[i][j] = matrixValues[i][j] + otherMatrix.matrixValues[i][j];
        return sumMatrix;
    } else {
        throw exception((const exception &) "error");
    }
}

RectangleMatrix RectangleMatrix::diffWith(RectangleMatrix &otherMatrix) noexcept(false) {
    if (otherMatrix.columnsMatrixIndex == columnsMatrixIndex && otherMatrix.rowMatrixIndex == rowMatrixIndex) {
        RectangleMatrix sumMatrix;
        sumMatrix.rowMatrixIndex = rowMatrixIndex;
        sumMatrix.columnsMatrixIndex = columnsMatrixIndex;
        sumMatrix.matrixValues = new double *[rowMatrixIndex];
        memoryExpansion(sumMatrix);
        for (int i = 0; i < rowMatrixIndex; i++)
            for (int j = 0; j < columnsMatrixIndex; j++)
                sumMatrix.matrixValues[i][j] = matrixValues[i][j] - otherMatrix.matrixValues[i][j];
        return sumMatrix;
    } else {
        throw exception((const exception &) "error");
    }
}

RectangleMatrix RectangleMatrix::multiplyWith(RectangleMatrix &otherMatrix) {
    RectangleMatrix multMatrix;
    multMatrix.rowMatrixIndex = rowMatrixIndex;
    multMatrix.columnsMatrixIndex = otherMatrix.columnsMatrixIndex;
    multMatrix.matrixValues = new double *[multMatrix.rowMatrixIndex];
    memoryExpansion(multMatrix);
    for (int i = 0; i < multMatrix.rowMatrixIndex; i++) {
        for (int j = 0; j < multMatrix.columnsMatrixIndex; j++) {
            for (int k = 0; k < columnsMatrixIndex; k++)
                multMatrix.matrixValues[i][j] += matrixValues[i][k] * otherMatrix.matrixValues[k][j];
        }
    }
    return multMatrix;
}

void RectangleMatrix::memoryExpansion(RectangleMatrix &matrix) {
    for (int i = 0; i < matrix.rowMatrixIndex; i++) {
        matrix.matrixValues[i] = new double[matrix.columnsMatrixIndex];
        for (int j = 0; j < matrix.columnsMatrixIndex; j++) {
            matrix.matrixValues[i][j] = 0;
        }
    }
}
