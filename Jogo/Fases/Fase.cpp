#include "Fase.h"
using namespace Jogo;
using namespace Fases;


Fase::Fase(const IDs::ID id) :Ente(id), listaObstaculos(), listaPersonagem(), pColisao(pColisao->getGerenciadorColisao()), pEventos(pEventos->getGerenciadorEventos())
{
	if (!pColisao) {
		std::cout << "Nao foi possivel criar um gerenciador de colisoes" << std::endl;
		exit(1);
	}
	if (!pEventos) {
		std::cout << "Nao foi possivel criar um gerenciador de eventos" << std::endl;
		exit(1);
	}
}

Fase::~Fase()
{
	if (pColisao) 
		pColisao = nullptr;
	
	listaPersonagem.limparLista();
	listaObstaculos.limparLista();
}

void Fase::criarInimigo(const sf::Vector2f pos)
{
	Entidades::Personagens::Inimigos::Inimigo* inimigo = new Entidades::Personagens::Inimigos::Inimigo(pos, sf::Vector2f(50.0f, 50.0f));

	if (!inimigo){
		std::cout << "Nao foi possivel criar o inimigo" << std::endl;
	}

	listaPersonagem.addEntidade(static_cast<Entidades::Entidade*>(inimigo));

	pColisao->addInimigo(inimigo);
}

void Fase::criarObstaculo(const sf::Vector2f pos)
{
	Entidades::Obstaculos::Obstaculo* plataforma1 = new Entidades::Obstaculos::Obstaculo(pos, Vector2f(350.0f, 50.0f));

	if (!plataforma1) {
		std::cout << "Nao foi possivel criar a plataforma" << std::endl;
	}

	listaObstaculos.addEntidade(static_cast<Entidades::Entidade*>(plataforma1));
}

void Fase::criarJogador1(const sf::Vector2f pos)
{
	Entidades::Personagens::Jogadores::Jogador* jogador1 = new Entidades::Personagens::Jogadores::Jogador(pos, Vector2f(20.0f, 45.0f));

	if (!jogador1) {
		std::cout << "Nao foi possivel criar o jogador 1" << std::endl;
	}

	listaPersonagem.addEntidade(static_cast<Entidades::Entidade*>(jogador1));

	pEventos->setJogador(jogador1);
	pColisao->setJogador(jogador1);
}

void Fase::criarJogador2(const sf::Vector2f pos)
{
	Entidades::Personagens::Jogadores::Jogador* jogador2 = new Entidades::Personagens::Jogadores::Jogador(pos, Vector2f(20.0f, 45.0f));

	if (!jogador2) {
		std::cout << "Nao foi possivel criar o jogador 2" << std::endl;
	}

	listaPersonagem.addEntidade(static_cast<Entidades::Entidade*>(jogador2));

	pEventos->setJogador2(jogador2);
	pColisao->setJogador2(jogador2);
}

void Fase::criarEntidade(char letra, const sf::Vector2i pos)
{
	switch (letra)
	{
		case('i'):
		{
			criarInimigo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('o'):
		{
			criarObstaculo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('j'):
		{
			criarJogador1(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;

		case('J'):
		{
			criarJogador2(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f));
		}
		break;
	}
}

void Fase::desenhar()
{
	listaObstaculos.executar();
	listaPersonagem.executar();
}

void Fase::executar()
{
	pColisao->executar();
	desenhar();
}