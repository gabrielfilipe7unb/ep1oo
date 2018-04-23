#include "imagem.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//MÉTODO CONTRUTOR
Imagem::Imagem(){}
//MÉTODO DESTRUTOR
Imagem::~Imagem(){}

//MÉTODOS ACESSORES
int Imagem::getDimensoes(){
  return dimensoes;
}
int Imagem::getAltura(){
  return altura;
}
int Imagem::getLargura(){
  return largura;
}
int Imagem::getPixelMax(){
  return pixelMax;
}
string Imagem::getReconhecimentoImagem(){
	return reconhecimentoImagem;
}

unsigned char *Imagem::getCodigoImagem(){
  return codigoImagem;
}

string Imagem::getComentario(){
  return comentario;
}

//MÉTODO PARA LEITURA DE DADOS DA IMAGEM
void Imagem::leituraDeImagem(string endereco){

  char caractere;
  ifstream file(endereco);

  if(!file.is_open()){

    cout << endl;
    cout <<"Falha ao ler arquivo"<< endl;
    cout << endl;
  }
  else{

    getline(file,reconhecimentoImagem); //LEITURA DA PRIMEIRA LINHA DO CABEÇALHO DO ARQUIVO;

    if (reconhecimentoImagem == "P2" || reconhecimentoImagem == "P5") //IDENTIFICAÇÃO DO TIPO DE IMAGEM PGM;
      dimensoes = 1;
    else if (reconhecimentoImagem == "P3" || reconhecimentoImagem == "P6") //IDENTIFICAÇÃO DO TIPO DE IMAGEM PPM;
      dimensoes = 3;

    file.get(caractere); //LEITURA DA SEGUNDA LINHA DO CABEÇALHO DO ARQUIVO;

    if(caractere == '#')
      getline(file, comentario);

    file >> altura >> largura >> pixelMax; //LEITURA DA TERCEIRA E QUARTA LINHA DO CABEÇALHO DO ARQUIVO;
    file.get();

    codigoImagem = new unsigned char [altura*largura*dimensoes];

    for(int i = 0; file.get(caractere); i++)
      codigoImagem[i] = caractere;

    file.close();

    }
}
