#include "Perseguidor.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Entidades::Personagens::Jogadores::Jogador* Perseguidor::pJogador = nullptr;
Entidades::Personagens::Jogadores::Jogador* Perseguidor::pJogador2 = nullptr;

Perseguidor::Perseguidor(const Vector2f pos, const Vector2f tam) :Inimigo(pos, tam)
{
	IDs::ID::perseguidor;
	corpo.setFillColor(Color::Magenta);
}

Perseguidor::~Perseguidor()
{

}
void Perseguidor::setJogador(Entidades::Personagens::Jogadores::Jogador* j)
{
	pJogador = j;
}

void Perseguidor::setJogador2(Entidades::Personagens::Jogadores::Jogador* j)
{
	pJogador2 = j;
}

void Perseguidor::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x - posInimigo.x > 0.f) {
		corpo.move(velFinal.x, 0.f);
	}
	else {
		corpo.move(-velFinal.x, 0.f);
	}
}
void Perseguidor::mover()
{
	sf::Vector2f posJogador1 = pJogador->getCorpo().getPosition();
	sf::Vector2f posJogador2 = pJogador2->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();
	float dist1 = fabs(posJogador1.x - posInimigo.x);
	float dist2 = fabs(posJogador2.x - posInimigo.x);

	if (dist1 <= RAIO_PERSEGUIR_X && dist2 > RAIO_PERSEGUIR_X) {
		persegueJogador(posJogador1, posInimigo);
	}
	else if (dist2 < RAIO_PERSEGUIR_X && dist1 > RAIO_PERSEGUIR_X) {
		persegueJogador(posJogador2, posInimigo);
	}
	else if (dist1 <= RAIO_PERSEGUIR_X && dist2 <= RAIO_PERSEGUIR_X) {
		if (dist1 <= dist2) {
			persegueJogador(posJogador1, posInimigo);
		}
		else {
			persegueJogador(posJogador2, posInimigo);
		}
	}
}

void Perseguidor::atualizar()
{
	acaoGravidade();
	mover();
}