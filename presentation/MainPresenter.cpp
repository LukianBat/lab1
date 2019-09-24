#include "MainPresenter.h"


double **MainPresenter::getMatrix() {
    return matrixOperator->getMatrix();
}

MainPresenter::MainPresenter(MatrixOperator *anOperator) {
    matrixOperator = anOperator;
}

void MainPresenter::setMatrix(int index, double **values) {
    matrixOperator->setMatrix(index, values);
}

void MainPresenter::transposeMatrix() {
    matrixOperator->transposeMatrix();
}

void MainPresenter::sumMatrix(double **otherMatrix) {
    matrixOperator->sumMatrix(otherMatrix);
}

MainPresenter::~MainPresenter() {
    delete matrixOperator;
}

void MainPresenter::multiplyMatrix(double **otherMatrix) {
    matrixOperator->multiplyMatrix(otherMatrix);
}

void MainPresenter::invertMatrix() {
    matrixOperator->invertMatrix();
}
