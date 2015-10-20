/*
 * =====================================================================================
 *
 *       Filename:  md.h
 *       Packet:    MD5
 *
 *    Description:  header del algoritmo
 *
 *        Version:  1.0
 *        Created:  02/10/15 11:07:44
 *       Compiler:  g++
 *
 *         Author:  Daniel Monzalvo,
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>

class md{
	public:
		md();
	private:
		bool terminado;
		long tamano;
		void init();
		std::string pass;
		void faseUno();
		void faseDos();
		char* passMod;
		int agregar;
		int size;
		char* iterador;
};
