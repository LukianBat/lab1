#ifndef LAB1_MAINPRESENTER_H
#define LAB1_MAINPRESENTER_H


#include "../domain/MatrixOperator.h"

class MainPresenter {
private:
    MatrixOperator *matrixOperator;
public:
    explicit MainPresenter(MatrixOperator *anOperator);

    void setMatrix(Matrix *matrix);

    void setMatrixParameters(int index, double **values);

    void transposeMatrix();

    void sumMatrix(double **values);

    void multiplyMatrix(double **values);

    void invertMatrix() noexcept(false);

    double **getMatrix();

    double getMatrixDeterminant();

    ~MainPresenter();
};


#endif
