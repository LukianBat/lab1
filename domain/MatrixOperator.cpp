#include "MatrixOperator.h"

void MatrixOperator::setMatrix(int index, int **values) {

    this->firstMatrix->setIndex(index);
    this->firstMatrix->setValues(values);
}

void MatrixOperator::transposeMatrix() {
    firstMatrix->transpose();
}

int **MatrixOperator::getMatrix() {
    return this->firstMatrix->getValues();
}

void MatrixOperator::sumMatrix(int **otherValues) {
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
