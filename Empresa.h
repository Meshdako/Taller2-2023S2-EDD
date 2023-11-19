//
// Created by Marti on 11/15/2023.
//

#ifndef CPP_TEST_EMPRESA_H
#define CPP_TEST_EMPRESA_H

#include <iostream>

#include "RUT.h"

using namespace std;

class Empresa {
private:
    string _rol;
    RUT _rut;
    string _nombre;
    string _direccion;
    string _giro;

public:
    Empresa();
    Empresa(string, RUT, string, string, string);

    void setRol(string x){ _rol = x; }
    void setRut(RUT x) { _rut = x; }
    void setNombre(string x) { _nombre = x; }
    void setDireccion(string x) { _direccion = x; }
    void setGiro(string x) { _giro = x; }

    string getRol(){ return _rol; }
    RUT getRut() { return _rut; }
    string getNombre() { return _nombre; }
    string getDireccion() { return _direccion; }
    string getGiro() { return _giro; }

    void verEmpresa();
    void verRolRutNombre();
};

#endif //CPP_TEST_EMPRESA_H
