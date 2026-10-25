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
        servicio->pacientes.insertar(paciente);
    }else{
        cout << "Servicio no encontrado: " << nombre << endl;
    }
}

Paciente* ListaServicios::buscarPorID(const std::string& id, std::string& ruta) {
    NodoServicio* actual = frente;
    while (actual != nullptr) {
        Paciente* paciente = actual->pacientes.buscarPorID(id, ruta);
        if (paciente != nullptr) {
            return paciente;
        }
        actual = actual->siguiente;
    }
    ruta = "";
    return nullptr;
}

Paciente* ListaServicios::buscarPorNombre(const std::string& nombre) {
    NodoServicio* actual = frente;
    while (actual != nullptr) {
        Paciente* paciente = actual->pacientes.buscarPorNombre(nombre);
        if (paciente != nullptr) {
            return paciente;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaServicios::mostrarEstado() {
    cout << "=== ESTADO DE LOS DEPARTAMENTOS ===" << endl;
    NodoServicio* actual = frente;
    while (actual != nullptr) {
        cout << actual->nombre << endl;
        
        if (actual->pacientes.estaVacio()) {
            cout << "Sin pacientes\n" << endl;
        } else {
            actual->pacientes.mostrarResumen();
            cout << endl; 
        }
        
        actual = actual->siguiente;
    }
}