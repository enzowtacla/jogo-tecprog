#include "Obstaculo.h"

using namespace Jogo;
using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo(const Vector2f pos, const Vector2f tam) : Entidade(pos, tam, IDs::ID::obstaculo)
{
	//corpo.setPosition(pos);
	textura = pGG->carregarTextura("./Assets/plataforma.png");
	corpo.setTexture(&textura);
}

Obstaculo::~Obstaculo()
{

}

void Obstaculo::atualizar()
{
	desenhar();
}
