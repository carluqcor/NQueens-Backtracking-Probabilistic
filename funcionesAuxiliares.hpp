/*!
  \file   funcionesAuxiliares.hpp
  \brief  Auxiliary Functions
  \author Carlos Luque Córdoba
  \date   2018/12/14
*/

#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "solucion.hpp"
#include "tablero.hpp"

/**
 * @brief      Menu for N Queens problem solved by Backtraing and Las Vegas Algorithms
 *
 * @return     Exit
 */
int menu();

/**
 * @brief      Check if the next queen is going to be threatened
 *
 * @param[in]  fila     The row
 * @param[in]  tablero  The board
 *
 * @return     True if the queen is threatened by other queen
 */
bool Amenaza(int fila, std::vector<int> tablero);

/**
 * @brief      Solve N Queens problem by Backtracking Algorithm
 *
 * @param[in]  n      Nº Queens
 * @param[in]      board  The board
 */
void reinasBackTracking(int n, Tablero &board);

/**
 * @brief      Solve N Queens problem by Las Vegas Algorithm
 *
 * @param[in]     n                Nº Queens
 * @param[in]     board            The board
 * @param[in]     solved           Check if the Algorithm found a solution
 * @param[in]     tableroAuxiliar  The Auxiliary Board
 */
void reinasVegas(int n, Tablero &board, bool &solved, std::vector<int> &tableroAuxiliar);

/**
 * @brief      Introduce number of Queens
 *
 * @param[in]     n     Nº Queens
 */
void introducirNumeroReinas(int &n);

/**
 * @brief      Introduce number of iterations
 *
 * @param[in]     n     Number of iterations
 */
void introducirIteracionesLasVegas(int &n);

/**
 * @brief      Do Las Vegas Algorithm Repeticiones times
 *
 * @param[in]  	  n                { parameter_description }
 * @param[in]     board            The board
 * @param[in]     tableroAuxiliar  The tablero auxiliar
 * @param[in]     repeticiones     The number of repetitions
 * @param[in]     intentos         The attempt to get a solution
 * @param[in]     tries            The vector of attempt to keep them
 */
void reinasVegasRepeticiones(int n, Tablero &board, std::vector<int> &tableroAuxiliar, int repeticiones, int &intentos, std::vector<int> &tries);

/**
 * @brief      Calculate media for getting a solution from Las Vegas
 *
 * @param      media  The mean
 * @param[in]  tries  The vector of attempt to keep them
 */
void calculoMedia(double &media, std::vector<int> tries);

/**
 * @brief      method with Backtracking and Las Vegas Algorithm
 */
void metodo();

/**
 * @brief      Shows the solutions as a matrix view
 *
 * @param[in]  tablero  The Board
 * @param[in]  n        Nº Queens
 */
void mostrarSolucion(std::vector<Solucion> tablero, int n);

#endif