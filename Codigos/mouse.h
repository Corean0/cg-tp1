// Registrando a posicao atual do mouse
// A posicao y nesta funcao assume um eixo em y invertido, portanto precisamos dos condicionais
// Realizamos essa parte antes do dia 12/09, no qual foi ensinado um jeito mais geral de realizar
void mouseMove(int x, int y)
{
    mouse.posicao.x = x;

    if(y < altura/2)
    {
    	mouse.posicao.y = altura/2 - y + altura/2;
    }

    else
    {
    	mouse.posicao.y = - y + altura;
    }

    // Realizando o efeito hover na selacao dos sets
	if(tela == 2)
	{
		set_1.textura = loadTexture("../Imagens/1set.png");

		if(mouse.posicao.x < set_1.posicao.x + set_1.dimensoes.x/2 && mouse.posicao.x > set_1.posicao.x - set_1.dimensoes.x/2 &&
		   mouse.posicao.y < set_1.posicao.y + set_1.dimensoes.y/2 && mouse.posicao.y > set_1.posicao.y - set_1.dimensoes.y/2)
		{
			set_1.textura = loadTexture("../Imagens/1set_preto.png");
		}

		set_3.textura = loadTexture("../Imagens/3set.png");

		if(mouse.posicao.x < set_3.posicao.x + set_3.dimensoes.x/2 && mouse.posicao.x > set_3.posicao.x - set_3.dimensoes.x/2 &&
		   mouse.posicao.y < set_3.posicao.y + set_3.dimensoes.y/2 && mouse.posicao.y > set_3.posicao.y - set_3.dimensoes.y/2)
		{
			set_3.textura = loadTexture("../Imagens/3set_preto.png");
		}

		set_5.textura = loadTexture("../Imagens/5set.png");

		if(mouse.posicao.x < set_5.posicao.x + set_5.dimensoes.x/2 && mouse.posicao.x > set_5.posicao.x - set_5.dimensoes.x/2 &&
		   mouse.posicao.y < set_5.posicao.y + set_5.dimensoes.y/2 && mouse.posicao.y > set_5.posicao.y - set_5.dimensoes.y/2)
		{
			set_5.textura = loadTexture("../Imagens/5set_preto.png");
		}

		set_7.textura = loadTexture("../Imagens/7set.png");

		if(mouse.posicao.x < set_7.posicao.x + set_7.dimensoes.x/2 && mouse.posicao.x > set_7.posicao.x - set_7.dimensoes.x/2 &&
		   mouse.posicao.y < set_7.posicao.y + set_7.dimensoes.y/2 && mouse.posicao.y > set_7.posicao.y - set_7.dimensoes.y/2)
		{
			set_7.textura = loadTexture("../Imagens/7set_preto.png");
		}

		set_9.textura = loadTexture("../Imagens/9set.png");

		if(mouse.posicao.x < set_9.posicao.x + set_9.dimensoes.x/2 && mouse.posicao.x > set_9.posicao.x - set_9.dimensoes.x/2 &&
		   mouse.posicao.y < set_9.posicao.y + set_9.dimensoes.y/2 && mouse.posicao.y > set_9.posicao.y - set_9.dimensoes.y/2)
		{
			set_9.textura = loadTexture("../Imagens/9set_preto.png");
		}

		switch (tipoJogo)
		{
			case 1:
				set_1.textura = loadTexture("../Imagens/1set_preto.png");
				break;

			case 3:
				set_3.textura = loadTexture("../Imagens/3set_preto.png");
				break;

			case 5:
				set_5.textura = loadTexture("../Imagens/5set_preto.png");
				break;

			case 7:
				set_7.textura = loadTexture("../Imagens/7set_preto.png");
				break;
				
			case 9:
				set_9.textura = loadTexture("../Imagens/9set_preto.png");
				break;
		}
	}
}

// Clique do mouse
void mouseClick(int botao, int estado, int x, int y)
{
	switch(botao)
    {
		case GLUT_LEFT_BUTTON :

			// Menu
			if(tela == 0)
			{
				// Teclando Jogar
				if(mouse.posicao.x < jogar.posicao.x + jogar.dimensoes.x/2 && mouse.posicao.x > jogar.posicao.x - jogar.dimensoes.x/2 &&
				   mouse.posicao.y < jogar.posicao.y + jogar.dimensoes.y/2 && mouse.posicao.y > jogar.posicao.y - jogar.dimensoes.y/2)
				{
					tela = 1;
					sleep_bola(DELAY_SET);
				}

				// Teclando Opcoes
				if(mouse.posicao.x < opcoes.posicao.x + opcoes.dimensoes.x/2 && mouse.posicao.x > opcoes.posicao.x - opcoes.dimensoes.x/2 &&
				   mouse.posicao.y < opcoes.posicao.y + opcoes.dimensoes.y/2 && mouse.posicao.y > opcoes.posicao.y - opcoes.dimensoes.y/2)
				{
					tela = 2;
				}

				// Teclando Creditos
				if(mouse.posicao.x < creditos.posicao.x + creditos.dimensoes.x/2 && mouse.posicao.x > creditos.posicao.x - creditos.dimensoes.x/2 &&
				   mouse.posicao.y < creditos.posicao.y + creditos.dimensoes.y/2 && mouse.posicao.y > creditos.posicao.y - creditos.dimensoes.y/2)
				{
					tela = 3;
				}

				// Teclando Sair
				if(mouse.posicao.x < saida.posicao.x + saida.dimensoes.x/2 && mouse.posicao.x > saida.posicao.x - saida.dimensoes.x/2 &&
				   mouse.posicao.y < saida.posicao.y + saida.dimensoes.y/2 && mouse.posicao.y > saida.posicao.y - saida.dimensoes.y/2)
				{
					exit(0);
				}
			}

			// Tela do Jogo
			else if(tela == 1)
			{
				if(reset == 1)
				{
					// Confirmando o reset (Sim)
					if(mouse.posicao.x < yes.posicao.x + yes.dimensoes.x/2 && mouse.posicao.x > yes.posicao.x - yes.dimensoes.x/2 &&
					   mouse.posicao.y < yes.posicao.y + yes.dimensoes.y/2 && mouse.posicao.y > yes.posicao.y - yes.dimensoes.y/2)
					{
						resetAll();
						pause ++;
						reset = 0;
					}

					// Negando o reset (Nao)
					if(mouse.posicao.x < no.posicao.x + no.dimensoes.x/2 && mouse.posicao.x > no.posicao.x - no.dimensoes.x/2 &&
					   mouse.posicao.y < no.posicao.y + no.dimensoes.y/2 && mouse.posicao.y > no.posicao.y - no.dimensoes.y/2)
					{
						pause ++;
						reset = 0;
					}
				}

				if(sair == 1)
				{
					// Confirmando o exit (Sim)
					if(mouse.posicao.x < yes.posicao.x + yes.dimensoes.x/2 && mouse.posicao.x > yes.posicao.x - yes.dimensoes.x/2 &&
					   mouse.posicao.y < yes.posicao.y + yes.dimensoes.y/2 && mouse.posicao.y > yes.posicao.y - yes.dimensoes.y/2)
					{
						resetAll();
						pause = 0;
						reset = 0;
						sair = 0;
						tela = 0;
					}

					// Negando o exit (Nao)
					if(mouse.posicao.x < no.posicao.x + no.dimensoes.x/2 && mouse.posicao.x > no.posicao.x - no.dimensoes.x/2 &&
					   mouse.posicao.y < no.posicao.y + no.dimensoes.y/2 && mouse.posicao.y > no.posicao.y - no.dimensoes.y/2)
					{
						sair = 0;
						pause = 0;
					}
				}
			}

			// Tela de Opcoes
			else if(tela == 2)
			{
				if(mouse.posicao.x < menu.posicao.x + menu.dimensoes.x/2 && mouse.posicao.x > menu.posicao.x - menu.dimensoes.x/2 &&
				   mouse.posicao.y < menu.posicao.y + menu.dimensoes.y/2 && mouse.posicao.y > menu.posicao.y - menu.dimensoes.y/2)
				{
					tela = 0;
				}

				if(mouse.posicao.x < set_1.posicao.x + set_1.dimensoes.x/2 && mouse.posicao.x > set_1.posicao.x - set_1.dimensoes.x/2 &&
				   mouse.posicao.y < set_1.posicao.y + set_1.dimensoes.y/2 && mouse.posicao.y > set_1.posicao.y - set_1.dimensoes.y/2)
				{
					tipoJogo = 1;
				}

				if(mouse.posicao.x < set_3.posicao.x + set_3.dimensoes.x/2 && mouse.posicao.x > set_3.posicao.x - set_3.dimensoes.x/2 &&
				   mouse.posicao.y < set_3.posicao.y + set_3.dimensoes.y/2 && mouse.posicao.y > set_3.posicao.y - set_3.dimensoes.y/2)
				{
					tipoJogo = 3;
				}

				if(mouse.posicao.x < set_5.posicao.x + set_5.dimensoes.x/2 && mouse.posicao.x > set_5.posicao.x - set_5.dimensoes.x/2 &&
				   mouse.posicao.y < set_5.posicao.y + set_5.dimensoes.y/2 && mouse.posicao.y > set_5.posicao.y - set_5.dimensoes.y/2)
				{
					tipoJogo = 5;
				}

				if(mouse.posicao.x < set_7.posicao.x + set_7.dimensoes.x/2 && mouse.posicao.x > set_7.posicao.x - set_7.dimensoes.x/2 &&
				   mouse.posicao.y < set_7.posicao.y + set_7.dimensoes.y/2 && mouse.posicao.y > set_7.posicao.y - set_7.dimensoes.y/2)
				{
					tipoJogo = 7;
				}

				if(mouse.posicao.x < set_9.posicao.x + set_9.dimensoes.x/2 && mouse.posicao.x > set_9.posicao.x - set_9.dimensoes.x/2 &&
				   mouse.posicao.y < set_9.posicao.y + set_9.dimensoes.y/2 && mouse.posicao.y > set_9.posicao.y - set_9.dimensoes.y/2)
				{
					tipoJogo = 9;
				}

				if(fase == 1);

				else if(mouse.posicao.x < seta_esquerda.posicao.x + seta_esquerda.dimensoes.x/2 && mouse.posicao.x > seta_esquerda.posicao.x - seta_esquerda.dimensoes.x/2 &&
				   	    mouse.posicao.y < seta_esquerda.posicao.y + seta_esquerda.dimensoes.y/2 && mouse.posicao.y > seta_esquerda.posicao.y - seta_esquerda.dimensoes.y/2)
				{
					fase = ponto_0_wallpaper - 0.01;
				}

				if(fase == FASE_FINAL);

				else if(mouse.posicao.x < seta_direita.posicao.x + seta_direita.dimensoes.x/2 && mouse.posicao.x > seta_direita.posicao.x - seta_direita.dimensoes.x/2 &&
				   	    mouse.posicao.y < seta_direita.posicao.y + seta_direita.dimensoes.y/2 && mouse.posicao.y > seta_direita.posicao.y - seta_direita.dimensoes.y/2)
				{
					fase = ponto_0_wallpaper + 1;
				}

			}

			// Tela de Creditos
			else if(tela == 3)
			{
				if(mouse.posicao.x < menu.posicao.x + menu.dimensoes.x/2 && mouse.posicao.x > menu.posicao.x - menu.dimensoes.x/2 &&
				   mouse.posicao.y < menu.posicao.y + menu.dimensoes.y/2 && mouse.posicao.y > menu.posicao.y - menu.dimensoes.y/2)
				{
					tela = 0;
				}
			}

		break;
	}
}