//
// Created by Marti on 11/17/2023.
//

#ifndef CPP_TEST_HEAP_H
#define CPP_TEST_HEAP_H

#include <queue>

template <class T, class TPrioridad = int>
class Heap {
public:
    Heap() {};
    virtual ~Heap() {};

    void agregar(T dato, TPrioridad prioridad) {
        ParPrioridadDato par;
        par.first = prioridad;
        par.second= dato;
        h2.push(par);
    };

    T extraer(){
        ParPrioridadDato par = h2.top();
        h2.pop();
        return par.second;
    }

    bool vacia() {
        return h2.empty();
    }

private:
    typedef std::pair<TPrioridad, T> ParPrioridadDato; // Prioridad, orden

    class ComparePrioridad {
    public:
        bool operator() (ParPrioridadDato a, ParPrioridadDato b) {
            return a.first > b.first;
        }
    };
    std::priority_queue<ParPrioridadDato, std::vector<ParPrioridadDato>, ComparePrioridad> h2;
};

#endif //CPP_TEST_HEAP_H
