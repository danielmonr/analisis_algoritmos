/*
 * =====================================================================================
 *
 *       Filename:  md.cpp
 *       Packet:    MD5
 *
 *    Description:  source code algorithm
 *
 *        Version:  1.0
 *        Created:  02/10/15 11:08:32
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Monzavlo
 *
 * =====================================================================================
 */

#include "md.h"
#include <cstring>

md::md(){
	init();
	//faseUno();
	//faseDos();

	std::string s = "";
	int contador = 0;
	char cont = 128;
	char* it = passMod;
	for (int i = 0; i < (size/8); ++i){
		for (int j = 0; j < 8; ++j){
			if ((*it & cont) == cont){
				s =  s + "1" ;
			}
			else{
				s = s +"0";
			}
			cont = cont >> 1;
			contador++;
		}
		cont = 1;
		++it;
	}

	std::cout << s<< std::endl;
	std::cout << "N= " << contador << std::endl;


}

void md::init(){
	terminado = false;
	std::cout << "Password: ";
	std::cin >> pass;
	const char* cpass = pass.c_str();
	tamano = pass.length();
	agregar = abs(((tamano*8)+agregar -448)%512);
	size = tamano*8 + agregar + 64;
	passMod = new char[(size / 8)];
	memcpy(passMod, cpass, strlen(cpass));
	iterador = passMod+strlen(cpass);
}

void md::faseUno(){
	// Agregar bytes con el fin de que sea multiplo de 64
	char c = 128;
	char c2 = 0;

	pass = pass + c;
	memset(iterador, c, 1);
	iterador = iterador+1;
	agregar = agregar-8;
	memset(iterador, c2, (agregar/8));
	agregar = 0;
	iterador = iterador +(agregar/8);
}

void md::faseDos(){
	// Concatenar en un entero de 64 bits el tamano inicial del password
	char* temp = new char[8];
	temp = ((char*)&tamano);
	memcpy(iterador, temp, 8);
}
