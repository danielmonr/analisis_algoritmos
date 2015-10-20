/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Algoritmo de MD5
 *
 *        Version:  1.0
 *        Created:  02/10/15 11:06:34
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Daniel Monzalvo
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../binario.h"
#include "md.h"
#include <cstring>

using namespace std;

int main (int argc , char** argv){

	md* uno= new md();
       	/* for (int i = 1; i < argc; ++i){
		if (*argv[i] >= '0' && argv[i] <= '9'){
			binario<int>::realizarBinario(atoi(argv[i]);
		}
		else{
			binario<char>::realizarBinario(*argv[i]);
		}
	}
	*/
/*
	long t = 96;
	char* temp = new char[8];
	temp = ((char*)&t);
	char* it = temp;
	char cont = 1;
	int contador = 0;
	string s = "";
	
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if ((*it & cont) == cont){
				s = "1" + s;
			}
			else{
				s = "0" +s;
			}
			cont = cont << 1;
			contador++;
		}
		cont = 1;
		++it;
	}

	cout << s<< endl;
	cout << "N= " << contador << endl;
*/

/* 
	char s[10];
	cin >> s;
	char* it = s+strlen(s);
	int i = strlen(s);
	s[i] = 'z';
	cout << *it;
	*/
//	char c[10];
//	size_t t = strlen(s);
//	memcpy(c, s,t);
//	cout << c;

	/*
	unsigned int n = 2;
	n = n >>1;
	if (num & n)
		cout << "correcto" << endl;
	cout << "num : " << num << "  n: " << n << endl;
	*/
	return 0;
}
