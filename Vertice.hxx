// =========================================================================
// @author: Anderson Alvarado
// =========================================================================

//Constructores
template <class T>
Vertice<T>::Vertice(){}

template <class T>
Vertice<T>::Vertice(T dato)
{
    this->dato = dato;
}
//Get
template <class T>
T* Vertice<T>::getDato()
{
    return &dato;
}
//Set
template <class T>
void Vertice<T>::setDato(T dato)
{
    this->dato = dato;
}
template <class T>
bool Vertice<T>::operator <(Vertice<T>& ver)
{
    if(dato < ver.dato)
        return true;
    return false;
}