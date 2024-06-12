#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

namespace Jogo
{
	namespace Gerenciadores
	{
		class GerenciadorGrafico
		{
		private:
			RenderWindow* janela;

			//static float tempo;
			//sf::Clock relogio;

			static GerenciadorGrafico* pGG;
			GerenciadorGrafico();

		public:
			~GerenciadorGrafico();
			static GerenciadorGrafico* getGrafico();
			RenderWindow* getJanela();
			void limpaJanela();
			void desenhaElementos(RectangleShape corpo);
			void mostraElementos();
			void fecharJanela();
			const bool verificaJanelaAberta();
			Texture carregarTextura(const char* caminhoTextura);
			/*void resetarRelogio();
			const float getTempo() const;*/
		};
	}
}