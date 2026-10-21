#include "PilaHistorial.hpp"
#include <iostream>
using namespace std;

PilaHistorial::PilaHistorial() : tope(nullptr), tamano(0) {}

PilaHistorial::~PilaHistorial() {
    while (!estaVacia()){
        NodoHistorial* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
}

void PilaHistorial::apilar(string evento){
    NodoHistorial* nuevoNodo = new NodoHistorial(evento);
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
    tamano++;
}
void PilaHistorial::mostrarHistorial(){
    if(estaVacia()){
        cout << "No hay eventos en el historial" << endl;
        return;
    }
    NodoHistorial* actual = tope;
    int contador = 1;
    while(actual != nullptr){
        cout << actual->evento << endl;
        actual = actual->siguiente;
        contador++;
    }
}

bool PilaHistorial::estaVacia(){
    return tope == nullptr;
}

int PilaHistorial::getTamano(){
    return tamano;
}