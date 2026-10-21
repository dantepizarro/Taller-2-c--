#include "ListaServicios.hpp"
#include <iostream>
using namespace std;

ListaServicios::ListaServicios() : frente(nullptr), final(nullptr), tamaño(0) {
    string nombres[8] = {"Urgencias", "Medicina General", "Cardiologia", "Neurologia", "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"};
    string* ptr = nombres;
    for(int i = 0; i <8; i++){
        if(final == nullptr){
            frente = new NodoServicio(*ptr);
            final = frente;

        }else{
            final->siguiente = new NodoServicio(*ptr);
            final = final->siguiente;
        }
        tamaño++;
        ptr++;
    }
}

ListaServicios::~ListaServicios() {
    NodoServicio* actual = frente;
    while(actual != nullptr){
        NodoServicio* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

NodoServicio* ListaServicios::buscarServicio(string nombre){
    NodoServicio* actual = frente;
    while(actual != nullptr){
        if(actual->nombre == nombre){
            return actual;
        }
        actual = actual->siguiente;

    }
    return nullptr;
}

void ListaServicios::insertar(string nombre, Paciente* paciente){
    NodoServicio* servicio = buscarServicio(nombre);
    if(servicio != nullptr){
        servicio->pacientes.encolar(paciente);
    }else{
        cout << "Servicio no encontrado: " << nombre << endl;
    }
}

