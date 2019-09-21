void comecaMusica(int loop) // -1 pra loop infinito
{
    Mix_Chunk * som = NULL;
    int canal;
    int canal_audio = 2;
    int taxa_audio = 22050;
    Uint16 formato_audio = AUDIO_S16SYS;
    int audio_buffers = 4096;

    if (Mix_OpenAudio(taxa_audio, formato_audio, canal_audio, audio_buffers) != 0)
    {
        printf("Não pode inicializar audio: %s\n", Mix_GetError());
    }

	switch(fase){
		case 1:
			som = Mix_LoadWAV("../Sons/musica_1.ogg");
			break;
		case 2:
			som = Mix_LoadWAV("../Sons/musica_2.ogg");
			break;
		case 3:
			som = Mix_LoadWAV("../Sons/musica_3.ogg");
			break;
		case 4:
			som = Mix_LoadWAV("../Sons/musica_4.ogg");
			break;
	}

    if (som == NULL)
    {
        printf("Não pode inicializar audio: %s\n", Mix_GetError());
    }

    Mix_HaltChannel(-1);
    canal = Mix_PlayChannel(-1, som, loop);

    if (canal == -1)
    {
        printf("Não pode inicializar audio: %s\n", Mix_GetError());
    }
}

void paraMusica() {
    Mix_HaltChannel(-1);
}
