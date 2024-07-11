#include "Aleatorio.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Aleatorio::Aleatorio(const Vector2f pos, const Vector2f tam) : Inimigo(pos, tam)
{
	IDs::ID::aleatorio;
	corpo.setFillColor(Color::Cyan);
	srand(time(NULL));
	moveAleatorio = rand() % 2;
}

Aleatorio::~Aleatorio()
{

}

void Aleatorio::movimentoAleatorio()
{
	if (moveAleatorio == 0)
	{
		corpo.move(velFinal.x, 0.0f);
	}
	else
	{
		corpo.move(-velFinal.x, 0.0f);
	}

	float dt = relogio.getElapsedTime().asSeconds();

	if (dt >= 1.0f) {
		moveAleatorio = rand() % 2;
		relogio.restart();
	}
}

void Aleatorio::atualizar()
{
	acaoGravidade();
	movimentoAleatorio();
}