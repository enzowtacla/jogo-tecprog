#pragma once

#include "../Gerenciadores/GerenciadorColisao.h"
#include "../Entidades/Personagens/Jogadores/Jogador.h"

namespace Jogo 
{
	namespace Gerenciadores
	{
		class GerenciadorEventos
		{
		private:
			GerenciadorGrafico* pGG;
			Entidades::Personagens::Jogadores::Jogador* pJogador;
			Entidades::Personagens::Jogadores::Jogador* pJogador2;
			static GerenciadorEventos* pEventos;
			GerenciadorEventos();

		public:
			~GerenciadorEventos();
			static GerenciadorEventos* getGerenciadorEventos();
			void setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador);
			void setJogador2(Entidades::Personagens::Jogadores::Jogador* pJogador2);
			void verificaTeclaPressionada(sf::Keyboard::Key tecla);
			void verificaTeclaSolta(sf::Keyboard::Key tecla);
			void executar();
		};
	}
}