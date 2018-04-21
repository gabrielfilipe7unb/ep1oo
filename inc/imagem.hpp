#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <iostream>
#include <string>

using namespace std;

class Imagem{

  private:

    int dimensoes;
    int altura;
    int largura;
    int pixelMax;

    string codigoImagem;
    string comentario;

    unsigned char *codigo;


  public:

    //MÉTODO CONTRUTOR
    Imagem();
    //MÉTODO DESTRUTOR
    ~Imagem();

    //MÉTODOS ACESSORES
    int getAltura();
    int getLargura();
    int getPixelMax();
    int getDimensoes();

    string getCodigoImagem();
    string getComentario();

    unsigned char *getCodigo();

    //MÉTODO PARA LEITURA DE DADOS DA IMAGEM
    void leituraDeImagem(string endereco);
};

#endif
