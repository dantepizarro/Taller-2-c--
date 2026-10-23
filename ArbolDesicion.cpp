#include "ArbolDesicion.hpp"
#include <iostream>

using namespace std;

ArbolDecision::ArbolDecision() : raiz(nullptr) {}

ArbolDecision::~ArbolDecision() {
    delete raiz;
}

bool ArbolDecision::responder(int pregunta, const Paciente& p){
    switch(pregunta){
        case 1: return p.getEdad() < 14;
        case 2: return p.getTrauma();
        case 3: return p.getRequiereCirugia();
        case 4: return p.getSintomasNeurologicos();
        case 5: return p.getTipoDolor() == "pecho";
        case 6: return p.getTemperatura() >= 38.5 || p.getDolor() >= 8 || p.getPresionArterial() < 90 || p.getPresionArterial() > 180;
        case 7: return p.getDiasHospitalizacion() >= 2;

    }
    return false;
}

void ArbolDecision::construir(){
    delete raiz;

    NodoDecision* hospitalizacion = new NodoDecision(7,"DiasHospitalizacion >= 2", "DiasHospitalizacion < 2", new NodoDecision("Hospitalizacion"), new NodoDecision("Medicina General"));

    NodoDecision* urgencia = new NodoDecision(6, "Temperatura >= 38.5, Dolor >= 8 o Presion critica", "Temperatura < 38.5, Dolor < 8 y presion normal", new NodoDecision("Urgencias"),hospitalizacion);

    NodoDecision* pecho = new NodoDecision(5,"TipoDolor == pecho", "TipoDolor != pecho", new NodoDecision("Cardiologia"), urgencia);

    NodoDecision* neurologico = new NodoDecision(4, "SintomasNeurologicos == 1", "SintomasNeurologicos == 0", new NodoDecision("Neurologia"), pecho);

    NodoDecision* cirugia = new NodoDecision(3, "RequiereCirugia == 1", "RequiereCIrugia == 0", new NodoDecision("Cirugia"), new NodoDecision("Traumatologia"));

    NodoDecision* trauma = new NodoDecision(2, "Trauma == 1", "Trauma == 0", cirugia, neurologico);

    raiz = new NodoDecision(1, "Edad < 14", "Edad >= 14", new NodoDecision("Pediatria"), trauma);
}

string ArbolDecision::evaluar(const Paciente& p, string& ruta){
    ruta = "";
    if(raiz == nullptr){
        return "Sin Asignar";
    }

    NodoDecision* actual = raiz;
    while(actual->pregunta != 0){
        if(!ruta.empty()){
            ruta += "->";
        }
        if(responder(actual->pregunta, p)){
            ruta += actual->textoSi;
            actual = actual ->si;
        }else {
            ruta += actual->textoNo;
            actual = actual->no;
        }

        
    }

    return actual->servicio;
}

void ArbolDecision::ImprimirNodo(NodoDecision* nodo, int nivel){
    for(int i = 0; i < nivel; i++){
        cout << " ";
    }
    if(nodo->pregunta == 0){
        cout << nodo->servicio << endl;
    }else{
        cout << nodo->textoSi << "?" << endl;
    }
}

void ArbolDecision::RecorrerPreorden(NodoDecision* nodo, int nivel){
    if(nodo == nullptr) return;
    ImprimirNodo(nodo, nivel);
    RecorrerPreorden(nodo->si, nivel +1);
    RecorrerPreorden(nodo->no, nivel +1);
}

void ArbolDecision::RecorrerInorden(NodoDecision* nodo, int nivel){
    if(nodo == nullptr) return;
    RecorrerInorden(nodo->si, nivel + 1);
    ImprimirNodo(nodo, nivel);
    RecorrerInorden(nodo->no, nivel + 1);
}

void ArbolDecision::RecorrerPostOrden(NodoDecision* nodo, int nivel){
    if(nodo == nullptr) return;
    RecorrerPostOrden(nodo->si, nivel + 1);
    RecorrerPostOrden(nodo->no, nivel + 1);
    ImprimirNodo(nodo,nivel);
}

void ArbolDecision::mostrarPreorden(){
    cout << "Recorrido preorden" << endl;
    RecorrerPreorden(raiz, 0);
}

void ArbolDecision::mostrarInOrden(){
    cout << "Recorrido inorden" << endl;
    RecorrerInorden(raiz,0);
}

void ArbolDecision::mostrarPostOrden(){
    cout << "Recorrido postorden" << endl;
    RecorrerPostOrden(raiz,0);
}
