#pragma once
#include <fstream>
#include <iostream>
#include "../Listas/ListaEntidade.h"
#include "../Ente.h"
#include "../Gerenciadores/GerenciadorColisao.h"
#include "../Gerenciadores/GerenciadorEventos.h"
#include "../Entidades/Personagens/Inimigos/Aleatorio.h"
#include "../Entidades/Personagens/Inimigos/Perseguidor.h"

namespace Jogo
{
	namespace Fases
	{
		class Fase : public Ente
		{
		protected:
			Listas::ListaEntidade listaPersonagem;
			Listas::ListaEntidade listaObstaculos;
			Gerenciadores::GerenciadorColisao* pColisao;
			Gerenciadores::GerenciadorEventos* pEventos;

		public:
			Fase(const IDs::ID id);
			~Fase();
			void criarAleatorio(const sf::Vector2f pos);
			void criarPerseguidor(const sf::Vector2f pos);
			void criarJogador1(const sf::Vector2f pos);
			void criarJogador2(const sf::Vector2f pos);
			void criarObstaculo(const sf::Vector2f pos);
			//virtual void carregarFundo() = 0;
			virtual void criarMapa(const std::string& arquivoTxt) = 0;
			void criarEntidade(char letra, const sf::Vector2i pos);
			void executar();
			void desenhar();
		};

	}
}