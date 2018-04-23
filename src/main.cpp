#include "imagem.hpp"
#include "pgm.hpp"
#include "ppm.hpp"

#include <iostream>
#include <string>

using namespace std;

int main(){

	Imagem imagem1;
	PGM imagem_pgm;
	PPM imagem_ppm;
	string enderecoEntrada;
	int tipo;

	cout<<endl;
	cout<<"====================== Decifrador de Mensagens de Imagem ======================"<<endl<<endl;
	cout<<"================ Qual tipo é o tipo de imagem PGM[1] ou PPM[2]? ==============="<<endl<<endl;
	cout<<"Resposta: ";
	cin>>tipo;
	cout<<endl;
	cin.ignore();

	while(tipo < 0 || tipo > 2 ) {
	cout<<endl;
	cout<<"===================== ERRO! DIGITE NOVAMENTE SUA RESPOSTA ====================="<<endl<<endl;
	cout<<"================ Qual tipo é o tipo de imagem PGM[1] ou PPM[2]? ==============="<<endl<<endl;
	cout<<"Resposta: ";
	cin>>tipo;
	cout<<endl;
	cin.ignore();
	}

			switch(tipo){
				case 1:

					cout<<"Digite o caminho da Imagem PGM: ";

					getline(cin,enderecoEntrada);
					imagem_pgm.leituraDeImagem(enderecoEntrada);
					imagem_pgm.decifrador();

					break;

				case 2:
					cout<<"Digite o caminho da Imagem PPM: ";

					getline(cin,enderecoEntrada);
					imagem_ppm.leituraDeImagem(enderecoEntrada);
					imagem_ppm.decifrador();

					break;
			}

	return 0;
}
