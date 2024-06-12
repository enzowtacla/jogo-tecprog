#include "Inimigo.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Inimigo::Inimigo(const Vector2f pos, const Vector2f tam) :
	Personagem(pos, tam, VELOCIDADE_INIMIGO_X, IDs::ID::inimigo)
{
	//corpo.setPosition(pos);
	corpo.setFillColor(Color::Red);
	inicializa();
	srand(time(NULL));
	moveAleatorio = rand() % 2;
	textura = pGG->carregarTextura("./Assets/inimigo.png");
	corpo.setTexture(&textura);
}

Inimigo::~Inimigo()
{

}

void Inimigo::inicializa()
{
	
}


void Inimigo::movimentoAleatorio()
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

void Inimigo::atualizar()
{
	acaoGravidade();
	movimentoAleatorio();
}

void Inimigo::desenhar()
{
	pGG->desenhaElementos(corpo);
}