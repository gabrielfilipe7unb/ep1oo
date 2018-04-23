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

    unsigned char *codigoImagem;
    string comentario;
    string reconhecimentoImagem;



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
    string getReconhecimentoImagem();

    unsigned char *getCodigoImagem();
    string getComentario();

    //MÉTODO PARA LEITURA DE DADOS DA IMAGEM
    void leituraDeImagem(string endereco);
};

#endif
