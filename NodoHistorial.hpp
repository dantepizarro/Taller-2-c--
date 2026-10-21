#pragma once
#include <string>
using namespace std;
struct NodoHistorial {
    string evento;
    NodoHistorial* siguiente;

    NodoHistorial(string evento) : evento(evento), siguiente(nullptr) {}; 
};