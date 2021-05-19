#ifndef LDL_H_INCLUDED
#define LDL_H_INCLUDED
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class LDL
{
private:
    struct NodoLDL
    {
        T dato;
        NodoLDL *siguiente, *anterior;
        NodoLDL(const T& element, NodoLDL* sig=nullptr, NodoLDL* ant=nullptr)
        {
            dato=element;
            siguiente=sig;
            anterior=ant;
        }
    };
    size_t listSize;
    NodoLDL *listFront, *listBack;

public:
    LDL()
    {
        listSize=0;
        listFront=nullptr;
        listBack=nullptr;
    }
    bool empty()const;
    size_t size()const;
    void push_front(const T& element);
    void push_back(const T& element);
    const T& front()const;
    const T& back()const;
    void pop_front();
    void pop_back();
};

template<typename T>
bool LDL<T>::empty()const
{
    return listSize==0;
}

template<typename T>
size_t LDL<T>::size()const
{
    return listSize;
}

template<typename T>
void LDL<T>::push_front(const T& element)
{
    if(empty())
    {
        listFront=new NodoLDL(element);
        listBack=listFront;
    }
    else
    {
        NodoLDL* nuevo= new NodoLDL(element,listFront);
        listFront->anterior=nuevo;
        listFront=nuevo;
    }
    listSize++;
}

template<typename T>
void LDL<T>::push_back(const T& element)
{
    if(empty())
    {
        listFront=new NodoLDL(element);
        listBack=listFront;
    }
    else
    {
        NodoLDL* nuevo=new NodoLDL(element,nullptr,listBack);
        listBack->siguiente=nuevo;
        listBack=nuevo;
    }
    listSize++;
}

template<typename T>
const T& LDL<T>::front()const
{
    if(empty())
        throw range_error("front() on empty list");
    return listFront->dato;
}

template<typename T>
const T& LDL<T>::back()const
{
    if(empty())
        throw range_error("back() on empty list");
    return listBack->dato;
}

template<typename T>
void LDL<T>::pop_front()
{
    if(empty())
        throw range_error("pop_front() on empty list");
    NodoLDL* eliminar=listFront;
    listFront=listFront->siguiente;
    listFront->anterior=nullptr;
    eliminar->siguiente=nullptr;
    delete eliminar;
    eliminar=nullptr;
    listSize--;
}

template<typename T>
void LDL<T>::pop_back()
{
    if(empty())
        throw range_error("pop_back() on empty list");
    NodoLDL* eliminar=listBack;
    listBack=listBack->anterior;
    listBack->siguiente=nullptr;
    eliminar->anterior=nullptr;
    delete eliminar;
    listSize--;
}

#endif // LDL_H_INCLUDED
