#include "Inimigo.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Inimigo::Inimigo(const Vector2f pos, const Vector2f tam) :
	Personagem(pos, tam, VELOCIDADE_INIMIGO_X, IDs::ID::inimigo)
{
	inicializa();
	//textura = pGG->carregarTextura("./Assets/inimigo.png");
	//corpo.setTexture(&textura);
}

Inimigo::~Inimigo()
{

}

void Inimigo::inicializa()
{
	
}

void Inimigo::desenhar()
{
	pGG->desenhaElementos(corpo);
}