#pragma once

#include <time.h>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Entidade.h"


#define GRAVIDADE 1200.0f

using namespace sf;

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Personagem :public Entidade
			{
			protected:
				Vector2f velFinal;
				bool podeAndar;
				bool paraEsquerda;
				Clock relogio;
				float dt;
				Animacoes::Animacao animacao;

			public:
				Personagem(const Vector2f pos, const Vector2f tam, const float vel, const IDs::ID id);
				~Personagem();
				void andar(const bool paraEsquerda);
				void parar();
				virtual void atualizar() = 0;
				//virtual void atualizarPosicao() = 0;
				Vector2f getVelFinal();
				virtual void desenhar();
				void acaoGravidade();
				const float getTempoDecorrido() const;
			};
		}
	}
}