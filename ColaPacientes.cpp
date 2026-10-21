#include "ColaPacientes.hpp"
#include <iostream>
using namespace std;
 
ColaPacientes::ColaPacientes() : frente(nullptr), final(nullptr), tamano(0) {}
 
ColaPacientes::~ColaPacientes() {
    NodoCola* actual = frente;
    while (actual != nullptr) {
        NodoCola* siguiente = actual->siguiente;
        delete actual->paciente;
        delete actual;
        actual = siguiente;
    }
}
 
void ColaPacientes::encolar(Paciente* p) {
    NodoCola* nuevo = new NodoCola(p);
    if (final == nullptr) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    tamano++;
}
 
Paciente* ColaPacientes::desencolar() {
    if (estaVacia()) {
        return nullptr;
    }
    NodoCola* temp = frente;
    Paciente* p = temp->paciente;
 
    frente = frente->siguiente;
    if (frente == nullptr) {
        final = nullptr;
    }
 
    delete temp;
    tamano--;
    return p;
}
 
bool ColaPacientes::estaVacia() {
    return frente == nullptr;
}
 
int ColaPacientes::getTamano() {
    return tamano;
}
 
void ColaPacientes::mostrar() {
    if (estaVacia()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }
    NodoCola* actual = frente;
    int contador = 1;
    while (actual != nullptr) {
        cout << contador << ". " << actual->paciente->getId()
             << " - " << actual->paciente->getNombre() << endl;
        actual = actual->siguiente;
        contador++;
    }
}

bool ColaPacientes::existeID(string id) {
    NodoCola* actual = frente;
    while (actual != nullptr) {
        if(actual->paciente->getId() == id) {
            return true;

        }
        actual = actual->siguiente;
    }
    return false;
}

