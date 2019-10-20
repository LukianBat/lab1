#include <iostream>

#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

using namespace std;

class Matrix {
public:
    static int count;
private:

    double calculateDeterminant(double **values, int index);

    void memoryExpansion(Matrix &matrix);

protected:

    int matrixIndex;
    double **matrixValues;

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

    Matrix(int index, double **values);

    Matrix(const Matrix &copyMatrix);

    Matrix &operator=(const Matrix &matrix);

    Matrix operator+(Matrix &matrix);

    Matrix operator-(Matrix &matrix);

    Matrix operator*(Matrix &matrix);

    Row operator[](int i);

    double operator()();

    friend istream &operator>>(istream &is, Matrix &matrix);

    friend ostream &operator<<(ostream &os, Matrix &matrix);

    friend ofstream &operator<<(ofstream &os, Matrix &matrix);

    friend ifstream &operator>>(ifstream &is, Matrix &matrix);

    virtual Matrix &transpose();

    Matrix &resize(int newIndex);

    Matrix diffWith(Matrix &otherMatrix);

    Matrix multiplyWith(Matrix &otherMatrix);

    Matrix &invert();

    double getDeterminant();

    virtual void outputInBinaryFile(ofstream &file);

    static Matrix inputFromBinaryFile(ifstream &file);

    ~Matrix();


};

#endif
