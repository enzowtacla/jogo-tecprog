#include "GerenciadorColisao.h"

using namespace Jogo;
using namespace Gerenciadores;

GerenciadorColisao* GerenciadorColisao::pColisao(nullptr);

GerenciadorColisao::GerenciadorColisao() :
	pJogador(nullptr), pJogador2(nullptr)
{

}

GerenciadorColisao::~GerenciadorColisao()
{
	inimigos.clear();
}

GerenciadorColisao* GerenciadorColisao::getGerenciadorColisao()
{
	if (!pColisao) {
		pColisao = new GerenciadorColisao();
	}

	return pColisao;
}

void GerenciadorColisao::setJogador(Entidades::Personagens::Jogadores::Jogador* pJogador)
{
	this->pJogador = pJogador;
}

void GerenciadorColisao::setJogador2(Entidades::Personagens::Jogadores::Jogador* pJogador2)
{
	this->pJogador2 = pJogador2;
}

void GerenciadorColisao::addInimigo(Entidades::Personagens::Inimigos::Inimigo* inimigo)
{
	if (inimigo) {
		inimigos.push_back(inimigo);
	}
	else
		std::cout << "Nao foi possivel adicionar o inimigo no vector" << std::endl;
}

void GerenciadorColisao::removeInimigo(int index)
{
	inimigos[index] = nullptr;
}

void GerenciadorColisao::executar()
{
	for (int i = 0; i < inimigos.size(); i++)
	{
		if (inimigos.at(i))
		{
			float distanciaX;
			float distanciaY;

			if (pJogador)
			{
				distanciaX = pJogador->getPos().x - inimigos.at(i)->getPos().x;
				distanciaY = pJogador->getPos().y - inimigos.at(i)->getPos().y;

				if (fabs(distanciaY) <= 20.0f && fabs(distanciaX) <= 10.0f)
				{
					std::cout << "Colidiu com o jogador 1" << std::endl;
				}
			}

			if (pJogador2)
			{
				distanciaX = pJogador2->getPos().x - inimigos.at(i)->getPos().x;
				distanciaY = pJogador2->getPos().y - inimigos.at(i)->getPos().y;

				if (fabs(distanciaY) <= 20.0f && fabs(distanciaX) <= 10.0f)
				{
					std::cout << "Colidiu com o jogador 2" << std::endl;
				}
			}
		}
	}
}