#include <iostream>   // para cout, cin
#include <string>     // para std::string
#include <iomanip>    // opcional, mas útil p/ formatar (ex: setw, setfill)
#include <cstdlib>    // para rand(), srand()
#include <ctime>      // para time() ? seed do rand
#include <sstream>
#include <algorithm> // Essencial para o random_shuffle
#include <ctime>   // Para time()
#include <cstdlib> // Para srand() e random_shuffle

using namespace std;


string intParaString(int valor) {
    stringstream ss;
    ss << valor;
    return ss.str();
}

	string formatar(int valor, int tamanho) {
    stringstream ss;
    ss << setw(tamanho) << setfill('0') << valor;
    return ss.str();
}

int main(){
	
	   setlocale(LC_ALL, "");
	
string baralho[2][52];


	
	//Baralho
	for(int i = 0; i <= 1; i++){
		
		//carta
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
	
	
string baralhoCompleto[104];

int k = 0;

for(int i = 0; i <= 1; i++){
    for(int j = 0; j <= 51; j++){
        baralhoCompleto[k] = baralho[i][j];
        k++;
    }
}

srand(time(0)); // Cria a semente baseada na hora atual
random_shuffle(baralhoCompleto, baralhoCompleto + 104);

string mao[4][11];


//Distribuir
int Carta_Atual = 0;

for(int j = 0; j <= 3; j++){
    for(int c = 0; c <= 10; c++){
		mao[j][c] =  baralhoCompleto[Carta_Atual];
		Carta_Atual++;
	}
}


// Ler Mãos
	//Baralho
	for(int j = 0; j <= 3; j++){
		
		cout << "Jogador" << " " << j + 1 << ":";
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

		cout << mao[j][c] << endl;
		cout << valor << " de " << naipe << " do baralho " << numbaralho << endl;
		cout << endl;
		}
		cout << endl;
	}
	
	return 0;
}