#include <exception>
#include "MatrixOperator.h"

const char *INVERTING_ERROR_MESSAGE = "inverting matrix error";

void MatrixOperator::transposeMatrix() {
    baseMatrix->transpose();
}

double **MatrixOperator::getMatrixValues() {
    return this->baseMatrix->getValues();
}

void MatrixOperator::sumMatrix(double **values) {
    operationMatrix->setIndex(baseMatrix->getIndex());
    operationMatrix->setValues(values);
    baseMatrix->sumWith(operationMatrix);
}

void MatrixOperator::multiplyMatrix(double **values) {
    operationMatrix->setIndex(baseMatrix->getIndex());
    operationMatrix->setValues(values);
    baseMatrix->multiplyWith(operationMatrix);
}

void MatrixOperator::invertMatrix() noexcept(false) {
    if (baseMatrix->getDeterminant() == 0) {
        throw std::exception(INVERTING_ERROR_MESSAGE);
    }
    baseMatrix->invert();
}

double MatrixOperator::getMatrixDeterminant() {
    return baseMatrix->getDeterminant();
}

MatrixOperator::~MatrixOperator() {
    delete baseMatrix;
}

void MatrixOperator::baseMatrixInit(Matrix *matrix) {
    this->baseMatrix = matrix;
}

void MatrixOperator::setMatrixParameters(int index, double **values) {
    baseMatrix->setIndex(index);
    baseMatrix->setValues(values);
}

MatrixOperator::MatrixOperator() {
    Matrix matrix{};
    this->operationMatrix = &matrix;
}
