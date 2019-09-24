
#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H


class Matrix {
private:
    int matrixIndex;
    double **matrixValues;
public:

    void setIndex(int index);

    void setValues(double **values);

    void transpose();

    double **getValues();

    void sumWith(Matrix *otherMatrix);

    void multiplyWith(Matrix *otherMatrix);

    void invert();

    ~Matrix();
};


#endif
