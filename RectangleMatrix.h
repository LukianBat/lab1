//
// Created by lukia on 19.10.2019.
//

#ifndef LAB1_RECTANGLEMATRIX_H
#define LAB1_RECTANGLEMATRIX_H


#include "Matrix.h"

class RectangleMatrix : public Matrix {
private:
    int rowMatrixIndex;
    int columnsMatrixIndex;

    void invert() {};

    void operator()() {};

    void getDeterminant() {};

    void memoryExpansion(RectangleMatrix &matrix);

public:
    ~RectangleMatrix();

    RectangleMatrix();

    RectangleMatrix(const RectangleMatrix &copyMatrix);

    RectangleMatrix(int columnIndex, int rowIndex, double **values);

    RectangleMatrix &operator=(const RectangleMatrix &matrix);

    RectangleMatrix operator+(RectangleMatrix &matrix);

    RectangleMatrix operator-(RectangleMatrix &matrix);

    RectangleMatrix operator*(RectangleMatrix &matrix);

    friend istream &operator>>(istream &is, RectangleMatrix &matrix);

    friend ostream &operator<<(ostream &os, RectangleMatrix &matrix);

    friend ofstream &operator<<(ofstream &os, RectangleMatrix &matrix);

    friend ifstream &operator>>(ifstream &is, RectangleMatrix &matrix);

    RectangleMatrix &transpose() override;

    RectangleMatrix &resize(int newColumn, int newRow);

    RectangleMatrix diffWith(RectangleMatrix &otherMatrix);

    RectangleMatrix multiplyWith(RectangleMatrix &otherMatrix);

    void outputInBinaryFile(ofstream &file) override;

    RectangleMatrix sumWith(RectangleMatrix &otherMatrix) noexcept(false);

    static RectangleMatrix inputFromBinaryFile(ifstream &file);
};


#endif //LAB1_RECTANGLEMATRIX_H
