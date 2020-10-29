/*Autor: Alan Jahir Martinez Sepulveda 
Codigo: 216569127
*/
#include <iostream>
#include <stdlib.h>

using namespace std; 

class CNodo
{
    private: 
        CNodo *pSiguiente; 
        CNodo *pAnterior; 
        float fContenido;

        friend class CLista;
        friend class CPila;
    public: 
        void InsertarAdelante(float fData);
        float EliminarSiguiente();
};

class CLista
{
    private: 
        CNodo Inicio;
        CNodo Final;

        friend class CPila;
    public: 
        void InsertarInicio(float fData);
        void InsertarFinal(float fData);
        bool IsEmpy();
        int Size();
        void Vaciar();
        CLista();
        ~CLista();
        void Imprime();
        float EliminarInicio();
        float EliminarFinal();
};

int main()
{
    CLista lista;
    lista.InsertarInicio(2.1);
    lista.InsertarInicio(6.0);
    lista.InsertarFinal(3.0);
    
    lista.IsEmpy();

    return 0;
}

CLista::CLista()
{
    Inicio.pSiguiente = &Final;
    Final.pAnterior = &Inicio;
}

CLista::~CLista()
{

}

void CNodo::InsertarAdelante(float fData)
{
    CNodo *nv = new CNodo; 
    nv ->pSiguiente = this ->pSiguiente;
    nv ->pAnterior= this;
    this->pSiguiente = nv;
    //nv->pSiguiente->pAnterior = nv;
    this->pSiguiente->pSiguiente->pAnterior=nv;
     nv ->fContenido = fData;
}

float CNodo::EliminarSiguiente()
{
    CNodo *nv = new CNodo;
    CNodo *aux;
    int nEnc = 0;
    //*nv = Inicio;
    if (fContenido > 1 ){
        nv = pSiguiente;
        for (int i=0; i<fContenido; i++)
        {
            aux = aux->pSiguiente;
        }
        aux->pAnterior->pSiguiente = aux->pSiguiente;
        nv->pAnterior = aux->pAnterior;
        delete (aux);
    }
    return aux->fContenido;
}

void CLista::InsertarInicio(float fData)
{
    Inicio.InsertarAdelante(fData);
}

void CLista::InsertarFinal(float fData)
{
    Final.InsertarAdelante(fData); 
}

float CLista::EliminarInicio()
{
    return Inicio.pSiguiente->pSiguiente->EliminarSiguiente();

}

float CLista::EliminarFinal()
{
    return Final.pAnterior->pAnterior->EliminarSiguiente();

}

int CLista::Size()
{
    int c =0; 
    CNodo *nv= &Inicio;
    while (nv != &Inicio)
    {
        nv = nv->pSiguiente;
        c++;
    }
    return c; 
}

bool CLista::IsEmpy()
{
    return Inicio.pSiguiente==&Final ? true : false; //Probando nuevo metodo
    /*if (Inicio.pSiguiente==&Final)
    {
        return true;
    }
    else {
        return false;
    }*/
}

void CLista::Vaciar()
{
    while (Inicio.pSiguiente != &Final)
        EliminarInicio();

    delete &Inicio;
    delete &Final;
}

void CLista::Imprime()
{
    CNodo *nv = new CNodo;
    while (nv!=&Final)
    {
        cout << nv->fContenido<<" "; 
        nv = nv->pSiguiente;
    }
}

class CPila
{
    private:
        CLista lista;
        friend class CLista;
        friend class CNodo;
    public: 
        void push (float nd);
        float pop();
        float tos();
        int size();
        bool isEmpy();
        bool isFull();
        void imprimir();
};

void CPila::push(float nd)
{
    lista.InsertarInicio(nd);
}

float CPila::pop()
{
    lista.EliminarInicio();
}

//float CPila::tos()
//{
    
//}

int CPila::size()
{
    lista.Size();
}

bool CPila::isEmpy()
{
    lista.IsEmpy();
}

bool CPila::isFull()
{
    return false;
}

void CPila::imprimir()
{
    lista.Imprime();
}

class CCola
{
    private: 
        CLista lista;
    public:
        void push (float nd);
        float pop();
        int size();
        bool isEmpy();
        bool isFull();
        void imprimir();
};

void CCola::push(float nd)
{
    lista.InsertarInicio(nd);
}

float CCola::pop()
{
    lista.EliminarFinal();
}

int CCola::size()
{
    lista.Size();
}

bool CCola::isEmpy()
{
    lista.IsEmpy();
}

bool CCola::isFull()
{
    return false;
}

void CCola::imprimir()
{
    lista.Imprime();
}
