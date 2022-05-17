#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
// TODO # 0: Incluir el archivo cabecera del grafo
#include "Grafo.h"
/*
=========================================================================
  @author: Anderson Alvarado
=========================================================================
*/

// -------------------------------------------------------------------------
struct Punto
{
  float X, Y;
  float distanciaA( const Punto& b ) const
    {
      float x = X - b.X;
      float y = Y - b.Y;
      return( sqrt( ( x * x ) + ( y * y ) ) );
    }
    bool operator ==(Punto& p) const{
      return ((X == p.X) && (Y == p.Y) );
    }
    bool operator !=(Punto& p) const{
      return ((X != p.X) || (Y != p.Y));
    }
    bool operator <(Punto& p) const{
      return ((X < p.X) && (Y < p.Y));
    }
};

// -------------------------------------------------------------------------

// TODO # 1: Definir el tipo para un grafo con Puntos como vertices y costos reales
typedef Grafo<Punto> *grafo; 

typedef vector< unsigned long > TRuta;
typedef vector< TRuta > TCaminos;
typedef vector< float > *TDist;

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
   if( argc < 2 )
  {
    cerr
      << "Uso: " << argv[ 0 ] << " archivo_entrada"
      << endl;
    return( 1 );

  }

  // TODO # 2: Declarar el grafo
  grafo g = new Grafo<Punto>();

  // Cargar el archivo en un bufer
  ifstream in_mesh_stream( argv[ 1 ], ifstream::binary );
  if( !in_mesh_stream )
  {
    cerr << "Error leyendo \"" << argv[ 1 ] << "\"" << endl;
    return( 1 );

  }
  in_mesh_stream.seekg( 0, in_mesh_stream.end );
  unsigned long in_mesh_file_length = in_mesh_stream.tellg( );
  in_mesh_stream.seekg( 0, in_mesh_stream.beg );
  char* in_mesh_file_buffer = new char[ in_mesh_file_length ];
  in_mesh_stream.read( in_mesh_file_buffer, in_mesh_file_length );
  in_mesh_stream.close( );
  istringstream in_mesh( in_mesh_file_buffer );

  // Leer los vertices desde el bufer
  long nPoints;
  in_mesh >> nPoints;
  for( long pId = 0; pId < nPoints; pId++ )
  {
    Punto pnt;
    in_mesh >> pnt.X >> pnt.Y;
    //std::cout << "x:" <<pnt.X <<endl;
    // TODO # 3: Insertar el Punto en el grafo
    g->insertarVertice(pnt);

  }

  // Leer las aristas desde el bufer
  long nEdges;
  in_mesh >> nEdges;
  list<Vertice<Punto>>::iterator it, it2;
  for( long eId = 0; eId < nEdges; eId++ )
  {
    long start, end;
    in_mesh >> start >> end;
   // std::cout << "start: " <<start <<" end: " <<end <<endl; 
   // TODO # 4: Calcular el costo de la arista, insertarla en el grafo como no dirigida
    list<Vertice<Punto>> l = g->getVertices();
    it = l.begin();
    it2 = l.begin();
    advance(it, start);
    advance(it2, end);

    float costo = it->getDato()->distanciaA(*it2->getDato());
    //std::cout << costo <<" "<<endl;
    //std::cout << "start: " <<it->getDato()->X <<" end: " <<it2->getDato()<<endl; 
     g->insertarArista(*it->getDato(), *it2->getDato(), costo);
     g->insertarArista(*it2->getDato(), *it->getDato(), costo);
  }
  delete [] in_mesh_file_buffer;
  //g->imprimirVertices();
  /*g->imprimiAristas();*/
  
  list<Vertice<Punto>> v = g->getVertices();
  list<Vertice<Punto>>::iterator itV = v.begin();
  
  cout << "Porteria: " 
       << itV->getDato()->X << "," << itV->getDato()->Y << endl;

  int tamanoGrafo=g->getConexiones().size();

  //TODO # 5: Calcular distancias lineales (distancia Euclidiana)
  TDist distPrim = new vector<float>(tamanoGrafo, 999999);
  TDist distDijk = new vector<float>(tamanoGrafo, 999999);

  //TODO # 6: Encontrar las rutas de costo minimo usando los algoritmos requeridos
  vector<Vertice<Punto>>* prede = new vector<Vertice<Punto> >(tamanoGrafo);
  vector<Punto>* SDijk = new vector<Punto>;
  vector<Punto>* SPrim = new vector<Punto>;
  g->recorridoPrim(distPrim, SPrim,*itV->getDato());
  g->recorridoDijkstra(distDijk, prede, SDijk,*itV->getDato());

  // TODO # 7: Imprimir el informe de Prim
  typename vector<Punto>::iterator itSP = SPrim->begin();
     
  cout << "======================================================================== " << endl;
  cout << "\t\tPRIM"<<endl;
  cout << "======================================================================== " << endl;
  for(; itSP != SPrim->end(); itSP++)
  {
    cout << itSP->X << "," << itSP->Y << endl;
  }

  // TODO # 8: Imprimir el informe de Dijkstra (mismo fomato que informe de Prim)
  typename vector<Punto>::iterator itSD = SDijk->begin();
   cout << "======================================================================== " << endl;
  cout << "\t\tDIJKSTRA"<<endl;
  cout << "======================================================================== " << endl;
  for(; itSD != SDijk->end(); itSD++)
  {
      cout << itSD->X << "," << itSD->Y << endl;
  }

  return( 0 );
}

// eof - taller_5_grafos.cxx
