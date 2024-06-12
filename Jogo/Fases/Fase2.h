#pragma once
#include "Fase.h"


namespace Jogo
{
	namespace Fases
	{
		class Fase2 :public Fase
		{
		public:
			Fase2();
			~Fase2();
			void criarMapa(const std::string& arquivoTxt);
		};
	}
}
