#include "MainPresenter.h"


int **MainPresenter::getMatrix() {
    return matrixOperator->getMatrix();
}

MainPresenter::MainPresenter(MatrixOperator *anOperator) {
    matrixOperator = anOperator;
}

void MainPresenter::setMatrix(int index, int **values) {
    matrixOperator->setMatrix(index, values);
}

void MainPresenter::transposeMatrix() {
    matrixOperator->transposeMatrix();
}

void MainPresenter::sumMatrix(int **otherMatrix) {
    matrixOperator->sumMatrix(otherMatrix);
}

MainPresenter::~MainPresenter() {
    delete matrixOperator;
}
