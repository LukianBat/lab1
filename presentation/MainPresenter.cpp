#include "MainPresenter.h"
#include <iostream>

const char *INVERTING_ERROR_MESSAGE = "inverting matrix error";

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

void MainPresenter::invertMatrix() noexcept(false) {
    if (matrixOperator->getMatrixDeterminant() != 0) {
        matrixOperator->invertMatrix();
    } else {
        throw std::exception(INVERTING_ERROR_MESSAGE);
    }
}

double MainPresenter::getMatrixDeterminant() {
    return matrixOperator->getMatrixDeterminant();
}
