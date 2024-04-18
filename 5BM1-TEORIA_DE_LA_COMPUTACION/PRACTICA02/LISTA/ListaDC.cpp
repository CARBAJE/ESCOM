#include "ListaDC.h"

Lista CrearLista(int* error) {
    Lista l = nullptr;
    l = new Nodo;
    if (l == nullptr) {
        std::cerr << "NO HAY SUFICIENTE ESPACIO PARA LA CREACION DE LA LISTA. LIBERE MEMORIA" << std::endl;
        *error = -2;
    } else {
        l->nodoSiguiente = l;
        l->nodoAnterior = l;
        *error = 0;
    }
    return l;
}

void InsertarIzquierda(Lista& l, Dato valor, int* error) {
    Nodo* nuevo_nodo = new Nodo;
    if (nuevo_nodo == nullptr) {
        std::cerr << "NO HAY SUFICIENTE MEMORIA PARA GUARDAR LA INFORMACION. LIBERE LA MEMORIA." << std::endl;
        *error = -1;
    } else {
        if (l == nullptr) {
            l = nuevo_nodo;
        }
        nuevo_nodo->dato = valor;
        nuevo_nodo->nodoSiguiente = l;
        nuevo_nodo->nodoAnterior = l->nodoAnterior;
        l->nodoAnterior->nodoSiguiente = nuevo_nodo;
        l->nodoAnterior = nuevo_nodo;
        l = nuevo_nodo;
        std::cout << "VALORES MANDADOS:\nPOS[" << l->nodoAnterior->dato << "]\tVAL:" << l->dato << std::endl;
    }
}

void InsertarDerecha(Lista& l, Dato valor, int* error) {
    Nodo* nuevo_nodo = new Nodo;
    if (nuevo_nodo == nullptr) {
        std::cerr << "NO HAY SUFICIENTE MEMORIA PARA GUARDAR LA INFORMACION. LIBERE LA MEMORIA." << std::endl;
        *error = -1;
    } else if (l == nullptr) {
        InsertarIzquierda(l, valor, error);
    } else {
        nuevo_nodo->dato = valor;
        nuevo_nodo->nodoSiguiente = l;
        nuevo_nodo->nodoAnterior = l->nodoAnterior;
        l->nodoAnterior->nodoSiguiente = nuevo_nodo;
        l->nodoAnterior = nuevo_nodo;
        std::cout << "VALORES MANDADOS:\nPOS[" << l->nodoAnterior->dato << "]\tVAL:" << l->dato << std::endl;
    }
}

void InsertarPosicion(Lista& l, Dato valor, int posicion, int* error) {
    if (posicion == 0 || l == nullptr)
        InsertarIzquierda(l, valor, error);
    else if (posicion == RecorrerLista(l, l))
        InsertarDerecha(l, valor, error);
    else if (posicion > 0 && posicion < RecorrerLista(l, l)) {
        Nodo* aux1 = l;
        Nodo* aux2;
        Nodo* nuevo_nodo = new Nodo;
        if (nuevo_nodo == nullptr) {
            std::cerr << "NO HAY SUFICIENTE MEMORIA PARA GUARDAR LA INFORMACION. LIBERE MEMORIA" << std::endl;
            *error = -1;
        } else {
            nuevo_nodo->dato = valor;
            nuevo_nodo->posicion = posicion;
            do {
                aux2 = aux1;
                aux1 = aux1->nodoSiguiente;
            } while (aux1->posicion != posicion);
            nuevo_nodo->nodoSiguiente = aux1;
            nuevo_nodo->nodoAnterior = aux2;
            aux1->nodoAnterior = nuevo_nodo;
            aux2->nodoSiguiente = nuevo_nodo;
            UpdatePosicion(l, aux1);
            *error = 0;
        }
    }
}

Dato ExtraerIzquierda(Lista& l, int* error) {
    if (!IsEmpty(l, error)) {
        Nodo* aux1 = l;
        Dato dato_extraido;
        dato_extraido = aux1->dato;
        l = aux1->nodoSiguiente;
        l->nodoAnterior = aux1->nodoAnterior;
        aux1->nodoAnterior->nodoSiguiente = l;
        aux1->nodoSiguiente = nullptr;
        delete aux1;
        ResetPosicion(l, l);
        return dato_extraido;
    } else {
        std::cerr << "LA LISTA ESTÁ VACÍA. NO SE PUEDE EXTRAER." << std::endl;
        return Dato(); // Devuelve un valor predeterminado para indicar un error.
    }
}

Dato ExtraerDerecha(Lista& l, int* error) {
    if (!IsEmpty(l, error)) {
        Nodo* aux1 = l;
        Dato dato_extraido;
        do {
            aux1 = aux1->nodoSiguiente;
        } while (aux1->nodoSiguiente != l);
        dato_extraido = aux1->dato;
        aux1->nodoAnterior->nodoSiguiente = l;
        l->nodoAnterior = aux1->nodoAnterior;
        aux1->nodoSiguiente = nullptr;
        delete aux1;
        return dato_extraido;
    } else {
        std::cerr << "LA LISTA ESTÁ VACÍA. NO SE PUEDE EXTRAER." << std::endl;
        return Dato(); // Devuelve un valor predeterminado para indicar un error.
    }
}

Dato ExtraerPosicion(Lista& l, int posicion, int* error) {
    if (!IsEmpty(l, error)) {
        Dato dato_extraido;
        if (posicion == 0)
            dato_extraido = ExtraerIzquierda(l, error);
        else if (posicion == RecorrerLista(l, l))
            dato_extraido = ExtraerDerecha(l, error);
        else if (posicion > 0 && posicion < RecorrerLista(l, l)) {
            Nodo* aux1 = l;
            Nodo* aux2;
            do {
                aux2 = aux1;
                aux1 = aux1->nodoSiguiente;
            } while (aux1->posicion != posicion);
            dato_extraido = aux1->dato;
            aux2->nodoSiguiente = aux1->nodoSiguiente;
            aux1->nodoSiguiente->nodoAnterior = aux2;
            aux1->nodoSiguiente = nullptr;
            delete aux1;
            ResetPosicion(l, aux2->nodoSiguiente);
            *error = 0;
            return dato_extraido;
        }
    } else {
        std::cerr << "LA LISTA ESTÁ VACÍA. NO SE PUEDE EXTRAER." << std::endl;
        return Dato(); // Devuelve un valor predeterminado para indicar un error.
    }
}

void UpdatePosicion(Lista& l, Nodo* nodo) {
    Nodo* aux = nodo;
    do {
        aux->posicion += 1;
        aux = aux->nodoSiguiente;
    } while (aux != l);
}

void ResetPosicion(Lista& l, Nodo* nodo) {
    Nodo* aux = nodo;
    do {
        aux->posicion -= 1;
        aux = aux->nodoSiguiente;
    } while (aux != l);
}

int RecorrerLista(Lista& l, Nodo* nodo) {
    int i = 0;
    Nodo* aux = nodo;
    do {
        aux = aux->nodoSiguiente;
        i++;
    } while (aux != l);
    return i;
}

void ImprimirLista(Lista l, int* error) {
    if (l == nullptr) {
        std::cerr << "LA LISTA ESTA VACIA." << std::endl;
        *error = -3;
        return;
    }
    Nodo* aux = l;
    do {
        std::cout << "Valor: " << aux->dato << std::endl;
        aux = aux->nodoSiguiente;
    } while (aux != l);
}

void DestruirLista(Lista l, int* error) {
    if (l == nullptr) {
        std::cerr << "LA LISTA ESTA VACIA." << std::endl;
        *error = -3;
        return;
    }
    Nodo* aux = l;
    do {
        Nodo* temp = aux;
        aux = aux->nodoSiguiente;
        delete temp;
    } while (aux != l);
    l = nullptr;
}

int main() {
    int error;
    Lista lista = CrearLista(&error);
    InsertarIzquierda(lista, 5, &error);
    InsertarDerecha(lista, 10, &error);
    ImprimirLista(lista, &error);
    DestruirLista(lista, &error);
    return 0;
}
