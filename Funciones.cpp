//
// Created by Marti on 11/15/2023.
//

#include "Funciones.h"
// ==== FUNCIÓN 7 ====;
// ==== FUNCIÓN 6 ====;
void archivoSalida(queue<Patente> &myNewQueue)
{
    string salida = "salida1.txt";

    ofstream archivoDeSalida(salida);
    archivoDeSalida << "ROL; RUT; NOMBRE; DIRECCIÓN COMERCIAL; GIRO; FECHA OTORGAMIENTO; TIPO PATENTE; VALOR PATENTE; PROCESADO" << endl;

    if (archivoDeSalida.is_open()) {
        while (!myNewQueue.empty()) {
            archivoDeSalida << myNewQueue.front().getRol() << ";" << myNewQueue.front().getRut().getRun() << "-" << myNewQueue.front().getRut().getDv()<< ";" << myNewQueue.front().getNombre()<< ";" << myNewQueue.front().getDireccion()<< ";" << myNewQueue.front().getFecha().getDia()<< "-" << myNewQueue.front().getFecha().getMes() << "-" << myNewQueue.front().getFecha().getAnho() << ";" << myNewQueue.front().getTipoPatente() << ";" << myNewQueue.front().getValorPatente() << ";" << (myNewQueue.front().getFueProcesado() ? "Si" : "No") << endl;
            myNewQueue.pop();
        }
        archivoDeSalida.close();
    }
}

void ordenarCola(queue<Patente> &myNewQueue)
{
    Heap<Patente, int> myPriorityQueue;

    while (!myNewQueue.empty()) {
        myPriorityQueue.agregar(myNewQueue.front(), myNewQueue.front().getRut().getRun());
        myNewQueue.pop();
    }

    while (!myPriorityQueue.vacia()) {
        myNewQueue.push(myPriorityQueue.extraer());
    }
}

void generacionDeArchivos(queue<Patente> &myQueue)
{
    // Ordenar la cola
    queue<Patente> Aux, myNewQueue;
    Patente miPatente;

    while(!myQueue.empty()) {
        miPatente = myQueue.front();
        myQueue.pop();

        myNewQueue.push(miPatente);

        Aux.push(miPatente);
    }

    ordenarCola(myNewQueue);
    archivoSalida(myNewQueue);

    // Volvemos a ingresar la información...
    while(!Aux.empty()) {
        myQueue.push(Aux.front());
        Aux.pop();
    }
}

// ==== FUNCIÓN 5 ====;
void consultaPorAnioyPatente(queue<Patente> &myQueue, int _anioIngresado, string _patenteIngresada)
{
    queue<Patente> Aux;
    Patente miPatente;

    while(!myQueue.empty()) {
        miPatente = myQueue.front();
        myQueue.pop();

        if (_anioIngresado == miPatente.getFecha().getAnho() && _patenteIngresada == miPatente.getTipoPatente()) {
            miPatente.verRRN();
        }

        Aux.push(miPatente);
    }

    // Volvemos a ingresar la información...
    while(!Aux.empty()) {
        myQueue.push(Aux.front());
        Aux.pop();
    }
}
// ==== FUNCIÓN 4 ====;

// ==== FUNCIÓN 3 ====;
void anhioConMasPatentesDeAlcoholes(queue<Patente> &myQueue)
{
    queue<Patente> Aux;
    Patente miPatente;

    int cont = 0;
    int Anhios[3000] = {0};

    while(!myQueue.empty()) {
        miPatente = myQueue.front();
        myQueue.pop();

        if (miPatente.getTipoPatente() == "ALCOHOLES") {
            Anhios[miPatente.getFecha().getAnho()]++;
        }
        Aux.push(miPatente);
    }

    int mayor = 0;
    int posicion = 0;

    for (int i = 0; i < 2025; i++) {
        if (Anhios[i] > mayor) {
            mayor = Anhios[i];
            posicion = i;
        }
    }

    cout << "El año con más patentes de ALCOHOLES es " << posicion << " con " << mayor << " patentes." << endl;

    // Volvemos a ingresar la información...
    while(!Aux.empty()) {
        myQueue.push(Aux.front());
        Aux.pop();
    }
}

// ==== FUNCIÓN 2 ====;
void actualizarDigitoVerificador(queue<Patente> &myQueue)
{
    queue<Patente> Aux;
    Patente miPatente;

    int contador = 0;

    while(!myQueue.empty()) {
        miPatente = myQueue.front();
        myQueue.pop();

        string old_dv = miPatente.getRut().getDv();
        miPatente.getRut().calcular_dv();

        if (old_dv != miPatente.getRut().getDv()) {
            contador++;
            cout << "Actualizado RUN: " << miPatente.getRut().getRun() << endl;
            cout << "DV Antiguo: " << old_dv << " // DV Nuevo: " << miPatente.getRut().getDv() << endl;
        }
        Aux.push(miPatente);
    }

    // Volvemos a ingresar la información...
    while(!Aux.empty()) {
        myQueue.push(Aux.front());
        Aux.pop();
    }

    cout << "Actualizados " << contador << " Digitos Verificadores" <<  endl;
}

// ==== FUNCIÓN 1 ====;
int valorAleatorio(int a, int b)
{
    std::random_device rd;
    std::mt19937 generador(rd());

    uniform_int_distribution<int> distribucion(a, b);

    return distribucion(generador);
}

int tipoPatente(Patente miPatente)
{
    if (miPatente.getTipoPatente() == "MICROEMPRESA")
        return valorAleatorio(1, 5);
    else if (miPatente.getTipoPatente() == "PROFESIONAL")
        return valorAleatorio(2, 6);
    else if (miPatente.getTipoPatente() == "INDUSTRIALES")
        return valorAleatorio(3, 7);
    else if (miPatente.getTipoPatente() == "COMERCIALES")
        return valorAleatorio(4, 8);
    else // Si no es ninguna de las anteriores, es ALCOHOLES
        return valorAleatorio(5, 10);
}

void completarValorPatente(queue<Patente> &myQueue)
{
    queue<Patente> Aux;
    Patente miPatente;

    while(!myQueue.empty()) {
        miPatente = myQueue.front();
        myQueue.pop();

        miPatente.setValorPatente(tipoPatente(miPatente));

        Aux.push(miPatente);
    }

    // Mostramos la información en pantalla.
    // mostrarPatentes(Aux);

    // Volvemos a ingresar la información...
    while(!Aux.empty()) {
        myQueue.push(Aux.front());
        Aux.pop();
    }
}

void mostrarPatentes(queue<Patente> myQueue)
{
    cout << "LO LOGRAMOS" << endl;
    while(!myQueue.empty()) {
        myQueue.front().verPatente();
        myQueue.pop();
    }
}

void leerDatos(std::string nombreArchivo, queue<Patente> &myQueue, int &indice)
{
    std::string lineaObtenida;
    std::string palabra;

    if (std::filesystem::exists(nombreArchivo)) {
        std::ifstream archivo(nombreArchivo, std::ios::binary);

        while (getline(archivo, lineaObtenida, '\n')){
            // ahora recorremos la línea
            std::vector<std::string> data = split(lineaObtenida, ';');

            if (indice > 0){

                // Leemos el RUT
                std::stringstream ss(data[1]);
                string str_run, digitoVerificador;

                getline(ss, str_run, '-');
                getline(ss, digitoVerificador);

                ss.clear();

                // Leemos la fecha
                ss.str(data[5]);
                string dia, mes, anio;

                getline(ss, dia, '-');
                getline(ss, mes, '-');
                getline(ss, anio);

                ss.clear();

                // CAMBIAR DIRECCION POR DIRECCION COMERCIAL
                // ROL;RUT;NOMBRE;DIRECCIÓN COMERCIAL;GIRO;FECHA OTORGAMIENTO;TIPO PATENTE

                Patente Aux(data[0], RUT(stoi(str_run), digitoVerificador), data[2], data[3], data[4], Fecha(stoi(dia), stoi(mes), stoi(anio)), data[6], 0, false);
                myQueue.push(Aux);
            }
            indice++;
        }

        std::cout << "¡Archivos cargados con éxito!!" << std::endl;
        archivo.close();
    } else {
        std::cerr << "Error: El archivo no existe - " << nombreArchivo << std::endl;
    }
}

std::vector<std::string> split(std::string lineaASeparar, char delimitador)
{
    std::vector<std::string> vector_interno;     //#include <vector>
    std::stringstream linea(lineaASeparar); //#include <sstream>
    std::string parteDelString;

    while (getline(linea, parteDelString, delimitador))
        vector_interno.push_back(parteDelString);

    return vector_interno;
}