#include <iostream>
#include <fstream>
#include "MainView.h"
#include "Matrix.h"

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
const char *INPUT_FILE_TEXT = "'8' - to input in the file   ";
const int INPUT_FILE_CODE = 8;
const char *OUTPUT_FILE_TEXT = "'9' - to output from file   ";
const int OUTPUT_FILE_CODE = 9;
const char *INPUT_BINARY_FILE_TEXT = "'10' - to input in the binary file   ";
const int INPUT_BINARY_FILE_CODE = 10;
const char *OUTPUT_BINARY_FILE_TEXT = "'11' - to output from binary file   ";
const int OUTPUT_BINARY_FILE_CODE = 11;
struct MatrixModel {
    int matrixIndex;
    double matrixValues[INT8_MAX][INT8_MAX];
};

void MainView::startMenu() {

    int code;
    cout << INPUT_TEXT << endl;
    cout << INPUT_INDEX_TEXT << endl;
    Matrix baseMatrix;
    cin >> baseMatrix;
    while (true) {
        cout
                << TRANSPOSE_TEXT
                << SUM_TEXT
                << MULTIPLY_TEXT
                << INVERT_TEXT
                << OUTPUT_TEXT
                << DETERMINANT_TEXT
                << NEW_INPUT_TEXT
                << INPUT_FILE_TEXT
                << OUTPUT_FILE_TEXT
                << INPUT_BINARY_FILE_TEXT
                << OUTPUT_BINARY_FILE_TEXT
                << endl;
        cin >> code;
        switch (code) {
            case TRANSPOSE_CODE: {
                baseMatrix.transpose();
                break;
            }
            case SUM_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                Matrix operationMatrix;
                cin >> operationMatrix;
                Matrix matrix = baseMatrix + operationMatrix;
                baseMatrix = matrix;
                cout << baseMatrix << endl;
                break;
            }
            case MULTIPLY_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                Matrix operationMatrix;
                cin >> operationMatrix;
                Matrix matrix = baseMatrix * operationMatrix;
                baseMatrix = matrix;
                cout << baseMatrix << endl;
                break;
            }
            case INVERT_CODE: {
                try {
                    baseMatrix.invert();
                } catch (exception exc) {
                    cout << exc.what() << endl;
                }
                break;
            }
            case OUTPUT_CODE: {
                cout << baseMatrix << endl;
                break;
            }
            case DETERMINANT_CODE: {
                cout << baseMatrix() << endl;
                break;
            }
            case NEW_INPUT_CODE: {
                cin >> baseMatrix;
                break;
            }
            case INPUT_FILE_CODE: {
                ofstream file("file.txt");
                if (!file) {
                    cout << "Ошибка открытия файла";
                    exit(1);
                }
                file << baseMatrix;
                file.close();
                break;
            }
            case OUTPUT_FILE_CODE: {
                ifstream file("file.txt");
                if (!file) {
                    cout << "Ошибка открытия файла";
                    exit(1);
                }
                file >> baseMatrix;
                file.close();
                break;
            }
            case INPUT_BINARY_FILE_CODE: {
                MatrixModel matrixModel;
                matrixModel.matrixIndex = baseMatrix.getIndex();
                for (int i = 0; i < matrixModel.matrixIndex; i++) {
                    for (int j = 0; j < matrixModel.matrixIndex; j++) {
                        matrixModel.matrixValues[i][j] = baseMatrix.getValues()[i][j];
                    }
                }
                ofstream binaryFile("binaryFile.dat");
                binaryFile.write((char *) &matrixModel, sizeof(MatrixModel));
                binaryFile.close();
                break;
            }
            case OUTPUT_BINARY_FILE_CODE: {
                ifstream binaryFile("binaryFile.dat");
                MatrixModel matrixModel{};
                binaryFile.read((char *) &matrixModel, sizeof(MatrixModel));
                binaryFile.close();
                Matrix matrix(matrixModel.matrixIndex);
                for (int i = 0; i < matrixModel.matrixIndex; i++) {
                    for (int j = 0; j < matrixModel.matrixIndex; j++) {
                        matrix[i][j] = matrixModel.matrixValues[i][j];
                    }
                }
                baseMatrix = matrix;
                cout << baseMatrix;
                break;
            }

            default:
                exit(0);
        }

    }


}

MainView::MainView() {
    startMenu();
}
