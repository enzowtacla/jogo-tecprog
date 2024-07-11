#pragma once

#include "../Personagem.h"

using namespace sf;

#define VELOCIDADE_INIMIGO_X 0.025f

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Inimigo : public Personagem
				{
				private:
					//Texture textura;
					short moveAleatorio;
					void inicializa();

				public:
					Inimigo(const Vector2f pos, const Vector2f tam);
					~Inimigo();
					//void movimentoAleatorio();
					virtual void atualizar() = 0;
					void desenhar();
				};
			}
		}
	}
}