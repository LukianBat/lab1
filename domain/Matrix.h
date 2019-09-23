
#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H


class Matrix {
private:
    int matrixIndex;
    int **matrixValues;
public:

    void setIndex(int index);

    void setValues(int **values);

    void transpose();

    int **getValues();

    void sumWith(Matrix *otherMatrix);

    ~Matrix();
};


#endif
