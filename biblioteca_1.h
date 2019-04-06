///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

/*****************************************************************************/
/**		*	*	*	* DECLARA��ES DE V�RIAVEIS E DEFINES *	*	*	*	*	**/
/*****************************************************************************/

//BIBLIOTECAS DE USO GRAFICO E OPERACIONAL
#include <stdio.h>
#include <conio.h>
#include <windows.h>
//ARQUIVOS DE FUNCOES E PROCEDIMENTOS
#include "tela.h"
//POSSIVEIS TECLAS
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27
#define KEY_ENTER 13

/*****************************************************************************/
/**  	*	*	*	*				FERRAMENTAS			*	*	*	*	*	**/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//FUNCAO QUE PULA QUANTAS LINHAS O USUARIO PEDIR
void pulaLinha(int quantasLinhas)
{
	for (int i = 0; i < quantasLinhas; ++i)
	{
		printf("\n");
	}
}
///////////////////////////////////////////////////////////////////////////////
//FUNCAO QUE MOSTRA AO USUARIO UMA SEQUENCIA DE OPCOES DE DIFICULDADE
void menu(int X,int Y)
{
		system("cls");
		gotoxy(X+1,Y);printf(" �������� ESCOLHA O JOGO �����Ŀ\n");
		gotoxy(X+2,Y);printf(" �                             �\n");
		gotoxy(X+3,Y);printf(" �1%c FACIL                    �\n",248);
		gotoxy(X+4,Y);printf(" �2%c DIFICIL                  �\n",248);
		gotoxy(X+5,Y);printf(" �3%c EXIT                     �\n",248);
		gotoxy(X+6,Y);printf(" �������������������������������");
}
///////////////////////////////////////////////////////////////////////////////
// LEITURA DE UM CARACTERE NAO BLOQUEANTE PARA AGUARDAR O INICIO DO PROGRAMA
char readNonBlock(){
	if (kbhit()){        // RETORNA VERDADEIRO QUANDO ALGUMA TECLA E PRESSIONONADA
		return getch();
    }return '\0';
}

///////////////////////////////////////////////////////////////////////////////
//PEDE UMA CONFIRMA��O SE O USER DESEJA CONTINUAR
int continua(){

    int continuar;
	scanf("%[SN]", &continuar);
	continuar=toupper(continuar);
	return continuar;
}
/*****************************************************************************/
/**                                                                         **/
/**	*	*	*	*	*			PARTE GR�FICA			*	*	*	*	*	**/
/**                                                                         **/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//FUN��O PARA DAR EFEITO DE ANIMA��O DE CORES AO PROGRAMA
void piscar_desenho()
{
    textbackground(CIANO_ESCURO);   textcolor(BRANCO);  printf(" ");clrscr();
		printa_tudo(1,1);
    textcolor(BRANCO);
		desenha_grade_qc8(15,20);
		desenha_grade_qc8(15,64);
	delay(400);
	system("cls");
	textcolor(PRETO);
		printa_tudo(1,1);
	textcolor(BRANCO);
		desenha_grade_qc8(15,20);
		desenha_grade_qc8(15,64);
	delay(400);
	system("cls");
}
///////////////////////////////////////////////////////////////////////////////
//TODOS OS PRINTS NUMA S� FUN��O
void printa_tudo(int Avisos, int titulo)
{
	if(titulo == 1){
		printf("\n\t    /$$$$$$$   /$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$         /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$ ");
		printf("\n\t   | $$__  $$ /$$__  $$ /$$__  $$| $$  | $$ /$$__  $$       /$$__  $$| $$  | $$ /$$__  $$ /$$__  $$");
		printf("\n\t   | $$  \\ $$| $$  \\ $$| $$  \\__/| $$  | $$| $$  \\ $$      | $$  \\__/| $$  | $$| $$  \\__/| $$  \\ $$");
		printf("\n\t   | $$$$$$$/| $$$$$$$$| $$      | $$$$$$$$| $$$$$$$$      | $$      | $$  | $$| $$      | $$$$$$$$");
		printf("\n\t   | $$__  $$| $$__  $$| $$      | $$__  $$| $$__  $$      | $$      | $$  | $$| $$      | $$__  $$");
		printf("\n\t   | $$  \\ $$| $$  | $$| $$    $$| $$  | $$| $$  | $$      | $$    $$| $$  | $$| $$    $$| $$  | $$");
		printf("\n\t   | $$  | $$| $$  | $$|  $$$$$$/| $$  | $$| $$  | $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/| $$  | $$");
		printf("\n\t   |__/  |__/|__/  |__/ \\______/ |__/  |__/|__/  |__/       \\______/  \\______/  \\______/ |__/  |__/");}
	if(Avisos==1){gotoxy(12,43);printf("PARA COMECAR APERTE ENTER");}
	if(Avisos==2){//VITORIA
		delay(400);printf("\n\t\t##    ##  ## ######## ######## ######## ##   ####");
		delay(400);printf("\n\t\t##    ##  ##    ##    ##    ## ##    ## ##  ##  ##");
		delay(400);printf("\n\t\t##    ##  ##    ##    ##    ## ##   ##  ## ##    ##");
		delay(400);printf("\n\t\t ##  ##   ##    ##    ##    ## #####    ## ########");
		delay(400);printf("\n\t\t  ####    ##    ##    ######## ##   ##  ## ##    ##");
		delay(2000);}
	if (Avisos==3){//DERROTA
		delay(400);printf("\n\t\t######    ######## ########  ######## ######## ########   ####");
		delay(400);printf("\n\t\t##    ##  ##       ##    ##  ##    ## ##    ##    ##     ##  ## ");
		delay(400);printf("\n\t\t##    ##  ######   ##   ##   ##   ##  ##    ##    ##    ##    ##");
		delay(400);printf("\n\t\t##    ##  ##       #####     #####    ##    ##    ##    ########");
		delay(400);printf("\n\t\t######    #######  ##   ##   ##   ##  ########    ##    ##    ##");
		delay(2000);}
	if (Avisos == 4){
    	gotoxy(10,40);printf(" ���������������������������������������Ŀ");
    	gotoxy(11,40);printf(" �       DESEJA JOGAR NOVAMENTE ?        �");
    	gotoxy(12,40);printf(" �---------------------------------------�");
   	 	gotoxy(13,40);printf(" �      |  S  |     OU     |  N  |       �");
   	 	gotoxy(14,40);printf(" �                                       �");
    	gotoxy(15,40);printf(" �����������������������������������������");
    	fflush(stdin);  gotoxy(16,55);}
}
///////////////////////////////////////////////////////////////////////////////
//FUN��O QUE SIMULA UM PSEUDO-CARREGAMENTO
void waiting_carregamento(int time)
{
	int i;
	textbackground(CIANO_ESCURO);textcolor(BRANCO);
	char Charging[120]="";

	for(i=0; i<=100; i++)
	{
		if(i%2){strcat(Charging,"�");}
		system("cls");
		gotoxy(13,20);printf("               ����������������������������������������������������Ŀ");
		gotoxy(14,20);printf(" CARREGANDO    �");printf("  %s",Charging);printf("� %d%% ",i);
		gotoxy(15,20);printf("               ������������������������������������������������������");
		delay(time);//Aguarda um tempo
    }
	Sleep(300);/*Aguarda um tempo*/		system("cls");		gotoxy(0,0);/*Volta ao DOS posi��o inicial*/
}
///////////////////////////////////////////////////////////////////////////////
//FUN��O PARA PRINTAR A GRADE E OS T�TULOS NA TELA
void desenha_grade(int Linha, int Coluna)
{
	
	//DESENHA O QUADRO
	gotoxy(Linha,Coluna);   printf("\332\304\304\304\304\304\304\304\302\304\304\304\304\304\304\304\302\304\304\304\304\304\304\304\277");
	gotoxy(Linha+1,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+2,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+3,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+4,Coluna); printf("\303\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\264");
	gotoxy(Linha+5,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+6,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+7,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+8,Coluna); printf("\303\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\305\304\304\304\304\304\304\304\264");
	gotoxy(Linha+9,Coluna); printf("\263       \263       \263       \263");
	gotoxy(Linha+10,Coluna);printf("\263       \263       \263       \263");
	gotoxy(Linha+11,Coluna);printf("\263       \263       \263       \263");
	gotoxy(Linha+12,Coluna);printf("\300\304\304\304\304\304\304\304\301\304\304\304\304\304\304\304\301\304\304\304\304\304\304\304\331");
}
#endif // BIBLIOTECA_H_INCLUDED
