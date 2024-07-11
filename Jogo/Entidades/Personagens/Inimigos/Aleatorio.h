#pragma once

#include "Inimigo.h"


namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Inimigos
			{
				class Aleatorio :public Inimigo
				{
				private:
					short moveAleatorio;

				public:
					Aleatorio(const Vector2f pos, const Vector2f tam);
					~Aleatorio();
					void movimentoAleatorio();
					void atualizar();
				};
			}
		}
	}
}