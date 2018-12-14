/*!
  \file   funcionesAuxiliares.cpp
  \brief  Auxiliary Functions
  \author Carlos Luque Córdoba
  \date   2018/12/14
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h> 
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

	PLACE(posicion++,6);
	std::cout <<BICYAN<< "[1] Introducir las reinas"<<RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIYELLOW<< "[2] N Reinas Backtracking"<<RESET;

	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIGREEN<< "[3] N Reinas Las Vegas"<<RESET;

	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIWHITE<< "[4] Calcular la media de soluciones para Las Vegas"<<RESET;

	posicion++;

	PLACE(posicion++,6);
	std::cout <<BIBLUE<< "[5] Imprimir solución/soluciones"<<RESET;

	posicion++;


	PLACE(posicion++,6);
	std::cout << BIRED << "[0] Volver al menú";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,6);
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

void reinasVegas(int n, Tablero &board, bool &solved, std::vector<int> &tableroAuxiliar){
	tableroAuxiliar.clear();
	tableroAuxiliar.resize(n, 0);
	std::vector<int> ok(n,0);
	int contador=0, i, j;
	for(i=0; i<n;i++){
		contador=0;
		for(j=1;j<=n;j++){
			tableroAuxiliar[i]=j;
			if(Amenaza(i, tableroAuxiliar)){
				contador++;
				ok[contador]=j;
			}
		}
		if(contador==0){
			return;
		}
		j=ok[std::rand() % contador+1];
		tableroAuxiliar[i]=j;
	}
	if(contador=0){
		solved=false;
	}else{
		solved=true;
		board.introducirSolucionTablero(tableroAuxiliar);
	}
}

void reinasVegasRepeticiones(int n, Tablero &board, std::vector<int> &tableroAuxiliar, int repeticiones, int &intentos, std::vector<int> &tries){
	for(int i=0;i<repeticiones;i++){
		bool solved=false;
		while(!solved){
			board.clearTablero();
			reinasVegas(n, board, solved, tableroAuxiliar);
			intentos++;
			if(solved){
				tries.push_back(intentos);
				intentos=0;
				solved=true;
			}
		}
	}

	for(int i=0;i<repeticiones;i++){
		std::cout<<BIWHITE<<"Iteracion "<<i<<": "<<BIYELLOW<<tries[i]<<"\n";
	}
	std::cout<<std::endl;
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
					//std::cout<<BIGREEN<<tab[j]<<RESET<<"  ";			
					std::cout<<BIGREEN<<"👑"<<RESET<<" ";
				}else{
					std::cout<<BIWHITE<<"➖ "<<RESET;
				}
			}
		std::cout<<std::endl;
		}
		std::cout<<"\n\n\n\n"; //Cambio de solución
	}
}

void calculoMedia(double &media, std::vector<int> tries){
	int intentos=0;
	for(int i=0;i<tries.size();i++){
		intentos+=tries[i];
	}
	media=trunc(intentos/(tries.size())); //Si quiero poner intento.intento quitar el trunc
}

void introducirNumeroReinas(int &n){
	std::cout<<BICYAN<<"Introduce el número de reinas: "<<BIGREEN;
	std::cin>>n;
	std::cout<<RESET<<std::endl;
}

void introducirIteracionesLasVegas(int &n){
	std::cout<<BICYAN<<"Introduce el número de repeticiones para las N Reinas: "<<BIGREEN;
	std::cin>>n;
	std::cout<<RESET<<std::endl;
}

void metodo(){
	int n, opcion, intentos=0, i, repeticiones=0;
	double media=0;
	std::vector<Solucion> tablero;
	Tablero board;
	bool solved;
	std::vector<int> tableroAuxiliar, tries;
	do{
		opcion = menu();      	
        std::cout << CLEAR_SCREEN;
        PLACE(3,1);
		switch(opcion){
			case 1:
				introducirNumeroReinas(n);
				break;

			case 2:
				board.clearTablero();
				tablero.clear();
				reinasBackTracking(n, board);
				for(int i=0;i<board.getSizeTableros();i++){
					tablero.push_back(board.getTablero(i));
				}
				mostrarSolucion(tablero, n);
				break;

			case 3:
				solved=false;
				board.clearTablero();
				tablero.clear();
				reinasVegas(n, board, solved, tableroAuxiliar);
				intentos++;
				if(solved){
					if(intentos==1){
						std::cout<<BIGREEN<<"Se ha encontrado una solución!\n"<<BIBLUE<<"Y se ha tardado: "<<BIRED<<intentos<<BIBLUE<<" repetición para conseguirla"<<RESET<<std::endl;
					}else if(intentos>1){
						std::cout<<BIGREEN<<"Se ha encontrado una solución!\n"<<BIBLUE<<"Y se ha tardado: "<<BIRED<<intentos<<BIBLUE<<" repeticiones para conseguirla"<<RESET<<std::endl;						
					}
					intentos=0;
				}else{
					std::cout<<BIRED<<"No se ha encontrado una solución!"<<RESET<<std::endl;
				}
				for(int i=0;i<board.getSizeTableros();i++){
					tablero.push_back(board.getTablero(i));
				}
				mostrarSolucion(tablero, n);
				break;

			case 4:
				solved=false;
				board.clearTablero();
				tablero.clear();
				tries.clear();
				media=intentos=0;
				introducirIteracionesLasVegas(repeticiones);
				reinasVegasRepeticiones(n, board, tableroAuxiliar, repeticiones, intentos, tries);
				calculoMedia(media, tries);
				std::cout<<BIPURPLE<<"El número medio de intentos es: "<<BIGREEN<<media<<RESET<<std::endl;
				std::cin.ignore();
				break;

			case 5:
				mostrarSolucion(tablero, n);
				break;

			default:
				break;
		}
		if (opcion !=0){
	        PLACE(25,1);
	        std::cout << "Pulse ";
	        std::cout << BIGREEN;
	        std::cout << "ENTER";
	        std::cout << RESET;
	        std::cout << " para mostrar el ";
	        std::cout << INVERSE;
	        std::cout << "menú"; 
	        std::cout << RESET;

	        // Pausa
	        std::cin.ignore();

	        std::cout << CLEAR_SCREEN;
	    }

	}while(opcion!=0);
    return;
}