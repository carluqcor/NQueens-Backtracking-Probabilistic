#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "solucion.hpp"
#include "tablero.hpp"

/**
 * @brief      Menu para el programa de las n reinas con Backtraing y Las Vegas
 *
 * @return     { Exit }
 */
int menu();

/**
 * @brief      Comprueba si la reina actual va a ser amenazada
 *
 * @param[in]  fila     The row
 * @param[in]  tablero  The board
 *
 * @return     { description_of_the_return_value }
 */
bool Amenaza(int fila, std::vector<int> tablero);
void reinasBackTracking(int n, Tablero &board);
void introducirNumeroReinas(int &n);
void metodoBackTracking();
void mostrarSolucion(std::vector<Solucion> tablero, int n);
#endif