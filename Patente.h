//
// Created by Marti on 11/15/2023.
//

#ifndef CPP_TEST_PATENTE_H
#define CPP_TEST_PATENTE_H

#include <iostream>

#include "Empresa.h"
#include "Fecha.h"

class Patente : public Empresa {
private:
    Fecha _fechaPatente;
    string _tipoPatente;
    int _valorPatente;
    bool _fueProcesado;

    static int contadorGlobal;
    int indice;

public:
    Patente();
    Patente(string, RUT, string, string, string, Fecha, string, int, bool);

    void setFecha(Fecha x){ _fechaPatente = x; }
    void setTipoPatente(string x){ _tipoPatente = x; }
    void setValorPatente(int x){ _valorPatente = x; }
    void setFueProcesado(bool x){ _fueProcesado = x; }

    Fecha getFecha(){ return _fechaPatente; }
    string getTipoPatente(){ return _tipoPatente; }
    int getValorPatente(){ return _valorPatente; }
    bool getFueProcesado(){ return _fueProcesado; }

    void verPatente();
    void verRRN();
};


#endif //CPP_TEST_PATENTE_H
