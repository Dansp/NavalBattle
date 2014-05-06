/*Batalha naval.
Programa que simula o jogo da batalha naval */

#include <stdio.h>

int main()
{
	int inimigo[5][10] = { {0,0,0,0,1,0,0,0,0,0},
						   {0,1,1,1,0,1,1,0,0,0},
						   {0,1,1,0,0,0,0,1,0,0},
						   {0,1,0,1,0,1,1,0,0,0},
						   {0,0,0,1,1,0,0,1,0,1} };

	char tabuleiro[5][10];

	int i, j;
	int rodada=0, tiros=24, acertos=0;
		for(i=0; i<10; i++) {
			for(j=0; j<10; j++) {
				tabuleiro[i][j] = '.';
			}
		}

		 do{
		 
			for(i=0; i<5; i++) {
				for(j=0; j<10; j++) {
					//putchar(tabuleiro[i][j] ); //PUTCHAR:imprime um caracter
					printf("%c ", tabuleiro[i][j]);
				}
				printf("\n");
			}

			//Fim do jogo
			if(rodada == 25) { 
				printf("\n\n\n                      ***Acabou seus tiros, você perdeu!!!***\n");
			break; }
			/////

			printf("\nInforme as coordenadas do tiro (linha coluna):\n");
			scanf("%d %d", &i, &j);



			///////Periodo de valídação
			while(i<0 || i>4 || j<0 || j>9) {
					printf("\n\n		******Coordenadas inválido, digite outro:*****\n\n");
					scanf("%d %d", &i, &j);

			}



			if(tabuleiro[i][j] == 'X' || tabuleiro[i][j] == 'O') {
				printf("\n\n		******Coordenadas inválidas, Alvo já abatido******\n\n");
				printf("\n\n\n		******Tente outro******\n\n\n");
			continue;
			}

			//////////////////////////////////////////////

			if(i>=0 && j>=0) {
				
					if(inimigo[i][j] == 1) {
						tabuleiro[i][j] ='X';
						acertos++;
						
					}


				else  {
					tabuleiro[i][j] = 'O';
				}


			}
			

			if(tiros == 0) {
				printf("Você não tem mais tiros\n");
				printf("Você acertou %i alvo(s)\n", acertos);
			}
			else {
				printf("Você tem %i tiro(s)\n", tiros);
				printf("Você acertou %i alvo(s)\n", acertos);
			}

			if(acertos==17) { 	
				printf("\n\n			*****Parabéns, você afundou todas!!!***** \n\n");
			break; 
			}
			
						

			rodada++;
			tiros--;
			

		}while(rodada <= 25);

		

	
	return 0;
}

