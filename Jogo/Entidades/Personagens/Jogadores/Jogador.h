#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Personagem.h"

#define VELOCIDADE_JOGADOR_X 200.0f

using namespace sf;

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			namespace Jogadores
			{
				class Jogador : public Personagem
				{
				private:
					void inicializa();

				public:
					Jogador(const Vector2f pos, const Vector2f tam);
					~Jogador();
					const RectangleShape getCorpo();
					void atualizar();
					void atualizarPosicao();
					void atualizarAnimacao();
					void desenhar();
				};
			}
		}
	}
}