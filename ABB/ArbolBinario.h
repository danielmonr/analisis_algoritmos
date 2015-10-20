//
//  ArbolBinario.h
//  Arboles
//
//  Created by Daniel on 20/10/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Arboles__ArbolBinario__
#define __Arboles__ArbolBinario__

#include <iostream>
#include "NodoB.h"

template <class T>
class ArbolBinario{
private:
    NodoB<T> * raiz = nullptr;
    std::ostream & imprime(std::ostream & os, NodoB<T> *  nodo);
    
public:
    ArbolBinario();
    ArbolBinario(NodoB<T> * info);
    ~ArbolBinario();
    
    void clear(NodoB<T> * nodo);
    bool empty();
    
    bool insert(T value, NodoB<T> * padre);
    bool insert(T value, T padre);
    
    NodoB<T> * getRaiz();
    
    void preOrden();
    void postOrden();
    void inOrden();
    
    void preOrden(NodoB<T> *  nodo);
    void postOrden(NodoB<T> *  nodo);
    void inOrden(NodoB<T> *  nodo);
    
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream & os, ArbolBinario<Tn> & arbol);
    
    NodoB<T>* buscar(T info);
    NodoB<T>* buscar(T info, NodoB<T> * nodo);
    
    NodoB<T> * suma(NodoB<T>* nodo);
    NodoB<T> * suma();
    
    void acumular(NodoB<T>* nodo, NodoB<T>* acumulador);
    T acumular(NodoB<T>* nodo);
};

template <class T>
ArbolBinario<T>::ArbolBinario(){
    // raiz = nullptr;
}

template <class T>
ArbolBinario<T>::ArbolBinario(NodoB<T> * info){
    raiz = info;
}

template <class T>
ArbolBinario<T>::~ArbolBinario(){
    clear(raiz);
}

template <class T>
void ArbolBinario<T>::clear(NodoB<T> * nodo){
    if (nodo){
        clear(nodo->getIzquierdo());
        clear(nodo->getDerecho());
        
        delete nodo;
    }
    
}

template <class T>
NodoB<T> * ArbolBinario<T>::getRaiz(){
    return raiz;
}

template <class T>
bool ArbolBinario<T>::empty(){
    return (raiz == nullptr);
}

template <class T>
bool ArbolBinario<T>::insert(T value, NodoB<T> * padre){
    if(!padre){
        raiz = new NodoB<T>(value);
    }
    else{
        if(!padre->getIzquierdo()){
            padre->setIzquierdo(new NodoB<T>(value));
        }
        else if(!padre->getDerecho()){
            padre->setDerecho(new NodoB<T>(value));
        }
        else{
            return false;
        }
    }
    return true;
}

template <class T>
bool ArbolBinario<T>::insert(T value, T padre){
    NodoB<T> * padre_ptr = buscar(padre);
    if(padre_ptr){
        return insert(value, padre_ptr);
    }
    return false;
}

template <class T>
void ArbolBinario<T>::preOrden(){
    preOrden(raiz);
}

template <class T>
void ArbolBinario<T>::postOrden(){
    postOrden(raiz);
}

template <class T>
void ArbolBinario<T>::inOrden(){
    inOrden(raiz);
}

template <class T>
void ArbolBinario<T>::preOrden(NodoB<T> *  nodo){
    if (nodo){
        std::cout << *nodo << " ";
        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
    }
}

template <class T>
void ArbolBinario<T>::postOrden(NodoB<T> *  nodo){
    if (nodo){
        preOrden(nodo->getIzquierdo());
        preOrden(nodo->getDerecho());
        std::cout << *nodo << " ";

    }
}

template <class T>
void ArbolBinario<T>::inOrden(NodoB<T> *  nodo){
    if (nodo){
        preOrden(nodo->getIzquierdo());
        std::cout << *nodo << " ";
        preOrden(nodo->getDerecho());
    }
}

template <class T>
std::ostream & ArbolBinario<T>::imprime(std::ostream & os, NodoB<T> *  nodo){
    if (nodo){
        os << *nodo << " ";
        imprime(os, nodo->getIzquierdo());
        imprime(os, nodo->getDerecho());
    }
    return os;
}

template <class T>
std::ostream & operator <<(std::ostream & os, ArbolBinario<T> & arbol){
    return arbol.imprime(os, arbol.raiz);
}


template <class T>
NodoB<T> * ArbolBinario<T>::buscar(T info){
    return buscar(info, raiz);
}

template <class T>
NodoB<T> * ArbolBinario<T>::buscar(T info, NodoB<T> * nodo){
    
    NodoB<T> * temp = nullptr;
    
    if(nodo){
        if(nodo->getInfo() == info){
            return nodo;
        }
        else{
            temp = buscar(info, nodo->getIzquierdo());
            
            if(temp){
                return temp;
            }
            return buscar(info, nodo->getDerecho());
        }
    }
    return temp;
}

template <class T>
NodoB<T> * ArbolBinario<T>::suma(){
    return suma(raiz);
}

template <class T>
NodoB<T> * ArbolBinario<T>::suma(NodoB<T> * nodo){
    
    T valor;
    
    if(nodo){
        valor = nodo->getInfo();
        
        NodoB<T> * suma_izq = suma(nodo->getIzquierdo());
        
        if(suma_izq){
            valor += suma_izq->getInfo();
            delete suma_izq;
        }
        
        NodoB<T> * suma_der = suma(nodo->getDerecho());
        
        if(suma_der){
            valor += suma_der->getInfo();
            delete suma_der;
        }
        
        return new NodoB<T>(valor);
    }
    return nullptr;
}


template <class T>
T ArbolBinario<T>::acumular(NodoB<T> * nodo){
    NodoB<T> * acumulador = new NodoB<T>(0);
    acumular(nodo, acumulador);
    T valor = acumulador->getInfo();
    delete acumulador;
    return valor;
}

template <class T>
void ArbolBinario<T>::acumular(NodoB<T> * nodo, NodoB<T> * acumulador){
    
    T valor;
    
    if(nodo){
        acumulador->setInfo(acumulador->getInfo() + nodo->getInfo());
        acumular(nodo->getIzquierdo(), acumulador);
        acumular(nodo->getDerecho(), acumulador);
        
    }
}

#endif /* defined(__Arboles__ArbolBinario__) */
