#ifndef LAB1_MAINPRESENTER_H
#define LAB1_MAINPRESENTER_H


#include "../domain/MatrixOperator.h"

class MainPresenter {
private:
    MatrixOperator *matrixOperator;
public:
    explicit MainPresenter(MatrixOperator *anOperator);

    void setMatrix(int index, int **values);

    void transposeMatrix();

    void sumMatrix(int **otherMatrix);

    int **getMatrix();

    ~MainPresenter();
};


#endif
