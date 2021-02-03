#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define DIM 3
int calcDet(int nDim, int mat[nDim][nDim]){
	int det=0, q, i, j, k, l, m;
	int smat[nDim-1][nDim-1];
	if(nDim > 2){
		for (i = 0; i < nDim; ++i)
		{
			q = pow(-1,i) * mat[0][i]; //coeff. Laplace
			for (j = 0; j < i; ++j)
			{
				for (k = 0; k < nDim-1; ++k)
				{
					smat[k][j] = mat[k+1][j];
				}
			}
			for(m = i+1; m < nDim; ++m)
			{
				for (l = 0; l < nDim-1; ++l)
				{
					smat[l][m-1] = mat[l+1][m];
				}
			}
			//stampa sottomatrici
			/*printf("Sottomatrice n.%d\n", i);
			for (int i = 0; i < nDim-1; ++i)
			{
				for (int j = 0; j < nDim-1; ++j)
				{
					printf(" %3d ",smat[i][j]);
				}
				printf("\n");
			}*/
			det +=q * calcDet(nDim-1,smat);
			//printf("Coeff. Laplace: %d \n", q);
			//printf("Somma Laplace parziale: %d\n", det);
		}
		
	}
	else det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
	//printf("Determinante Sottomatrice: %d\n", det);
	return det;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int matrice[DIM][DIM];
	int det;
	for (int i = 0; i < DIM; ++i)
	{
		for (int j = 0; j < DIM; ++j)
		{
			matrice[i][j]= (rand() % 10);
			//printf("Elemento matrice[%d][%d]: %d\n", i,j,matrice[i][j]);
		}
	}
	printf("MATRICE: \n");
	for (int i = 0; i < DIM; ++i)
	{
		for (int j = 0; j < DIM; ++j)
		{
			printf(" %3d ",matrice[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
	printf("Calcolo determinante matrice... \n");
	det = calcDet(DIM, matrice);
	printf("Determinante: %d\n", det);
	return 0;
}