#pragma once
#include "Inimigo.h"
#include "../Jogadores/Jogador.h"
#define RAIO_PERSEGUIR_X 200.0f

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Perseguidor :public Inimigo
				{
				private:
					static Entidades::Personagens::Jogadores::Jogador* pJogador;
					static Entidades::Personagens::Jogadores::Jogador* pJogador2;
				public:
					Perseguidor(const Vector2f pos, const Vector2f tam);
					~Perseguidor();
					static void setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador);
					static void setJogador2(Entidades::Personagens::Jogadores::Jogador* pJogador2);
					void atualizar();
					void mover();
					void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
				};
			}
		}
	}
}