#include "GerenciadorGrafico.h"

using namespace sf;
using namespace Jogo;
using namespace Gerenciadores;

GerenciadorGrafico* GerenciadorGrafico::pGG(nullptr);
//float GerenciadorGrafico::tempo(0.0f);

GerenciadorGrafico::GerenciadorGrafico() :
	janela(new RenderWindow(VideoMode(800.0f, 600.0f), "Jogo++"))//, relogio()
{
	if (!janela) {
		std::cout << "Erro ao criar a janela" << std::endl;
		exit(1);
	}
	janela->setFramerateLimit(0);
}


GerenciadorGrafico::~GerenciadorGrafico()
{
	if (janela) {
		delete janela;
		janela = nullptr;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGrafico()
{
	if (!pGG) {
		pGG = new GerenciadorGrafico();
	}
	return pGG;
}

RenderWindow* GerenciadorGrafico::getJanela()
{
	return janela;
}

void GerenciadorGrafico::limpaJanela()
{
	janela->clear();
}

void GerenciadorGrafico::desenhaElementos(RectangleShape corpo)
{
	janela->draw(corpo);
}

void GerenciadorGrafico::mostraElementos()
{
	janela->display();
}

void GerenciadorGrafico::fecharJanela()
{
	janela->close();
}

const bool GerenciadorGrafico::verificaJanelaAberta()
{
	if (janela->isOpen()) {
		return true;
	}
	else {
		return false;
	}
}

Texture GerenciadorGrafico::carregarTextura(const char* caminhoTextura)
{
	Texture textura;

	if (!textura.loadFromFile(caminhoTextura)) {
		std::cout << "Nao foi possivel carregar a textura do obstaculo" << std::endl;
		exit(1);
	}

	return textura;
}

/*void GerenciadorGrafico::resetarRelogio()
{
	tempo = relogio.getElapsedTime().asSeconds();
	relogio.restart();
}

const float GerenciadorGrafico::getTempo() const
{
	tempo = relogio.getElapsedTime().asSeconds();
	return tempo;
}*/