#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "GerenciadorGrafico.h"
#include "../Ente.h"
#include "../Animacoes/Animacao.h"

namespace Jogo
{
	namespace Entidades
	{
		class Entidade : public Ente
		{
		protected:
			sf::RectangleShape corpo;
			sf::Vector2f pos;
			sf::Vector2f tam;
			bool poderemover;
			
			//static Gerenciadores::GerenciadorGrafico* pGG;

		public:
			Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::ID id);
			~Entidade();
			const sf::RectangleShape getCorpo() const;
			virtual void atualizar() = 0;
			void setPos(const sf::Vector2f pos);
			void setTam(const sf::Vector2f tam);
			sf::Vector2f getPos();
			const sf::Vector2f getTam() const;
			const bool getRemover() const;
			virtual void desenhar();
		};
	}
}