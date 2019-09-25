
#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H


class Matrix {
private:
    int matrixIndex{};
    double **matrixValues{};

    double calculateDeterminant(double **values, int index);

public:

    Matrix();

    Matrix(int index, double **values);

    int getIndex();

    void setValues(double **values);

    void setIndex(int index);

    void transpose();

    double **getValues();

    void sumWith(Matrix *otherMatrix);

    void multiplyWith(Matrix *otherMatrix);

    void invert();

    double getDeterminant();

    ~Matrix();
};


#endif
