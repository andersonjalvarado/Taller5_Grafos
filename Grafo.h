// =========================================================================
// @author: Anderson Alvarado
// =========================================================================
#ifndef __GRAFO__H__
#define __GRAFO__H__
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <limits>
#include "Vertice.h"
#include "Arista.h"
using namespace std;

template <class T>
class Grafo
{
    private:
        list<Vertice<T>> vertices;
        list<list<Arista<T>>> conexiones;
    public:
        Grafo();
        list<Vertice<T>> getVertices();
        list<list<Arista<T>>> getConexiones();
        void setVertices(list<Vertice<T> >vertices);
        void setConexiones (list<list<Arista<T> > > conexiones);
        bool esVacio();
        int cantidadVertices();
        int cantidadAristas();
        bool insertarVertice(Vertice<T> vertice);
        bool insertarVertice(T dato);
        bool estaVertice(Vertice<T> vertice);
        bool estaVertice(T dato);
        int insertarArista(Vertice<T> ver_o, Vertice<T> ver_d, float peso);
        int insertarArista(T ver_org, T ver_des, float peso);
        list<Arista<T> >* obtenerConexionesVertice(int indice);
        int obtenerIndice(T ver_org);
        Vertice<T>* buscarVertice(T ver_des);
        bool insertarConexion(list<Arista<T> >* conex, Vertice<T>* verDes, float peso);
        int eliminarConexionesEnEliminarVertice(list<Arista<T> >* c,T  dato);
        bool eliminarVertice(T dato);
        void imprimiAristas();
        void imprimirVertices();
        bool eliminarConexion(list<Arista<T> >* conex, Vertice<T>* verDes);
        int eliminarArista(T ver_org, T ver_des);
        Arista<T>* buscarArista(T ver_org, T ver_des);
        bool verticeVisitado(list<Vertice<T>* > lista, T dato);
        float recorridoPrim(vector<float>* distancias,vector<T> *S, T dato);
        Vertice<T> mindistance(list<Vertice<T> >* todosLosVertices, vector<float> distancias);
        float recorridoDijkstra(vector<float>* distancias, vector<Vertice<T> >* prede, vector<T> *S, T dato);
        void imprimirPredecesores(vector<Vertice<int> > lista);
};

#include "Grafo.hxx"
#endif