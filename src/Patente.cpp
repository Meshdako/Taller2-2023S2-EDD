//
// Created by Marti on 11/15/2023.
//

#include "../include/Patente.h"

Patente::Patente()
{
    _tipoPatente = "";
    _valorPatente = 0;
    _fueProcesado = false;
}

Patente::Patente(string aa, RUT bb, string cc, string dd, string ee, Fecha a, string b, int c, bool d) : Empresa(aa, bb, cc, dd, ee)
{
    _fechaPatente = a;
    _tipoPatente = b;
    _valorPatente = c;
    _fueProcesado = d;
    indice = ++contadorGlobal;
}

int Patente::contadorGlobal = 0;

void Patente::verPatente()
{
    cout << "======== Patente #" << indice << " ========\n";
    verEmpresa();
    _fechaPatente.verFecha();
    cout << "\tTipo Patente: " << _tipoPatente << endl;
    cout << "\tValor Patente: " << _valorPatente << endl;

    cout << "\t¿Fue Procesado? " << (_fueProcesado ? "Sí" : "No") << "\n";
}

void Patente::verRRN()
{
    cout << "======== Patente #" << indice << " ========\n";
    verRolRutNombre();
}

