//
// Created by Marti on 11/15/2023.
//

#include "../include/Fecha.h"

Fecha::Fecha()
{
    _dd = 0;
    _mm = 0;
    _aa = 0;
}

Fecha::Fecha(int a, int b, int c)
{
    _dd = a;
    _mm = b;
    _aa = c;
}

void Fecha::verFecha()
{
    cout << "\t" << _dd << "/" << _mm << "/" << _aa << endl;
}