//
// Created by Marti on 11/15/2023.
//

#include "RUT.h"

RUT::RUT()
{
    _run = 0;
    _dv = "0";
}

RUT::RUT(int a, string b)
{
    _run = a;
    _dv = b;
}

void RUT::calcular_dv()
{
    int run = _run;
    int suma = 0;
    for(int j = 2; run > 0; run /= 10, j++) {
        if(j > 7) {
            j = 2;
        }

        suma += (run % 10) * j;
    }

    int resto = suma / 11;
    resto *= 11;

    suma -= resto;
    suma = 11 - suma;

    std::string dv_calculado;

    if(suma == 11)
        dv_calculado = '0';
    else if(suma == 10)
        dv_calculado = 'k';
    else
        dv_calculado = std::to_string(suma);

    _dv = dv_calculado[0];
}

void RUT::verRun()
{
    cout << "\tRUT: " << _run << "-" << _dv << endl;
}
