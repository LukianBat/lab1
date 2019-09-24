#include <iostream>
#include "MainView.h"

using namespace std;

const char *INPUT_TEXT = "input matrix   ";
const char *INPUT_INDEX_TEXT = "input rang   ";
const char *INPUT_VALUES_TEXT = "input values   ";
const char *TRANSPOSE_TEXT = "'1'- to transpose matrix;    ";
const int TRANSPOSE_CODE = 1;
const char *SUM_TEXT = "'2' - to sum with other matrix;   ";
const int SUM_CODE = 2;
const char *OTHER_MATRIX_INPUT_TEXT = "input other matrix   ";
const char *MULTIPLY_TEXT = "'3' - to multiply with other matrix   ";
const int MULTIPLY_CODE = 3;
const char *INVERT_TEXT = "'4' - to invert matrix   ";
const int INVERT_CODE = 4;
const char *OUTPUT_TEXT = "'5' - to output matrix   ";
const int OUTPUT_CODE = 5;

void MainView::startMenu() {

    int n;
    bool state = true;
    cout << INPUT_TEXT << endl;
    cout << INPUT_INDEX_TEXT << endl;
    int baseIndex;
    cin >> baseIndex;
    matrixIndex = baseIndex;
    double **baseValues = new double *[baseIndex];
    inputMatrixValues(baseIndex, baseValues);
    presenter->setMatrix(baseIndex, baseValues);

    while (state) {
        cout
                << TRANSPOSE_TEXT
                << SUM_TEXT
                << MULTIPLY_TEXT
                << OUTPUT_TEXT
                << endl;
        cin >> n;
        switch (n) {
            case TRANSPOSE_CODE: {
                presenter->transposeMatrix();
                break;
            }
            case SUM_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                int index = matrixIndex;
                double **values = new double *[index];
                inputMatrixValues(index, values);
                presenter->sumMatrix(values);
                break;
            }
            case MULTIPLY_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                int index = matrixIndex;
                double **values = new double *[index];
                inputMatrixValues(index, values);
                presenter->multiplyMatrix(values);
                break;
            }
            case INVERT_CODE: {
                presenter->invertMatrix();
                break;
            }
            case OUTPUT_CODE: {
                printResult();
                break;
            }
            default:
                state = false;
                exit(0);
        }

    }


}

MainView::MainView(MainPresenter *presenter) {
    this->presenter = presenter;
    startMenu();
}

void MainView::printResult() {
    int index = matrixIndex;
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index; j++) {
            cout << presenter->getMatrix()[i][j] << " ";
        }
        cout << endl;
    }
}

MainView::~MainView() {
    delete presenter;
    matrixIndex = NULL;
}

void MainView::inputMatrixValues(int index, double **values) {
    for (int i = 0; i < index; i++) {
        values[i] = new double[index];
    }
    for (int i = 0; i < index; i++)
        for (int j = 0; j < index; j++) {
            cin >> values[i][j];
        }
}


