#include "Jogador.h"

using namespace Jogo;
using namespace Entidades;
using namespace Personagens;
using namespace Jogadores;



Jogador::Jogador(const Vector2f pos, const Vector2f tam) :
	Personagem(pos, tam, VELOCIDADE_JOGADOR_X, IDs::ID::jogador)
{
	corpo.setPosition(pos);
	inicializa();
}

Jogador::~Jogador()
{

}

void Jogador::inicializa()
{
	animacao.addAnimacao("./Assets/Parado.png", "PARADO", 11, 0.12f, sf::Vector2f(2, 2));
	animacao.addAnimacao("./Assets/Anda.png", "ANDA", 12, 0.12f, sf::Vector2f(2, 2));
	corpo.setOrigin(sf::Vector2f(tam.x / 2.5f, tam.y / 2.0f));
}

const RectangleShape Jogador::getCorpo()
{
	return corpo;
}

void Jogador::atualizar()
{
	atualizarPosicao();
	atualizarAnimacao();
}

void Jogador::desenhar()
{
	pGG->desenhaElementos(corpo);
}

void Jogador::atualizarPosicao()
{
	acaoGravidade();
	if (podeAndar) {
		dt = getTempoDecorrido();

		float ds = velFinal.x * dt;

		if (paraEsquerda) {
			ds *= -1;
		}
		corpo.move(ds, 0.0f);
	}
	relogio.restart();
}

void Jogador::atualizarAnimacao()
{
	if (podeAndar) {
		animacao.atualizar(paraEsquerda, "ANDA");
	}
	else if (!podeAndar) {
		animacao.atualizar(paraEsquerda, "PARADO");
	}
}