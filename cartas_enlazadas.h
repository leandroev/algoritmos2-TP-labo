#ifndef CARTAS_ENLAZADAS_H_
#define CARTAS_ENLAZADAS_H_

#include <iostream>
#include <cassert>
using namespace std;

/* 
 * Se puede asumir que el tipo T tiene constructor por copia y operator==
 * No se puede asumir que el tipo T tenga operator=
 */
template<typename T>
class CartasEnlazadas {

  public:

	/**
	 * Crea un nuevo juego.
	 */	
	CartasEnlazadas();

	/**
	 * Una vez copiada, ambos juegos deben ser independientes, 
	 * es decir, cuando se borre una no debe borrar la otra.
	 */	
	CartasEnlazadas(const CartasEnlazadas<T>&);
	
	/**
	 * Acordarse de liberar toda la memoria!
	 */	 
	~CartasEnlazadas();  
	
	/**
	* Agrega un jugador a la mesa. El mismo debe sentarse en la posición 
	* siguiente a la posición del jugador con el mazo azul. Por ejemplo si en la
	* mesa hay 3 jugadores sentados de la siguiente forma: [j1 j2 j3], y el 
	* mazo rojo lo tiene el jugador j3, la mesa debe quedar: [j1 j2 j3 j4].
	* PRE: el jugador a agregar no existe.
	*/
	void agregarJugador(const T&);
	
	/**
	* Adelanta el mazo rojo n posiciones. Por ejemplo: si en la mesa hay 3 
	* jugadores sentados de la siguiente forma: [j1 j2 j3] y el jugador j2
	* tiene el mazo rojo, si se adelanta 1 posicion el mazo rojo pasa al jugador j3. En
	* cambio si el mazo rojo se adelanta 2 posiciones el mazo rojo pasa al jugador j1.
	* En caso de que n sea negativo debe retroceder el mazo rojo -n posiciones.
	* PRE: existe al menos un jugador
	*/
	void adelantarMazoRojo(int n);
	
	/**
	* Adelanta el mazo azul n posiciones. Por ejemplo: si en la mesa hay 3 
	* jugadores sentados de la siguiente forma: [j1 j2 j3] y el jugador j2
	* tiene el mazo azul, si se adelanta 1 posicion el mazo azul pasa al jugador j3. En
	* cambio si el mazo azul se adelanta 2 posiciones el mazo azul pasa al jugador j1.
	* En caso de que n sea negativo debe retroceder el mazo azul -n posiciones.
	* PRE: existe al menos un jugador
	*/
	void adelantarMazoAzul(int n);
	
	/**
	* Devuelve el jugador que tiene el mazo Rojo actualmente.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugadorConMazoRojo() const;
	
	/**
	* Devuelve el jugador que tiene el mazo Azul actualmente.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugadorConMazoAzul() const;
	
	/**
	* Devuelve el jugador que se encuentra n posiciones adelante a la posicion 
	* del jugador con el mazo rojo. En caso de que n sea negativo deberia devolver 
	* el jugador que se encuentra -n posiciones atrás.
	* PRE: existe al menos un jugador
	*/
	const T& dameJugador(int n) const;
	
	/**
	* Devuelve el jugador que se encuentra enfreantado al jugador que tiene el 
	* mazo rojo. Por ejemplo si en la mesa hay cuatros jugadores sentados de la
	* siguiente forma: [J1 J2 J3 J4] y el el jugador J2 tiene el mazo rojo, el
	* resultado debe ser J4.
	* PRE: cantidad de jugadores par, al menos un jugador
	*/
	const T& dameJugadorEnfrentado() const;
	
	/**
	* Elimina el jugador pasado como parámetro.
	* En el caso de que el jugador no exista, el método no debe hacer nada.
	* En el caso de que el jugador tenga algún mazo, se le pasa el mazo al 
	* siguiente jugador en la ronda.
	*/
	void eliminarJugador(const T&);
	
	/**
	* Elimina al jugador que tiene el mazo azul.
	* Por ejemplo si los jugadores estan sentadods de la siguiente forma: 
	* [J1 J2 J3 J4 J5] y el mazo lo tiene el jugador J3. Cuando se eliminan al 
	* jugador con  del mazo, la mesa * debería quedar de la siguiente forma 
	* [J1 J2 J4 J5].
	* En el caso de que algún jugador tenga algún mazo, se le pasa el mazo al 
	* siguiente jugador en la ronda.
	* PRE: al menos un jugador
	*/
	void eliminarJugadorConMazoAzul();
	
	/**
	* Dice si el jugador existe.
	*/
	bool existeJugador(const T&) const;

	/**
	* Le suma los puntos al jugador.
	* PRE: el jugador existe
	*/
	void sumarPuntosAlJugador(const T&, int);
	
	/**
	* Devuelve la cantidad de puntos que tiene el jugador pasado como 
	* parámetro.
	* PRE: el jugador existe
	*/
	int puntosDelJugador(const T&) const;
	
	/**
	* Devuelve al jugador que más puntos tiene.
	* PRE: hay un único jugador que tiene más puntos que todos los demás.
	*/
	const T& ganador() const;
	
	/*
	 * Dice si hay jugadores en la mesa.
	 */
	bool esVacia() const;

	/*
	 * Devuelve la cantidad de jugadores.
	 */
	int tamanio() const;	

	/*
	 * Devuelve true si los juegos son iguales.
	 */
	bool operator==(const CartasEnlazadas<T>&) const;	
	
	/*
	 * Debe mostrar la ronda por el ostream (y retornar el mismo).
	 * CartasEnlazadas vacio: []
	 * CartasEnlazadas con 1 elementos (e1 tiene el mazo azul y el rojo, p es el puntaje): [(e1,p)*]
	 * CartasEnlazadas con 2 elementos (e2 tiene el mazo azul y e1 el mazo rojo, p es el puntaje): [(e2,p), (e1,p)*]
	 * CartasEnlazadas con 3 elementos (e1 tiene el mazo, e3 fue agregado después que e2,
	 * e1 fue agregado antes que e2): [(e1, 0)*, (e3, 0), (e2, 0)]
	 */
	ostream& mostrarCartasEnlazadas(ostream&) const;
  private:
  
	/*
	 * No se puede modificar esta funcion.
	 */
	CartasEnlazadas<T>& operator=(const CartasEnlazadas<T>& otra) {
		assert(false);
		return *this;
	}

	/*
	 * Aca va la implementación del nodo.
	 */
    struct Nodo {
 			T jugador;
 			Nodo* siguiente;
 			Nodo* anterior;
 			int puntos;

 			Nodo(const T& j) : jugador(j){
 				siguiente = NULL;
 				anterior = NULL;
 				puntos = 0;
 			};
    };
    Nodo* azul;
    Nodo* rojo;
    int longitud;
};


template<class T>
ostream& operator<<(ostream& out, const CartasEnlazadas<T>& a) {
	return a.mostrarCartasEnlazadas(out);
}


// Implementación a hacer por los alumnos.

template<typename T>
CartasEnlazadas<T>::CartasEnlazadas(){		
	rojo = NULL;
	azul = NULL;
	longitud = 0;
}

template<typename T>	
CartasEnlazadas<T>::CartasEnlazadas(const CartasEnlazadas<T>& orig){
	if (orig.longitud == 0){
		rojo = NULL;
		azul = NULL;
		longitud = 0;
	} else {
		Nodo* it = orig.azul;
		azul = new Nodo(it->jugador);
		azul->puntos = it->puntos;
		rojo = azul;
		int i = 1;
		it = it->siguiente;
		Nodo* itprev = azul;
		while (i < orig.longitud){
			Nodo* nuevonodo = new Nodo(it->jugador);
			nuevonodo->puntos = it->puntos;
			itprev->siguiente = nuevonodo;
			nuevonodo->anterior = itprev;
			if (it == orig.rojo){
				rojo = nuevonodo;
			}
			it = it->siguiente;
			itprev = itprev->siguiente;
			i = i+1;
		}
		itprev->siguiente = azul;
		azul->anterior = itprev;
		longitud = orig.longitud;
	}
}
	
template<typename T>	
CartasEnlazadas<T>::~CartasEnlazadas(){
	rojo = NULL;
	if (!esVacia()){
		Nodo* it = azul->siguiente;
		while (it != NULL){
			Nodo* itNext = it->siguiente;
			delete it;
			it = itNext;
			if(it == azul){
				it = NULL;
			}
		}
	}
	if (azul != NULL){
		delete azul;
	}
	azul = NULL;		
	longitud = 0;
}
	
template<typename T>	
void CartasEnlazadas<T>::agregarJugador(const T& j){
	Nodo* nuevo = new Nodo(j);
	if(longitud == 0){
		azul = nuevo;
		rojo = nuevo;
	} else {
		if(longitud > 1){
			nuevo->anterior = azul;
			azul->siguiente->anterior = nuevo;
			nuevo->siguiente = azul->siguiente;
			azul->siguiente = nuevo;
		}
		else{
			azul->siguiente = nuevo;
			azul->anterior = nuevo;
			nuevo->siguiente = azul;
			nuevo->anterior = azul;
		}
	}
	longitud++;
}
	
template<typename T>
void CartasEnlazadas<T>::adelantarMazoRojo(int n){
	if (n > 0){
		for (int i = 0; i != n; ++i){
			rojo = rojo->siguiente;
		}
	}
	if (n < 0){
		for (int i = 0; i != n; --i){
			rojo = rojo->anterior;
		}
	}
}
	
template<typename T>
void CartasEnlazadas<T>::adelantarMazoAzul(int n){
	if (n > 0){
		for (int i = 0; i != n; ++i){
			azul = azul->siguiente;
		}
	}
	if (n < 0){
		for (int i = 0; i != n; --i){
			azul = azul->anterior;
		}
	}
}
	
template<typename T>	
const T& CartasEnlazadas<T>::dameJugadorConMazoRojo() const{
	const T& red = rojo->jugador;
	return red;
}
	
template<typename T>	
const T& CartasEnlazadas<T>::dameJugadorConMazoAzul() const{
	const T& blue = azul->jugador;
	return blue;
}
	
template<typename T>	
const T& CartasEnlazadas<T>::dameJugador(int n) const{
	Nodo* p = rojo;
	if (n > 0){
		for (int i = 0; i != n; ++i){
			p = p->siguiente;
		}
	}
	if (n < 0){
		for (int i = 0; i != n; --i){
			p = p->anterior;
		}
	}
	const T& player = p->jugador;
	return player;
}
	
template<typename T>
const T& CartasEnlazadas<T>::dameJugadorEnfrentado() const{
	int n = 0;
	Nodo* it = rojo;
	while (n != longitud/2){
		it = it->siguiente;
		n++;
	}
	const T& enfrentado = it->jugador;
	return enfrentado;
}
	
template<typename T>
void CartasEnlazadas<T>::eliminarJugador(const T& nominado){
	if (longitud == 1){
		if (azul->jugador == nominado){
			rojo = NULL;
			delete azul;
			azul= NULL;
			longitud = 0;
		}
	}
	if (longitud > 1){
		int n = 0;
		Nodo* it = azul;
		while (n != longitud && !(it->jugador == nominado)){
			it = it->siguiente;
			n++;
		}
		if (it->jugador == nominado){
			if(rojo == it){
				rojo = it->siguiente;
			}
			if(azul == it){
				azul = it->siguiente;
			}
			it->siguiente->anterior = it->anterior;
			it->anterior->siguiente = it->siguiente;
			it->siguiente = NULL;
			it->anterior = NULL;
			delete it;
			it = NULL;
		}
		longitud --;
	}
}
	
template<typename T>
void CartasEnlazadas<T>::eliminarJugadorConMazoAzul(){
	if(longitud > 1){
		Nodo* it = azul;
		if (rojo == it){
			rojo = it->siguiente;
		}
		azul = azul->siguiente;
		it->anterior->siguiente = azul;
		azul->anterior = it->anterior;
		delete it;
		it = NULL;
		longitud --;
	}
	else{
		rojo = NULL;
		delete azul;
		azul = NULL;
		longitud = 0;
	}
}
	
template<typename T>
bool CartasEnlazadas<T>::existeJugador(const T& j) const{
	int n = 0;
	Nodo* it = azul;
	while(n != longitud && it != NULL){
		if (it->jugador == j){
			return true;
		}
		it = it->siguiente;
		n++;
	}
	return false;	
}

template<typename T>
void CartasEnlazadas<T>::sumarPuntosAlJugador(const T& j, int n){
	Nodo* it = azul;
	while (it->jugador != j){
		it = it->siguiente;
	}
	it->puntos = it->puntos + n;
}
	
template<typename T>
int CartasEnlazadas<T>::puntosDelJugador(const T& j) const{
	Nodo* it = azul;
	while (it != NULL && it->jugador != j){
		it = it->siguiente;
	}
	return it->puntos;
}
	
template<typename T>
const T& CartasEnlazadas<T>::ganador() const{
	Nodo* it = azul;
	Nodo* winner = azul;
	for (int i = 1; i < longitud; ++i){
		if (winner->puntos < it->siguiente->puntos){
			winner = it->siguiente;
		}
		it = it->siguiente;
	}
	const T& gana = winner->jugador;
	return gana;
}
	
template<typename T>
bool CartasEnlazadas<T>::esVacia() const{
	return longitud == 0;
}

template<typename T>
int CartasEnlazadas<T>::tamanio() const{
	return longitud;
}	

template<typename T>
bool CartasEnlazadas<T>::operator==(const CartasEnlazadas<T>& otro) const{
	if (tamanio() != otro.tamanio()){
	 	return false;
	}
	if(!esVacia()){
		Nodo* it1 = azul;
		Nodo* it2 = otro.azul;
		if (longitud >1){
			it1 = it1->siguiente;
			it2 = it2->siguiente;
			while((it1->jugador == it2->jugador) && ((it1 != azul) && (it2 != otro.azul))){
				if ( ((rojo == it1) != (otro.rojo == it2)) || (it1->puntos != it2->puntos) ){
					return false;
				}
				it1 = it1->siguiente;
				it2 = it2->siguiente;
			}
		}
		return (it1->jugador == it2->jugador);
	} else{
		return true;	
	}
}
	
template<typename T>	
ostream& CartasEnlazadas<T>::mostrarCartasEnlazadas(ostream& os) const{
	os << "[";
	if(azul != NULL){
		Nodo* imprimir = azul;
		os << "(";
				os << imprimir->jugador;
				os << ", ";
				os << imprimir->puntos;
				os << ")";
				if(imprimir == rojo){
					os << "*";
				}
		if(azul->siguiente != NULL){
			int n = 1;
			imprimir = imprimir->siguiente;
			while(imprimir != azul){
				os << ", (";
				os << imprimir->jugador;
				os << ", ";
				os << imprimir->puntos;
				os << ")";
				if(imprimir == rojo){
					os << "*";
				}
				n++;
				imprimir = imprimir->siguiente;
			}
		}
	}
	os << "]";
	return os;
}



#endif //CARTAS_ENLAZADAS_H_
