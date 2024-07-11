#include "Imagem.h"

using namespace Jogo;
using namespace Animacoes;

Imagem::Imagem(const char* caminhoTextura, const unsigned int qtdImagens, const float tempoTroca, const sf::Vector2f escala) :
	pGG(pGG->getGrafico()), qtdImagens(qtdImagens), tempoTroca(tempoTroca), tempoTotal(0.0f), tamanho(0, 0, 0, 0), imgAtual(0),
	textura(pGG->carregarTextura(caminhoTextura)), escala(escala)
{
	tamanho.width = textura.getSize().x / (float)qtdImagens; //largura da cada imagem, divindo o total da textura pelo número de imagens
	tamanho.height = textura.getSize().y; //altura de cada imagem, igual à altura total da textura
}

Imagem::~Imagem()
{

}

void Imagem::atualizar(const bool paraEsquerda, const float dt)
{
	tempoTotal = tempoTotal + dt;
	if (tempoTotal >= tempoTroca) {
		tempoTotal -= tempoTroca;
		imgAtual++;
		if (imgAtual >= qtdImagens) { //volta para imagem inicial, criando um loop
			imgAtual = 0;
		}
	}
	if (paraEsquerda) {
		tamanho.left = (imgAtual + 1) * abs(tamanho.width);
		tamanho.width = -abs(tamanho.width);
	}
	else {
		tamanho.left = imgAtual * tamanho.width;
		tamanho.width = abs(tamanho.width);
	}
}

void Imagem::resetar()
{
	imgAtual = 0;
	tempoTotal = 0.0f;
}

const sf::IntRect Imagem::getTamanho() const
{
	return tamanho;
}

const sf::Texture* Imagem::getTextura() const
{
	return &textura;
}

const sf::Vector2f Imagem::getEscala() const
{
	return escala;
}