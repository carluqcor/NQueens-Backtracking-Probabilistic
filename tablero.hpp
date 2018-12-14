/*!
  \file   tablero.hpp
  \brief  Board Functions
  \author Carlos Luque Córdoba
  \date   2018/12/14
*/

#ifndef TABLERO_HPP
#define TABLERO_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "solucion.hpp"

/**
* @brief      Class for table.
*/
class Tablero{
	private:
		/**
		* Private table of solutions 
		*/
		std::vector<Solucion> _tablero;

	public:
		/**
		* @brief      Constructs the object Tablero
		*/
		//inline Tablero();

		/**
		* @brief      Gets a value from table.
		*
		* @param[in]  i       Position
		*
		* @return     The tablero.
		*/
		inline Solucion getTablero(int i){
			return _tablero[i];
		}

		/**
		* @brief      Gets the size of the vector table.
		*
		* @return     The size tableros.
		*/
		inline int getSizeTableros(){
			return _tablero.size();
		}

		/**
		* @brief      Sets the tablero value by value.
		*
		* @param[in]  i       Position
		* @param[in]  n       Value to set
		*/
		inline void setTablero(int i, Solucion n){
			_tablero[i]=n;
		}

		/**
		 * @brief      Clears the board vector
		 */
		inline void clearTablero(){
			_tablero.clear();
		}

		/**
		* @brief      Introduce new solution to the solution's vector
		*
		* @param[in]  solution  Int vector with a solution
		*/
		void introducirSolucionTablero(std::vector<int> solution);

		/**
		 * @brief      Resizes the board vector
		 */
		inline void resizeTablero(){
			_tablero.resize(getSizeTableros()+1);
		}
};

#endif