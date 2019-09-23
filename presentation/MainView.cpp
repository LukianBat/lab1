#include <iostream>
#include "MainView.h"

using namespace std;


void MainView::startInput() {
    cout << "index = ";
    cin >> this->matrixIndex;
    int index = matrixIndex;
    cout << "values = ";
    int **values = new int *[index];
    for (int i = 0; i < index; i++) {
        values[i] = new int[index];
    }
    for (int i = 0; i < index; i++)
        for (int j = 0; j < index; j++) {
            cin >> values[i][j];
        }
    presenter->setMatrix(index, values);
    presenter->sumMatrix(values);
    printResult();

}

MainView::MainView(MainPresenter *presenter) {
    this->presenter = presenter;
    startInput();
}

void MainView::printResult() {
    int index = 2;
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index; j++) {
            cout << presenter->getMatrix()[i][j] << " ";
        }
        cout << endl;
    }
    exit(0);
}

MainView::~MainView() {
    delete presenter;
    matrixIndex = NULL;

}

