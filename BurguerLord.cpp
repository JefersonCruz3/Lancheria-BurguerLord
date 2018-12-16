#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <cmath>

int pedidos[20][4];
int totalmatriz;
int coluna[4];
int maisvendido;
int menosvendido;
char bgmaisnome;
char bgmenosnome;
int linha[20];
int vendasdia;
int dia;
int hamburguermais;
int hamburguermenos;
int vetfaturamentodia[20];
int caixa;
int varmenu;
int maiorfatdia;
int fatdia;

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
void criamatriz(){//criando matriz com variaveis aleatorios
	for(int i=0;i < 20; i++){
		for(int j=0;j < 4; j++){
			pedidos[i][j]=rand() %4;
		}
	}
}
void somamatriz(){//somando a matriz por completo
	for(int i=0;i < 20; i++){
		for(int j=0;j < 4; j++){
			totalmatriz=totalmatriz + pedidos[i][j];
		}
	}
	gotoxy(50,6);	printf("Total de laches vendidos no periodo de vinte dias: %d\n", totalmatriz);//print que vai estar no switch final
	totalmatriz = 0;
}
void somacoluna(){//somando as colunas da matriz
	for(int j=0;j < 4; j++){
		for(int i=0;i < 20; i++){
			coluna[j]=coluna[j]+pedidos[i][j];
		}	
	}
}
void preferenciadelanches(){//verificando qual lanche foi mais vendido
	somacoluna();	
	maisvendido = coluna[1];
	for(int i=0;i < 4; i++){
		if(maisvendido <= coluna[i]){// variavel "hamburguermais" e "hamburguermenos" para verificar qual hamburquer vendeu mais e qual vendeu menos
			maisvendido = coluna[i];
			hamburguermais = i+1;
		}else{
			menosvendido = coluna[i];
			hamburguermenos = i+1;
		}	
	}
}
void nomeburguer(){
	preferenciadelanches();
	switch(hamburguermais){// switch para colocar a mensagem de qual hamburguer vendeu mais e menos, usando as variaveis "hamburguermais" e "hamburguermenos" para fazer a certificação.
		case 1:
			gotoxy(50,6);	printf("O lanche mais vendido foi o SandubaDeLuz.\n");
		break;
		case 2:
			gotoxy(50,6);	printf("O lanche mais vendido foi o JarJar Burguer.\n");
		break;
		case 3:
			gotoxy(50,6);	printf("O lanche mais vendido foi o Skywalker Burguer.\n");
		break;
		case 4:
			gotoxy(50,6);	printf("O lanche mais vendido foi o Bauru-Yoda.\n");
		break;
	}
		switch(hamburguermenos){
		case 1:
			gotoxy(50,7);	printf("O menos vendido foi o SandubaDeLuz.\n");
		break;
		case 2:
			gotoxy(50,7);	printf("O menos vendido foi o JarJar Burguer,\n");
		break;
		case 3:
			gotoxy(50,7);	printf("O menos vendido foi o Skywalker Burguer.\n");
		break;
		case 4:
			gotoxy(50,7);	printf("O menos vendido foi o Bauru-Yoda.\n");
		break;
	}	
}
void somalinha(){// O nome já é auto esplicativo né?
	for(int i=0;i < 20; i++){
		for(int j=0;j < 4; j++){
			linha[i]=linha[i]+pedidos[i][j];
		}
	}
}
void diamaisvendido(){ 
	somalinha();
	for(int i=1;i < 20; i++){
		if(vendasdia <= linha[i]){
			vendasdia = linha[i];
			dia = i+1; // variavel "dia" para dizer qual o numero do dia vendeu mais
		}
	}
}
void faturamentodia(){// somando o faturamento de cada dia em reais R$
	for(int i=0;i < 20; i++){
		for(int j=0;j < 4; j++){
			switch(j){
				case 0:
					vetfaturamentodia[i]=vetfaturamentodia[i] + (pedidos[i][j] * 15);
				break;
				case 1:
					vetfaturamentodia[i]=vetfaturamentodia[i] + (pedidos[i][j] * 28);
				break;
				case 2:
					vetfaturamentodia[i]=vetfaturamentodia[i] + (pedidos[i][j] * 30);
				break;
				case 3:
					vetfaturamentodia[i]=vetfaturamentodia[i] + (pedidos[i][j] * 25);
				break;		
			}
		}
	}
	for(int i=1;i < 20; i++){// verificando qual dia teve o maior faturamento em reais R$
		if(maiorfatdia <= vetfaturamentodia[i]){
			maiorfatdia = vetfaturamentodia[i];
			fatdia = i+1;
		}
	}
}
void faturamentomes(){// somando o faturamento do mes em reais R$
	faturamentodia();
	for(int i=0; i < 20;i++){
		caixa=caixa + vetfaturamentodia[i];
	}
}
void bemvindo(){// print do menu na tela
	gotoxy(1,1);	printf("=====================================\n");
	gotoxy(1,2);	printf("|MENU                               |\n");
	gotoxy(1,3);	printf("=====================================\n");
	gotoxy(1,4);	printf("|1- Total de lanches vendidos       |\n");
	gotoxy(1,5);	printf("|2- Mais vendido e menos vendido    |\n");
	gotoxy(1,6);	printf("|3- Dia com mais vendas             |\n");
	gotoxy(1,7);	printf("|4- Dia mais lucrativo              |\n");
	gotoxy(1,8);	printf("|5- Faturamento do mês              |\n");
	gotoxy(1,9);	printf("|6- Sair                            |\n");
	gotoxy(1,10);	printf("=====================================\n");
	gotoxy(1,11);	printf("Escolha: ");
	scanf("%d",&varmenu);// leitura da escolha
	gotoxy(1,11);	printf("Escolha:                                                                      ");
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	criamatriz();
	faturamentomes();
	while(true){
		bemvindo();
		somamatriz();
		diamaisvendido();
		faturamentodia();
		switch(varmenu){// switch para verificar oq foi pedido pelo usuario e mostrar na tela corretamente
			case 1: 
				gotoxy(50,6);	printf("                                                                                     ");
				gotoxy(50,7);	printf("                                                                                     ");
				somamatriz();
			break;
			case 2:
				gotoxy(50,6);	printf("                                                                                     ");
				gotoxy(50,7);	printf("                                                                                     "); 
				nomeburguer();		
			break;
			case 3:
				gotoxy(50,6);	printf("                                                                                     ");
				gotoxy(50,7);	printf("                                                                                     ");
				gotoxy(50,6);	printf("O dia com mais vendas foi o dia %d", dia);	
			break;
			case 4:
				gotoxy(50,6);	printf("                                                                                     ");
				gotoxy(50,7);	printf("                                                                                     ");
				gotoxy(50,6);	printf("O dia mais lucartivo foi o dia %d", fatdia);	
			break;
			case 5:
				gotoxy(50,6);	printf("                                                                                     ");
				gotoxy(50,7);	printf("                                                                                     ");
				gotoxy(50,6);	printf("O faturamento do mês foi de R$ %d", caixa);	
			break;
			case 6:
				gotoxy(1,12);	printf("by: Jéferson Cruz");
				gotoxy(1,12);
				return false;
			break;
			default:
				gotoxy(50,6);	printf("                                                                                     ");
				gotoxy(50,7);	printf("                                                                                     ");
				gotoxy(50,6);	printf("Opção invalida tente novamente");
			break;			
		}// Aparentemente ainda não peguei a manha de comentar de forma construtiva kkkkkkkkkkkkk
	}
}

