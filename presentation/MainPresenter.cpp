#include "MainPresenter.h"
#include <iostream>

double **MainPresenter::getMatrix() {
    return matrixOperator->getMatrixValues();
}

MainPresenter::MainPresenter(MatrixOperator *anOperator) {
    matrixOperator = anOperator;
}

void MainPresenter::setMatrix(Matrix *matrix) {
    matrixOperator->baseMatrixInit(matrix);
}

void MainPresenter::transposeMatrix() {
    matrixOperator->transposeMatrix();
}

void MainPresenter::sumMatrix(double **values) {
    matrixOperator->sumMatrix(values);
}

MainPresenter::~MainPresenter() {
    delete matrixOperator;
}

void MainPresenter::multiplyMatrix(double **values) {
    matrixOperator->multiplyMatrix(values);
}

void MainPresenter::invertMatrix() noexcept(false) {
    try {
        matrixOperator->invertMatrix();
    }
    catch (std::exception ex) {
        throw ex;
    }
}

double MainPresenter::getMatrixDeterminant() {
    return matrixOperator->getMatrixDeterminant();
}

void MainPresenter::setMatrixParameters(int index, double **values) {
    matrixOperator->setMatrixParameters(index, values);
}
