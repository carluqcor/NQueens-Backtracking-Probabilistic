#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "solucion.cpp"
#include "tablero.hpp"


void Tablero::introducirSolucionTablero(std::vector<int> solution){
	Solucion solucion;
	for(int i=0;i<solution.size();i++){
		solucion.resizeSolucion();
		solucion.setSolucion(i, solution[i]);
	}
	solucion.setID(getSizeTableros()+1);

	std::vector<Solucion> table;
	for(int i=0;i<getSizeTableros();i++){
		table.push_back(getTablero(i));
	}
	table.push_back(solucion);

	resizeTablero();
	for(int i=0;i<table.size();i++){
		setTablero(i, table[i]);
	}
	std::cout<<"\n\n\n\n";
}