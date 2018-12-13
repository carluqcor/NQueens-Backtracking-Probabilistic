#ifndef SOLUCION_HPP
#define SOLUCION_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

/**
* @brief      Class for solution.
*/
class Solucion{

	private:
		/**
		* { Private int vector for a solution }
		*/
		std::vector<int> _solucion;

		/**
		* { Private ID for such solution }
		*/
		int _id;

	public:
		/**
		* @brief      Constructs the solution
		*/
		/*
		inline Solucion();*/

		/**
		* @brief      Gets a value from solution.
		*
		* @param[in]  i     { Position }
		*
		* @return     The tablero.
		*/
		inline int getSolucion(int i){
			return _solucion[i];
		}

		/**
		* @brief      Gets the size of the vector solution.
		*
		* @return     The size tableros.
		*/
		inline int getSize(){
			return _solucion.size();
		}

		/**
		* @brief      Gets the id of a solution.
		*
		* @return     The id.
		*/
		inline int getID(){
			return _id;
		}

		/**
		* @brief      Sets the solucion.
		*
		* @param[in]  i     { Position }
		* @param[in]  n     { Value to set }
		*/
		inline void setSolucion(int i, int n){
			_solucion[i]=n;
		}

		/**
		* @brief      Sets the id of a solution.
		*
		* @param[in]  id    The identifier
		*/
		inline void setID(int id){
			_id=id;
		}

		inline void resizeSolucion(){
			_solucion.resize(getSize()+1);
		}
};

#endif