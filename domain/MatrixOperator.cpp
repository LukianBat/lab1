#include "MatrixOperator.h"
#include "iostream"

void MatrixOperator::setMatrix(int index, double **values) {

    this->firstMatrix->setIndex(index);
    this->firstMatrix->setValues(values);

}

void MatrixOperator::transposeMatrix() {
    firstMatrix->transpose();
}

double **MatrixOperator::getMatrix() {
    return this->firstMatrix->getValues();
}

void MatrixOperator::sumMatrix(double **otherValues) {
    secondMatrix->setValues(otherValues);
    firstMatrix->sumWith(secondMatrix);
}

MatrixOperator::MatrixOperator() {
    Matrix firstMatrix{};
    Matrix secondMatrix{};
    this->firstMatrix = &firstMatrix;
    this->secondMatrix = &secondMatrix;
}

MatrixOperator::~MatrixOperator() {
    delete secondMatrix;
    delete firstMatrix;
}

void MatrixOperator::multiplyMatrix(double **otherValues) {
    secondMatrix->setValues(otherValues);
    firstMatrix->multiplyWith(secondMatrix);
}

void MatrixOperator::invertMatrix() {
    firstMatrix->invert();
}

double MatrixOperator::getMatrixDeterminant() {
    return firstMatrix->getDeterminant();
}