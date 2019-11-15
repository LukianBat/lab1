#include <iostream>
#include <fstream>
#include "MainView.h"
#include "Matrix.h"
#include "SingleMatrix.h"
#include "RectangleMatrix.h"
#include <vector>

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
const int OUTPUT_IN_FILE_CODE = 10;
const char *OUTPUT_FILE_TEXT = "'11' - to output from file   ";
const int INPUT_FROM_FILE_CODE = 11;
const char *INPUT_BINARY_FILE_TEXT = "'12' - to input in the binary file   ";
const int OUTPUT_IN_BINARY_FILE_CODE = 12;
const char *OUTPUT_BINARY_FILE_TEXT = "'13' - to output from binary file   ";
const int INPUT_FROM_BINARY_FILE_CODE = 13;
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

    cout << "square matrix - 0 " << endl << "single matrix 1 " << endl << "rectangle matrix 2 ";
    int matrixCode;
    cin >> matrixCode;
    int code;
    int arrayIndex = 0;
    int currentMatrixNumber = 0;
    cout << "input number of matrix" << endl;
    cin >> counter;
    bool secState = true;
    vector<RectangleMatrix> rectangleMatrixVector;
    vector<SingleMatrix> singleMatrixVector;
    vector<Matrix> matrixVector;
    switch (matrixCode) {
        case 2: {
            rectangleMatrixVector.reserve(counter);
            for (int i = 0; i < counter; ++i) {
                cout << ADD_TEXT << endl;
                arrayIndex++;
                RectangleMatrix matrix;
                cin >> matrix;
                rectangleMatrixVector.push_back(matrix);
            }
            break;
        }
        case 0: {
            matrixVector.reserve(counter);
            for (int i = 0; i < counter; ++i) {
                cout << ADD_TEXT << endl;
                arrayIndex++;
                Matrix matrix;
                cin >> matrix;
                matrixVector.push_back(matrix);
            }
            break;
        }
        case 1: {
            singleMatrixVector.reserve(counter);
            for (int i = 0; i < counter; ++i) {
                cout << ADD_TEXT << endl;
                arrayIndex++;
                SingleMatrix matrix;
                cin >> matrix;
                singleMatrixVector.push_back(matrix);
            }
            break;
        }
        default: {
            matrixVector.reserve(counter);
            for (int i = 0; i < counter; ++i) {
                cout << ADD_TEXT << endl;
                arrayIndex++;
                Matrix matrix;
                cin >> matrix;
                matrixVector.push_back(matrix);
            }
            break;
        }
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
                if (checkInVector(currentMatrixNumber)) {
                    switch (matrixCode) {
                        case 2: {
                            cout << rectangleMatrixVector.at(currentMatrixNumber).transpose() << endl;
                            break;
                        }
                        case 0: {
                            cout << matrixVector.at(currentMatrixNumber).transpose() << endl;
                            break;
                        }
                        case 1: {
                            cout << singleMatrixVector.at(currentMatrixNumber).transpose() << endl;
                            break;
                        }
                        default:
                            cout << matrixVector.at(currentMatrixNumber).transpose() << endl;
                    }
                } else
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

                        switch (matrixCode) {
                            case 2: {
                                RectangleMatrix matrix =
                                        rectangleMatrixVector.at(currentMatrixNumber) +
                                        (rectangleMatrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            case 0: {
                                Matrix matrix =
                                        matrixVector.at(currentMatrixNumber) +
                                        (matrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            case 1: {
                                Matrix matrix =
                                        singleMatrixVector.at(currentMatrixNumber) +
                                        (singleMatrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            default:
                                Matrix matrix =
                                        matrixVector.at(currentMatrixNumber) +
                                        (matrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                        }
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
                        switch (matrixCode) {
                            case 2: {
                                RectangleMatrix matrix =
                                        rectangleMatrixVector.at(currentMatrixNumber) -
                                        (rectangleMatrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            case 0: {
                                Matrix matrix =
                                        matrixVector.at(currentMatrixNumber) -
                                        (matrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            case 1: {
                                Matrix matrix =
                                        singleMatrixVector.at(currentMatrixNumber) -
                                        (singleMatrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            default:
                                Matrix matrix =
                                        matrixVector.at(currentMatrixNumber) -
                                        (matrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                        }
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
                        switch (matrixCode) {
                            case 2: {
                                RectangleMatrix matrix =
                                        rectangleMatrixVector.at(currentMatrixNumber) *
                                        (rectangleMatrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            case 0: {
                                Matrix matrix =
                                        matrixVector.at(currentMatrixNumber) *
                                        (matrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            case 1: {
                                Matrix matrix =
                                        singleMatrixVector.at(currentMatrixNumber) *
                                        (singleMatrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                                break;
                            }
                            default:
                                Matrix matrix =
                                        matrixVector.at(currentMatrixNumber) *
                                        (matrixVector.at(operationMatrixNumber));
                                cout << matrix << endl;
                                cout << endl;
                        }
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
                if (checkInVector(currentMatrixNumber) && matrixCode != 2)
                    try {
                        switch (matrixCode) {
                            case 0:
                                cout << matrixVector.at(currentMatrixNumber).invert() << endl;
                                cout << endl;
                                break;
                            case 1: {
                                cout << singleMatrixVector.at(currentMatrixNumber).invert() << endl;
                                cout << endl;
                                break;
                            }
                            default: {
                                cout << singleMatrixVector.at(currentMatrixNumber).invert() << endl;
                                cout << endl;
                                break;
                            }
                        }
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
                    switch (matrixCode) {
                        case 0:
                            cout << matrixVector.at(currentMatrixNumber) << endl;
                            cout << endl;
                            break;
                        case 1: {
                            cout << singleMatrixVector.at(currentMatrixNumber) << endl;
                            cout << endl;
                            break;
                        }
                        case 2: {
                            cout << rectangleMatrixVector.at(currentMatrixNumber) << endl;
                            cout << endl;
                        }
                        default: {
                            cout << matrixVector.at(currentMatrixNumber).invert() << endl;
                            cout << endl;
                            break;
                        }
                    }
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case DETERMINANT_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber) && matrixCode != 2) {
                    switch (matrixCode) {
                        case 0:
                            cout << matrixVector.at(currentMatrixNumber).getDeterminant() << endl;
                            cout << endl;
                            break;
                        case 1: {
                            cout << singleMatrixVector.at(currentMatrixNumber).getDeterminant() << endl;
                            cout << endl;
                            break;
                        }
                        default: {
                            cout << matrixVector.at(currentMatrixNumber).getDeterminant() << endl;
                            cout << endl;
                            break;
                        }
                    }
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case NEW_INPUT_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber)) {
                    switch (matrixCode) {
                        case 2: {
                            RectangleMatrix *matrix = &rectangleMatrixVector.at(currentMatrixNumber);
                            cin >> *matrix;
                            break;
                        }
                        case 0: {
                            Matrix *matrix = &matrixVector.at(currentMatrixNumber);
                            cin >> *matrix;
                            break;
                        }
                        case 1: {
                            SingleMatrix *matrix = &singleMatrixVector.at(currentMatrixNumber);
                            cin >> *matrix;
                            break;
                        }
                        default:
                            Matrix *matrix = &matrixVector.at(currentMatrixNumber);
                            cin >> *matrix;
                    }
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case OUTPUT_IN_FILE_CODE: {
                ofstream file(FILE_NAME, ios::out);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                if (counter != 0) {
                    file << counter << "\n";
                    switch (matrixCode) {
                        case 2: {
                            for (auto &matrix : rectangleMatrixVector) {
                                file << matrix;
                            }
                            break;
                        }
                        case 0: {
                            for (auto &matrix : matrixVector) {
                                file << matrix;
                            }
                            break;
                        }
                        case 1: {
                            for (auto &matrix : singleMatrixVector) {
                                file << matrix;
                            }
                            break;
                        }
                        default:
                            for (auto &matrix : matrixVector) {
                                file << matrix;
                            }
                    }
                } else cout << "  Empty!  " << endl;
                file.close();
                break;
            }
            case INPUT_FROM_FILE_CODE: {
                ifstream file(FILE_NAME, ios::in);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                int fileCounter;
                file >> fileCounter;
                switch (matrixCode) {
                    case 2: {
                        for (int i = 0; i < fileCounter; i++) {
                            RectangleMatrix matrix;
                            file >> matrix;
                            rectangleMatrixVector.push_back(matrix);
                        }
                        break;
                    }
                    case 0: {
                        for (int i = 0; i < fileCounter; i++) {
                            Matrix matrix;
                            file >> matrix;
                            matrixVector.push_back(matrix);
                        }
                        break;
                    }
                    case 1: {
                        for (int i = 0; i < fileCounter; i++) {
                            SingleMatrix matrix;
                            file >> matrix;
                            singleMatrixVector.push_back(matrix);
                        }
                        break;
                    }
                    default:
                        for (int i = 0; i < fileCounter; i++) {
                            Matrix matrix;
                            file >> matrix;
                            matrixVector.push_back(matrix);
                        }
                }
                counter += fileCounter;
                file.close();
                break;
            }
            case OUTPUT_IN_BINARY_FILE_CODE: {
                ofstream file(BINARY_FILE_NAME, ios::binary | ios::out);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                if (counter != 0) {
                    file.write((char *) &counter, sizeof(int));
                    switch (matrixCode) {
                        case 2: {
                            for (auto &matrix : rectangleMatrixVector) {
                                matrix.outputInBinaryFile(file);
                            }
                            break;
                        }
                        case 0: {
                            for (auto &matrix : matrixVector) {
                                matrix.outputInBinaryFile(file);
                            }
                            break;
                        }
                        case 1: {
                            for (auto &matrix : singleMatrixVector) {
                                matrix.outputInBinaryFile(file);
                            }
                            break;
                        }
                        default:
                            for (auto &matrix : matrixVector) {
                                matrix.outputInBinaryFile(file);
                            }
                    }
                } else cout << "  Empty!  " << endl;
                file.close();
                break;
            }
            case INPUT_FROM_BINARY_FILE_CODE: {
                ifstream file(BINARY_FILE_NAME, ios::binary | ios::in);
                if (!file) {
                    cout << OPEN_FILE_ERROR << endl;
                    break;
                }
                int fileCounter;
                file.read((char *) &fileCounter, sizeof(int));
                switch (matrixCode) {
                    case 2: {
                        for (int i = 0; i < fileCounter; i++) {
                            RectangleMatrix matrix = RectangleMatrix::inputFromBinaryFile(file);
                            rectangleMatrixVector.push_back(matrix);
                        }
                        break;
                    }
                    case 0: {
                        for (int i = 0; i < fileCounter; i++) {
                            Matrix matrix = Matrix::inputFromBinaryFile(file);
                            matrixVector.push_back(matrix);
                        }
                        break;
                    }
                    case 1: {
                        for (int i = 0; i < fileCounter; i++) {
                            SingleMatrix matrix = SingleMatrix::inputFromBinaryFile(file);
                            singleMatrixVector.push_back(matrix);
                        }
                        break;
                    }
                    default:
                        for (int i = 0; i < fileCounter; i++) {
                            Matrix matrix = Matrix::inputFromBinaryFile(file);
                            matrixVector.push_back(matrix);
                        }
                }
                counter += fileCounter;
                file.close();
                break;
            }
            case GET_MATRIX_CODE: {
//                cout << "input Matrix number" << endl;
//                cin >> currentMatrixNumber;
//                if (checkInVector(currentMatrixNumber)) {
//                    int i, j;
//                    cout << "input i and j";
//                    cin >> i >> j;
//                    Matrix &matrix = rectangleMatrixVector.at(currentMatrixNumber);
//                    //double d = matrix->operator[](i).operator[](j);
//                    double c = matrix[i][j];
//                    cout << "c = " << c << endl;
//                    matrix[i][j] = 1.2345;
//                    cout << matrix[i][j] << endl;
//                } else
//                    cout << INPUT_ERROR_TEXT;
//                break;
            }
            case RESIZE_CODE: {
                cout << "input Matrix number" << endl;
                cin >> currentMatrixNumber;
                if (checkInVector(currentMatrixNumber)) {
                    int newColumn, newRow;
                    switch (matrixCode) {
                        case 2: {
                            cin >> newColumn >> newRow;
                            RectangleMatrix *matrix;
                            matrix = &rectangleMatrixVector.at(currentMatrixNumber);
                            cout << matrix->resize(newColumn, newRow) << endl;
                            cout << endl;
                            break;
                        }
                        case 0: {
                            cin >> newColumn;
                            Matrix *matrix;
                            matrix = &matrixVector.at(currentMatrixNumber);
                            cout << matrix->resize(newColumn) << endl;
                            cout << endl;
                            break;
                        }
                        case 1: {
                            cin >> newColumn;
                            SingleMatrix *matrix;
                            matrix = &singleMatrixVector.at(currentMatrixNumber);
                            cout << matrix->resize(newColumn) << endl;
                            cout << endl;
                            break;
                        }
                        default:
                            cin >> newColumn;
                            Matrix *matrix;
                            matrix = &matrixVector.at(currentMatrixNumber);
                            cout << matrix->resize(newColumn) << endl;
                            cout << endl;
                            break;
                    }
                } else
                    cout << INPUT_ERROR_TEXT;
                break;
            }
            case ADD_NEW_MATRIX_CODE: {
                cout << INPUT_TEXT << endl;
                switch (matrixCode) {
                    case 2: {
                        RectangleMatrix matrix;
                        cin >> matrix;
                        rectangleMatrixVector.push_back(matrix);
                        break;
                    }
                    case 0: {
                        Matrix matrix;
                        cin >> matrix;
                        matrixVector.push_back(matrix);
                        break;
                    }
                    case 1: {
                        SingleMatrix matrix;
                        cin >> matrix;
                        singleMatrixVector.push_back(matrix);
                        break;
                    }
                    default:
                        Matrix matrix;
                        cin >> matrix;
                        matrixVector.push_back(matrix);
                }
                counter++;
                break;
            }
            case OUTPUT_ALL_CODE: {
                if (counter != 0) {
                    int j = 0;
                    switch (matrixCode) {
                        case 2: {
                            for (auto &matrix : rectangleMatrixVector) {
                                cout << j << endl;
                                cout << matrix << endl;
                                j++;
                            }
                            break;
                        }
                        case 0: {
                            for (auto &matrix : matrixVector) {
                                cout << j << endl;
                                cout << matrix << endl;
                                j++;
                            }
                            break;
                        }
                        case 1: {
                            for (auto &matrix : singleMatrixVector) {
                                cout << j << endl;
                                cout << matrix << endl;
                                j++;
                            }
                            break;
                        }
                        default:
                            for (auto &matrix : matrixVector) {
                                cout << j << endl;
                                cout << matrix << endl;
                                j++;
                            }
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
