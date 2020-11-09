#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

#define INFECTADO 'X'
#define SANO 'O'

void introduce (vector< vector<char> >& matriz){
	int i,j;
	
	cout << "Introdueix les coordenades del nen infectat, un valor de x entre 0 i "<< matriz.size()-1 << " i un valor de y entre 0 i " << matriz[0].size()-1<< endl;
	cin >> i;
	cin >> j;
	while (i < 0 || i >= matriz.size() || j<0 || j>= matriz[0].size()){
		cout << "Valors incorrectes, introdueix un valor de x entre 0 i "<< matriz.size()-1 << " i un valor de y entre 0 i " << matriz[0].size()-1<< endl;
		cin >> i;
		cin >> j;
	}
	
	matriz [i][j] = INFECTADO;
	}

void leer (vector< vector<char> >& matriz){
		
		
	for(int i=0; i<matriz.size(); i++){
		for(int j=0; j<matriz[i].size(); j++){
			cout << " " << matriz [i][j];
		
		}
		printf("\n");
	}
	printf ("\n");
}

void continuar (vector< vector<char> >& matriuentrada, vector< vector<char> >& matriusortida){

	int count=0;
	bool hayAlgunSano=true;
	while (hayAlgunSano){
		// Infectar matriu sortida
		for(int i=0; i<matriuentrada.size(); i++){
			for(int j=0; j<matriuentrada[i].size(); j++){
				if (matriuentrada [i][j]==INFECTADO){
					// Infectar fila anterior
					if (i>0){
						if (j>0) matriusortida [i-1][j-1]=INFECTADO;
						matriusortida [i-1][j]=INFECTADO;
						if (j+1<matriuentrada[i].size()) matriusortida [i-1][j+1]=INFECTADO;
					}
					// Infectar fila actual
					if (j>0) matriusortida [i][j-1]=INFECTADO;
					matriusortida [i][j]=INFECTADO;
					if (j+1<matriuentrada[i].size()) matriusortida [i][j+1]=INFECTADO;
					// Infectar fila siguiente
					if (i+1<matriuentrada.size()){
						if (j>0) matriusortida [i+1][j-1]=INFECTADO;
						matriusortida [i+1][j]=INFECTADO;
						if (j+1<matriuentrada[i].size()) matriusortida [i+1][j+1]=INFECTADO;
					}
					
				}
				else {
					hayAlgunSano = true;
				} 
			}
		
		}
		
		// Comprovar si queden sans
		hayAlgunSano = false;
		for(int i=0; i<matriusortida.size() && !hayAlgunSano; i++){
			for(int j=0; j<matriusortida[i].size() && !hayAlgunSano; j++){
				if (matriusortida[i][j] == SANO){
					hayAlgunSano = true;
				}
				
			}
		}
		count++;
		leer(matriusortida);
		cout << "Els nens del voltant de l'infectat es van contagiant." << endl;
		system ("PAUSE");
		matriuentrada.swap(matriusortida);
	} 
	cout << "Han passat "<< count <<" dies des de que l'infeccio va començar fins que tots els nens han estat infectats'.\n";
        
}
	
int main (){
	
	int filas, columnas;
	
	cout << "Introduiu les dimensions de la matriu: \n(primer escriviu el num. de files, despres pulseu 'intro' i finalment el num. de columnes) " << endl;
	cin >> filas;
	cin >> columnas;
	while (filas>20 || columnas>20 || filas<=0 || columnas<=0){
		cout << "Introdueix uns valors més petits o iguals a 20"<< endl;
		cin >> filas;
		cin >> columnas;
	}
	
	vector< vector<char> > matriuentrada(filas, vector<char>(columnas, SANO));
	vector< vector<char> > matriusortida(filas, vector<char>(columnas, SANO));
	system ("PAUSE");
	
	introduce(matriuentrada); //significado "introduce"
	leer(matriuentrada); 
	continuar (matriuentrada, matriusortida);
	
		
	system ("PAUSE");
	return 0;
	
}
