#pragma once
#include "iostream"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "IDs/ID.h"

namespace Jogo
{
	class Ente
	{
	protected:
		static Gerenciadores::GerenciadorGrafico* pGG;
		const IDs::ID id;

	public:
		Ente(const IDs::ID id);
		~Ente();
		const IDs::ID getId() const;
		virtual void desenhar() = 0;
	};
}