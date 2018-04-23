#include "pgm.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

PGM::PGM(){
}
PGM::~PGM(){
}

void PGM::setComecoMensagem(int comecoMensagem){
	this->comecoMensagem = comecoMensagem;
}
void PGM::setTamanhoTotalMensagem(int tamanhoTotalMensagem){
	this->tamanhoTotalMensagem = tamanhoTotalMensagem;
}

void PGM::setParametros(){

	stringstream comentario;

	comentario << getComentario();
	comentario >> this->comecoMensagem >>this->tamanhoTotalMensagem >>this->numMsg;
}


void PGM::setNumMsg(int numMsg){
	this->numMsg = numMsg;
}

char *PGM::decifrador(){

	unsigned char *codigo;

	setParametros();

	this->mensagem = new char[tamanhoTotalMensagem]; //ADAPTAÇÃO DO TAMANHO DE IMAGEM À PGM (*1)
	codigo = new unsigned char [getAltura() * getLargura() * getDimensoes()];
	codigo = getCodigoImagem();

	//DECIFRA A MENSAGEM
	for(int i = comecoMensagem, count = 0; i < (comecoMensagem + tamanhoTotalMensagem); i++, count++){

		if(codigo[i]>='a' && codigo[i] <= 'z'){

			if((codigo[i] - numMsg) < 'a')
				codigo[i] += (26 - numMsg);
			else
				codigo[i] -= numMsg;
		}

		else if(codigo[i]>='A' && codigo[i] <= 'Z'){

			if((codigo[i] - numMsg) < 'A')
				codigo[i] += (26 - numMsg);
			else
				codigo[i] -= numMsg;
		}

		this->mensagem[count] = codigo[i];
	}

	cout<<endl;
	cout<<"A mensagem descriptografada é: " << mensagem <<endl;
	cout<<endl;

	return this->mensagem;
}
