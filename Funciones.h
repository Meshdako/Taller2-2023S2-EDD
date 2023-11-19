//
// Created by Marti on 11/15/2023.
//

#ifndef CPP_TEST_FUNCIONES_H
#define CPP_TEST_FUNCIONES_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include <fstream>
#include <limits>       //relacionada a los límites de valores
#include <cstdlib>
#include <ctime>
#include <random>
#include <cctype>
#include <set>
#include <stack>
#include <queue>

#include "Patente.h"
#include "Empresa.h"
#include "Fecha.h"
#include "RUT.h"

#include "Heap.h"

using namespace std;

// Funciones
void generacionDeArchivos(queue<Patente> &myQueue);
void consultaPorAnioyPatente(queue<Patente> &myQueue, int _anioIngresado, string _patenteIngresada);
void anhioConMasPatentesDeAlcoholes(queue<Patente> &myQueue);
void actualizarDigitoVerificador(queue<Patente> &myQueue);
void completarValorPatente(queue<Patente> &myQueue);

void mostrarPatentes(queue<Patente> myQueue);

// Función de lectura de datos
void leerDatos(std::string nombreArchivo, queue<Patente> &myQueue, int &indice);

std::vector<std::string> split(std::string, char);

#endif //CPP_TEST_FUNCIONES_H
