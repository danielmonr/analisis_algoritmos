/*
 * =====================================================================================
 *
 *       Filename:  bianrio.h
 *
 *    Description:  imprime el bianrio de la variable
 *
 *        Version:  1.0
 *        Created:  06/10/15 18:36:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Monzalvo
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

template <class T>
class binario{
	public:
		static std::string realizarBinario(T variable);
		static std::string realizarBinarioCadena(char**, int);
	private:
		static void imprimir(std::string s);
};

template <class T>
void binario<T>::imprimir(std::string s){
	std::cout << s << std::endl;
}

template <class T>
std::string binario<T>::realizarBinario(T variable){
	std::string imprime = "";
	long cont = 1;
	int sizeOfT = sizeof(T);
	for(int i = 0; i < sizeOfT; ++i){
		for (int j = 0; j < 8; ++j){
			if((variable & cont)  == cont){
				imprime = "1" + imprime;
			}
			else{
				imprime = "0" + imprime;
			}
			cont = cont << 1;
		}
	}
	imprimir(imprime);
}
