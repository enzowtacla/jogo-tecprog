#include "Fase2.h"

using namespace Jogo;
using namespace Fases;

Fase2::Fase2() : Fase(IDs::ID::fase2)
{

}

Fase2::~Fase2()
{

}

void Fase2::criarMapa(const std::string& arquivoTxt)
{
	std::ifstream arquivo(arquivoTxt);
	std::string linha;

	if (!arquivo.is_open())
	{
		std::cout << "Nao foi possivel abrir o mapa da fase 2" << std::endl;
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