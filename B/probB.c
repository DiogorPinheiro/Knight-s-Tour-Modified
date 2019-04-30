#include <stdio.h>
#include <stdlib.h>

int validarSalto(int x, int y, int N, int matriz[N][N]){
    if ((x >= 0) && (x < N) && (y >= 0) && (y < N) && (matriz[x][y] == 0))
      return(1);
    return(0);
}

int validarPosicao(int x, int y, int N){
    if ((x >= 0) && (x < N) && (y >= 0) && (y < N))
      return(1);
    return(0);
}

int saltosPossiveis(int x, int y, int N, int matriz[N][N], int *xp, int *yp){
    int i, cont = 0, next_x, next_y;
    for(i = 0; i < 8;i++){
        next_x = x + xp[i];
        next_y = y + yp[i];
        if(validarSalto(next_x,next_y,N,matriz))
            cont++;
    }
    return cont;
}

void printSolution(int N, int sol[N][N] ){ 
    int x, y;
	for ( x = 0; x < N; x++) 
    { 
        for (y = 0; y < N; y++) 
            printf(" %2d ", sol[x][y]); 
        printf("\n"); 
    } 
} 

void bubble_sort(int A[8][2]){   
  long c, d, t, i;

  for (c = 0 ; c < 7; c++){
    for (d = 0 ; d < 7 - c; d++){
      if (A[d][0] > A[d+1][0]){
        t = A[d][0];
        i = A[d][1];

        A[d][0] = A[d+1][0];
        A[d+1][0] = t;

        A[d][1] = A[d+1][1];
        A[d+1][1] = i;
      }
    }
  }
}

void arrMenor( int N, int A[8], int coord[N][N], int xp[], int yp[]){
    int saltos[8][2], i, j, x, y;
    for (i = 0 ; i < 8 ; i ++ ){
        x = x + xp[i];
        y = y + yp[i];
        if(validarSalto(x,y,N,coord)){
            saltos[i][0] = saltosPossiveis(x,y,N,coord,xp,yp);
            saltos[i][1] = i;
        } else{
        saltos[i][0] = 1000;
        saltos[i][1] = i;
        }
    }
    bubble_sort(saltos);
    for(j = 0; j < 8 ; j++){
      A[j] = saltos[j][1];
    }
}

int resultado(int x, int y, int N, int saltos,int coord[N][N], int possivel, int *xp, int *yp){
    int i, A[8], next_x, next_y;
    if(validarPosicao(x , y , N )){
		
		if(saltos == possivel)
			return 1;
    	//arrMenor(N,A,coord,xp,yp);
    	
    	for(i = 0; i < 8; i++){
    		
        	next_x = x + xp[i];
        	next_y = y + yp[i];
        	if ( validarSalto(next_x , next_y , N , coord)){
            	coord[next_x][next_y] = saltos;
            	if ( resultado(next_x,next_y,N, (saltos+1) ,coord,possivel,xp,yp))
                	return 1;
            	else
                	coord[next_x][next_y] = 0;
       		}
       		
    	}
	}	
    
    return 0;
}

int main(){
    int i, j, N, x_init, y_init, peoes, posx, posy, possivel, res;
	FILE *f;
	
	f = fopen("sample11.txt", "r");

    fscanf(f,"%d ", &N);
    fscanf(f,"%d %d ", &x_init, &y_init);
    fscanf(f,"%d ", &peoes);

    int xp[8] = {-2, -2, -1, -1,  1, 1,  2, 2 };
    int yp[8] = {-1,  1, -2,  2, -2, 2, -1, 1 };
    int coord[N][N];

    for( i = 0; i < N; i++){
      for( j = 0; j < N; j++)
        coord[i][j] = 0;
    }

    for( i = 0 ; i < peoes ; i++){
        fscanf(f,"%d %d",&posx,&posy);
        coord[posx][posy] = -1;
    }

    possivel = (N*N)-peoes;
    coord[x_init][y_init] = 1;

    res = resultado(x_init, y_init, N, 2, coord, possivel, xp, yp);

    if ( res ==  1){
	
      printf("YES");
	}
    else
      printf("NO");

    return 0;
}
