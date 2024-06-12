#pragma once

#include "../Entidade.h"

using namespace sf;

namespace Jogo
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Obstaculo : public Entidade
			{
			private:
				sf::Texture textura;
			public:
				Obstaculo(const Vector2f pos, const Vector2f tam);
				~Obstaculo();
				void atualizar(); //desenhar
			};
		}
	}
}