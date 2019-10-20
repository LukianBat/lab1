//
// Created by lukia on 19.10.2019.
//

#ifndef LAB1_SINGLEMATRIX_H
#define LAB1_SINGLEMATRIX_H


#include "Matrix.h"

class SingleMatrix : public Matrix {
public:

    ~SingleMatrix();

    SingleMatrix();

    SingleMatrix(const SingleMatrix &copyMatrix);

    explicit SingleMatrix(int index);

    friend istream &operator>>(istream &is, SingleMatrix &matrix);

    friend ifstream &operator>>(ifstream &is, SingleMatrix &matrix);

    static SingleMatrix inputFromBinaryFile(ifstream &file);
};


#endif //LAB1_SINGLEMATRIX_H
