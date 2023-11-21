//
// Created by Marti on 11/15/2023.
//

#include "../include/Funciones.h"

// ==== EXTRA ====;
template <class CharT, bool International = false>
class my_moneypunct;

template <class CharT, bool International = false>
class my_moneypunct_byname : public std::moneypunct_byname<CharT, International>
{
    friend class my_moneypunct<CharT, International>;
    using std::moneypunct_byname<CharT, International>::moneypunct_byname;
};

template <class CharT, bool International>
class my_moneypunct : public std::moneypunct_byname<CharT, International>
{
    my_moneypunct_byname<CharT, International> other_moneypunct;
public:
    explicit my_moneypunct(const char* myName, const char* otherName, std::size_t refs = 0) :
            std::moneypunct_byname<CharT, International>(myName, refs), other_moneypunct(otherName, refs) {}
    typename std::moneypunct_byname<CharT, International>::string_type do_curr_symbol() const override {
        return other_moneypunct.do_curr_symbol();
    }
    virtual ~my_moneypunct() = default;
};

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

void mediana(vector<std::string> &tP, queue<Patente> &myQueue, int valorUTM)
{
    queue<Patente> Aux;
    Patente miPatente;

    vector<double> valoresDePatentes;

    for (unsigned i = 0; i < tP.size(); i++) {
        cout << "Calculando Mediana por Tipo de Patente: " << tP[i] << endl;
        while(!myQueue.empty()) {
            miPatente = myQueue.front();
            myQueue.pop();

            if (tP[i] == miPatente.getTipoPatente()) {
                valoresDePatentes.push_back(miPatente.getValorPatente() * valorUTM);
            }

            Aux.push(miPatente);
        }

        sort(valoresDePatentes.begin(), valoresDePatentes.end());
        size_t tamanho = valoresDePatentes.size();

        cout << '\t';
        (tamanho == 0) ?
            cout << "La Mediana es 0" :
            (tamanho % 2 == 0) ?
                cout << "La Mediana es: " << valoresDePatentes[tamanho / 2 - 1] + valoresDePatentes[tamanho / 2] / 2.0 << endl :
                cout << "La Mediana es: " << valoresDePatentes[tamanho / 2] << endl;

        while(!Aux.empty()) {
            myQueue.push(Aux.front());
            Aux.pop();
        }
    }
}

double calcularMediaAritmetica(queue<Patente> &queueTemp, int valorUTM)
{
    int contador = 0;
    double suma = 0.0;

    while (!queueTemp.empty()) {
        suma += queueTemp.front().getValorPatente() * valorUTM;
        queueTemp.pop();
        contador++;
    }

    return (contador == 0) ? 0.0 : (suma / contador);
}

void mediaAritmetica(vector<std::string> &tP, queue<Patente> &myQueue, int valorUTM)
{
    queue<Patente> Aux, AuxTemp;
    Patente miPatente;

    int contador[5] = {0};
    int valoresDePatentes[5] = {0};

    for (unsigned i = 0; i < tP.size(); i++) {
        cout << "Calculando Media por Tipo de Patente: " << tP[i] << endl;
        while(!myQueue.empty()) {
            miPatente = myQueue.front();
            myQueue.pop();

            if (tP[i] == miPatente.getTipoPatente()) {
                AuxTemp.push(miPatente);
            }

            Aux.push(miPatente);
        }

        double X = calcularMediaAritmetica(AuxTemp, valorUTM);

        cout << "\tLa Media es: " << X << endl;

        while(!Aux.empty()) {
            myQueue.push(Aux.front());
            Aux.pop();
        }
    }
}

double calcularDesviacionEstandar(queue<Patente> &queueTemp, int valorUTM, double _mediaAritmetica)
{
    int contador = 0;
    double sumaDiferenciasCuadradas = 0.0;

    while (!queueTemp.empty()) {
        double diferencia = (queueTemp.front().getValorPatente() * valorUTM) - _mediaAritmetica;
        sumaDiferenciasCuadradas += diferencia * diferencia;
        queueTemp.pop();
        contador++;
    }

    double varianza = sumaDiferenciasCuadradas / contador;

    double dE = sqrt(varianza);

    return dE;
}

void desviacionEstandar(vector<std::string> &tP, queue<Patente> &myQueue, int valorUTM)
{
    queue<Patente> Aux, Temp_1, Temp_2;
    Patente miPatente;

    double _mediaAritmetica, sumaDiferenciasCuadradas = 0.0;

    for (unsigned i = 0; i < tP.size(); i++) {
        cout << "Calculando Desviación Estandar por Tipo de Patente: " << tP[i] << endl;
        while(!myQueue.empty()) {
            miPatente = myQueue.front();
            myQueue.pop();

            if (tP[i] == miPatente.getTipoPatente()) {
                Temp_1.push(miPatente);
                Temp_2.push(miPatente);
            }

            Aux.push(miPatente);
        }

        _mediaAritmetica = calcularMediaAritmetica(Temp_1, valorUTM);

        // Calculo de Desviación Estandar

        cout << "\tLa Desviación Estandar es: " << calcularDesviacionEstandar(Temp_2, valorUTM, _mediaAritmetica) <<  endl;

        while(!Aux.empty()) {
            myQueue.push(Aux.front());
            Aux.pop();
        }
    }
}


void mayorVariabilidad(queue<Patente> &myQueue, int valorUTM)
{
    queue<Patente> Aux, Temp_1, Temp_2;
    Patente miPatente;

    double CV[3];

    string girosDePatente[3] = { "BOTILLERIA", "MINIMERCADOS", "REST.DIURNO"};

    for (int i = 0; i < 3; i++) {
        while(!myQueue.empty()) {
            miPatente = myQueue.front();
            myQueue.pop();

            if (miPatente.getGiro() == girosDePatente[i]) {
                Temp_1.push(miPatente);
                Temp_2.push(miPatente);
            }

            Aux.push(miPatente);
        }
        double X = calcularMediaAritmetica(Temp_1, valorUTM);
        double S = calcularDesviacionEstandar(Temp_2, valorUTM, X);

        CV[i] = S/X;

        while(!Aux.empty()) {
            myQueue.push(Aux.front());
            Aux.pop();
        }
    }

    int posicion;
    double _mayorVariabilidad = 0.0;

    for(int i = 0; i < 3; i++) {
        if (CV[i] > _mayorVariabilidad) {
            _mayorVariabilidad = CV[i];
            posicion = i;
        }
    }

    cout << "La Mayor Variabilidad es de: " << girosDePatente[posicion] << " con una variabilidad de: " << _mayorVariabilidad <<  endl;
}

vector<std::string> tiposDePatentes(queue<Patente> &myQueue)
{
    vector<std::string> tP;

    queue<Patente> Aux, newAux;
    Patente miPatente;

    int valoresDePatentes[5] = {0};

    while(!myQueue.empty()) {
        miPatente = myQueue.front();
        myQueue.pop();

        tP.push_back(miPatente.getTipoPatente());

        Aux.push(miPatente);
    }

    set<string> string_set(tP.begin(), tP.end());
    tP.assign(string_set.begin(), string_set.end());

    // Volvemos a ingresar la información...
    while(!Aux.empty()) {
        myQueue.push(Aux.front());
        Aux.pop();
    }

    return tP;
}

void estadisticasDescriptivas(queue<Patente> &myQueue, int valorUTM)
{
    queue<Patente> Aux;
    Patente miPatente;

    vector<std::string> tP = tiposDePatentes(myQueue);

    int opcion;

    do {
        cout << "1. Calcualr Media Aritmética." << endl;
        cout << "2. Calcualr Mediana." << endl;
        cout << "3. Calcualr Desviación Estandar." << endl;
        cout << "4. Mayor Variabilidad." << endl;

        cin >> opcion;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;
            case 1:
                mediaAritmetica(tP, myQueue, valorUTM);
                break;
            case 2:
                mediana(tP, myQueue, valorUTM);
                break;
            case 3:
                desviacionEstandar(tP, myQueue, valorUTM);
                break;
            case 4:
                mayorVariabilidad(myQueue, valorUTM);
            default:
                break;
        }
    }while(opcion != 0);
}

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