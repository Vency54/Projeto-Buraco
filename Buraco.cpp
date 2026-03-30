		#include <iostream>   
		#include <string>   
		#include <iomanip>   
		#include <cstdlib>   
		#include <ctime>      
		#include <sstream>
		#include <algorithm> 
		
		using namespace std;
		
		/*
		Programa Realizado Por João Victor Lima Venceslau
		*/
		
		//transforma um número inteiro em uma string com zeros à esquerda
			string formatar(int valor, int tamanho) {
		    stringstream ss;
		    ss << setw(tamanho) << setfill('0') << valor;
		    return ss.str();
		}
		
		int main(){
			
			   setlocale(LC_ALL, "");
			
				string baralho[2][52];
		
		
			
			//Gerar Baralho
			for(int i = 0; i <= 1; i++){
				
		
				for(int j = 0; j <= 51; j++){
				int naipe = j /  13 + 1;
				int valor = j % 13 + 1;
			  string strnaipe = formatar(naipe, 1);
				string strvalor = formatar(valor, 2);
				string strbaralho = formatar(i + 1, 1);
		
		            string carta = strnaipe + "-" + strvalor + "-" + strbaralho;
		            baralho[i][j] = carta;
				}
			}
			
		//Unir dois Baralhos	
		string baralhoCompleto[104];
		
		int k = 0;
		
		for(int i = 0; i <= 1; i++){
		    for(int j = 0; j <= 51; j++){
		        baralhoCompleto[k] = baralho[i][j];
		        k++;
		    }
		}
		
		//Embaralha as cartas
		srand(time(0)); 
		random_shuffle(baralhoCompleto, baralhoCompleto + 104);
		
		string mao[4][11];
		
		
		//Distribuir 11 para 4 jogadores
		int Carta_Atual = 0;
		
		for(int j = 0; j <= 3; j++){
		    for(int c = 0; c <= 10; c++){
				mao[j][c] =  baralhoCompleto[Carta_Atual];
				Carta_Atual++;
			}
		}
		
		
		// Ler Mãos
	
			for(int j = 0; j <= 3; j++){
				
				cout << "-----Jogador" << " " << j + 1 << "-----";
				cout << endl;
				
				for(int c = 0; c <= 10; c++){
					
				string naipe = " ";
				string valor = " ";
				
				int p1 = mao[j][c] .find('-');
				int p2 = mao[j][c] .find('-', p1 + 1);
				
				string numnaipe = mao[j][c] .substr(0, p1);
				string numvalor = mao[j][c].substr(p1 + 1, p2 - p1 - 1);
			   	string numbaralho = mao[j][c].substr(p2 + 1);
			   	
			   		if (numnaipe == "1") {
		    naipe = "Copas";
		}
		else if (numnaipe == "2") {
		    naipe = "Paus";
		}
		else if (numnaipe == "3") {
		    naipe = "Ouro";
		}
		else if (numnaipe == "4") {
		    naipe = "Espada";
		}
		else {
		    naipe = "Desconhecido";
		}
		
			if(numvalor == "01"){
				valor = "Ás";
			}
			else if(numvalor == "13"){
				valor = "Rei";
			}
			else{
				valor = numvalor;
			}
		
				cout << valor << " de " << naipe << " do baralho " << numbaralho << endl;
				cout << endl;
				}
				cout << "===================================" << endl;
				cout << endl;
			}
			
			return 0;
		}
