#pragma once

#include "../Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>

namespace Jogo
{
	namespace Animacoes
	{
		class Imagem
		{
		private:
			Gerenciadores::GerenciadorGrafico* pGG;
			sf::Texture textura;
			sf::IntRect tamanho;
			const sf::Vector2f escala;
			const unsigned int qtdImagens;
			unsigned int imgAtual;
			const float tempoTroca;
			float tempoTotal;

		public:
			Imagem(const char* caminhoTextura, const unsigned int qtdImagens, const float tempoTroca, const sf::Vector2f escala);
			~Imagem();
			void atualizar(const bool paraEsquerda, const float dt);
			void resetar();
			const sf::IntRect getTamanho() const;
			const sf::Texture* getTextura() const;
			const sf::Vector2f getEscala() const;
		};
	}
}
