#pragma once
#include "Fase.h"


namespace Jogo
{
	namespace Fases
	{
		class Fase1 :public Fase
		{
		public:
			Fase1();
			~Fase1();
			void criarMapa(const std::string& arquivoTxt);
		};
	}
}