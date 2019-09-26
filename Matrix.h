#include <iostream>

#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

using namespace std;

class Matrix {
private:
    int matrixIndex;
    double **matrixValues;

    double calculateDeterminant(double **values, int index);

    void memoryExpansion(Matrix &matrix);

public:

    Matrix();

    Matrix(int index);

    Matrix(int index, double **values);

    Matrix(const Matrix &copyMatrix);

    Matrix &operator=(const Matrix &matrix);

    Matrix operator+(Matrix &matrix);

    Matrix operator-(Matrix &matrix);

    Matrix operator*(Matrix &matrix);

    const double *operator[](int index) const;

    double *operator[](int index);

    double operator()();

    friend ostream &operator<<(ostream &os, Matrix &matrix);

    friend istream &operator>>(istream &is, Matrix &matrix);

    friend ofstream &operator<<(ofstream &os, Matrix &matrix);

    friend ifstream &operator>>(ifstream &is, Matrix &matrix);

    int getIndex();

    void transpose();

    double **getValues();

    void sumWith(Matrix &otherMatrix);

    void diffWith(Matrix &otherMatrix);

    void multiplyWith(Matrix &otherMatrix);

    void invert();

    double getDeterminant();

    ~Matrix();


};

#endif
