// Movendo a barra
void moveBar()
{
	if(tela == 1)
	{	 
		// Tecla w/W		
	    if(keyboard[87] == 1) 
	    {
	        if(bar1.posicao.y < altura-largura/10)
	        {
	            bar1.posicao.y += largura/100;
	        }
	    }

	    // Tecla s/S
	    if(keyboard[83] == 1)  
	    {
	        if(bar1.posicao.y > largura/10)
	        {
	            bar1.posicao.y -= largura/100;
	        }
	    }

	    // Tecla o/O
	    if(keyboard[111] == 1)  
	    {
	        if(bar2.posicao.y < altura-largura/10)
	        {
	            bar2.posicao.y += largura/100;
	        }
	    }

	    // Tecla l/L
	    if(keyboard[108] == 1)  
	    {
	        if(bar2.posicao.y > largura/10)
	        {
	            bar2.posicao.y -= largura/100;
	        }
	    }
	}
}

// Movendo a bola
void moveBall()
{
	if(tela == 1)
	{
	    ball.posicao.x += ball.movimento.x;
	    ball.posicao.y += ball.movimento.y;

	    // Movimentação do teto para o chão
	    if(ball.posicao.y + ball.dimensoes.y/2 >= altura)
	    {
	        ball.movimento.y = -spd;
	    }

	    // Movimentação do chão para o teto
	    if(ball.posicao.y - ball.dimensoes.y/2 <= 0)
	    {
	        ball.movimento.y = spd;
	    }

		if(lugarJogadores % 2 == 0)
		{
		    // Movimentação da direita para a esquerda
		    if((ball.posicao.x + ball.dimensoes.x/2 >= bar2.posicao.x - bar2.dimensoes.x/2) && 
		       (ball.posicao.y + ball.dimensoes.y/2 >= bar2.posicao.y - bar2.dimensoes.y/2) && 
		       (ball.posicao.y - ball.dimensoes.y/2 <= bar2.posicao.y + bar2.dimensoes.y/2))
		    {
		    	spd += 0.4;
				ball.movimento.x = -spd;
				rebatida(Player2);
		    }

		    // Pontuação na direita
		    if((ball.posicao.x + ball.dimensoes.x/2 > bar2.posicao.x + bar2.dimensoes.x/2) &&
		       ((ball.posicao.y + ball.dimensoes.y/2 < bar2.posicao.y - bar2.dimensoes.y/2) || 
		       (ball.posicao.y - ball.dimensoes.y/2 > bar2.posicao.y + bar2.dimensoes.y/2)))
		    {
		    	spd = 10;
				addPoint(Player1);

				// Variavel para decidir a direção da bola após uma pontuação
				ultimo_pontuador = 1;
				
				if(pontos1.pontos != 0)
				{
					sleep_bola(DELAY_PONT);
				}else
					sleep_bola(DELAY_SET);

				resetBall();
		    }

		    // Movimentação da esquerda para a direita
		    if((ball.posicao.x - ball.dimensoes.x/2 <= bar1.posicao.x + bar1.dimensoes.x/2) && 
		       (ball.posicao.y + ball.dimensoes.y/2 >= bar1.posicao.y - bar1.dimensoes.y/2  &&
		        ball.posicao.y - ball.dimensoes.y/2 <= bar1.posicao.y + bar1.dimensoes.y/2))
		    {
		    	spd += 0.4;
				ball.movimento.x = spd;
				rebatida(Player1);
		    }

		    // Pontuação na esquerda
		    if((ball.posicao.x - ball.dimensoes.x/2 < bar1.posicao.x - bar1.dimensoes.x/2) &&
		       ((ball.posicao.y + ball.dimensoes.y/2 < bar1.posicao.y - bar1.dimensoes.y/2) ||
		       (ball.posicao.y - ball.dimensoes.y/2 >= bar1.posicao.y + bar1.dimensoes.y/2)))
		    {
		    	spd = 10;
				addPoint(Player2);

				// Variavel para decidir a direção da bola após uma pontuação
				ultimo_pontuador = 2;

				if(pontos2.pontos != 0)
				{
					sleep_bola(DELAY_PONT);
				}else
					sleep_bola(DELAY_SET);
				
				resetBall();
		    }
		}
		
		else
		{
		    // Movimentação da direita para a esquerda
		    if((ball.posicao.x + ball.dimensoes.x/2 >= bar1.posicao.x - bar1.dimensoes.x/2) &&
		       (ball.posicao.y + ball.dimensoes.y/2 >= bar1.posicao.y - bar1.dimensoes.y/2) &&
		       (ball.posicao.y - ball.dimensoes.y/2 <= bar1.posicao.y + bar1.dimensoes.y/2))
		    {
		    	spd += 0.4;
				ball.movimento.x = -spd;
				rebatida(Player1);
		    }

		    // Pontuação na direita
		    if((ball.posicao.x + ball.dimensoes.x/2 > bar1.posicao.x + bar1.dimensoes.x/2) &&
		      ((ball.posicao.y + ball.dimensoes.y/2 < bar1.posicao.y - bar1.dimensoes.y/2) ||
		       (ball.posicao.y - ball.dimensoes.y/2 > bar1.posicao.y + bar1.dimensoes.y/2)))
		    {
		    	spd = 10;
				addPoint(Player2);

				// Variavel para decidir a direção da bola após uma pontuação
				ultimo_pontuador = 1;

				if(pontos2.pontos != 0)
				{
					sleep_bola(DELAY_PONT);
				}else
					sleep_bola(DELAY_SET);

				resetBall();
		    }

		    // Movimentação da esquerda para a direita
		    if((ball.posicao.x - ball.dimensoes.x/2 <= bar2.posicao.x + bar2.dimensoes.x/2) &&
		       (ball.posicao.y + ball.dimensoes.y/2 >= bar2.posicao.y - bar2.dimensoes.y/2  &&
		        ball.posicao.y - ball.dimensoes.y/2 <= bar2.posicao.y + bar2.dimensoes.y/2))
		    {
		    	spd += 0.4;
				ball.movimento.x = spd;
				rebatida(Player2);
		    }

		    // Pontuação na esquerda
		    if((ball.posicao.x - ball.dimensoes.x/2 < bar2.posicao.x - bar2.dimensoes.x/2) &&
		       ((ball.posicao.y + ball.dimensoes.y/2 < bar2.posicao.y - bar2.dimensoes.y/2) ||
		       (ball.posicao.y - ball.dimensoes.y/2 >= bar2.posicao.y + bar2.dimensoes.y/2)))
		    {
		    	spd = 10;
				addPoint(Player1);

				// Variavel para decidir a direção da bola após uma pontuação
				ultimo_pontuador = 2;

				if(pontos1.pontos != 0)
				{
					sleep_bola(DELAY_PONT);
				}else
					sleep_bola(DELAY_SET);
				
				resetBall();
		    }
		}
	}
}

void move_mario()
{
	if(lugarJogadores % 2 == 0)
	{
		mario_voador.posicao.x += mario_voador.movimento.x;
	}

	else
	{
		mario_voador.posicao.x += -mario_voador.movimento.x;
	}
}

void move_kamek()
{
	if(lugarJogadores % 2 == 0)
	{
		kamek_voador.posicao.x += -kamek_voador.movimento.x;
	}

	else
	{
		kamek_voador.posicao.x += kamek_voador.movimento.x;
	}
}

void move_wallpaper_direita()
{
	wallPaper.posicao.x += wallPaper.movimento.x;
}

void move_wallpaper_esquerda()
{
	wallPaper.posicao.x -= wallPaper.movimento.x;
}