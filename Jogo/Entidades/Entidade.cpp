#include "Entidade.h"

using namespace Jogo;
using namespace Entidades;


Entidade::Entidade(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::ID id):
	Ente(id), corpo(sf::RectangleShape(tam)), pos(pos), tam(tam), poderemover(false)
{
	corpo.setPosition(pos);
}

Entidade::~Entidade()
{

}

const sf::RectangleShape Entidade::getCorpo() const
{
	return corpo;
}

void Entidade::setPos(const sf::Vector2f pos)
{
	corpo.setPosition(pos);
	this->pos = pos;
}

void Entidade::setTam(const sf::Vector2f tam)
{
	corpo.setSize(tam);
	this->tam = tam;
}

sf::Vector2f Entidade::getPos() 
{
	return corpo.getPosition();
}

const sf::Vector2f Entidade::getTam() const
{
	return tam;
}

const bool Entidade::getRemover() const
{
	return poderemover;
}

void Entidade::desenhar()
{
	pGG->desenhaElementos(corpo);
}