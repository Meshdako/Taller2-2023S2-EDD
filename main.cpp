#include <iostream>
#include <stack>
#include <queue>

#include "Funciones.h"

#include "Patente.h"
#include "Empresa.h"
#include "Fecha.h"
#include "RUT.h"

using namespace std;

int main() {
    srand(time(0));

    queue<Patente> myQueue;
    int indice = 0;

    string archivoALeer= "patentesComerciales.txt";

    leerDatos(archivoALeer, myQueue, indice);

    // mostrarPatentes(myQueue);

    completarValorPatente(myQueue);
    actualizarDigitoVerificador(myQueue);
    anhioConMasPatentesDeAlcoholes(myQueue);
    // consultaPorAnioyPatente(myQueue, 2000, "ALCOHOLES");
    generacionDeArchivos(myQueue);
    return 0;
}
