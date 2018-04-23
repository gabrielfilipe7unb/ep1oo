#ifndef PGM_HPP
#define PGM_HPP

#include <iostream>
#include <string>
#include "imagem.hpp"

using namespace std;

class PGM : public Imagem{

	private:

		int comecoMensagem;
		int tamanhoTotalMensagem;
		int numMsg;
		char *mensagem;

	public:

		PGM();
		~PGM();

    char *decifrador();

		void setParametros();
		void setComecoMensagem(int comecoMensagem);
		void setTamanhoTotalMensagem(int tamanhoTotalMensagem);
		void setNumMsg(int numMsg);

};

#endif
