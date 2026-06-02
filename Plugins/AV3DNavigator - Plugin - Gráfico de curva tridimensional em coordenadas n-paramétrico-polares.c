/*
Proprietário: Antonio Vandré Pedrosa Furtunato Gomes

AV3DNavigator: "https://github.com/antoniovandre/AV3DNavigator".

Arquivo gerador de um espaço do AV3DNavigator gráfico de curva tridimensional em coordenadas n-paramétrico-polares.

Argumentos: 1: primeiramente a string título e, após barra vertical "|", strings separadas por barra vertical "|" com campos separados por ponto e vírgula ";", composta das tríades de funções θ em "VARIAVELDESUBSTITUICAO3", funções φ em "VARIAVELDESUBSTITUICAO3" e funções ρ em "VARIAVELDESUBSTITUICAO3" separadas por vírgula ",", o menor valor atribuído a "VARIAVELDESUBSTITUICAO3", o maior valor atribuído a "VARIAVELDESUBSTITUICAO3", os pontos de exclusões no intervalo separados por vírgula, e a cor RGB com os menores para vermelho, verde e azul separados por vírgula ",". 2: a resolução.

Última atualização: 02-06-2026. Sem considerar alterações em variáveis globais.
*/

#include "antoniovandre_eval/antoniovandre.c"

#define BUILTIN VERDADE

#define MAXITENS 10
#define MAXTAMANHOCAMPO 1024

#define EVALSOFTWARE "antoniovandre_eval"
#define EVALSOFTWARETAIL " 0 2>> /dev/null \| tr -d ' ' \| tr -d '\n'"

int main (int argc, char * argv[])
	{
	int shift = NUMEROZERO;
	int inicio = NUMEROZERO;
	int argi = NUMEROZERO;
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int o;
	int p;
	int q;
	int r;
	int s;
	int t;
	char c;
	int flag = NUMEROZERO;
	char mainstring [MAXTAMANHOCAMPO];
	char resstring [MAXTAMANHOCAMPO];
	char titulo [MAXTAMANHOCAMPO];
	char item [MAXITENS] [MAXTAMANHOCAMPO];
	char funcaoteta [MAXITENS] [MAXITENS] [MAXTAMANHOCAMPO];
	char funcaophi [MAXITENS] [MAXITENS] [MAXTAMANHOCAMPO];
	char funcaorho [MAXITENS] [MAXITENS] [MAXTAMANHOCAMPO];
	char funcaox [MAXITENS] [MAXTAMANHOCAMPO];
	char funcaoy [MAXITENS] [MAXTAMANHOCAMPO];
	char funcaoz [MAXITENS] [MAXTAMANHOCAMPO];
	char menor [MAXITENS] [MAXTAMANHOCAMPO];
	char maior [MAXITENS] [MAXTAMANHOCAMPO];
	char exclusao [MAXITENS] [MAXTAMANHOCAMPO];
	char exclusaoarr [MAXITENS] [MAXITENS] [MAXTAMANHOCAMPO];
	char rgb [MAXITENS] [MAXTAMANHOCAMPO];
	char verifstr [MAXTAMANHOCAMPO];
	TIPONUMEROREAL menores [MAXITENS];
	TIPONUMEROREAL maiores [MAXITENS];
	TIPONUMEROREAL exclusoes [MAXITENS] [MAXITENS];
	TIPONUMEROREAL margemexclusao = 0.1;
	char * err;
	char tc;
	char * output;
	char mensagemerro [MAXTAMANHOCAMPO];
	char tempstr [MAXTAMANHOCAMPO];
	char * temp;

	int precisao = antoniovandre_precisao_real ();

	temp = (char *) malloc (MAXTAMANHOCAMPO);

	antoniovandre_copiarstring (temp, STRINGVAZIA);

	antoniovandre_copiarstring (temp, "system variaveldesubstituicao3");

	char variavel = (char) ((int) strtold (temp, precisao), & err));

	for (i = NUMEROZERO; i < MAXTAMANHOCAMPO; i++) mensagemerro[i] = '\0';

	strcpy(mensagemerro, "Erro.\n\nArgumentos: 1: primeiramente a string título e, após barra vertical \"|\", strings separadas por barra vertical \"|\" com campos separados por ponto e vírgula \";\", composta dos pares de funções θ em \"VARIAVELDESUBSTITUICAO3\", funções φ em \"VARIAVELDESUBSTITUICAO3\" e funções ρ em \"VARIAVELDESUBSTITUICAO3\" separadas por vírgula \",\", o menor valor atribuído a \"VARIAVELDESUBSTITUICAO3\", o maior valor atribuído a \"VARIAVELDESUBSTITUICAO3\", os pontos de exclusões no intervalo separados por vírgula, e a cor RGB com os menores para vermelho, verde e azul separados por vírgula \",\". 2: a resolução.\n");

	for (i = NUMEROZERO; i < MAXTAMANHOCAMPO; i++) tempstr[i] = '\0';

	for (i = NUMEROZERO; i < strlen(mensagemerro); i++)
		{
		temp = antoniovandre_substring(mensagemerro, i, i + 22);

		if (! (strcmp(temp, "VARIAVELDESUBSTITUICAO3")))
			{
			strncat(tempstr, & variavel, NUMEROUM);
			i += 22;
			}
		else
			strncat(tempstr, & mensagemerro[i], NUMEROUM);

		free(temp);
		}

	strcpy(mensagemerro, tempstr);

	if (argc != 3) {printf(mensagemerro); return NUMEROUM;}

	for (i = NUMEROZERO; i < MAXTAMANHOCAMPO; i++) {mainstring[i] = '\0'; resstring[i] = '\0';}

	for (i = NUMEROZERO; i < MAXITENS; i++)
		for (j = NUMEROZERO; j < MAXITENS; j++)
			for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++)
				{funcaoteta[i][j][k] = '\0'; funcaophi[i][j][k] = '\0'; funcaorho[i][j][k] = '\0';}

	for (i = NUMEROZERO; i < MAXITENS; i++)
		for (j = NUMEROZERO; j < MAXTAMANHOCAMPO; j++)
			{item[i][j] = '\0'; funcaox[i][j] = '\0'; funcaoy[i][j] = '\0'; funcaoz[i][j] = '\0'; menor[i][j] = '\0'; maior[i][j] = '\0'; exclusao[i][j] = '\0'; rgb[i][j] = '\0';}

	j = NUMEROZERO;

	for (i = NUMEROZERO; i < MAXTAMANHOCAMPO; i++)
		{
		if (argv[NUMEROUM][i] == '\0') break;
		mainstring[j++] = argv[NUMEROUM][i];
		}

	j = NUMEROZERO;

	for (i = NUMEROZERO; i < MAXTAMANHOCAMPO; i++)
		{
		if (argv[2][i] == '\0') break;
		resstring[j++] = argv[2][i];
		}

	int resolucao = atoi(resstring);

	if (resolucao == NUMEROZERO) {printf(mensagemerro); return NUMEROUM;}

	do
		{
		c = mainstring[inicio];
		if ((c != '|') && (c != '\0')) {titulo[inicio++] = c;} else break;
		} while (VERDADE);

	titulo[inicio] = '\0';

	shift = inicio;

	do
		{
		i = NUMEROZERO;

		do
			{
			c = mainstring[shift++ + NUMEROUM];
			if (c != ' ') {if ((c != '|') && (c != '\0')) {item[argi][i++] = c;} else break;}
			} while (VERDADE);

		item[argi][i] = '\0';

		if (c == '\0') flag = NUMEROUM;

		t = NUMEROZERO;
		shift = NUMEROZERO;

		do
			{
			j = NUMEROZERO;

			do
				{
				c = item[argi][shift++];
				if ((c != ',') && (c != '\0')) {funcaoteta[argi][t][j++] = c;} else break;
				} while (VERDADE);

			funcaoteta[argi][t][j] = '\0';

			k = NUMEROZERO;

			do
				{
				c = item[argi][shift++];
				if ((c != ',') && (c != '\0')) {funcaophi[argi][t][k++] = c;} else break;
				} while (VERDADE);

			funcaophi[argi][t][k] = '\0';

			l = NUMEROZERO;

			do
				{
				c = item[argi][shift++];
				if ((c != ',') && (c != ';') && (c != '\0')) {funcaorho[argi][t][l++] = c;} else break;
				} while (VERDADE);

			funcaorho[argi][t++][l] = '\0';
			} while ((c != ';') && (c != '\0'));

		m = NUMEROZERO; shift -= 2;

		do
			{
			c = item[argi][shift + m + 2];
			if ((c != ';') && (c != '\0')) {menor[argi][m++] = c;} else break;
			} while (VERDADE);

		menor[argi][m] = '\0';

		temp = antoniovandre_eval(menor[argi], precisao);
		menores[argi] = strtod(temp, &err);

		if ((! strcmp(menor[argi], "")) || (err == temp)) {printf(mensagemerro); free(temp); return NUMEROUM;}

		free(temp);

		n = NUMEROZERO;

		do
			{
			c = item[argi][shift + m + n + 3];
			if ((c != ';') && (c != '\0')) {maior[argi][n++] = c;} else break;
			} while (VERDADE);

		maior[argi][n] = '\0';

		temp = antoniovandre_eval(maior[argi], precisao);
		maiores[argi] = strtod(temp, &err);

		if ((! strcmp(maior[argi], "")) || (err == temp)) {printf(mensagemerro); free(temp); return NUMEROUM;}

		free(temp);

		if (menores[argi] >= maiores[argi]) {printf(mensagemerro); return NUMEROUM;}

		o = NUMEROZERO;

		do
			{
			c = item[argi][shift + m + n + o + 4];
			if ((c != ';') && (c != '\0')) {exclusao[argi][o++] = c;} else break;
			} while (VERDADE);

		exclusao[argi][o] = '\0';

		p = NUMEROZERO;
		q = NUMEROZERO;
		r = NUMEROZERO;

		do
			{
			do
				{
				c = exclusao[argi][q++];
				if ((c != ',') && (c != '\0')) {exclusaoarr[argi][p][r++] = c;} else break;
				} while (VERDADE);

			exclusaoarr[argi][p][r] = '\0';

			if (strlen(exclusaoarr[argi][p]) != NUMEROZERO)
				{
				exclusoes[argi][p] = strtod(exclusaoarr[argi][p], &err);

				if ((! strcmp(exclusaoarr[argi][p], "")) || (err == exclusao[argi][p])) {printf(mensagemerro); return NUMEROUM;}

				if ((exclusoes[argi][p] < menores[argi]) || (exclusoes[argi][p] > maiores[argi])) {printf(mensagemerro); return NUMEROUM;}
				}

			r = NUMEROZERO;
			p++;
			} while (c != '\0');

		s = NUMEROZERO;

		do
			{
			c = item[argi][shift + m + n + r + s + 5];
			if (c != '\0') {rgb[argi][s++] = c;} else break;
			} while (VERDADE);

		rgb[argi][s] = '\0';

		i = NUMEROZERO;

		do
			{
			j = NUMEROZERO;

			for(int k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) {verifstr[k] = '\0';}

			do
				{
				c = rgb[argi][i++];
				if ((c != '\0') && (c != ',')) {verifstr[j++] = c;} else break;
				if ((c != '0') && (c != '1') && (c != '2') && (c != '3') && (c != '4') && (c != '5') && (c != '6') && (c != '7') && (c != '8') && (c != '9')) {printf(mensagemerro); return NUMEROUM;}
				} while (VERDADE);

			if ((atoi (verifstr) < NUMEROZERO) || (atoi (verifstr) > 255))  {printf(mensagemerro); return NUMEROUM;}
			} while (c != '\0');

		if (++argi > MAXITENS) {printf(mensagemerro); return NUMEROUM;}
		} while (flag == NUMEROZERO);

	for (i = NUMEROZERO; i < argi; i++) for (j = NUMEROZERO; j < t; j++)
		{
		shift = NUMEROZERO;
		tc = TOKENINICIOEVAL; strncat(funcaox[i], & tc, NUMEROUM);

		do strncat(funcaox[i], & funcaorho[i][j][shift], NUMEROUM); while (funcaorho[i][j][++shift] != '\0');

		tc = TOKENFIMEVAL; strncat(funcaox[i], & tc, NUMEROUM);

		strcat(funcaox[i], "cos");
		tc = TOKENINICIOEVAL; strncat(funcaox[i], & tc, NUMEROUM);
		strcat(funcaox[i], funcaoteta[i][j]);
		tc = TOKENFIMEVAL; strncat(funcaox[i], & tc, NUMEROUM);

		strcat(funcaox[i], "cos");
		tc = TOKENINICIOEVAL; strncat(funcaox[i], & tc, NUMEROUM);
		strcat(funcaox[i], funcaophi[i][j]);
		tc = TOKENFIMEVAL; strncat(funcaox[i], & tc, NUMEROUM);

		if (j < t - NUMEROUM) {tc = '+'; strncat(funcaox[i], & tc, NUMEROUM);}
		}

	for (i = NUMEROZERO; i < argi; i++) for (j = NUMEROZERO; j < t; j++)
		{
		shift = NUMEROZERO;
		tc = TOKENINICIOEVAL; strncat(funcaoy[i], & tc, NUMEROUM);

		do strncat(funcaoy[i], & funcaorho[i][j][shift], NUMEROUM); while (funcaorho[i][j][++shift] != '\0');

		tc = TOKENFIMEVAL; strncat(funcaoy[i], & tc, NUMEROUM);

		strcat(funcaoy[i], "sen");
		tc = TOKENINICIOEVAL; strncat(funcaoy[i], & tc, NUMEROUM);
		strcat(funcaoy[i], funcaoteta[i][j]);
		tc = TOKENFIMEVAL; strncat(funcaoy[i], & tc, NUMEROUM);

		strcat(funcaoy[i], "cos");
		tc = TOKENINICIOEVAL; strncat(funcaoy[i], & tc, NUMEROUM);
		strcat(funcaoy[i], funcaophi[i][j]);
		tc = TOKENFIMEVAL; strncat(funcaoy[i], & tc, NUMEROUM);

		if (j < t - NUMEROUM) {tc = '+'; strncat(funcaoy[i], & tc, NUMEROUM);}
		}

	for (i = NUMEROZERO; i < argi; i++) for (j = NUMEROZERO; j < t; j++)
		{
		shift = NUMEROZERO;
		tc = TOKENINICIOEVAL; strncat(funcaoz[i], & tc, NUMEROUM);

		do strncat(funcaoz[i], & funcaorho[i][j][shift], NUMEROUM); while (funcaorho[i][j][++shift] != '\0');

		tc = TOKENFIMEVAL; strncat(funcaoz[i], & tc, NUMEROUM);

		strcat(funcaoz[i], "sen");
		tc = TOKENINICIOEVAL; strncat(funcaoz[i], & tc, NUMEROUM);
		strcat(funcaoz[i], funcaophi[i][j]);
		tc = TOKENFIMEVAL; strncat(funcaoz[i], & tc, NUMEROUM);


		if (j < t - NUMEROUM) {tc = '+'; strncat(funcaoz[i], & tc, NUMEROUM);}
		}

	for (i = NUMEROZERO; i < argi; i++)
		for (j = NUMEROZERO; j < resolucao; j++)
			{
			flag = NUMEROZERO;

			if (strlen(exclusao[i]) != NUMEROZERO) for (k = NUMEROZERO; k < o; k++)
				if ((exclusoes[i][k] >= menores[i] + j * (maiores[i] - menores[i]) / resolucao - margemexclusao) && (exclusoes[i][k] <= menores[i] + (j + NUMEROUM) * (maiores[i] - menores[i]) / resolucao + margemexclusao))
					flag = NUMEROUM;

			if (flag == NUMEROZERO)
				{
				char valorstr [MAXTAMANHOCAMPO];
				char tempstr [MAXTAMANHOCAMPO];
				char pontostr [MAXTAMANHOCAMPO];

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) valorstr[k] = '\0';

				if (! BUILTIN)
					{
					strcpy(valorstr, EVALSOFTWARE);
					strcat(valorstr, " \"");
					}

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) {tempstr[k] = '\0'; pontostr[k] = '\0';}

				shift = NUMEROZERO;
				k = NUMEROZERO;

				sprintf(pontostr, "%Lf", menores[i] + j * (maiores[i] - menores[i]) / resolucao);

				do
					{
					c = funcaox[i][shift++];

					if (c != variavel)
						{tempstr[k++] = c;}
					else
						{
						tc = TOKENINICIOEVAL; strncat(tempstr, & tc, NUMEROUM);
						strcat(tempstr, pontostr);
						tc = TOKENFIMEVAL; strncat(tempstr, & tc, NUMEROUM);

						k += strlen(pontostr) + 2;
						}
					} while (c != '\0');

				tempstr[k] = '\0';

				strcat(valorstr, tempstr);

				if (! BUILTIN)
					{
					strcat(valorstr, "\"");
					strcat(valorstr, EVALSOFTWARETAIL);
					}

				if (BUILTIN)
					{
					output = antoniovandre_eval (valorstr, precisao);
					printf("%s", output);
					free (output);
					}
				else
					system(valorstr);

				fflush(stdout);

				printf(","); fflush(stdout);

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) valorstr[k] = '\0';

				if (! BUILTIN)
					{
					strcpy(valorstr, EVALSOFTWARE);
					strcat(valorstr, " \"");
					}

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) {tempstr[k] = '\0';}

				shift = NUMEROZERO;
				k = NUMEROZERO;

				do
					{
					c = funcaoy[i][shift++];

					if (c != variavel)
						{tempstr[k++] = c;}
					else
						{
						tc = TOKENINICIOEVAL; strncat(tempstr, & tc, NUMEROUM);
						strcat(tempstr, pontostr);
						tc = TOKENFIMEVAL; strncat(tempstr, & tc, NUMEROUM);

						k += strlen(pontostr) + 2;
						}
					} while (c != '\0');

				tempstr[k] = '\0';

				strcat(valorstr, tempstr);

				if (! BUILTIN)
					{
					strcat(valorstr, "\"");
					strcat(valorstr, EVALSOFTWARETAIL);
					}

				if (BUILTIN)
					{
					output = antoniovandre_eval (valorstr, precisao);
					printf("%s", output);
					free (output);
					}
				else
					system(valorstr);

				fflush(stdout);

				printf(","); fflush(stdout);

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) valorstr[k] = '\0';

				if (! BUILTIN)
					{
					strcpy(valorstr, EVALSOFTWARE);
					strcat(valorstr, " \"");
					}

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) {tempstr[k] = '\0';}

				shift = NUMEROZERO;
				k = NUMEROZERO;

				do
					{
					c = funcaoz[i][shift++];

					if (c != variavel)
						{tempstr[k++] = c;}
					else
						{
						tc = TOKENINICIOEVAL; strncat(tempstr, & tc, NUMEROUM);
						strcat(tempstr, pontostr);
						tc = TOKENFIMEVAL; strncat(tempstr, & tc, NUMEROUM);

						k += strlen(pontostr) + 2;
						}
					} while (c != '\0');

				tempstr[k] = '\0';

				strcat(valorstr, tempstr);

				if (! BUILTIN)
					{
					strcat(valorstr, "\"");
					strcat(valorstr, EVALSOFTWARETAIL);
					}

				if (BUILTIN)
					{
					output = antoniovandre_eval (valorstr, precisao);
					printf("%s", output);
					free (output);
					}
				else
					system(valorstr);

				fflush(stdout);

				printf(";"); fflush(stdout);

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) valorstr[k] = '\0';

				if (! BUILTIN)
					{
					strcpy(valorstr, EVALSOFTWARE);
					strcat(valorstr, " \"");
					}

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) {tempstr[k] = '\0'; pontostr[k] = '\0';}

				shift = NUMEROZERO;
				k = NUMEROZERO;

				sprintf(pontostr, "%Lf", menores[i] + (j + NUMEROUM) * (maiores[i] - menores[i]) / resolucao);

				do
					{
					c = funcaox[i][shift++];

					if (c != variavel)
						{tempstr[k++] = c;}
					else
						{
						tc = TOKENINICIOEVAL; strncat(tempstr, & tc, NUMEROUM);
						strcat(tempstr, pontostr);
						tc = TOKENFIMEVAL; strncat(tempstr, & tc, NUMEROUM);

						k += strlen(pontostr) + 2;
						}

					} while (c != '\0');

				tempstr[k] = '\0';

				strcat(valorstr, tempstr);

				if (! BUILTIN)
					{
					strcat(valorstr, "\"");
					strcat(valorstr, EVALSOFTWARETAIL);
					}

				if (BUILTIN)
					{
					output = antoniovandre_eval (valorstr, precisao);
					printf("%s", output);
					free (output);
					}
				else
					system(valorstr);

				fflush(stdout);

				printf(","); fflush(stdout);

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) valorstr[k] = '\0';

				if (! BUILTIN)
					{
					strcpy(valorstr, EVALSOFTWARE);
					strcat(valorstr, " \"");
					}

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) {tempstr[k] = '\0'; pontostr[k] = '\0';}

				shift = NUMEROZERO;
				k = NUMEROZERO;

				sprintf(pontostr, "%Lf", menores[i] + (j + NUMEROUM) * (maiores[i] - menores[i]) / resolucao);

				do
					{
					c = funcaoy[i][shift++];

					if (c != variavel)
						{tempstr[k++] = c;}
					else
						{
						tc = TOKENINICIOEVAL; strncat(tempstr, & tc, NUMEROUM);
						strcat(tempstr, pontostr);
						tc = TOKENFIMEVAL; strncat(tempstr, & tc, NUMEROUM);

						k += strlen(pontostr) + 2;
						}
					} while (c != '\0');

				tempstr[k] = '\0';

				strcat(valorstr, tempstr);

				if (! BUILTIN)
					{
					strcat(valorstr, "\"");
					strcat(valorstr, EVALSOFTWARETAIL);
					}

				if (BUILTIN)
					{
					output = antoniovandre_eval (valorstr, precisao);
					printf("%s", output);
					free (output);
					}
				else
					system(valorstr);

				fflush(stdout);

				printf(","); fflush(stdout);

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) valorstr[k] = '\0';

				if (! BUILTIN)
					{
					strcpy(valorstr, EVALSOFTWARE);
					strcat(valorstr, " \"");
					}

				for (k = NUMEROZERO; k < MAXTAMANHOCAMPO; k++) {tempstr[k] = '\0'; pontostr[k] = '\0';}

				shift = NUMEROZERO;
				k = NUMEROZERO;

				sprintf(pontostr, "%Lf", menores[i] + (j + NUMEROUM) * (maiores[i] - menores[i]) / resolucao);

				do
					{
					c = funcaoz[i][shift++];

					if (c != variavel)
						{tempstr[k++] = c;}
					else
						{
						tc = TOKENINICIOEVAL; strncat(tempstr, & tc, NUMEROUM);
						strcat(tempstr, pontostr);
						tc = TOKENFIMEVAL; strncat(tempstr, & tc, NUMEROUM);

						k += strlen(pontostr) + 2;
						}
					} while (c != '\0');

				tempstr[k] = '\0';

				strcat(valorstr, tempstr);

				if (! BUILTIN)
					{
					strcat(valorstr, "\"");
					strcat(valorstr, EVALSOFTWARETAIL);
					}

				if (BUILTIN)
					{
					output = antoniovandre_eval (valorstr, precisao);
					printf("%s", output);
					free (output);
					}
				else
					system(valorstr);

				fflush(stdout);

				printf("c%s|", rgb[i]);

				fflush(stdout);
				}
			}

	printf("@@");

	printf("%s|_____|", titulo); fflush(stdout);

	for (i = NUMEROZERO; i < argi; i++)
		{
		for (j = NUMEROZERO; j < t; j++)
			{
			printf("θ_%d = %s, φ_%d = %s, ρ_%d = %s", j, funcaoteta[i][j], j, funcaophi[i][j], j, funcaorho[i][j], rgb[i]);

			if (j < s - NUMEROUM) printf(",");
			}

		printf(";%s|", rgb[i]);
		}
	}