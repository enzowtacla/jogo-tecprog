#include "Fase1.h"

using namespace Jogo;
using namespace Fases;

Fase1::Fase1() : Fase(IDs::ID::fase1)
{

}

Fase1::~Fase1()
{

}

void Fase1::criarMapa(const std::string& arquivoTxt)
{
	std::ifstream arquivo(arquivoTxt);
	std::string linha;
	
	if (!arquivo.is_open())
	{
		std::cout << "Nao foi possivel abrir o mapa da fase 1" << std::endl;
		exit(1);
	}
	int j = 0;
	while (std::getline(arquivo, linha))
	{
		for (int i = 0; i < linha.size(); i++)
		{
			if (linha[i] != ' ') {
				criarEntidade(linha[i], sf::Vector2i(i, j));
			}
		}
		j++;
	}
	arquivo.close();
}