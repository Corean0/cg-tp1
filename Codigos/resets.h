// Reseta o set
void resetSet()
{
    set1.pontos = set2.pontos = 0;
}

// Reseta pontuação dentro do set
void resetPont()
{
    deuce1.pontos = deuce2.pontos = pontos1.pontos = pontos2.pontos = dezena1.pontos = dezena2.pontos = 0;
}

// Reinicia a bola no meio
void resetBall()
{
    spd = 10;

    if(ultimo_pontuador == 1)
    {
        // Reset da bola para direita
        ball.movimento.x = spd;
    }

    else
    {
        // Reset a bola para esquerda       
        ball.movimento.x = -spd;
    }

    // Randomizando direção do set
    if(rand() % 2 == 0)
    {
        ball.movimento.y = spd;
    }

    else
    {
        ball.movimento.y = -spd;
    }

    ball.posicao.x = largura/2;
    ball.posicao.y = altura/2;
    ball.textura = loadTexture("../imagens/shell_animado_purple.png");
}

// Reinicia as barras no meio
void resetBar()
{
    if(lugarJogadores % 2 == 0)
    {
        bar1.posicao.x = largura/60;
        bar2.posicao.x = largura - largura/60;
    }

    else
    {
        bar1.posicao.x = largura - largura/60;
        bar2.posicao.x = largura/60;
    }

    bar1.posicao.y = altura/2;
    bar2.posicao.y = altura/2;
}

// Reseta Game completo (Pontuação/Barra/Bola/all)
void resetAll()
{
    if(lugarJogadores % 2 != 0)
    {
	    trocarJogadores();
		mario_voador.posicao.x = largura;
		kamek_voador.posicao.x = 0;
    }
    resetBar();
    resetBall();
    resetPont();
    resetSet();
}