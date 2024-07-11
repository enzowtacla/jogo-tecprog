#pragma once
#include "../Jogo/Fases/Fase1.h"
#include "../Jogo/Fases/Fase2.h"
#include "../Jogo/Gerenciadores/GerenciadorGrafico.h"
#include "../Jogo/Gerenciadores/GerenciadorEventos.h"


namespace Jogo {

	class Principal
	{
	private:
		Gerenciadores::GerenciadorGrafico* pGG;
		Gerenciadores::GerenciadorEventos* pEventos;
		
		Fases::Fase* fase;

		void criarFase();
	public:
		Principal();
		~Principal();
		void Executar();
	};
}