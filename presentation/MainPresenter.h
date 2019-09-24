#ifndef LAB1_MAINPRESENTER_H
#define LAB1_MAINPRESENTER_H


#include "../domain/MatrixOperator.h"

class MainPresenter {
private:
    MatrixOperator *matrixOperator;
public:
    explicit MainPresenter(MatrixOperator *anOperator);

    void setMatrix(int index, double **values);

    void transposeMatrix();

    void sumMatrix(double **otherMatrix);

    void multiplyMatrix(double **otherMatrix);

    void invertMatrix();

    double **getMatrix();

    ~MainPresenter();
};


#endif
