/*
Proprietário: Antonio Vandré Pedrosa Furtunato Gomes

Av3DNavigator: "https://github.com/antoniovandre/AV3DNavigator".

Arquivo gerador do "AV3DNavigator - Espaço - Relógio.txt".

Última atualização: 19-09-2025. Não considerando alterações em variáveis globais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char * argv[])
	{
	long double raiosegundos = 4;
	long double raiominutos = 3;
	long double raiohoras = 2;
	long double espessura = 1;

	printf("@");

	printf("9divisor%Lf * cos(pi + AV3DNPTS * pi/30)divisor%Lf * sin(pi + AV3DNPTS * pi/30)DIVISOR9divisor%Lf * cos(AV3DNPTS * pi/30)divisor%Lf * sin(AV3DNPTS * pi/30)DIVISOR", espessura / 2, espessura / 2, espessura / 2, espessura / 2);

	fflush(stdout);

	printf("9divisor%Lf * cos(pi/2 + AV3DNPTS * pi/30)divisor%Lf * sin(pi/2 + AV3DNPTS * pi/30)color255divisor0divisor0|", raiosegundos, raiosegundos);

	fflush(stdout);

	printf("8divisor%Lf * cos(pi + AV3DNPTM * pi/30)divisor%Lf * sin(pi + AV3DNPTM * pi/30 + AV3DNPTS * pi/1800)DIVISOR8divisor%Lf * cos(AV3DNPTM * pi/30 + AV3DNPTS * pi/1800)divisor%Lf * sin(AV3DNPTM * pi/30 + AV3DNPTS * pi/1800)DIVISOR", espessura / 2, espessura / 2, espessura / 2, espessura / 2);

	fflush(stdout);

	printf("8divisor%Lf * cos(pi/2 + AV3DNPTM * pi/30 + AV3DNPTS * pi/1800)divisor%Lf * sin(pi/2 + AV3DNPTM * pi/30 + AV3DNPTS * pi/1800)color0divisor255divisor0|", raiominutos, raiominutos);

	fflush(stdout);

	printf("7divisor%Lf * cos(pi + AV3DNPTH * pi/6 + AV3DNPTM * pi/360)divisor%Lf * sin(pi + AV3DNPTH * pi/6 + AV3DNPTM * pi/360)DIVISOR7divisor%Lf * cos(AV3DNPTH * pi/6)divisor%Lf * sin(AV3DNPTH * pi/6 + AV3DNPTM * pi/360)DIVISOR", espessura / 2, espessura / 2, espessura / 2, espessura / 2);

	fflush(stdout);

	printf("7divisor%Lf * cos(pi/2 + AV3DNPTH * pi/6 + AV3DNPTM * pi/360)divisor%Lf * sin(pi/2 + AV3DNPTH * pi/6 + AV3DNPTM * pi/360)color255divisor255divisor0|", raiohoras, raiohoras);

	fflush(stdout);
	}
