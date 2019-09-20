// Função para trocar jogadores, placar, barras de lugar
void trocarJogadores()
{
    lugarJogadores++;
    trocarPosicoesPlacares();
    resetBar(); 
}

// Chamada pelo trocaJogadores()
void trocarPosicoesPlacares(){

    if(lugarJogadores % 2 == 0){

        set1.posicao.x = 3*posIdealx*largura;
        set1.posicao.y = altura - posIdealy*altura;

        dezena1.posicao.x = 5*posIdealx*largura;
        dezena1.posicao.y = altura - posIdealy*altura;

        pontos1.posicao.x = 7*posIdealx*largura;
        pontos1.posicao.y = altura - posIdealy*altura;

        deuce1.posicao.x = 9*posIdealx*largura;
        deuce1.posicao.y = altura - posIdealy*altura*2;

        set2.posicao.x = largura - 7*posIdealx*largura;
        set2.posicao.y = altura - posIdealy*altura;

        dezena2.posicao.x=largura - 5*posIdealx*largura;
        dezena2.posicao.y=altura - posIdealy*altura;

        pontos2.posicao.x = largura - 3*posIdealx*largura;
        pontos2.posicao.y = altura - posIdealy*altura;

        deuce2.posicao.x = largura - posIdealx*largura;
        deuce2.posicao.y = altura - posIdealy*altura*2;
    }

    else
    {
        set2.posicao.x = 3*posIdealx*largura;
        set2.posicao.y = altura - posIdealy*altura;

        dezena2.posicao.x = 5*posIdealx*largura;
        dezena2.posicao.y = altura - posIdealy*altura;

        pontos2.posicao.x = 7*posIdealx*largura;
        pontos2.posicao.y = altura - posIdealy*altura;

        deuce2.posicao.x = 9*posIdealx*largura;
        deuce2.posicao.y = altura - posIdealy*altura*2;

        set1.posicao.x = largura - 7*posIdealx*largura;
        set1.posicao.y = altura - posIdealy*altura;

        dezena1.posicao.x=largura - 5*posIdealx*largura;
        dezena1.posicao.y=altura - posIdealy*altura;

        pontos1.posicao.x = largura - 3*posIdealx*largura;
        pontos1.posicao.y = altura - posIdealy*altura;

        deuce1.posicao.x = largura - posIdealx*largura;
        deuce1.posicao.y = altura - posIdealy*altura*2;
    }
}

// Estrela acompanha quem está ganhando
void posAtualEstrela()
{
	if(vencedorMomento() == 1)
    {
		estrela.posicao.x = deuce1.posicao.x;
		estrela.posicao.y = altura - (1/20.0)*altura;
	}

    else
    {
		estrela.posicao.x = deuce2.posicao.x;
		estrela.posicao.y = altura - (1/20.0)*altura;
	}
}