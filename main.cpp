// =========================================================================
// @author: Anderson Alvarado
// =========================================================================
#include <iostream>
#include <vector>
#include <list>
#include "Grafo.h"
#include "Vertice.h"

using namespace std;

int main()
{
    typedef Grafo<char> *graf; 
    graf g = new Grafo<char>();

    g->insertarVertice('s');
    g->insertarVertice('t');
    g->insertarVertice('x');
    g->insertarVertice('y');
    g->insertarVertice('z');
    g->insertarArista('s','t',10);
    g->insertarArista('s','y',5);
    g->insertarArista('t','x',1);
    g->insertarArista('t','y',2);
    g->insertarArista('x','z',4);
    g->insertarArista('y','x',9);
    g->insertarArista('y','t',3);
    g->insertarArista('y','z',2);
    g->insertarArista('z','x',6);
    g->insertarArista('z','s',7);


    typedef Grafo<int> *grafo; 
    grafo h = new Grafo<int>();
    h->insertarVertice(0);
    h->insertarVertice(1);
    h->insertarVertice(2);
    h->insertarVertice(3);
    h->insertarVertice(4);
    h->insertarVertice(5);
    h->insertarVertice(6);
    h->insertarVertice(7);
    h->insertarArista(0,1,5);
    h->insertarArista(0,4,9);
    h->insertarArista(0,7,8);
    h->insertarArista(1,2,12);
    h->insertarArista(1,3,15);
    h->insertarArista(1,7,4);
    h->insertarArista(2,3,3);
    h->insertarArista(2,6,11);
    h->insertarArista(3,6,9);
    h->insertarArista(4,5,4);
    h->insertarArista(4,6,20);
    h->insertarArista(4,7,5);
    h->insertarArista(5,2,1);
    h->insertarArista(5,6,13);
    h->insertarArista(7,2,7);
    h->insertarArista(7,5,6);

    cout << "======================================================================== " << endl;
    cout << "\t\t@author: Anderson Alvarado"<<endl;
    cout << "======================================================================== " << endl;
    cout << "\n---------------------------------------------------";


    cout << "\nGRAFO DEL h" << endl;
    vector<int>* S1 = new vector<int> ();
    vector<int>* distan = new vector<int>();
    
    h->imprimirVertices();// mostrar vertices
    cout <<endl;
    h->imprimiAristas();
  
    cout << "\nRECORRIDO PRIM" << endl;
    h->prim(distan,S1,0);

    typename vector<int>::iterator it1 = S1->begin();  
   
    for(; it1 != S1->end(); it1++)
    {
        cout << *it1 << endl;
    }


    cout << "\nGRAFO DEL g" << endl;
    g->imprimirVertices();// mostrar vertices
    cout <<endl;
    g->imprimiAristas();
    int tamanoGrafo = g->getConexiones().size();
    vector<int>* distancias = new vector<int>(tamanoGrafo, 999999);
    vector<Vertice<char>>* prede = new vector<Vertice<char> >(tamanoGrafo);
    vector<char>* S = new vector<char> (tamanoGrafo);

    cout << "\n---------------------------------------------------";
    cout << "\n\nRECORRIDO DIJKSTRA" << endl;
    g->recorridoDijkstra(distancias, prede,S,'s');

    cout << "\nS" << endl;

    typename vector<char>::iterator it = S->begin();  
   
    for(; it != S->end(); it++)
    {
        cout << *it << endl;
    }
}