#include <iostream>
#include <fstream>
#include "MainView.h"
#include "Matrix.h"
#include <vector>
#include <limits>

const char *INPUT_TEXT = "input matrix   ";
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
const char *GET_MATRIX_TEXT = " '8' - to get matrix value     ";
const int GET_MATRIX_CODE = 8;
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
const char *RESIZE_TEXT = "'14' - to resize matrix      ";
const int RESIZE_CODE = 14;
const char *EXIT_TEXT = "'0' - to exit   ";
const int EXIT_CODE = 0;
const char *INPUT_ERROR_TEXT = "input error, try again  ";
const char *OPEN_FILE_ERROR = "open file error ";
const char *FILE_NAME = "file.txt";
const char *BINARY_FILE_NAME = "fileBinary.dat";
const char *ADD_TEXT = "add new matrix   ";
const char *ADD_NEW_MATRIX = "'15' - add new matrix     ";
const int ADD_NEW_MATRIX_CODE = 15;
const char *OUTPUT_ALL_TEXT = "'16' - to output all matrix     ";
const int OUTPUT_ALL_CODE = 16;
using namespace std;


int counter;

void MainView::startMenu() {

    int code;
    int arrayIndex = 0;
    int currentMatrixNumber = 0;
    cout << "input number of matrix" << endl;
    cin >> counter;
    bool secState = true;
    vector<Matrix> matrixVector;
    matrixVector.reserve(counter);
    for (int i = 0; i < counter; ++i) {
        cout << ADD_TEXT << endl;
        arrayIndex++;
        Matrix matrix;
        cin >> matrix;
        matrixVector.push_back(matrix);
    }
    while (secState) {
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
                << GET_MATRIX_TEXT
                << NEW_INPUT_TEXT
                << endl
                << INPUT_FILE_TEXT
                << OUTPUT_FILE_TEXT
                << INPUT_BINARY_FILE_TEXT
                << endl
                << OUTPUT_BINARY_FILE_TEXT
                << RESIZE_TEXT
                << ADD_NEW_MATRIX
                << OUTPUT_ALL_TEXT
                << EXIT_TEXT
                << endl;
        cin >> code;
        switch (code) {
            case TRANSPOSE_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber))
                    cout << matrixVector.at(currentMatrixNumber).transpose() << endl;
                else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case SUM_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                int operationMatrixNumber;
                cin >> operationMatrixNumber;
                if (checkInVector(currentMatrixNumber) && checkInVector(operationMatrixNumber))
                    try {
                        counter++;
                        Matrix matrix =
                                matrixVector.at(currentMatrixNumber) + (matrixVector.at(operationMatrixNumber));
                        cout << matrix << endl;
                        cout << endl;
                    } catch (exception ex) {
                        cout << ex.what() << endl;
                    }
                else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case DIFF_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                int operationMatrixNumber;
                cin >> operationMatrixNumber;
                if (checkInVector(currentMatrixNumber) && checkInVector(operationMatrixNumber))

                    try {
                        counter++;
                        Matrix matrix = matrixVector.at(currentMatrixNumber) - (matrixVector.at(operationMatrixNumber));
                        cout << matrix << endl;
                        cout << endl;
                    } catch (exception ex) {
                        cout << ex.what() << endl;
                    }
                else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case MULTIPLY_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                cout << OTHER_MATRIX_INPUT_TEXT << endl;
                int operationMatrixNumber;
                cin >> operationMatrixNumber;
                if (checkInVector(currentMatrixNumber) && checkInVector(operationMatrixNumber))
                    try {
                        counter++;
                        Matrix matrix = matrixVector.at(currentMatrixNumber) * (matrixVector.at(operationMatrixNumber));
                        cout << matrix << endl;
                        cout << endl;
                    } catch (exception ex) {
                        cout << ex.what() << endl;
                    }
                else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case INVERT_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber))
                    try {
                        cout << matrixVector.at(currentMatrixNumber).invert() << endl;
                        cout << endl;
                    } catch (exception exc) {
                        cout << exc.what() << endl;
                    }
                else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case OUTPUT_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber)) {
                    cout << matrixVector.at(currentMatrixNumber) << endl;
                    cout << endl;
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case DETERMINANT_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber))
                    cout << matrixVector.at(currentMatrixNumber).getDeterminant() << endl;
                else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case NEW_INPUT_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber)) {
                    Matrix *matrix = &matrixVector.at(currentMatrixNumber);
                    cin >> *matrix;
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case INPUT_FILE_CODE: {
                ofstream file(FILE_NAME);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                if (counter != 0) {
                    file << counter << "\n";
                    for (auto &matrix : matrixVector) {
                        file << matrix;
                    }
                } else cout << "  Empty!  " << endl;
                file.close();
                break;
            }
            case OUTPUT_FILE_CODE: {
                ifstream file(FILE_NAME);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                int fileCounter;
                file >> fileCounter;
                for (int i = 0; i < fileCounter; i++) {
                    Matrix matrix;
                    file >> matrix;
                    matrixVector.push_back(matrix);
                }
                counter += fileCounter;
                file.close();
                break;
            }
            case INPUT_BINARY_FILE_CODE: {
                ofstream file(BINARY_FILE_NAME, ios::binary);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                if (counter != 0) {
                    file.write((char *) &counter, sizeof(int));
                    for (auto &matrix : matrixVector) {
                        int index = matrix.getIndex();
                        double **values = matrix.getValues();
                        file.write((char *) &index, sizeof(int));
                        for (int i = 0; i < index; i++) {
                            double *row = values[i];
                            for (int j = 0; j < index; j++) {
                                double value = row[j];
                                file.write((char *) &value, sizeof(double));
                            }
                        }
                    }
                } else cout << "  Empty!  " << endl;
                file.close();
                break;
            }
            case OUTPUT_BINARY_FILE_CODE: {
                ifstream file(BINARY_FILE_NAME, ios::binary);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                int fileCounter;
                file.read((char *) &fileCounter, sizeof(int));
                for (int i = 0; i < fileCounter; i++) {
                    int index;
                    file.read((char *) &index, sizeof(int));
                    auto **values = new double *[index];
                    for (int j = 0; j < index; j++) {
                        auto *row = new double[index];
                        values[j] = row;
                        for (int k = 0; k < index; k++) {
                            double value;
                            file.read((char *) &value, sizeof(double));
                            row[k] = value;
                        }
                    }
                    matrixVector.push_back(Matrix(index, values));
                }
                counter += fileCounter;
                file.close();
                break;
            }
            case GET_MATRIX_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber)) {
                    int i, j;
                    cout << "input i and j";
                    cin >> i >> j;
                    Matrix &matrix = matrixVector.at(currentMatrixNumber);
                    //double d = matrix->operator[](i).operator[](j);
                    double c = matrix[i][j];
                    cout << "c = " << c << endl;
                    matrix[i][j] = 1.2345;
                    cout << matrix[i][j] << endl;
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case RESIZE_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber)) {
                    int newIndex;
                    cin >> newIndex;
                    Matrix *matrix;
                    matrix = &matrixVector.at(currentMatrixNumber);
                    cout << matrix->resize(newIndex) << endl;
                    cout << endl;
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case ADD_NEW_MATRIX_CODE: {
                cout << INPUT_TEXT << endl;
                Matrix matrix;
                cin >> matrix;
                matrixVector.push_back(matrix);
                counter++;
                break;
            }
            case OUTPUT_ALL_CODE: {
                if (counter != 0) {
                    int j = 0;
                    for (auto &matrix : matrixVector) {
                        cout << j << endl;
                        cout << matrix << endl;
                        j++;
                    }
                } else cout << "  Empty!  " << endl;
                break;
            }
            case EXIT_CODE:
                exit(0);
            default:
                cout << INPUT_ERROR_TEXT << endl;
                secState = false;
                cin.clear();
                startMenu();
                break;
        }
    }

    startMenu();

}

MainView::MainView() {
    startMenu();
}

bool MainView::checkInVector(int current) {
    return current <= counter - 1;
}
