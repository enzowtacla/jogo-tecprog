#pragma once

#include "Imagem.h"
#include <map>

namespace Jogo
{
	namespace Animacoes
	{
		class Animacao
		{
		private:
			sf::RectangleShape* corpo;
			std::map<std::string, Imagem*> mapImagem;
			sf::Clock relogio;
			std::string imgAtual;

		public:
			Animacao(sf::RectangleShape* corpo);
			~Animacao();
			void atualizar(const bool paraEsquerda, std::string imgAtual);
			void addAnimacao(const char* caminhoTextura, std::string nomeAnimacao, const unsigned int qtdImagem, const float tempoTroca, const sf::Vector2f escala);
		};
	}
}