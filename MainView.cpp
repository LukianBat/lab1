#include <iostream>
#include <fstream>
#include "MainView.h"
#include "Matrix.h"

const char *INPUT_TEXT = "input matrix   ";
const char *INPUT_INDEX_TEXT = "input index:   ";
const char *INPUT_VALUE_TEXT = "input value:   ";
const char *TRANSPOSE_TEXT = "'1'- to transpose matrix;    ";
const int TRANSPOSE_CODE = 1;
const char *SUM_TEXT = "'2' - to sum with other matrix;   ";
const int SUM_CODE = 2;
const char *DIFF_TEXT = "'3' - to differ with other matrix;   ";
const int DIFF_CODE = 3;
const char *OTHER_MATRIX_INPUT_TEXT = "input other matrix   ";
const char *MULTIPLY_TEXT = "'4' - to multiply with other matrix   ";
const int MULTIPLY_CODE = 4;
const char *INVERT_TEXT = "'5' - to invert matrix   ";
const int INVERT_CODE = 5;
const char *OUTPUT_TEXT = "'6' - to output matrix   ";
const int OUTPUT_CODE = 6;
const char *DETERMINANT_TEXT = "'7' - to output determinant   ";
const int DETERMINANT_CODE = 7;
const char *EDIT_MATRIX_TEXT = " '8' - to edit matrix value     ";
const int EDIT_MATRIX_CODE = 8;
const char *NEW_INPUT_TEXT = "'9' - to input new matrix   ";
const int NEW_INPUT_CODE = 9;
const char *INPUT_FILE_TEXT = "'10' - to input in the file   ";
const int INPUT_FILE_CODE = 10;
const char *OUTPUT_FILE_TEXT = "'11' - to output from file   ";
const int OUTPUT_FILE_CODE = 11;
const char *INPUT_BINARY_FILE_TEXT = "'12' - to input in the binary file   ";
const int INPUT_BINARY_FILE_CODE = 12;
const char *OUTPUT_BINARY_FILE_TEXT = "'13' - to output from binary file   ";
const int OUTPUT_BINARY_FILE_CODE = 13;
const char *EXIT_TEXT = "'0' - to exit   ";
const int EXIT_CODE = 0;
const char *INPUT_ERROR_TEXT = "input error, try again";
const char *OPEN_FILE_ERROR = "open file error ";
const char *FILE_NAME = "file.txt";
const char *BINARY_FILE_NAME = "fileBinary.dat";

using namespace std;


void MainView::startMenu() {

    int code;
    bool state = true;
    Matrix baseMatrix;
    cout << INPUT_TEXT << endl;
    cout << INPUT_INDEX_TEXT << endl;
    cin >> baseMatrix;
    while (state) {
        cout
                << TRANSPOSE_TEXT
                << SUM_TEXT
                << DIFF_TEXT
                << endl
                << MULTIPLY_TEXT
                << INVERT_TEXT
                << OUTPUT_TEXT
                << endl
                << DETERMINANT_TEXT
                << EDIT_MATRIX_TEXT
                << NEW_INPUT_TEXT
                << endl
                << INPUT_FILE_TEXT
                << OUTPUT_FILE_TEXT
                << INPUT_BINARY_FILE_TEXT
                << endl
                << OUTPUT_BINARY_FILE_TEXT
                << EXIT_TEXT
                << endl;
        cin >> code;
        switch (code) {
            case TRANSPOSE_CODE: {
                baseMatrix.transpose();
                cout << baseMatrix << endl;
                break;
            }
            case SUM_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                Matrix operationMatrix;
                cin >> operationMatrix;
                try {
                    Matrix matrix = baseMatrix + operationMatrix;
                    baseMatrix = matrix;
                } catch (exception ex) {
                    cout << ex.what() << endl;
                }
                cout << baseMatrix << endl;
                break;
            }
            case DIFF_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                Matrix operationMatrix;
                cin >> operationMatrix;
                try {
                    Matrix matrix = baseMatrix - operationMatrix;
                    baseMatrix = matrix;
                } catch (exception ex) {
                    cout << ex.what() << endl;
                }
                cout << baseMatrix << endl;
                break;
            }
            case MULTIPLY_CODE: {
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                Matrix operationMatrix;
                cin >> operationMatrix;
                try {
                    Matrix matrix = baseMatrix * operationMatrix;
                    baseMatrix = matrix;
                } catch (exception ex) {
                    cout << ex.what() << endl;
                }
                cout << baseMatrix << endl;
                break;
            }
            case INVERT_CODE: {
                try {
                    baseMatrix.invert();
                    cout << baseMatrix;
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
                ofstream file(FILE_NAME);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                file << baseMatrix;
                file.close();
                break;
            }
            case OUTPUT_FILE_CODE: {
                ifstream file(FILE_NAME);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                file >> baseMatrix;
                cout << baseMatrix;
                file.close();
                break;
            }
            case INPUT_BINARY_FILE_CODE: {
                ofstream binaryFile(BINARY_FILE_NAME, ios::binary);
                if (!binaryFile) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                binaryFile << baseMatrix;
                binaryFile.close();
                break;
            }
            case OUTPUT_BINARY_FILE_CODE: {
                ifstream binaryFile(BINARY_FILE_NAME, ios::binary);
                if (!binaryFile) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                binaryFile >> baseMatrix;
                cout << baseMatrix;
                break;
            }
            case EDIT_MATRIX_CODE: {
                int i, j;
                double value;
                cout << INPUT_INDEX_TEXT << endl;
                cin >> i >> j;
                cout << INPUT_VALUE_TEXT << endl;
                cin >> value;
                baseMatrix[i][j] = value;
                break;
            }
            case EXIT_CODE:
                exit(0);

            default:
                cout << INPUT_ERROR_TEXT << endl;
                state = false;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                startMenu();
                break;
        }
    }
    startMenu();
}

MainView::MainView() {
    startMenu();
}
