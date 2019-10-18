#include <iostream>

#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

using namespace std;

class Matrix {
public:
    static int count;
private:
    int matrixIndex;

    double **matrixValues;

    double calculateDeterminant(double **values, int index);

    void memoryExpansion(Matrix &matrix);

    class Row {

    public:
        double *rows;
    public:
        Row(double *rows);

        double &operator[](int j);

    };

public:
    Matrix();

    Matrix sumWith(Matrix &otherMatrix) noexcept(false);

    explicit Matrix(int index);

    Matrix(int index, double **values);

    Matrix(const Matrix &copyMatrix);

    Matrix &operator=(const Matrix &matrix);

    Matrix operator+(Matrix &matrix);

    Matrix operator-(Matrix &matrix);

    Matrix operator*(Matrix &matrix);

    Row operator[](int i);

    double operator()();

    friend ostream &operator<<(ostream &os, Matrix &matrix);

    friend istream &operator>>(istream &is, Matrix &matrix);

    friend ofstream &operator<<(ofstream &os, Matrix &matrix);

    friend ifstream &operator>>(ifstream &is, Matrix &matrix);

    int getIndex();

    Matrix &transpose();

    Matrix &resize(int newIndex);

    Matrix diffWith(Matrix &otherMatrix);

    Matrix multiplyWith(Matrix &otherMatrix);

    double **getValues();

    double getValue(int i, int j);

    Matrix &invert();

    double getDeterminant();

    ~Matrix();


};

#endif
