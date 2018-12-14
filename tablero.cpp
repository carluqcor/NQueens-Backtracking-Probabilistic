/*!
  \file   tablero.cpp
  \brief  Board Functions
  \author Carlos Luque Córdoba
  \date   2018/12/14
*/

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

	std::vector<Solucion> board;
	for(int i=0;i<getSizeTableros();i++){
		board.push_back(getTablero(i));
	}
	board.push_back(solucion);

	resizeTablero();
	for(int i=0;i<board.size();i++){
		setTablero(i, board[i]);
	}
}