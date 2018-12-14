/*!
  \file   main.cpp
  \brief  Main Function
  \author Carlos Luque Córdoba
  \date   2018/12/14
*/

/*!
 \mainpage Implementation of N Queens problem by Backtracking and Las Vegas Algorithm
 \author   Carlos Luque Córdoba
 \date     2018/12/14
 \version  1.0
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

/**
 * @brief      Main Fuction
 *
 * @return     Exit
 */
int main(){
	srand(time(NULL));
	metodo();
	return 1;
}