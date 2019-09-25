#include <iostream>
#include "MainView.h"

using namespace std;

const char *INPUT_TEXT = "input matrix   ";
const char *INPUT_INDEX_TEXT = "input index   ";
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
const char *DETERMINANT_TEXT = "'6' - to output determinant   ";
const int DETERMINANT_CODE = 6;
const char *NEW_INPUT_TEXT = "'7' - to input new matrix   ";
const int NEW_INPUT_CODE = 7;

void MainView::startMenu() {

    int code;
    cout << INPUT_TEXT << endl;
    cout << INPUT_INDEX_TEXT << endl;
    int baseIndex;
    cin >> baseIndex;
    matrixIndex = baseIndex;
    auto **baseValues = new double *[baseIndex];
    inputMatrixValues(baseIndex, baseValues);
    presenter->setMatrix(baseIndex, baseValues);

    while (true) {
        cout
                << TRANSPOSE_TEXT
                << SUM_TEXT
                << MULTIPLY_TEXT
                << INVERT_TEXT
                << OUTPUT_TEXT
                << DETERMINANT_TEXT
                << NEW_INPUT_TEXT
                << endl;
        cin >> code;
        switch (code) {
            case TRANSPOSE_CODE: {
                presenter->transposeMatrix();
                break;
            }
            case SUM_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                int index = matrixIndex;
                auto **values = new double *[index];
                inputMatrixValues(index, values);
                presenter->sumMatrix(values);
                delete[] values;
                break;
            }
            case MULTIPLY_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                int index = matrixIndex;
                auto **values = new double *[index];
                inputMatrixValues(index, values);
                presenter->multiplyMatrix(values);
                delete[] values;
                break;
            }
            case INVERT_CODE: {
                try {
                    presenter->invertMatrix();
                } catch (exception exc) {
                    cout << exc.what() << endl;
                }
                break;
            }
            case OUTPUT_CODE: {
                printMatrix();
                break;
            }
            case DETERMINANT_CODE: {
                cout << presenter->getMatrixDeterminant() << endl;
                break;
            }
            case NEW_INPUT_CODE: {
                delete[] baseValues;
                cout << INPUT_INDEX_TEXT << endl;
                cin >> baseIndex;
                matrixIndex = baseIndex;
                baseValues = new double *[baseIndex];
                for (int i = 0; i < baseIndex; i++) {
                    baseValues[i] = new double[baseIndex];
                }
                for (int i = 0; i < baseIndex; i++)
                    for (int j = 0; j < baseIndex; j++) {
                        cin >> baseValues[i][j];
                    }
                presenter->setMatrix(baseIndex, baseValues);
                break;
            }
            default:
                delete[] baseValues;
                exit(0);
        }

    }


}

MainView::MainView(MainPresenter *presenter) {
    this->presenter = presenter;
    startMenu();
}

void MainView::printMatrix() {
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
