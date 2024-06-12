#pragma once

#include "Lista.h"
#include "../Entidades/Entidade.h"

namespace Jogo
{
	namespace Listas
	{
		class ListaEntidade
		{
		private:
			Lista<Entidades::Entidade> LEs;

		public:
			ListaEntidade();
			~ListaEntidade();
			void addEntidade(Entidades::Entidade* entidade);
			void removerEntidade(Entidades::Entidade* entidade, const bool deletar);
			void removerEntidade(int pos, const bool deletar);
			int getTam();
			Entidades::Entidade* operator[](int pos);
			void executar();
			//void desenharEntidades();
			void limparLista();
		};
	}
}