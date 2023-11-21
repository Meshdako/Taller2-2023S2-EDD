//
// Created by Marti on 11/15/2023.
//

#ifndef CPP_TEST_RUT_H
#define CPP_TEST_RUT_H

#include <iostream>

using namespace std;

class RUT {
private:
    int _run;
    string _dv;

public:
    RUT();
    RUT(int, string);

    void setRun(int x){ _run = x; }
    void setDv(string x){ _dv = x; }

    int getRun(){ return _run; }
    string getDv(){ return _dv; }

    void calcular_dv();
    void verRun();
};


#endif //CPP_TEST_RUT_H
