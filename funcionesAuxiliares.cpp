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
	std::cout << "Programa principal de la Practica 5 de Algorítmica";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,6);
	std::cout <<BICYAN<< "[1] Rellenar Sistema Monetario"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIYELLOW<< "[2] Borrar Sistema Monetario"<<RESET;

	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIGREEN<< "[3] Introducir la cantidad para recibir el Cambio"<<RESET;

	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIBLUE<< "[4] Devolución del cambio"<<RESET;

	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIWHITE<< "[5] Imprimir la devolución del cambio"<<RESET;

	posicion++;

	PLACE(posicion++,7);
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
	for(int i=0; i<fila-1;i++){
		if(tablero[i]==tablero[fila] || std::abs(tablero[i]-tablero[fila])==std::abs(i-fila)){
			return false;
		}
	}
	return true;
}

void reinasBackTracking(int n, Tablero &table){
	std::vector<int> tablero(n+1,0);
	tablero[0]=0;
	int k=1;
	do{
		tablero[k]+=1;
		do{
			tablero[k]+=1;
		}while(tablero[k]<=n && !Amenaza(k, tablero));

		if(tablero[k]<=n){
			if(k==n){
				std::cout<<"Se encuentra Solucion\n";
				table.introducirSolucionTablero(tablero);
			}else{
				k+=1;
				tablero[k]=0;
			}
		}else{
			k-=1;
		}
	}while(k>0);
}

void mostrarSolucion(std::vector<Solucion> tablero, int n){
	int contador=1;
	for(int i=0;i<tablero.size();i++){
		std::vector<int> tab;
		for(int k=0;k<tablero[i].getSize();k++){
			tab.push_back(tablero[i].getSolucion(k));
		}
		for(int j=0; j<tab.size();j++){
			if(contador==n){
				std::cout<<tab[j]<<std::endl<<std::endl;;
				contador=1;
			}else{
				std::cout<<tab[j]<<"\t";
				contador++;
			}
			
		}
		std::cout<<"\n\n\n\n";
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
	Tablero table;
	introducirNumeroReinas(n);
	reinasBackTracking(n, table);
	for(int i=0;i<table.getSizeTableros();i++){
		tablero.push_back(table.getTablero(i));
	}
	mostrarSolucion(tablero, n);
}