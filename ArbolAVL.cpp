#include "ArbolAVL.hpp"


using namespace std;

ArbolAVL::ArbolAVL() : raiz(nullptr) {}
ArbolAVL::~ArbolAVL() {
    destruirArbol(raiz);
}



void ArbolAVL::destruirArbol(NodoAVL* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->izquierdo);
        destruirArbol(nodo->derecho);
        delete nodo->paciente;
        delete nodo;
    }
}

int ArbolAVL::getAltura(NodoAVL* nodo) {
    if (nodo == nullptr) {
    return 0;
} else {
    return nodo->altura;
}
}

int ArbolAVL::getBalance(NodoAVL* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return getAltura(nodo->izquierdo) - getAltura(nodo->derecho);
}

void ArbolAVL::actualizarAltura(NodoAVL* nodo) {
    if (nodo != nullptr) {
        nodo->altura = 1 + max(getAltura(nodo->izquierdo), getAltura(nodo->derecho));
    }
}


NodoAVL* ArbolAVL::Derecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = max(getAltura(y->izquierdo), getAltura(y->derecho)) + 1;
    x->altura = max(getAltura(x->izquierdo), getAltura(x->derecho)) + 1;

    return x;
}


NodoAVL* ArbolAVL::Izquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = max(getAltura(x->izquierdo), getAltura(x->derecho)) + 1;
    y->altura = max(getAltura(y->izquierdo), getAltura(y->derecho)) + 1;

    return y;
}

NodoAVL* ArbolAVL::insertar(NodoAVL* nodo, Paciente* paciente){
    if(paciente == nullptr){
        return nodo;
    }

    if(nodo == nullptr){
        return new NodoAVL(paciente);
    }

    string idPaciente = paciente->getId();
    string idNodo = nodo->paciente->getId();

    if(idPaciente < idNodo){
        nodo->izquierdo = insertar(nodo->izquierdo, paciente);
    }else if(idPaciente > idNodo){
        nodo->derecho = insertar(nodo->derecho, paciente);
    }else{
        return nodo;
    }

    actualizarAltura(nodo);
    int balance = getBalance(nodo);

    if(balance >1 && idPaciente < nodo->izquierdo->paciente->getId()){
        return Derecha(nodo);
    }

    if(balance <-1 && idPaciente > nodo->derecho->paciente->getId()){
        return Izquierda(nodo);
    }

    if(balance < -1 && idPaciente < nodo->derecho->paciente->getId()){
        nodo->derecho = Derecha(nodo->derecho);
        return Izquierda(nodo);
    }

    if(balance > 1 && idPaciente > nodo->izquierdo->paciente->getId()){
        nodo->izquierdo = Izquierda(nodo->izquierdo);
        return Derecha(nodo);
    }

    return nodo;
}

void ArbolAVL::insertar(Paciente* paciente){
    raiz = insertar(raiz, paciente);
}

Paciente* ArbolAVL::buscarPorID(std::string id,std::string& ruta){
    NodoAVL* actual = raiz;
    ruta = "";
    while(actual != nullptr){
        string idActual = actual->paciente->getId();
        if(id == idActual){
            ruta += idActual;
            return actual->paciente;
        } else if(id < idActual){
            ruta += idActual + " -> ";
            actual = actual->izquierdo;
        } else {
            ruta += idActual + " -> ";
            actual = actual->derecho;
        }
    }
    ruta = "";
    return nullptr;
}
Paciente* ArbolAVL::buscarPorNombre(NodoAVL* nodo, const std::string nombre) {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (nodo->paciente->getNombre() == nombre) {
        return nodo->paciente;
    }

    Paciente* pacienteIzquierdo = buscarPorNombre(nodo->izquierdo, nombre);
    if (pacienteIzquierdo != nullptr) {
        return pacienteIzquierdo;
    }

    return buscarPorNombre(nodo->derecho, nombre);
}
Paciente* ArbolAVL::buscarPorNombre(const std::string& nombre) {
    return buscarPorNombre(raiz, nombre);
}
void ArbolAVL::PreOrden(NodoAVL* nodo){
    if(nodo != nullptr){
        nodo->paciente->mostrar();
        PreOrden(nodo->izquierdo);
        PreOrden(nodo->derecho);
    }
}

void ArbolAVL::InOrden(NodoAVL* nodo){
    if(nodo != nullptr){
        InOrden(nodo->izquierdo);
        nodo->paciente->mostrar();
        InOrden(nodo->derecho);
    }
}

void ArbolAVL::PostOrden(NodoAVL* nodo){
    if(nodo != nullptr){
        PostOrden(nodo->izquierdo);
        PostOrden(nodo->derecho);
        nodo->paciente->mostrar();
    }
}

void ArbolAVL::mostrarPreOrden(){
    if(estaVacio()){
        cout << "El arbol esta vacio." << endl;
        return;
    }
    PreOrden(raiz);
}

void ArbolAVL::mostrarInOrden(){
    if(estaVacio()){
        cout << "El arbol esta vacio." << endl;
        return;
    }
    InOrden(raiz);
}

void ArbolAVL::mostrarPostOrden(){
    if(estaVacio()){
        cout << "El arbol esta vacio." << endl;
        return;
    }
    PostOrden(raiz);
}

bool ArbolAVL::estaVacio(){
    return raiz == nullptr;
}
void ArbolAVL::mostrarAltura() {
    if (estaVacio()) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    cout << "Altura del arbol: " << getAltura(raiz) << endl;
}

void ArbolAVL::mostrarFactorBalance() {
    if (estaVacio()) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    mostrarBalance(raiz);
}
void ArbolAVL::mostrarBalance(NodoAVL* nodo) {
    if (nodo != nullptr) {
        mostrarBalance(nodo->izquierdo);
        cout << "ID: " << nodo->paciente->getId() << ", Factor de balance: " << getBalance(nodo) << endl;
        mostrarBalance(nodo->derecho);
    }
}

void ArbolAVL::mostrarResumen() {
    if (estaVacio()) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    cout << "Pacientes: ";
    bool primero = true;
    listarResumen(raiz, primero);
    cout << endl;
}
void ArbolAVL::listarResumen(NodoAVL* nodo, bool& primero) {
    if (nodo != nullptr) {
        listarResumen(nodo->izquierdo, primero);
        if (!primero) {
            cout << ", ";
        }
        cout << nodo->paciente->getNombre() + " (" + nodo->paciente->getId() + ")";
        primero = false;
        listarResumen(nodo->derecho, primero);
    }
}
