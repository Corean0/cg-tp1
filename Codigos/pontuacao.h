// Sistema de pontuação e de fim de jogo
// Pontuador = 1 para Player1 e 2 para Player2

void addPoint(int pontuador)
{
    if(pontos1.pontos == pontos2.pontos && pontos1.pontos == 10)
    {
        if(pontuador == Player1)
        {
            deuce1.pontos++;
        }

        else if(pontuador == Player2)
        {
            deuce2.pontos++;
        }

        // Caso entre em deuce novamente reseta
        if(deuce1.pontos == deuce2.pontos && deuce1.pontos == 1)
        {
            deuce1.pontos = deuce2.pontos = 0;
        }

        else if(deuce1.pontos == 2)
        {
            pontos1.pontos++;
        }

        else if(deuce2.pontos == 2)
        {
            pontos2.pontos++;
        }
    }

    else if(pontuador == Player1)
    {
        pontos1.pontos++;

        if(pontos1.pontos == 10)
        {
            dezena1.pontos = 1;
        }
    }

    else if(pontuador == Player2)
    {
        pontos2.pontos++;

        if(pontos2.pontos == 10)
        {
            dezena2.pontos = 1;
        }
    }

    if(pontos1.pontos == 11)
    {
        addSet(pontuador,tipoJogo);

	   if(set1.pontos != tipoJogo)
        {
	        tempo_switch(TEMPO_TROCA);
        }
    }

    else if(pontos2.pontos == 11)
    {
        addSet(pontuador,tipoJogo);

	   if(set2.pontos != tipoJogo)
       {
	        tempo_switch(TEMPO_TROCA);
       }
    }
}

// Adiciona sets
// 1 para Player1 e 2 para Player2

void addSet(int pontuador, int tipoJogo)
{
    if(pontuador == Player1)
    {
        set1.pontos++;
    }

    else
    {
        set2.pontos++;
    }

    resetPont();
    trocarJogadores();
}

// Conferir quem está na liderança para atribuir o "reizinho"
// 1 para Player1, 2 para Player2, 0 para empatado
int vencedorMomento()
{     
	if(set1.pontos == set2.pontos)
    {
		if(pontos1.pontos == pontos2.pontos)
        {
			if(deuce1.pontos == deuce2.pontos)
            {
				return 0;
			}

            else if(deuce1.pontos > deuce2.pontos)
            {
				return Player1;
			}

            else
            {
				return Player2;
			}

		}

        else if(pontos1.pontos > pontos2.pontos)
        {
			return Player1;
		}

        else
        {
			return Player2;
		}

	}

    else if(set1.pontos > set2.pontos)
    {
		return Player1;
	}

    else
    {
		return Player2;
	}
}