#ifndef FUNCIONESAUXILIARES_HPP
#define FUNCIONESAUXILIARES_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "solucion.hpp"
#include "tablero.hpp"

int menu();
bool Amenaza(int fila, std::vector<int> tablero);
void reinasBackTracking(int n, Tablero &table);
void introducirNumeroReinas(int &n);
void metodoBackTracking();
void mostrarSolucion(std::vector<Solucion> tablero, int n);
#endif