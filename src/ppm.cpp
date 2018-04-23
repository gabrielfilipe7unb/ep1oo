#include "ppm.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

PPM::PPM(){
}
PPM::~PPM(){
}

void PPM::setTamanhoTotalMensagem(int tamanhoTotalMensagem){
	this->tamanhoTotalMensagem = tamanhoTotalMensagem;
}
void PPM::setComecoMensagem(int comecoMensagem){
	this->comecoMensagem = comecoMensagem;
}
void PPM::setParametros(){

	stringstream comentario;

	this->keyWord = new char[28];

	comentario << getComentario();//RECEBE AS STRINGS SEPARADAMENTE PELOS ESPAÇOS

	comentario >> this->comecoMensagem >>this->tamanhoTotalMensagem >>this->keyWord;
}

void PPM::setAlfabeto(){

	char letra;
	bool letra_Existe;

	this->letrasAlfabeto = new char[27];

	for(unsigned int i = 0; i < 27; i++){

		if(i == 0)
			this->letrasAlfabeto[i]=' ';
		else if(i <= strlen(this->keyWord))
			this->letrasAlfabeto[i] = this->keyWord[i-1];

	}

	for(int i = strlen(this->keyWord)+1, contador = 0; i < 27 ; contador++){

		letra = 97 + contador; 		//CONVERSOR PARA TABELA ASCII
		letra_Existe = false;

		for(unsigned int j = 0; j < strlen(this->keyWord); j++){

			if(letra == this->keyWord[j])
				letra_Existe = true;
		}

		if(letra_Existe == false){

			this->letrasAlfabeto[i] = letra;
			i++;

		}
	}
}

char *PPM::decifrador(){

	setParametros();
	setAlfabeto();

	unsigned char *codigo;
	char letra;
	int posicao_letra;

	int numCodigo[tamanhoTotalMensagem * getDimensoes()]; //ADAPTAÇÃO DO TAMANHO DE IMAGEM À PPM (*3)
	this->mensagem = new char[this->tamanhoTotalMensagem * getDimensoes()];
	codigo = getCodigoImagem();

	//COM O PASSAR DE TRÊS VALORES O VALOR INDICE DO LAÇO MUDA.
	for(int i = comecoMensagem, indice_num = 0, count = 0; i < (comecoMensagem + (tamanhoTotalMensagem * getDimensoes())); i++, count++){

		if(count > 2){
			count = 0;
			indice_num++;
		}
		if(count == 0)
			numCodigo[indice_num] = 0;
		if(count < 3)
			numCodigo[indice_num] = numCodigo[indice_num] + (codigo[i] % 10);
	}

	//DECIFRA A MENSAGEM
	for(int i=0; i<(tamanhoTotalMensagem); i++){

		if (numCodigo[i] == 0) //RECONHECE O ESPAÇO
			letra = 32;
    else
    	letra = numCodigo[i] + 96; //RECONHECE AS LETRAS MINUSCULAS DE ACORDO COM A TABELA ASCII
      
    for(int j = 0; j < 27; j++){ //COMPARA COM O ALFABETO USUAL
    	if(letra == letrasAlfabeto[j])
    		posicao_letra = j;
    		}
    		if(posicao_letra == 0)
    			mensagem[i] = 32; //RECONHECE O ESPAÇO
    		else
    			mensagem[i] = posicao_letra + 64;
   	}
	cout<<endl;
	cout<<"A mensagem descriptografada é: " << mensagem <<endl;
	cout<<endl;
	return this->mensagem;
}
