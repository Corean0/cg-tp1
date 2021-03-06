﻿// Função que determina o vencedor da partida
void winner(int player)
{
	if(player == 1)
	{
		vencedor.textura = loadTexture("../Imagens/player1_win.png");
	}

	if(player == 2)
	{
		vencedor.textura = loadTexture("../Imagens/player2_win.png");
	}
}

// Função que determina quem está a um ponto de vencer a partida
void matchPoint(int player)
{
	if(player == 1)
	{
		match.textura = loadTexture("../Imagens/match_point_blue.png");
	}

	else
	{
		match.textura = loadTexture("../Imagens/match_point_red.png");
	}
}

// Função que determina quem está a um ponto de vencer o set
void setPoint(int player)
{
	if(player == 1)
	{
		setP.textura = loadTexture("../Imagens/set_point_blue.png");
	}

	else
	{
		setP.textura = loadTexture("../Imagens/set_point_red.png");
	}
}

// Função que altera a textura animada da bola a cada rebatida
void rebatida(int player)
{
	if(player == 1)
	{
		ball.textura = loadTexture("../Imagens/shell_animado_blue.png");
	}

	else
	{
		ball.textura = loadTexture("../Imagens/shell_animado_red.png");
	}
}

// Pause temporário da bola
void sleep_bola(double segundos)
{
	segundos_sleep = segundos*1000;
}

double bola_dormindo()
{
	segundos_sleep = segundos_sleep - 1000/FPS;
	return segundos_sleep;
}

// Função que roda a animação de troca de lados
void Switch()
{
	drawObject(kamek_voador);
	drawObjectA(mario_voador);
	drawObject(switch_player);
	move_mario();
	move_kamek();
}

void tempo_switch(double segundos)
{
	if(lugarJogadores % 2 == 0)
	{
		kamek_voador.textura = loadTexture("../Imagens/kamek_invertido.png");
		mario_voador.textura = loadTexture("../Imagens/mario.png");
	}

	else
	{
		kamek_voador.textura = loadTexture("../Imagens/kamek.png");
		mario_voador.textura = loadTexture("../Imagens/mario_invertido.png");
	}

	sleep_bola(segundos+1);
	timer_switch = segundos*1000;
}

// Função que pausa enquanto a animação de switch está rodando
double switch_rodando()
{
	timer_switch = timer_switch - 1000/FPS;
	return timer_switch;
}

// Seta 1 a 2 para primeira, 2 a 3 para segundo e assim em diante
void faseAtual()
{ 
    double aux = wallPaper.posicao.x/largura;
    ponto_0_wallpaper = 3 - aux; // Fase atual
}
