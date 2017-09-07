/*

		CARLOS ALBERTO
		LUCAS BRUNO
		CAIO DE SOUZA

*/

#include <stdio.h>
#include <stdlib.h>

#define LIN 16 // qtd de linhas
#define COL 4 // qtd de colunas

typedef struct gates
{
	int comb[COL];
}gates;

int tabelaV[LIN][COL]; // matriz tabela verdade
int user[LIN]; // vetor de valores digitados pelo user
int matKarn[4][4]; // matriz para montagem do karnaugh
int matAux[4][4]; // matriz auxiliar para inserir os conjuntos ja formados

gates allComb[LIN]; // vetor do tipo gates para armazenar as estruturas


void ifTRUE();
void trueTable(); // tabela verdade
void userResult(); // saidas definidas pelo usuario
void tablePrint(); // imprime a tabela com as saidas
void printComb(); // imprime a combinacoes
void karnaugh(); // mapa de karnaugh
void one(); // quando o resultado for 1
void octeto(); // montagem do octeto
void quarteto(); // montagem quarteto
void duplas(); // montagens duplas
void unitario(); // montagem unitarios

int main()
{

	trueTable();
	userResult();
	tablePrint();
	ifTRUE();
	printComb();
	karnaugh();
	one();
	octeto();
	quarteto();
	duplas();
	unitario();


return 0;
}

//===============================FUNCOES=============================================

//---------------------------ENTER-----------------------------------------------------

void ifTRUE()
{
	int i, j;

	for (i = 0; i < LIN; ++i)
	{
		if (user[i] == 1)
		{
			for (j = 0; j < COL; ++j)
			{
				allComb[i].comb[j] = tabelaV[i][j];
			}

			if (allComb[i].comb[0] == 0 && allComb[i].comb[1] == 0)
			{
				if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 0)
				{
					matKarn[0][0] = user[i];
				}
				else if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 1)
				{
					matKarn[0][1] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 1)
				{
					matKarn[0][2] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 0)
				{
					matKarn[0][3] = user[i];
				}
			}
			else if (allComb[i].comb[0] == 0 && allComb[i].comb[1] == 1)
			{
				if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 0)
				{
					matKarn[1][0] = user[i];
				}
				else if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 1)
				{
					matKarn[1][1] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 1)
				{
					matKarn[1][2] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 0)
				{
					matKarn[1][3] = user[i];
				}
			}
			else if (allComb[i].comb[0] == 1 && allComb[i].comb[1] == 1)
			{
				if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 0)
				{
					matKarn[2][0] = user[i];
				}
				else if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 1)
				{
					matKarn[2][1] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 1)
				{
					matKarn[2][2] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 0)
				{
					matKarn[2][3] = user[i];
				}
			}
			else if (allComb[i].comb[0] == 1 && allComb[i].comb[1] == 0)
			{
				if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 0)
				{
					matKarn[3][0] = user[i];
				}
				else if (allComb[i].comb[2] == 0 && allComb[i].comb[3] == 1)
				{
					matKarn[3][1] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 1)
				{
					matKarn[3][2] = user[i];
				}
				else if (allComb[i].comb[2] == 1 && allComb[i].comb[3] == 0)
				{
					matKarn[3][3] = user[i];
				}
			}

		}
	}

	//---- ZERA TODAS AS POSICOES DE MATAUX------

	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			matAux[i][j] = 0;
		}
	}
}


//--------------------------TRUETABLE----------------------------------------------------

void trueTable()
{

	int i, j;

//-------------------PORTA A-------------------------------
	for (i = 0; i < COL; ++i)
	{
		for (j = 0; j < LIN; ++j)
		{
			if (i == 0 && j <= 7)
			{
				tabelaV[j][i] = 0;
			}
			else if (i == 0 && j > 7)
			{
				tabelaV[j][i] = 1;
			}

//-------------------PORTA B------------------------------------

			if (i == 1 && j <= 3)
			{
				tabelaV[j][i] = 0;
			}
			else if (i == 1 && (j > 3 && j <= 7))
			{
				tabelaV[j][i] = 1;
			}
			else if (i == 1 && (j > 7 && j <= 11))
			{
				tabelaV[j][i] = 0;
			}
			else if (i == 1 && j > 11)
			{
				tabelaV[j][i] = 1;
			}

// ------------------PORTA C---------------------------------------

			if (i == 2 && j <= 1)
			{
				tabelaV[j][i] = 0;
			}
			else if (i == 2 && (j > 1 && j <= 3))
			{
				tabelaV[j][i] = 1;
			}
			else if (i == 2 && (j > 3 && j <= 5))
			{
				tabelaV[j][i] = 0;
			}
			else if (i == 2 && (j > 5 && j <= 7))
			{
				tabelaV[j][i] = 1;
			}
			else if (i == 2 && (j > 7 && j <= 9))
			{
				tabelaV[j][i] = 0;
			}
			else if (i == 2 && (j > 9 && j <= 11))
			{
				tabelaV[j][i] = 1;
			}
			else if (i == 2 && (j > 11 && j <= 13))
			{
				tabelaV[j][i] = 0;
			}
			else if (i == 2 && j > 13)
			{
				tabelaV[j][i] = 1;
			}

//-------------------PORTA D---------------------------------------

			if (i == 3)
			{
				if(j == 0 || tabelaV[j - 1][i] == 1)
				{
					tabelaV[j][i] = 0;
				}
				else if (tabelaV[j - 1][i] == 0)
				{
					tabelaV[j][i] = 1;
				}

			}

		}
	}

//------------------------------------------------------------------

	printf("A B C D \n\n");

	for (i = 0; i < LIN; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			printf("%d ", tabelaV[i][j]);
		}
		printf("\n");
	}
}

//---------------------------------TABLEPRINT------------------------------------------------

void tablePrint()
{
	int i, j, x = 0; // x eh controlador para impressao dos valores digitados pelo vetor user

	printf("\n\n");

	printf("A B C D   S\n\n");

	for (i = 0; i < LIN; ++i)
	{
		for (j = 0; j < COL; ++j)
		{
			printf("%d ", tabelaV[i][j]);
		}

		printf("- %d \n", user[x]);
		x++;
	}

	printf("\n");
}

//---------------------------------USERRESULT----------------------------------------------------

void userResult()
{
	int i;

	printf("\n Digite 16 saidas para o circuito (0 ou 1): \n");

	for (i = 0; i < LIN; ++i)
	{
		scanf("%d", &user[i]);
	}
}


//------------------------------PRINTCOMB--------------------------------------------------------

void printComb()
{
	int i, j;

	printf("\n\n Combinaoces das saidas verdadeiras: \n");

	for (i = 0; i < LIN; ++i)
	{
		if (user[i] == 1)
		{
			for (j = 0; j < COL; ++j)
			{
				printf("%d ", allComb[i].comb[j]);
			}
			printf("\n");
		}
	}

	printf("\n\n");
}

//-----------------------------KARNAUGH-----------------------------------------------------------

void karnaugh()
{

//---------------------------------------------------------------------------------------------

	printf("\t   KARNAUGH \n");

	printf("\n ________________________________\n");
	printf("|    |  __  |  _   |      |   _  |\n");
	printf("|    |  CD  |  CD  |  CD  |  CD  |\n");
	printf("|____|______|______|______|______|\n");
	printf("| __ |      |      |      |      |\n");
	printf("| AB |  %i   |  %i   |  %i   |  %i   |\n", matKarn[0][0], matKarn[0][1], matKarn[0][2], matKarn[0][3]);
	printf("|____|______|______|______|______|\n");
	printf("| _  |      |      |      |      |\n");
	printf("| AB |  %i   |  %i   |  %i   |  %i   |\n", matKarn[1][0], matKarn[1][1], matKarn[1][2], matKarn[1][3]);
	printf("|____|______|______|______|______|\n");
	printf("|    |      |      |      |      |\n");
	printf("| AB |  %i   |  %i   |  %i   |  %i   |\n", matKarn[2][0], matKarn[2][1], matKarn[2][2], matKarn[2][3]);
	printf("|____|______|______|______|______|\n");
	printf("|  _ |      |      |      |      |\n");
	printf("| AB |  %i   |  %i   |  %i   |  %i   |\n", matKarn[3][0], matKarn[3][1], matKarn[3][2], matKarn[3][3]);
	printf("|____|______|______|______|______|\n\n\n");

	printf("F(ABCD) = ");

}

void one()
{
	int i, j;

	if (matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[0][3] == 0 &&
		matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[1][3] == 0 &&
		matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[2][3] == 0 &&
		matAux[3][0] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0)
	{
		if (matKarn[0][0] == 1 && matKarn[0][1] == 1 && matKarn[0][2] == 1 && matKarn[0][3] == 1 &&
			matKarn[1][0] == 1 && matKarn[1][1] == 1 && matKarn[1][2] == 1 && matKarn[1][3] == 1 &&
			matKarn[2][0] == 1 && matKarn[2][1] == 1 && matKarn[2][2] == 1 && matKarn[2][3] == 1 &&
			matKarn[3][0] == 1 && matKarn[3][1] == 1 && matKarn[3][2] == 1 && matKarn[3][3] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				for (j = 0; j < 4; ++j)
				{
					matAux[i][j] = 1;
				}
			}

			printf(" 1\n");
		}
	}
}

//============================================OCTETO=======================================================================
void octeto()
{
	int i;

//------------------------------------------OCTETO HORIZONTAL--------------------------------------------
	if ((matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[0][3] == 0) &&
		(matKarn[0][0] == 1 && matKarn[0][1] == 1 && matKarn[0][2] == 1 && matKarn[0][3] == 1))
	{
		if((matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[1][3] == 0) &&
			(matKarn[1][0] == 1 && matKarn[1][1] == 1 && matKarn[1][2] == 1 && matKarn[1][3] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[0][i] = 1;
				matAux[1][i] = 1;
			}

			printf(" A'");
		}
		if ((matAux[3][0] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0) &&
			(matKarn[3][0] == 1 && matKarn[3][1] == 1 && matKarn[3][2] == 1 && matKarn[3][3] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[0][i] = 1;
				matAux[3][i] = 1;
			}

			printf(" B'");
		}

	}
	if ((matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[1][3] == 0) &&
		(matKarn[1][0] == 1 && matKarn[1][1] == 1 && matKarn[1][2] == 1 && matKarn[1][3] == 1))
	{

		if ((matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[2][3] == 0) &&
			(matKarn[2][0] == 1 && matKarn[2][1] == 1 && matKarn[2][2] == 1 && matKarn[2][3] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[1][i] = 1;
				matAux[2][i] = 1;
			}

			printf(" B");
		}
	}

	if ((matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[2][3] == 0) &&
		(matKarn[2][0] == 1 && matKarn[2][1] == 1 && matKarn[2][2] == 1 && matKarn[2][3] == 1))
	{

		if ((matAux[3][0] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0) &&
			(matKarn[3][0] == 1 && matKarn[3][1] == 1 && matKarn[3][2] == 1 && matKarn[3][3] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[2][i] = 1;
				matAux[3][i] = 1;
			}

			printf(" A");
		}
	}

//-------------------------------------OCTETO VERTICAL----------------------------------------------------

	if ((matAux[0][0] == 0 && matAux[1][0] == 0 && matAux[2][0] == 0 && matAux[3][0] == 0) &&
		(matKarn[0][0] == 1 && matKarn[1][0] == 1 && matKarn[2][0] == 1 && matKarn[3][0] == 1))
	{

		if((matAux[0][1] == 0 && matAux[1][1] == 0 && matAux[2][1] == 0 && matAux[3][1] == 0) &&
			(matKarn[0][1] == 1 && matKarn[1][1] == 1 && matKarn[2][1] == 1 && matKarn[3][1] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][0] = 1;
				matAux[i][1] = 1;
			}

			printf(" C'");
		}
		else if ((matAux[0][3] == 0 && matAux[1][3] == 0 && matAux[2][3] == 0 && matAux[3][3] == 0) &&
				(matKarn[0][3] == 1 && matKarn[1][3] == 1 && matKarn[2][3] == 1 && matKarn[3][3] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][0] = 1;
				matAux[i][3] = 1;
			}

			printf(" D'");
		}

	}
	else if ((matAux[0][1] == 0 && matAux[1][1] == 0 && matAux[2][1] == 0 && matAux[3][1] == 0) &&
			(matKarn[0][1] == 1 && matKarn[1][1] == 1 && matKarn[2][1] == 1 && matKarn[3][1] == 1))
	{

		if ((matAux[0][2] == 0 && matAux[1][2] == 0 && matAux[2][2] == 0 && matAux[3][2] == 0) &&
			(matKarn[0][2] == 1 && matKarn[1][2] == 1 && matKarn[2][2] == 1 && matKarn[3][2] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][1] = 1;
				matAux[i][2] = 1;
			}

			printf(" D");
		}
	}

	if ((matAux[0][2] == 0 && matAux[1][2] == 0 && matAux[2][2] == 0 && matAux[3][2] == 0) &&
		(matKarn[0][2] == 1 && matKarn[1][2] == 1 && matKarn[2][2] == 1 && matKarn[3][2] == 1))
	{

		if ((matAux[0][3] == 1 && matAux[1][3] == 1 && matAux[2][3] == 1 && matAux[3][3] == 1) &&
			(matKarn[0][3] == 1 && matKarn[1][3] == 1 && matKarn[2][3] == 1 && matKarn[3][3] == 1))
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][2] = 1;
				matAux[i][3] = 1;
			}

			printf(" C");
		}
	}

}

//==================================QUARTETO======================================================

void quarteto()
{
	int i;
//=============================QUARTETO=LINEAR====================================================
	//-------------HORIZONTAL----------------------------------------

	//verifica qual linha de matAux esta vazia
	if (matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[0][3] == 0)
	{
		if (matKarn[0][0] == 1 && matKarn[0][1] == 1 && matKarn[0][2] == 1 && matKarn[0][3] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[0][i] = 1;
			}

			printf(" A'B'");
		}
	}

	if (matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[1][3] == 0)
	{
		if (matKarn[1][0] == 1 && matKarn[1][1] == 1 && matKarn[1][2] == 1 && matKarn[1][3] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[1][i] = 1;
			}

			printf(" A'B");
		}
	}

	if (matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[2][3] == 0)
	{
		if (matKarn[2][0] == 1 && matKarn[2][1] == 1 && matKarn[2][2] == 1 && matKarn[2][3] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[2][i] = 1;
			}

			printf(" AB");
		}
	}

	if (matAux[3][0] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0)
	{
		if (matKarn[3][0] == 1 && matKarn[3][1] == 1 && matKarn[3][2] == 1 && matKarn[3][3] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[3][i] = 1;
			}

			printf(" AB'");
		}
	}
//--------------------------------------------------------------------------------------------------------
//---------------------------------VERTICAL---------------------------------------------------------------

	if ((matAux[0][0] == 0 && matAux[1][0] == 0 && matAux[2][0] == 0 && matAux[3][0] == 0) ||
		(matAux[0][0] == 1 && matAux[1][0] == 1 && matAux[2][0] == 0 && matAux[3][0] == 0) || // octeto
		(matAux[0][0] == 1 && matAux[1][0] == 0 && matAux[2][0] == 0 && matAux[3][0] == 1) || // octeto
		(matAux[0][0] == 0 && matAux[1][0] == 1 && matAux[2][0] == 1 && matAux[3][0] == 0) || // octeto
		(matAux[0][0] == 0 && matAux[1][0] == 0 && matAux[2][0] == 1 && matAux[3][0] == 1) || // octeto
		(matAux[0][0] == 1 && matAux[1][0] == 0 && matAux[2][0] == 0 && matAux[3][0] == 0) || // quarteto
		(matAux[0][0] == 1 && matAux[1][0] == 0 && matAux[2][0] == 1 && matAux[3][0] == 0) || // quarteto
		(matAux[0][0] == 0 && matAux[1][0] == 1 && matAux[2][0] == 0 && matAux[3][0] == 0) || // quarteto
		(matAux[0][0] == 0 && matAux[1][0] == 1 && matAux[2][0] == 0 && matAux[3][0] == 1) || // quarteto
		(matAux[0][0] == 1 && matAux[1][0] == 1 && matAux[2][0] == 0 && matAux[3][0] == 0) || // quarteto
		(matAux[0][0] == 0 && matAux[1][0] == 0 && matAux[2][0] == 1 && matAux[3][0] == 0) || // quarteto
		(matAux[0][0] == 0 && matAux[1][0] == 0 && matAux[2][0] == 0 && matAux[3][0] == 1))   // quarteto
	{
		if (matKarn[0][0] == 1 && matKarn[1][0] == 1 && matKarn[2][0] == 1 && matKarn[3][0] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][0] = 1;
			}

			printf(" C'D'");
		}
	}

	if ((matAux[0][1] == 0 && matAux[1][1] == 0 && matAux[2][1] == 0 && matAux[3][1] == 0) ||
	   	(matAux[0][1] == 1 && matAux[1][1] == 1 && matAux[2][1] == 0 && matAux[3][1] == 0) || // octeto
	   	(matAux[0][1] == 1 && matAux[1][1] == 0 && matAux[2][1] == 0 && matAux[3][1] == 1) || // octeto
	   	(matAux[0][1] == 0 && matAux[1][1] == 1 && matAux[2][1] == 1 && matAux[3][1] == 0) || // octeto
	   	(matAux[0][1] == 0 && matAux[1][1] == 0 && matAux[2][1] == 1 && matAux[3][1] == 1) || // octeto
	   	(matAux[0][1] == 1 && matAux[1][1] == 0 && matAux[2][1] == 0 && matAux[3][1] == 0) || // quarteto
	   	(matAux[0][1] == 1 && matAux[1][1] == 0 && matAux[2][1] == 1 && matAux[3][1] == 0) || // quarteto
	   	(matAux[0][1] == 0 && matAux[1][1] == 1 && matAux[2][1] == 0 && matAux[3][1] == 0) || // quarteto
	   	(matAux[0][1] == 0 && matAux[1][1] == 1 && matAux[2][1] == 0 && matAux[3][1] == 1) || // quarteto
       	(matAux[0][1] == 1 && matAux[1][1] == 1 && matAux[2][1] == 0 && matAux[3][1] == 0) || // quarteto
	   	(matAux[0][1] == 0 && matAux[1][1] == 0 && matAux[2][1] == 1 && matAux[3][1] == 0) || // quarteto
	   	(matAux[0][1] == 0 && matAux[1][1] == 0 && matAux[2][1] == 0 && matAux[3][1] == 1))   // quarteto)
	{
		if (matKarn[0][1] == 1 && matKarn[1][1] == 1 && matKarn[2][1] == 1 && matKarn[3][1] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][1] = 1;
			}

			printf(" C'D");
		}
	}

	if ((matAux[0][2] == 0 && matAux[1][2] == 0 && matAux[2][2] == 0 && matAux[3][2] == 0) ||
	   	(matAux[0][2] == 1 && matAux[1][2] == 1 && matAux[2][2] == 0 && matAux[3][2] == 0) || // octeto
	   	(matAux[0][2] == 1 && matAux[1][2] == 0 && matAux[2][2] == 0 && matAux[3][2] == 1) || // octeto
	   	(matAux[0][2] == 0 && matAux[1][2] == 1 && matAux[2][2] == 1 && matAux[3][2] == 0) || // octeto
	   	(matAux[0][2] == 0 && matAux[1][2] == 0 && matAux[2][2] == 1 && matAux[3][2] == 1) || // octeto
	   	(matAux[0][2] == 1 && matAux[1][2] == 0 && matAux[2][2] == 0 && matAux[3][2] == 0) || // quarteto
	   	(matAux[0][2] == 1 && matAux[1][2] == 0 && matAux[2][2] == 1 && matAux[3][2] == 0) || // quarteto
	   	(matAux[0][2] == 0 && matAux[1][2] == 1 && matAux[2][2] == 0 && matAux[3][2] == 0) || // quarteto
	   	(matAux[0][2] == 0 && matAux[1][2] == 1 && matAux[2][2] == 0 && matAux[3][2] == 1) || // quarteto
       	(matAux[0][2] == 1 && matAux[1][2] == 1 && matAux[2][2] == 0 && matAux[3][2] == 0) || // quarteto
	   	(matAux[0][2] == 0 && matAux[1][2] == 0 && matAux[2][2] == 1 && matAux[3][2] == 0) || // quarteto
	   	(matAux[0][2] == 0 && matAux[1][2] == 0 && matAux[2][2] == 0 && matAux[3][2] == 1))   // quarteto))
	{
		if (matKarn[0][2] == 1 && matKarn[1][2] == 1 && matKarn[2][2] == 1 && matKarn[3][2] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][2] = 1;
			}

			printf(" CD");
		}
	}

	if ((matAux[0][3] == 0 && matAux[1][3] == 0 && matAux[2][3] == 0 && matAux[3][3] == 0) ||
	   	(matAux[0][3] == 1 && matAux[1][3] == 1 && matAux[2][3] == 0 && matAux[3][3] == 0) || // octeto
	   	(matAux[0][3] == 1 && matAux[1][3] == 0 && matAux[2][3] == 0 && matAux[3][3] == 1) || // octeto
	   	(matAux[0][3] == 0 && matAux[1][3] == 1 && matAux[2][3] == 1 && matAux[3][3] == 0) || // octeto
	   	(matAux[0][3] == 0 && matAux[1][3] == 0 && matAux[2][3] == 1 && matAux[3][3] == 1) || // octeto
	   	(matAux[0][3] == 1 && matAux[1][3] == 0 && matAux[2][3] == 0 && matAux[3][3] == 0) || // quarteto
	   	(matAux[0][3] == 1 && matAux[1][3] == 0 && matAux[2][3] == 1 && matAux[3][3] == 0) || // quarteto
	   	(matAux[0][3] == 0 && matAux[1][3] == 1 && matAux[2][3] == 0 && matAux[3][3] == 0) || // quarteto
	   	(matAux[0][3] == 0 && matAux[1][3] == 1 && matAux[2][3] == 0 && matAux[3][3] == 1) || // quarteto
       	(matAux[0][3] == 1 && matAux[1][3] == 1 && matAux[2][3] == 0 && matAux[3][3] == 0) || // quarteto
	   	(matAux[0][3] == 0 && matAux[1][3] == 0 && matAux[2][3] == 1 && matAux[3][3] == 0) || // quarteto
	   	(matAux[0][3] == 0 && matAux[1][3] == 0 && matAux[2][3] == 0 && matAux[3][3] == 1))   // quarteto))
	{
		if (matKarn[0][3] == 1 && matKarn[1][3] == 1 && matKarn[2][3] == 1 && matKarn[3][3] == 1)
		{
			for (i = 0; i < 4; ++i)
			{
				matAux[i][3] = 1;
			}

			printf(" CD'");
		}
	}
//-------------------------------------------------------------------------------------------------------

//=====================================QUADRADO-JUNTO==========================================================

//-------------------------------------QUADRADO-SUP-ESQ---------------------------------------------------------

	if ((matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[1][0] == 0 && matAux[1][1] == 0) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[1][0] == 0 && matAux[1][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[1][0] == 0 && matAux[1][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[1][0] == 1 && matAux[1][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[1][0] == 0 && matAux[1][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 1 && matAux[1][0] == 0 && matAux[1][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[1][0] == 0 && matAux[1][1] == 1) ||
		(matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[1][0] == 1 && matAux[1][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[1][0] == 1 && matAux[1][1] == 0) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[1][0] == 0 && matAux[1][1] == 1) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[1][0] == 1 && matAux[1][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[1][0] == 1 && matAux[1][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[1][0] == 1 && matAux[1][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 1 && matAux[1][0] == 0 && matAux[1][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 1 && matAux[1][0] == 1 && matAux[1][1] == 0))
	{
		if (matKarn[0][0] == 1 && matKarn[0][1] == 1 && matKarn[1][0] == 1 && matKarn[1][1] == 1)
		{
			matAux[0][0] = 1;
			matAux[0][1] = 1;
			matAux[1][0] = 1;
			matAux[1][1] = 1;

			printf(" A'C' ");
		}
	}

//--------------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-SUP-MEIO---------------------------------------------------------

	if ((matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[1][1] == 0 && matAux[1][2] == 0) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[1][1] == 0 && matAux[1][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[1][1] == 0 && matAux[1][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[1][1] == 1 && matAux[1][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[1][1] == 0 && matAux[1][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 1 && matAux[1][1] == 0 && matAux[1][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[1][1] == 0 && matAux[1][2] == 1) ||
		(matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[1][1] == 1 && matAux[1][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[1][1] == 1 && matAux[1][2] == 0) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[1][1] == 0 && matAux[1][2] == 1) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[1][1] == 1 && matAux[1][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[1][1] == 1 && matAux[1][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[1][1] == 1 && matAux[1][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 1 && matAux[1][1] == 0 && matAux[1][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 1 && matAux[1][1] == 1 && matAux[1][2] == 0))
	{
		if (matKarn[0][1] == 1 && matKarn[0][2] == 1 && matKarn[1][1] == 1 && matKarn[1][2] == 1)
		{
			matAux[0][1] = 1;
			matAux[0][2] = 1;
			matAux[1][1] = 1;
			matAux[1][2] = 1;

			printf(" A'D ");
		}
	}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-SUP-DIR---------------------------------------------------------

	if ((matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[1][2] == 0 && matAux[1][3] == 0) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[1][2] == 0 && matAux[1][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[1][2] == 0 && matAux[1][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[1][2] == 1 && matAux[1][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[1][2] == 0 && matAux[1][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 1 && matAux[1][2] == 0 && matAux[1][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[1][2] == 0 && matAux[1][3] == 1) ||
		(matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[1][2] == 1 && matAux[1][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[1][2] == 1 && matAux[1][3] == 0) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[1][2] == 0 && matAux[1][3] == 1) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[1][2] == 1 && matAux[1][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[1][2] == 1 && matAux[1][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[1][2] == 1 && matAux[1][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 1 && matAux[1][2] == 0 && matAux[1][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 1 && matAux[1][2] == 1 && matAux[1][3] == 0))
	{
		if (matKarn[0][2] == 1 && matKarn[0][3] == 1 && matKarn[1][2] == 1 && matKarn[1][3] == 1)
		{
			matAux[0][2] = 1;
			matAux[0][3] = 1;
			matAux[1][2] = 1;
			matAux[1][3] = 1;

			printf(" A'C  ");
		}
	}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-MEIO-ESQ--------------------------------------------------------

	if ((matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[2][0] == 0 && matAux[2][1] == 0) ||
		(matAux[1][0] == 1 && matAux[1][1] == 0 && matAux[2][0] == 0 && matAux[2][1] == 0) ||
		(matAux[1][0] == 0 && matAux[1][1] == 1 && matAux[2][0] == 0 && matAux[2][1] == 0) ||
		(matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[2][0] == 1 && matAux[2][1] == 0) ||
		(matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[2][0] == 0 && matAux[2][1] == 1) ||
		(matAux[1][0] == 1 && matAux[1][1] == 1 && matAux[2][0] == 0 && matAux[2][1] == 0) ||
		(matAux[1][0] == 0 && matAux[1][1] == 1 && matAux[2][0] == 0 && matAux[2][1] == 1) ||
		(matAux[1][0] == 0 && matAux[1][1] == 0 && matAux[2][0] == 1 && matAux[2][1] == 1) ||
		(matAux[1][0] == 1 && matAux[1][1] == 0 && matAux[2][0] == 1 && matAux[2][1] == 0) ||
		(matAux[1][0] == 1 && matAux[1][1] == 0 && matAux[2][0] == 0 && matAux[2][1] == 1) ||
		(matAux[1][0] == 0 && matAux[1][1] == 1 && matAux[2][0] == 1 && matAux[2][1] == 0) ||
		(matAux[1][0] == 0 && matAux[1][1] == 1 && matAux[2][0] == 1 && matAux[2][1] == 1) ||
		(matAux[1][0] == 1 && matAux[1][1] == 0 && matAux[2][0] == 1 && matAux[2][1] == 1) ||
		(matAux[1][0] == 1 && matAux[1][1] == 1 && matAux[2][0] == 0 && matAux[2][1] == 1) ||
		(matAux[1][0] == 1 && matAux[1][1] == 1 && matAux[2][0] == 1 && matAux[2][1] == 0))
	{
		if (matKarn[1][0] == 1 && matKarn[1][1] == 1 && matKarn[2][0] == 1 && matKarn[2][1] == 1)
		{
			matAux[1][0] = 1;
			matAux[1][1] = 1;
			matAux[2][0] = 1;
			matAux[2][1] = 1;

			printf(" BC' ");
		}
	}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-MEIO-MEIO-------------------------------------------------------

	if ((matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[2][1] == 0 && matAux[2][2] == 0) ||
		(matAux[1][1] == 1 && matAux[1][2] == 0 && matAux[2][1] == 0 && matAux[2][2] == 0) ||
		(matAux[1][1] == 0 && matAux[1][2] == 1 && matAux[2][1] == 0 && matAux[2][2] == 0) ||
		(matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[2][1] == 1 && matAux[2][2] == 0) ||
		(matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[2][1] == 0 && matAux[2][2] == 1) ||
		(matAux[1][1] == 1 && matAux[1][2] == 1 && matAux[2][1] == 0 && matAux[2][2] == 0) ||
		(matAux[1][1] == 0 && matAux[1][2] == 1 && matAux[2][1] == 0 && matAux[2][2] == 1) ||
		(matAux[1][1] == 0 && matAux[1][2] == 0 && matAux[2][1] == 1 && matAux[2][2] == 1) ||
		(matAux[1][1] == 1 && matAux[1][2] == 0 && matAux[2][1] == 1 && matAux[2][2] == 0) ||
		(matAux[1][1] == 1 && matAux[1][2] == 0 && matAux[2][1] == 0 && matAux[2][2] == 1) ||
		(matAux[1][1] == 0 && matAux[1][2] == 1 && matAux[2][1] == 1 && matAux[2][2] == 0) ||
		(matAux[1][1] == 0 && matAux[1][2] == 1 && matAux[2][1] == 1 && matAux[2][2] == 1) ||
		(matAux[1][1] == 1 && matAux[1][2] == 0 && matAux[2][1] == 1 && matAux[2][2] == 1) ||
		(matAux[1][1] == 1 && matAux[1][2] == 1 && matAux[2][1] == 0 && matAux[2][2] == 1) ||
		(matAux[1][1] == 1 && matAux[1][2] == 1 && matAux[2][1] == 1 && matAux[2][2] == 0))
	{
		if (matKarn[1][1] == 1 && matKarn[1][2] == 1 && matKarn[2][1] == 1 && matKarn[2][2] == 1)
		{
			matAux[1][1] = 1;
			matAux[1][2] = 1;
			matAux[2][1] = 1;
			matAux[2][2] = 1;

			printf(" BD ");
		}
	}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-MEIO-DIR--------------------------------------------------------

	if ((matAux[1][2] == 0 && matAux[1][3] == 0 && matAux[2][2] == 0 && matAux[2][3] == 0) ||
		(matAux[1][2] == 1 && matAux[1][3] == 0 && matAux[2][2] == 0 && matAux[2][3] == 0) ||
		(matAux[1][2] == 0 && matAux[1][3] == 1 && matAux[2][2] == 0 && matAux[2][3] == 0) ||
		(matAux[1][2] == 0 && matAux[1][3] == 0 && matAux[2][2] == 1 && matAux[2][3] == 0) ||
		(matAux[1][2] == 0 && matAux[1][3] == 0 && matAux[2][2] == 0 && matAux[2][3] == 1) ||
		(matAux[1][2] == 1 && matAux[1][3] == 1 && matAux[2][2] == 0 && matAux[2][3] == 0) ||
		(matAux[1][2] == 0 && matAux[1][3] == 1 && matAux[2][2] == 0 && matAux[2][3] == 1) ||
		(matAux[1][2] == 0 && matAux[1][3] == 0 && matAux[2][2] == 1 && matAux[2][3] == 1) ||
		(matAux[1][2] == 1 && matAux[1][3] == 0 && matAux[2][2] == 1 && matAux[2][3] == 0) ||
		(matAux[1][2] == 1 && matAux[1][3] == 0 && matAux[2][2] == 0 && matAux[2][3] == 1) ||
		(matAux[1][2] == 0 && matAux[1][3] == 1 && matAux[2][2] == 1 && matAux[2][3] == 0) ||
		(matAux[1][2] == 0 && matAux[1][3] == 1 && matAux[2][2] == 1 && matAux[2][3] == 1) ||
		(matAux[1][2] == 1 && matAux[1][3] == 0 && matAux[2][2] == 1 && matAux[2][3] == 1) ||
		(matAux[1][2] == 1 && matAux[1][3] == 1 && matAux[2][2] == 0 && matAux[2][3] == 1) ||
		(matAux[1][2] == 1 && matAux[1][3] == 1 && matAux[2][2] == 1 && matAux[2][3] == 0))
	{
		if (matKarn[1][2] == 1 && matKarn[1][3] == 1 && matKarn[2][2] == 1 && matKarn[2][3] == 1)
		{
			matAux[1][2] = 1;
			matAux[1][3] = 1;
			matAux[2][2] = 1;
			matAux[2][3] = 1;

			printf(" BC ");
		}
	}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-INF-ESQ---------------------------------------------------------

	if ((matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[2][0] == 1 && matAux[2][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[2][0] == 0 && matAux[2][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 0) ||
		(matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[2][0] == 1 && matAux[2][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[2][0] == 0 && matAux[2][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[2][0] == 0 && matAux[2][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 1) ||
		(matAux[2][0] == 1 && matAux[2][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 0) ||
		(matAux[2][0] == 1 && matAux[2][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[2][0] == 0 && matAux[2][1] == 1 && matAux[3][0] == 1 && matAux[3][1] == 0) ||
		(matAux[2][0] == 0 && matAux[2][1] == 1 && matAux[3][0] == 1 && matAux[3][1] == 1) ||
		(matAux[2][0] == 1 && matAux[2][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 1) ||
		(matAux[2][0] == 1 && matAux[2][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[2][0] == 1 && matAux[2][1] == 1 && matAux[3][0] == 1 && matAux[3][1] == 0))
	{
		if (matKarn[2][0] == 1 && matKarn[2][1] == 1 && matKarn[3][0] == 1 && matKarn[3][1] == 1)
		{
			matAux[2][0] = 1;
			matAux[2][1] = 1;
			matAux[3][0] = 1;
			matAux[3][1] = 1;

			printf(" AC' ");
		}
	}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-INF-MEIO--------------------------------------------------------

	if ((matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[2][1] == 1 && matAux[2][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[2][1] == 0 && matAux[2][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 0) ||
		(matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[2][1] == 1 && matAux[2][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[2][1] == 0 && matAux[2][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[2][1] == 0 && matAux[2][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 1) ||
		(matAux[2][1] == 1 && matAux[2][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 0) ||
		(matAux[2][1] == 1 && matAux[2][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[2][1] == 0 && matAux[2][2] == 1 && matAux[3][1] == 1 && matAux[3][2] == 0) ||
		(matAux[2][1] == 0 && matAux[2][2] == 1 && matAux[3][1] == 1 && matAux[3][2] == 1) ||
		(matAux[2][1] == 1 && matAux[2][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 1) ||
		(matAux[2][1] == 1 && matAux[2][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[2][1] == 1 && matAux[2][2] == 1 && matAux[3][1] == 1 && matAux[3][2] == 0))
	{
		if (matKarn[2][1] == 1 && matKarn[2][2] == 1 && matKarn[3][1] == 1 && matKarn[3][2] == 1)
		{
			matAux[2][1] = 1;
			matAux[2][2] = 1;
			matAux[3][1] = 1;
			matAux[3][2] = 1;

			printf(" AD ");
		}
	}

//-------------------------------------------------------------------------------------------------------
//-------------------------------------QUADRADO-INF-DIR---------------------------------------------------------

	if ((matAux[2][2] == 0 && matAux[2][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[2][2] == 1 && matAux[2][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[2][2] == 0 && matAux[2][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[2][2] == 0 && matAux[2][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 0) ||
		(matAux[2][2] == 0 && matAux[2][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[2][2] == 1 && matAux[2][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[2][2] == 0 && matAux[2][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[2][2] == 0 && matAux[2][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 1) ||
		(matAux[2][2] == 1 && matAux[2][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 0) ||
		(matAux[2][2] == 1 && matAux[2][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[2][2] == 0 && matAux[2][3] == 1 && matAux[3][2] == 1 && matAux[3][3] == 0) ||
		(matAux[2][2] == 0 && matAux[2][3] == 1 && matAux[3][2] == 1 && matAux[3][3] == 1) ||
		(matAux[2][2] == 1 && matAux[2][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 1) ||
		(matAux[2][2] == 1 && matAux[2][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[2][2] == 1 && matAux[2][3] == 1 && matAux[3][2] == 1 && matAux[3][3] == 0))
	{
		if (matKarn[2][2] == 1 && matKarn[2][3] == 1 && matKarn[3][2] == 1 && matKarn[3][3] == 1)
		{
			matAux[2][2] = 1;
			matAux[2][3] = 1;
			matAux[3][2] = 1;
			matAux[3][3] = 1;

			printf(" AC ");
		}
	}

//-------------------------------------------------------------------------------------------------------

//====================================QUADRADO-DIVIDIDO==================================================


/*


			******** COLOCAR CONDICOES PARA QUARTETO QUADRADO SEPARADO ********


*/

//-----------------------------------SUP-INF-ESQ---------------------------------------------------------
	if ((matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[0][0] == 0 && matAux[0][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 0) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[3][0] == 1 && matAux[3][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1 && matAux[3][0] == 1 && matAux[3][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0 && matAux[3][0] == 1 && matAux[3][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 1 && matAux[3][0] == 0 && matAux[3][1] == 1) ||
		(matAux[0][0] == 1 && matAux[0][1] == 1 && matAux[3][0] == 1 && matAux[3][1] == 0))
	{
		if (matKarn[0][0] == 1 && matKarn[0][1] == 1 && matKarn[3][0] == 1 && matKarn[3][1] == 1)
		 {
		 	matAux[0][0] = 1;
		 	matAux[0][1] = 1;
		 	matAux[3][0] = 1;
		 	matAux[3][1] = 1;

		 	printf(" B'C' ");
		 }
	}
//-------------------------------------------------------------------------------------------------------
//-----------------------------------SUP-INF-MEIO---------------------------------------------------------
	if ((matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[0][1] == 0 && matAux[0][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 0) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[3][1] == 1 && matAux[3][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1 && matAux[3][1] == 1 && matAux[3][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0 && matAux[3][1] == 1 && matAux[3][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 1 && matAux[3][1] == 0 && matAux[3][2] == 1) ||
		(matAux[0][1] == 1 && matAux[0][2] == 1 && matAux[3][1] == 1 && matAux[3][2] == 0))
	{
		if (matKarn[0][1] == 1 && matKarn[0][2] == 1 && matKarn[3][1] == 1 && matKarn[3][2] == 1)
		 {
		 	matAux[0][1] = 1;
		 	matAux[0][2] = 1;
		 	matAux[3][1] = 1;
		 	matAux[3][2] = 1;

		 	printf(" B'D ");
		 }
	}
//-------------------------------------------------------------------------------------------------------
//-----------------------------------SUP-INF-DIR---------------------------------------------------------
	if ((matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[0][2] == 0 && matAux[0][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 0) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[3][2] == 1 && matAux[3][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1 && matAux[3][2] == 1 && matAux[3][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0 && matAux[3][2] == 1 && matAux[3][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 1 && matAux[3][2] == 0 && matAux[3][3] == 1) ||
		(matAux[0][2] == 1 && matAux[0][3] == 1 && matAux[3][2] == 1 && matAux[3][3] == 0))
	{
		if (matKarn[0][2] == 1 && matKarn[0][3] == 1 && matKarn[3][2] == 1 && matKarn[3][3] == 1)
		 {
		 	matAux[0][2] = 1;
		 	matAux[0][3] = 1;
		 	matAux[3][2] = 1;
		 	matAux[3][3] = 1;

		 	printf(" B'C ");
		 }
	}
//-------------------------------------------------------------------------------------------------------
//-----------------------------------DIR-ESQ-SUP---------------------------------------------------------
	if ((matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[1][0] == 0 && matAux[1][3] == 0) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[1][0] == 0 && matAux[1][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[1][0] == 0 && matAux[1][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[1][0] == 1 && matAux[1][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[1][0] == 0 && matAux[1][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 1 && matAux[1][0] == 0 && matAux[1][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[1][0] == 0 && matAux[1][3] == 1) ||
		(matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[1][0] == 1 && matAux[1][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[1][0] == 1 && matAux[1][3] == 0) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[1][0] == 0 && matAux[1][3] == 1) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[1][0] == 1 && matAux[1][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[1][0] == 1 && matAux[1][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[1][0] == 1 && matAux[1][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 1 && matAux[1][0] == 0 && matAux[1][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 1 && matAux[1][0] == 1 && matAux[1][3] == 0))
	{
		if (matKarn[0][0] == 1 && matKarn[0][3] == 1 && matKarn[1][0] == 1 && matKarn[1][3] == 1)
		 {
		 	matAux[0][0] = 1;
		 	matAux[0][3] = 1;
		 	matAux[1][0] = 1;
		 	matAux[1][3] = 1;

		 	printf(" A'D' ");
		 }
	}
//-------------------------------------------------------------------------------------------------------
//-----------------------------------DIR-ESQ-MEIO---------------------------------------------------------
	if ((matAux[1][0] == 0 && matAux[1][3] == 0 && matAux[2][0] == 0 && matAux[2][3] == 0) ||
		(matAux[1][0] == 1 && matAux[1][3] == 0 && matAux[2][0] == 0 && matAux[2][3] == 0) ||
		(matAux[1][0] == 0 && matAux[1][3] == 1 && matAux[2][0] == 0 && matAux[2][3] == 0) ||
		(matAux[1][0] == 0 && matAux[1][3] == 0 && matAux[2][0] == 1 && matAux[2][3] == 0) ||
		(matAux[1][0] == 0 && matAux[1][3] == 0 && matAux[2][0] == 0 && matAux[2][3] == 1) ||
		(matAux[1][0] == 1 && matAux[1][3] == 1 && matAux[2][0] == 0 && matAux[2][3] == 0) ||
		(matAux[1][0] == 0 && matAux[1][3] == 1 && matAux[2][0] == 0 && matAux[2][3] == 1) ||
		(matAux[1][0] == 0 && matAux[1][3] == 0 && matAux[2][0] == 1 && matAux[2][3] == 1) ||
		(matAux[1][0] == 1 && matAux[1][3] == 0 && matAux[2][0] == 1 && matAux[2][3] == 0) ||
		(matAux[1][0] == 1 && matAux[1][3] == 0 && matAux[2][0] == 0 && matAux[2][3] == 1) ||
		(matAux[1][0] == 0 && matAux[1][3] == 1 && matAux[2][0] == 1 && matAux[2][3] == 0) ||
		(matAux[1][0] == 0 && matAux[1][3] == 1 && matAux[2][0] == 1 && matAux[2][3] == 1) ||
		(matAux[1][0] == 1 && matAux[1][3] == 0 && matAux[2][0] == 1 && matAux[2][3] == 1) ||
		(matAux[1][0] == 1 && matAux[1][3] == 1 && matAux[2][0] == 0 && matAux[2][3] == 1) ||
		(matAux[1][0] == 1 && matAux[1][3] == 1 && matAux[2][0] == 1 && matAux[2][3] == 0))
	{
		if (matKarn[1][0] == 1 && matKarn[1][3] == 1 && matKarn[2][0] == 1 && matKarn[2][3] == 1)
		 {
		 	matAux[1][0] = 1;
		 	matAux[1][3] = 1;
		 	matAux[2][0] = 1;
		 	matAux[2][3] = 1;

		 	printf(" BD' ");
		 }
	}
//-------------------------------------------------------------------------------------------------------
//-----------------------------------DIR-ESQ-INF---------------------------------------------------------
	if ((matAux[2][0] == 0 && matAux[2][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[2][0] == 1 && matAux[2][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[2][0] == 0 && matAux[2][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[2][0] == 0 && matAux[2][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 0) ||
		(matAux[2][0] == 0 && matAux[2][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[2][0] == 1 && matAux[2][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[2][0] == 0 && matAux[2][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[2][0] == 0 && matAux[2][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 1) ||
		(matAux[2][0] == 1 && matAux[2][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 0) ||
		(matAux[2][0] == 1 && matAux[2][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[2][0] == 0 && matAux[2][3] == 1 && matAux[3][0] == 1 && matAux[3][3] == 0) ||
		(matAux[2][0] == 0 && matAux[2][3] == 1 && matAux[3][0] == 1 && matAux[3][3] == 1) ||
		(matAux[2][0] == 1 && matAux[2][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 1) ||
		(matAux[2][0] == 1 && matAux[2][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[2][0] == 1 && matAux[2][3] == 1 && matAux[3][0] == 1 && matAux[3][3] == 0))
	{
		if (matKarn[2][0] == 1 && matKarn[2][3] == 1 && matKarn[3][0] == 1 && matKarn[3][3] == 1)
		 {
		 	matAux[2][0] = 1;
		 	matAux[2][3] = 1;
		 	matAux[3][0] = 1;
		 	matAux[3][3] = 1;

		 	printf(" AD' ");
		 }
	}
//-------------------------------------------------------------------------------------------------------
//===================================QUINAS==============================================================

	if ((matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[0][0] == 0 && matAux[0][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 0) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[3][0] == 1 && matAux[3][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1 && matAux[3][0] == 1 && matAux[3][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0 && matAux[3][0] == 1 && matAux[3][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 1 && matAux[3][0] == 0 && matAux[3][3] == 1) ||
		(matAux[0][0] == 1 && matAux[0][3] == 1 && matAux[3][0] == 1 && matAux[3][3] == 0))
	{

		if (matKarn[0][0] == 1 && matKarn[0][3] == 1 && matKarn[3][0] == 1 && matKarn[3][3] == 1)
		{
			matAux[0][0] = 1;
			matAux[0][3] = 1;
			matAux[3][0] = 1;
			matAux[3][3] = 1;

			printf(" B'D'");
		}

	}

//-------------------------------------------------------------------------------------------------------

}

//=======================================DUPLAS==========================================================
void duplas()
{
//============================================LINHAS=========================================================

//********************LINHA 0***************************************

//---------------------ESQUERDA------------------------------
	if ((matAux[0][0] == 0 && matAux[0][1] == 0) ||
		(matAux[0][0] == 1 && matAux[0][1] == 0) ||
		(matAux[0][0] == 0 && matAux[0][1] == 1))
	{
		if (matKarn[0][0] == 1 && matKarn[0][1] == 1)
		{
			matAux[0][0] = 1;
			matAux[0][1] = 1;

			printf(" A'B'C'");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[0][1] == 0 && matAux[0][2] == 0) ||
		(matAux[0][1] == 1 && matAux[0][2] == 0) ||
		(matAux[0][1] == 0 && matAux[0][2] == 1))
	{
		if (matKarn[0][1] == 1 && matKarn[0][2] == 1)
		{
			matAux[0][1] = 1;
			matAux[0][2] = 1;

			printf(" A'B'D");
		}
	}

//---------------------DIREITA------------------------------
	if ((matAux[0][2] == 0 && matAux[0][3] == 0) ||
		(matAux[0][2] == 1 && matAux[0][3] == 0) ||
		(matAux[0][2] == 0 && matAux[0][3] == 1))
	{
		if (matKarn[0][2] == 1 && matKarn[0][3] == 1)
		{
			matAux[0][2] = 1;
			matAux[0][3] = 1;

			printf(" A'B'C");
		}
	}

//********************LINHA 1***************************************

//---------------------ESQUERDA------------------------------
	if ((matAux[1][0] == 0 && matAux[1][1] == 0) ||
		(matAux[1][0] == 1 && matAux[1][1] == 0) ||
		(matAux[1][0] == 0 && matAux[1][1] == 1))
	{
		if (matKarn[1][0] == 1 && matKarn[1][1] == 1)
		{
			matAux[1][0] = 1;
			matAux[1][1] = 1;

			printf(" A'BC'");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[1][1] == 0 && matAux[1][2] == 0) ||
		(matAux[1][1] == 1 && matAux[1][2] == 0) ||
		(matAux[1][1] == 0 && matAux[1][2] == 1))
	{
		if (matKarn[1][1] == 1 && matKarn[1][2] == 1)
		{
			matAux[1][1] = 1;
			matAux[1][2] = 1;

			printf(" A'BD");
		}
	}

//---------------------DIREITA------------------------------
	if ((matAux[1][2] == 0 && matAux[1][3] == 0) ||
		(matAux[1][2] == 1 && matAux[1][3] == 0) ||
		(matAux[1][2] == 0 && matAux[1][3] == 1))
	{
		if (matKarn[1][2] == 1 && matKarn[1][3] == 1)
		{
			matAux[1][2] = 1;
			matAux[1][3] = 1;

			printf(" A'BC");
		}
	}

//********************LINHA 2***************************************

//---------------------ESQUERDA------------------------------
	if ((matAux[2][0] == 0 && matAux[2][1] == 0) ||
		(matAux[2][0] == 1 && matAux[2][1] == 0) ||
		(matAux[2][0] == 0 && matAux[2][1] == 1))
	{
		if (matKarn[2][0] == 1 && matKarn[2][1] == 1)
		{
			matAux[2][0] = 1;
			matAux[2][1] = 1;

			printf(" ABC'");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[2][1] == 0 && matAux[2][2] == 0) ||
		(matAux[2][1] == 1 && matAux[2][2] == 0) ||
		(matAux[2][1] == 0 && matAux[2][2] == 1))
	{
		if (matKarn[2][1] == 1 && matKarn[2][2] == 1)
		{
			matAux[2][1] = 1;
			matAux[2][2] = 1;

			printf(" ABD");
		}
	}

//---------------------DIREITA------------------------------
	if ((matAux[2][2] == 0 && matAux[2][3] == 0) ||
		(matAux[2][2] == 1 && matAux[2][3] == 0) ||
		(matAux[2][2] == 0 && matAux[2][3] == 1))
	{
		if (matKarn[2][2] == 1 && matKarn[2][3] == 1)
		{
			matAux[2][2] = 1;
			matAux[2][3] = 1;

			printf(" ABC");
		}
	}

//********************LINHA 3***************************************

//---------------------ESQUERDA------------------------------
	if ((matAux[3][0] == 0 && matAux[3][1] == 0) ||
		(matAux[3][0] == 1 && matAux[3][1] == 0) ||
		(matAux[3][0] == 0 && matAux[3][1] == 1))
	{
		if (matKarn[3][0] == 1 && matKarn[3][1] == 1)
		{
			matAux[3][0] = 1;
			matAux[3][1] = 1;

			printf(" AB'C'");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[3][1] == 0 && matAux[3][2] == 0) ||
		(matAux[3][1] == 1 && matAux[3][2] == 0) ||
		(matAux[3][1] == 0 && matAux[3][2] == 1))
	{
		if (matKarn[3][1] == 1 && matKarn[3][2] == 1)
		{
			matAux[3][1] = 1;
			matAux[3][2] = 1;

			printf(" AB'D");
		}
	}

//---------------------DIREITA------------------------------
	if ((matAux[3][2] == 0 && matAux[3][3] == 0) ||
		(matAux[3][2] == 1 && matAux[3][3] == 0) ||
		(matAux[3][2] == 0 && matAux[3][3] == 1))
	{
		if (matKarn[3][2] == 1 && matKarn[3][3] == 1)
		{
			matAux[3][2] = 1;
			matAux[3][3] = 1;

			printf(" AB'C");
		}
	}

//=====================================COLUNAS=====================================

//********************COLUNA 0***************************************

//--------------------CIMA------------------------------
	if ((matAux[0][0] == 0 && matAux[1][0] == 0) ||
		(matAux[0][0] == 1 && matAux[1][0] == 0) ||
		(matAux[0][0] == 0 && matAux[1][0] == 1))
	{
		if (matKarn[0][0] == 1 && matKarn[1][0] == 1)
		{
			matAux[0][0] = 1;
			matAux[1][0] = 1;

			printf(" A'C'D'");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[1][0] == 0 && matAux[2][0] == 0) ||
		(matAux[1][0] == 1 && matAux[2][0] == 0) ||
		(matAux[1][0] == 0 && matAux[2][0] == 1))
	{
		if (matKarn[1][0] == 1 && matKarn[2][0] == 1)
		{
			matAux[1][0] = 1;
			matAux[2][0] = 1;

			printf(" BC'D'");
		}
	}

//---------------------INFERIOR------------------------------
	if ((matAux[2][0] == 0 && matAux[3][0] == 0) ||
		(matAux[2][0] == 1 && matAux[3][0] == 0) ||
		(matAux[2][0] == 0 && matAux[3][0] == 1))
	{
		if (matKarn[2][0] == 1 && matKarn[3][0] == 1)
		{
			matAux[2][0] = 1;
			matAux[3][0] = 1;

			printf(" AC'D'");
		}
	}

//********************COLUNA 1***************************************

//--------------------CIMA------------------------------
	if ((matAux[0][1] == 0 && matAux[1][1] == 0) ||
		(matAux[0][1] == 1 && matAux[1][1] == 0) ||
		(matAux[0][1] == 0 && matAux[1][1] == 1))
	{
		if (matKarn[0][1] == 1 && matKarn[1][1] == 1)
		{
			matAux[0][1] = 1;
			matAux[1][1] = 1;

			printf(" A'C'D");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[1][1] == 0 && matAux[2][1] == 0) ||
		(matAux[1][1] == 1 && matAux[2][1] == 0) ||
		(matAux[1][1] == 0 && matAux[2][1] == 1))
	{
		if (matKarn[1][1] == 1 && matKarn[2][1] == 1)
		{
			matAux[1][1] = 1;
			matAux[2][1] = 1;

			printf(" BC'D");
		}
	}

//---------------------INFERIOR------------------------------
	if ((matAux[2][1] == 0 && matAux[3][1] == 0) ||
		(matAux[2][1] == 1 && matAux[3][1] == 0) ||
		(matAux[2][1] == 0 && matAux[3][1] == 1))
	{
		if (matKarn[2][1] == 1 && matKarn[3][1] == 1)
		{
			matAux[2][1] = 1;
			matAux[3][1] = 1;

			printf(" AC'D");
		}
	}

//********************COLUNA 2***************************************

//--------------------CIMA------------------------------
	if ((matAux[0][2] == 0 && matAux[1][2] == 0) ||
		(matAux[0][2] == 1 && matAux[1][2] == 0) ||
		(matAux[0][2] == 0 && matAux[1][2] == 1))
	{
		if (matKarn[0][2] == 1 && matKarn[1][2] == 1)
		{
			matAux[0][2] = 1;
			matAux[1][2] = 1;

			printf(" A'CD");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[1][2] == 0 && matAux[2][2] == 0) ||
		(matAux[1][2] == 1 && matAux[2][2] == 0) ||
		(matAux[1][2] == 0 && matAux[2][2] == 1))
	{
		if (matKarn[1][2] == 1 && matKarn[2][2] == 1)
		{
			matAux[1][2] = 1;
			matAux[2][2] = 1;

			printf(" BCD");
		}
	}

//---------------------INFERIOR------------------------------
	if ((matAux[2][2] == 0 && matAux[3][2] == 0) ||
		(matAux[2][2] == 1 && matAux[3][2] == 0) ||
		(matAux[2][2] == 0 && matAux[3][2] == 1))
	{
		if (matKarn[2][2] == 1 && matKarn[3][2] == 1)
		{
			matAux[2][2] = 1;
			matAux[3][2] = 1;

			printf(" ACD");
		}
	}

//********************COLUNA 3***************************************

//--------------------CIMA------------------------------
	if ((matAux[0][3] == 0 && matAux[1][3] == 0) ||
		(matAux[0][3] == 1 && matAux[1][3] == 0) ||
		(matAux[0][3] == 0 && matAux[1][3] == 1))
	{
		if (matKarn[0][3] == 1 && matKarn[1][3] == 1)
		{
			matAux[0][3] = 1;
			matAux[1][3] = 1;

			printf(" A'CD'");
		}
	}

//---------------------MEIO---------------------------------
	if ((matAux[1][3] == 0 && matAux[2][3] == 0) ||
		(matAux[1][3] == 1 && matAux[2][3] == 0) ||
		(matAux[1][3] == 0 && matAux[2][3] == 1))
	{
		if (matKarn[1][3] == 1 && matKarn[2][3] == 1)
		{
			matAux[1][3] = 1;
			matAux[2][3] = 1;

			printf(" BCD'");
		}
	}

//---------------------INFERIOR------------------------------
	if ((matAux[2][3] == 0 && matAux[3][3] == 0) ||
		(matAux[2][3] == 1 && matAux[3][3] == 0) ||
		(matAux[2][3] == 0 && matAux[3][3] == 1))
	{
		if (matKarn[2][3] == 1 && matKarn[3][3] == 1)
		{
			matAux[2][3] = 1;
			matAux[3][3] = 1;

			printf(" ACD'");
		}
	}

//======================DUPLA DIVIDIDA=================================================

//********************LINHAS***************************************

//---------------------LINHA0------------------------
	if ((matAux[0][0] == 0 && matAux[0][3] == 0) ||
		(matAux[0][0] == 1 && matAux[0][3] == 0) ||
		(matAux[0][0] == 0 && matAux[0][3] == 1))
	{
		if (matKarn[0][0] == 1 && matKarn[0][3] == 1)
		{
			matAux[0][0] = 1;
			matAux[0][3] = 1;

			printf(" A'B'D'");
		}
	}

//---------------------LINHA1-------------------------------
	if ((matAux[1][0] == 0 && matAux[1][3] == 0) ||
		(matAux[1][0] == 1 && matAux[1][3] == 0) ||
		(matAux[1][0] == 0 && matAux[1][3] == 1))
	{
		if (matKarn[1][0] == 1 && matKarn[1][3] == 1)
		{
			matAux[1][0] = 1;
			matAux[1][3] = 1;

			printf(" A'BD'");
		}
	}

//---------------------LINHA2-------------------------------
	if ((matAux[2][0] == 0 && matAux[2][3] == 0) ||
		(matAux[2][0] == 1 && matAux[2][3] == 0) ||
		(matAux[2][0] == 0 && matAux[2][3] == 1))
	{
		if (matKarn[2][0] == 1 && matKarn[2][3] == 1)
		{
			matAux[2][0] = 1;
			matAux[2][3] = 1;

			printf(" ABD'");
		}
	}

//---------------------LINHA3-------------------------------
	if ((matAux[3][0] == 0 && matAux[3][3] == 0) ||
		(matAux[3][0] == 1 && matAux[3][3] == 0) ||
		(matAux[3][0] == 0 && matAux[3][3] == 1))
	{
		if (matKarn[3][0] == 1 && matKarn[3][3] == 1)
		{
			matAux[3][0] = 1;
			matAux[3][3] = 1;

			printf(" AB'D'");
		}
	}

//********************COLUNAS**************************************

//---------------------COLUNA0-----------------------------
	if ((matAux[0][0] == 0 && matAux[3][0] == 0) ||
		(matAux[0][0] == 1 && matAux[3][0] == 0) ||
		(matAux[0][0] == 0 && matAux[3][0] == 1))
	{
		if (matKarn[0][0] == 1 && matKarn[3][0] == 1)
		{
			matAux[0][0] = 1;
			matAux[3][0] = 1;

			printf(" B'C'D'");
		}
	}

//------------------COLUNA1-------------------------------
	if ((matAux[0][1] == 0 && matAux[3][1] == 0) ||
		(matAux[0][1] == 1 && matAux[3][1] == 0) ||
		(matAux[0][1] == 0 && matAux[3][1] == 1))
	{
		if (matKarn[0][1] == 1 && matKarn[3][1] == 1)
		{
			matAux[0][1] = 1;
			matAux[3][1] = 1;

			printf(" B'C'D");
		}
	}

//--------------------COLUNA2-------------------------------
	if ((matAux[0][2] == 0 && matAux[3][2] == 0) ||
		(matAux[0][2] == 1 && matAux[3][2] == 0) ||
		(matAux[0][2] == 0 && matAux[3][2] == 1))
	{
		if (matKarn[0][2] == 1 && matKarn[3][2] == 1)
		{
			matAux[0][2] = 1;
			matAux[3][2] = 1;

			printf(" B'CD");
		}
	}

//--------------------COLUNA3-------------------------------
	if ((matAux[0][3] == 0 && matAux[3][3] == 0) ||
		(matAux[0][3] == 1 && matAux[3][3] == 0) ||
		(matAux[0][3] == 0 && matAux[3][3] == 1))
	{
		if (matKarn[0][3] == 1 && matKarn[3][3] == 1)
		{
			matAux[0][3] = 1;
			matAux[3][3] = 1;

			printf(" B'CD'");
		}
	}
}

// =========================UNITARIO=============================================================

void unitario()
{

//------------LINHA0----------------------------------------------
	if (matAux[0][0] == 0 && matKarn[0][0] == 1)
	{
		matAux[0][0] = 1;

		printf(" A'B'C'D'");
	}

	if (matAux[0][1] == 0 && matKarn[0][1] == 1)
	{
		matAux[0][1] = 1;

		printf(" A'B'C'D");
	}

	if (matAux[0][2] == 0 && matKarn[0][2] == 1)
	{
		matAux[0][2] = 1;

		printf(" A'B'CD");
	}

	if (matAux[0][3] == 0 && matKarn[0][3] == 1)
	{
		matAux[0][3] = 1;

		printf(" A'B'CD'");
	}

//---------------------LINHA1------------------------------------------

	if (matAux[1][0] == 0 && matKarn[1][0] == 1)
	{
		matAux[1][0] = 1;

		printf(" A'BC'D'");
	}

	if (matAux[1][1] == 0 && matKarn[1][1] == 1)
	{
		matAux[1][1] = 1;

		printf(" A'BC'D");
	}

	if (matAux[1][2] == 0 && matKarn[1][2] == 1)
	{
		matAux[1][2] = 1;

		printf(" A'BCD");
	}

	if (matAux[1][3] == 0 && matKarn[1][3] == 1)
	{
		matAux[1][3] = 1;

		printf(" A'BCD'");
	}

//----------------------LINHA2-----------------------------------------------

	if (matAux[2][0] == 0 && matKarn[2][0] == 1)
	{
		matAux[2][0] = 1;

		printf(" ABC'D'");
	}

	if (matAux[2][1] == 0 && matKarn[2][1] == 1)
	{
		matAux[2][1] = 1;

		printf(" ABC'D");
	}

	if (matAux[2][2] == 0 && matKarn[2][2] == 1)
	{
		matAux[2][2] = 1;

		printf(" ABCD");
	}

	if (matAux[2][3] == 0 && matKarn[2][3] == 1)
	{
		matAux[2][3] = 1;

		printf(" ABCD'");
	}

//------------------LINHA3----------------------------------------------

	if (matAux[3][0] == 0 && matKarn[3][0] == 1)
	{
		matAux[3][0] = 1;

		printf(" AB'C'D'");
	}

	if (matAux[3][1] == 0 && matKarn[3][1] == 1)
	{
		matAux[3][1] = 1;

		printf(" AB'C'D");
	}

	if (matAux[3][2] == 0 && matKarn[3][2] == 1)
	{
		matAux[3][2] = 1;

		printf(" AB'CD");
	}

	if (matAux[3][3] == 0 && matKarn[3][3] == 1)
	{
		matAux[3][3] = 1;

		printf(" AB'CD'");
	}
}

