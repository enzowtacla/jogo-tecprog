#include "GerenciadorEventos.h"

using namespace Jogo;
using namespace Gerenciadores;

GerenciadorEventos* GerenciadorEventos::pEventos(nullptr);

GerenciadorEventos::GerenciadorEventos():
	pGG(pGG->getGrafico()), pJogador(nullptr), pJogador2(nullptr)
{

}

GerenciadorEventos::~GerenciadorEventos()
{

}

GerenciadorEventos* GerenciadorEventos::getGerenciadorEventos()
{
	if (!pEventos) {
		pEventos = new GerenciadorEventos();
	}
	return pEventos;
}

void GerenciadorEventos::setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador)
{
	this->pJogador = pJogador;
}

void GerenciadorEventos::setJogador2(Entidades::Personagens::Jogadores::Jogador* pJogador2)
{
	this->pJogador2 = pJogador2;
}

void GerenciadorEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::A) {
		pJogador->andar(true);
	}
	else if (tecla == sf::Keyboard::D) {
		pJogador->andar(false);
	}
	else if (tecla == sf::Keyboard::Left) {
		pJogador2->andar(true);
	}
	else if (tecla == sf::Keyboard::Right) {
		pJogador2->andar(false);
	}
}

void GerenciadorEventos::verificaTeclaSolta(sf::Keyboard::Key tecla)
{
	if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D)
	{
		pJogador->parar();
	}
	else if (tecla == sf::Keyboard::Left || tecla == sf::Keyboard::Right)
	{
		pJogador2->parar();
	}
}

void GerenciadorEventos::executar()
{
	sf::Event evento;

	if(pGG->getJanela()->pollEvent(evento))
	{
		if (evento.type == sf::Event::KeyPressed) {
			verificaTeclaPressionada(evento.key.code);
		}
		else if (evento.type == sf::Event::KeyReleased) {
			verificaTeclaSolta(evento.key.code);
		}
		else if (evento.type == sf::Event::Closed) {
			pGG->fecharJanela();
		}
	}
}

