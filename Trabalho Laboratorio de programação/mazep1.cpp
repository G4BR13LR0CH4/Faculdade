//Feito no DEV-C++. COMPILAR EM CPP
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* mat;

void criacao(int m, int n){
	mat = (int*)malloc(m*n*sizeof(int));
	int po;

	srand(time(NULL));
//passo: 0, criar uma matriz e separar as celulas x, 
	for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if((i%2) == 0)
                mat[i*n+j] = 1;
            else if((j%2) != 0)//para ser uma celula x o valor j e o valor i tem que ser impar.
                mat[i*n+j] = 0;
            else
                mat[i*n+j] = 1;
        }
    }
//passo: 1, quebra as paredes das celulas aleatoriamente;
    for(int i = 1; i < m - 1; i = i+2){
    	for(int j = 1; j < n - 1; j = j+2){
    		po = rand()%2;//escolha de 0 ou 1 para decidir a quebra da parede.
    		/*olhando uma matriz impar, com as celulas separadas, eu considerei que uma celula
			só pode quebrar um dos dois indices, seja ele o indice que está a baixo ou o
			indice que está a sua direita.*/
    		if(po == 1){//quebrar o indice a direita
    			mat[(i + 1)*n+j]= 0;
			}if(po == 0){//quebra o indice que esta em baixo
				mat[i*n+(j + 1)] = 0;
			}
		}
	}
	//criação das paredes mestres
	for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == m - 1)
            	mat[i*n+j] = 1;
            else if(j == 0 || j == n - 1)
            	mat[i*n+j] = 1;
        }
    }
	mat[1*n+0] = 0;
    mat[(m - 2)*n+(n - 1)] = 4;
	////
	for(int i = 0; i < m - 1; i++){
		for(int j = 0; j < n - 1; j++){
			if(mat[i*n+j] == 0){
				if((mat[i*n+(j + 1)] == 0) || (mat[i*n+(j - 1)] == 0) || (mat[(i - 1)*n+j] == 0) || (mat[(i + 1)*n+j] == 0))
					mat[i*n+j] = 2;
				else{
							if(mat[i*n+(j - 1)] != 2)
								mat[i*n+(j - 1)] = 2;
							if(mat[i*n+(j + 1)] != 2)
								mat[i*n+(j + 1)] = 2;
							if(mat[(i - 1)*n+j] != 2)
								mat[(i - 1)*n+j] = 2;
							if(mat[(i + 1)*n+j] != 2)
								mat[(i + 1)*n+j] = 2;
				}
					
			}
		}
	}
}

void exibir(int m, int n){
	FILE *pont_arq;
	
	pont_arq = fopen("maze1.txt","w");
	//criação das paredes mestres
	for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == m - 1)
            	mat[i*n+j] = 1;
            else if(j == 0 || j == n - 1)
            	mat[i*n+j] = 1;
        }
    }
    //abertura de entrada e saida
    /*nessa abertura, irei atribuir um valor qualquer para servir com um objetivo, ou seja, quando for percorrer
	a função recursiva só deve para quando encontra esse valor que ficara na entrada e na saida.*/
	mat[1*n+0] = 0;
    mat[(m - 2)*n+(n - 1)] = 0;
    /*essa parte de baixo será alterada por comandos de escrever no arquivo*/
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
        	if((i%2 == 0) && (j%2 == 0) && (mat[i*n+j] == 1))
   				fprintf(pont_arq, "+", mat[i*n+j]);       		
			else if((mat[(i - 1)*n+j] == 1) && (mat[(i+1)*n+j] == 1) && (mat[i*n+j] == 1))
   				fprintf(pont_arq, "|", mat[i*n+j]);
   			else if((mat[i*n+(j+1)] == 1) && (mat[i*n+(j - 1)] == 1) && (mat[i*n+j] == 1))
   				fprintf(pont_arq, "-", mat[i*n+j]);
   			if(mat[i*n+j] == 2 || mat[i*n+j] == 0)
   				fprintf(pont_arq, " ", mat[i*n+j]);
        }
        fprintf(pont_arq,"\n");
    }
    fclose(pont_arq);
    if(pont_arq != NULL)
		printf("\tLabirinto criado.");
	else
		printf("\tErro ao criar o labirinto");
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	m = m*2;
	n = n*2;

	if((m%2) == 0){
		m += 1;
	} if((n%2) == 0){
		n += 1;
	}

	criacao(m,n);
	exibir(m,n);
	
	FILE* num;
	
	num = fopen("num.txt", "w");
	
	fprintf(num , "%d ", m);
	fprintf(num , "%d", n);
	
	fclose(num);
	return 0;
}
