//
// Created by Marti on 11/15/2023.
//

#ifndef CPP_TEST_FECHA_H
#define CPP_TEST_FECHA_H

#include <iostream>

using namespace std;

class Fecha {
private:
    int _dd, _mm, _aa;
public:
    Fecha();
    Fecha(int, int, int);

    void setDia(int x){ _dd = x; }
    void setMes(int x){ _mm = x; }
    void setAnho(int x){ _aa = x; }

    int getDia(){ return _dd; }
    int getMes(){ return _mm; }
    int getAnho(){ return _aa; }

    void verFecha();
};


#endif //CPP_TEST_FECHA_H
