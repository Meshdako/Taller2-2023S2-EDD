//
// Created by Marti on 11/15/2023.
//

#include "Empresa.h"

Empresa::Empresa()
{
    _rol = "";
    _nombre = "";
    _direccion = "";
    _giro = "";
}

Empresa::Empresa(string a, RUT b, string c, string d, string e)
{
    _rol = a;
    _rut = b;
    _nombre = c;
    _direccion = d;
    _giro = e;
}

void Empresa::verEmpresa()
{
    cout << "\tROL: " << _rol << endl;
    _rut.verRun();
    cout << "\tNombre: " << _nombre << endl;
    cout << "\tDireccion: " << _direccion << endl;
    cout << "\tGiro: " << _giro << endl;

}

void Empresa::verRolRutNombre()
{
    cout << "\tROL: " << _rol << endl;
    _rut.verRun();
    cout << "\tNombre: " << _nombre << endl;
}
