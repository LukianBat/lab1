#ifndef LAB1_MAINVIEW_H

#define LAB1_MAINVIEW_H

#include "MainPresenter.h"

class MainView {
private:
    MainPresenter *presenter;
    int matrixIndex{};

    void startInput();

    void printResult();

public:

    explicit MainView(MainPresenter *presenter);

    ~MainView();
};

#endif
