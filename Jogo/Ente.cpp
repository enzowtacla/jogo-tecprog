#include "Ente.h"

namespace Jogo
{
	Gerenciadores::GerenciadorGrafico* Ente::pGG = Gerenciadores::GerenciadorGrafico::getGrafico();

	Ente::Ente(const IDs::ID id) : id(id) {

	}

	Ente::~Ente() {

	}

	const IDs::ID Ente::getId() const {
		return id;
	}
}