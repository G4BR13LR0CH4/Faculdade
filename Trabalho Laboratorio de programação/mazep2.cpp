#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include <windows.h>

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
			s� pode quebrar um dos dois indices, seja ele o indice que est� a baixo ou o
			indice que est� a sua direita.*/
    		if(po == 1){//quebrar o indice a direita
    			mat[(i + 1)*n+j]= 0;
			}if(po == 0){//quebra o indice que esta em baixo
				mat[i*n+(j + 1)] = 0;
			}
		}
	}
	//cria��o das paredes mestres
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
	//cria��o das paredes mestres
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
	a fun��o recursiva s� deve para quando encontra esse valor que ficara na entrada e na saida.*/
	mat[1*n+0] = 3;
    mat[(m - 2)*n+(n - 1)] = 4;
    /*essa parte de baixo ser� alterada por comandos de escrever no arquivo*/
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
        	if((i%2 == 0) && (j%2 == 0) && (mat[i*n+j] == 1))
   				printf("+", mat[i*n+j]);       		
			else if((mat[(i - 1)*n+j] == 1) && (mat[(i+1)*n+j] == 1) && (mat[i*n+j] == 1))
   				printf("|", mat[i*n+j]);
   			else if((mat[i*n+(j+1)] == 1) && (mat[i*n+(j - 1)] == 1) && (mat[i*n+j] == 1))
   				printf("-", mat[i*n+j]);
   			if(mat[i*n+j] == 2 || mat[i*n+j] == 0)
   				printf(" ", mat[i*n+j]);
   			if(mat[i*n+j] == 3 || mat[i*n+j] == 4)
   				printf("#");
        }
        printf("\n");
    }
}
int back(int i, int j,int n, int m){
	system("cls");
	if((mat[i*n+j] == 4)){//|| (mat[(i+1)*n+j] == 4) || (mat[(i-1)*n+j] == 4) || (mat[i*n+(j-1)] == 4) || (mat[i*n+(j+1)] == 4))
		mat[i*n+j] = 3;
		exibir(m,n);
		return 0;
	}	
 else if(mat[i*n+(j + 1)] == 2 || mat[i*n+(j + 1)] == 0 || mat[i*n+(j + 1)] == 4|| mat[i*n+(j)] == 3){//direita
		mat[i*n+j] = 3;
		j++;
		if(mat[i*n+(j)] == 4){
			mat[i*n+(j)] = 3;
			exibir(m,n);
			return 0;
		}
		exibir(m,n);
		back(i,j,n,m);
	}  else if(mat[i*n+(j - 1)] == 2 || mat[i*n+(j - 1)] == 0 || mat[i*n+(j - 1)] == 4 || mat[i*n+(j)] == 3){//esquerda;
		mat[i*n+j] = 3;
		j--;
		if(mat[i*n+(j)] == 4){
			mat[i*n+(j)] = 3;
			exibir(m,n);
			return 0;
		}
		exibir(m,n);
		back(i,j,n,m);
	}
	else if(mat[(i + 1)*n+j] == 2 || mat[(i + 1)*n+j] == 0 || mat[(i + 1)*n+j] == 4 || mat[i*n+(j)] == 3){//baixo
		mat[i*n+j] = 3;
		i++;
		if(mat[(i)*n+j] == 4){
			mat[i*n+(j)] = 3;
			exibir(m,n);
			return 0;
		}
		exibir(m,n);
		back(i,j,n,m);
	} else if(mat[(i - 1)*n+j] == 2 || mat[(i - 1)*n+j] == 0 || mat[(i - 1)*n+j] == 4 || mat[i*n+(j)] == 3){//cima
		mat[i*n+j] = 3;
		i--;
		if(mat[(i)*n+j] == 4){
			mat[i*n+(j)] = 3;
			exibir(m,n);
			return 0;
		}
		exibir(m,n);
		back(i,j,n,m);
	}
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
	back(1,0,n,m);
	exibir(m,n);
	return 0;
}
