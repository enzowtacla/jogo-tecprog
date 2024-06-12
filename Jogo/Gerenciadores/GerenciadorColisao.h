#pragma once

#include "../Entidades/Personagens/Jogadores/Jogador.h"
#include "../Entidades/Personagens/Inimigos/Inimigo.h"
#include "../Entidades/Obstaculos/Obstaculo.h"

namespace Jogo
{
	namespace Gerenciadores
	{
		class GerenciadorColisao
		{
		private:
			Entidades::Personagens::Jogadores::Jogador* pJogador;
			Entidades::Personagens::Jogadores::Jogador* pJogador2;
			std::vector<Entidades::Personagens::Inimigos::Inimigo*> inimigos;
			static GerenciadorColisao* pColisao;
			GerenciadorColisao();

		public:
			~GerenciadorColisao();
			static GerenciadorColisao* getGerenciadorColisao();
			void setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador);
			void setJogador2(Entidades::Personagens::Jogadores::Jogador* pJogador2);
			void addInimigo(Entidades::Personagens::Inimigos::Inimigo* inimigo);
			void removeInimigo(int index);
			void executar();
		};
	}
}
