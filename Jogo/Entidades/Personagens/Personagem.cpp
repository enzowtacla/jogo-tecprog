#include "Personagem.h"
using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace sf;

Personagem::Personagem(const Vector2f pos, const Vector2f tam, const float vel, const IDs::ID id) :
	Entidade(pos,tam, id), velFinal(vel, 0.0f), podeAndar(false), paraEsquerda(false), relogio(), dt(0.0f), animacao(&corpo)
{

}

Personagem::~Personagem()
{

}

void Personagem::andar(const bool paraEsquerda)
{
	podeAndar = true;
	this->paraEsquerda = paraEsquerda;
}

void Personagem::parar()
{
	podeAndar = false;
}

/*void Personagem::atualizarPosicao()
{

	dt = getTempoDecorrido();
	
	float ds = velFinal.x * dt;

	if (paraEsquerda) {
		ds *= -1;
	}
	corpo.move(ds, 0.0f);

}*/

Vector2f Personagem::getVelFinal()
{
	return velFinal;
}

void Personagem::desenhar()
{
	pGG->desenhaElementos(corpo);
}

void Personagem::acaoGravidade()
{
	dt = getTempoDecorrido();

	float Vy = GRAVIDADE * dt;
	corpo.move(0, Vy);

	// Verificação de colisão com a parte inferior da janela
	if (corpo.getPosition().y + 50.f > 550.f) {
		corpo.setPosition(corpo.getPosition().x, 550.f - 50.f);
	}
}

const float Personagem::getTempoDecorrido() const
{
	return relogio.getElapsedTime().asSeconds();
}