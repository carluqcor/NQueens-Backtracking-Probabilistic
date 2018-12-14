#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include "solucion.hpp"
#include "tablero.hpp"
#include "funcionesAuxiliares.hpp"
#include "macros.hpp"

int menu(){
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=4;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principal de la Practica 6 de Algorítmica";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,5);
	std::cout <<BICYAN<< "[1] Introducir las reinas"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,5);
	std::cout <<BIYELLOW<< "[2] N Reinas Backtracking"<<RESET;

	posicion++;

	PLACE(posicion++,5);
	std::cout <<BIGREEN<< "[3] N Reinas Las Vegas"<<RESET;

	posicion++;

	PLACE(posicion++,5);
	std::cout <<BIBLUE<< "[4] Imprimir solución/soluciones"<<RESET;

	posicion++;


	PLACE(posicion++,6);
	std::cout << BIRED << "[0] Volver al menú";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,5);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opcinón
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}

bool Amenaza(int fila, std::vector<int> tablero){
	for(int i=0; i<fila;i++){
		if(tablero[i]==tablero[fila] || std::abs(tablero[i]-tablero[fila])==std::abs(i-fila)){
			return false;
		}
	}
	return true;
}

void reinasBackTracking(int n, Tablero &board){
	std::vector<int> tablero(n,0);
	int reinas=0; //Primera reina usada
	while(reinas>=0){	
		tablero[reinas]++;
		while(tablero[reinas]<=n && !Amenaza(reinas, tablero)){
			tablero[reinas]++;
		}

		if(tablero[reinas]<=n){
			if(reinas==(n-1)){
				board.introducirSolucionTablero(tablero);
			}else{
				reinas++;
				tablero[reinas]=0;
			}
		}else{
			reinas--;
		}
	}
}

void mostrarSolucion(std::vector<Solucion> tablero, int n){
	if(tablero.size()>0){
		std::cout<<BIYELLOW<<"Se han encontrado: "<<BIRED<<tablero.size()<<BIYELLOW<<" soluciones"<<RESET<<std::endl;
	}else{
		std::cout<<BIRED<<"No se han encontrado soluciones!!!"<<RESET<<std::endl;
		return;
	}
	int contador=1;
	for(int i=0;i<tablero.size();i++){
		std::cout<<BIWHITE<<"Esta es la solución "<<BIRED<<i+1<<RESET<<std::endl;
		std::vector<int> tab;
		for(int k=0;k<tablero[i].getSize();k++){
			tab.push_back(tablero[i].getSolucion(k));
		}
		for(int j=0; j<n;j++){
			for(int r=1;r<n+1;r++){
				if(j==0){
				}
				if(r==tab[j]){
					std::cout<<BIGREEN<<tab[j]<<RESET<<"  ";
				}else{
					std::cout<<"-  ";
				}
			}
		std::cout<<std::endl;
		}
		std::cout<<"\n\n\n\n"; //Cambio de solución
	}
}


void introducirNumeroReinas(int &n){
	std::cout<<BICYAN<<"Introduce el número de reinas: "<<BIGREEN;
	std::cin>>n;
	std::cout<<RESET<<std::endl;
}

void metodoBackTracking(){
	int n;
	std::vector<Solucion> tablero;
	Tablero board;
	introducirNumeroReinas(n);
	reinasBackTracking(n, board);
	for(int i=0;i<board.getSizeTableros();i++){
		tablero.push_back(board.getTablero(i));
	}
	mostrarSolucion(tablero, n);
}