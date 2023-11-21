#include <iostream>
#include <queue>

#include "../include/Funciones.h"

#include "../include/Patente.h"
#include "../include/Empresa.h"
#include "../include/Fecha.h"
#include "../include/RUT.h"

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

    estadisticasDescriptivas(myQueue, 63960);

    /*
    cout << "Ingrese valor UTM del mes actual: ";
    cin >> */
    return 0;
}
