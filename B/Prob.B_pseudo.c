/*
    MAIN{
    1) Parâmetros entrada:
        - Tamanho eixos : N
        - Posição inicial : x_init e y_init ; coor[x_init][y_init];
        - Número de peoes : peoes;
        - Coordenadas peoes : ocupada->x e ocupada->y;

    2) Combinações de movimentos possíveis a partir da posição do cavalo :
        int xp[8] = {-2, -2, -1, -1,  1, 1,  2, 2 };
        int yp[8] = {-1,  1, -2,  2, -2, 2, -1, 1 };

    3) Criar matriz com valores inicialmente a 0 :
        for (int i = 0; i< N*N; ++i)
            Ocupada[i] = 0;
        }

        ou

        int coord[N][N] = {0};
        int coord[x_init][y_init] = 1;
        possivel = (N*N)-peoes;
        Opcao(x_init, y_init, N, 1, coord, possivel);

    }

    5)Função para verificar validade da próxima posição :
        bool validarSalto(int N, int x, int y, int matriz)
        - Se x >= 0 e x < N && y >= 0 e y < N ( Se encontra-se dentro dos limites)
        - if matriz[i][j] = 0
            TRUE
          else
            FALSE

    5)Funcao resultado(int x, int y, int N, int saltos,int coord[][], int possivel)
        int A[8];
        if(saltos == possivel)
           return true;
        A =  arrMenor(A,coord,xp,yp);
        for(0 a 8)              -> Corresponder ao nºcombinações saltos
            next_x = x + xp[k];
            next_y = y + yp[k];

            ValidarSalto(int next_x, int next_y, N, matriz)
                Sim ?
                    coord[next_x][next_y] = saltos;
                    cont = Saltos(int next_x, int next_y)
                    É a menor ?
                        Sim ?
                            coord[next_x][next_y] = saltos;
                            Opcao(next_x, next_y, N,1+saltos);
                Não ?
                    continue;
        return false

    int *arrmenor( int N, int A[8], int coord[N][N], int xp[], int yp[]){
        int saltos[8][2], x, y;
        for ( int i = 0 ; i < 8 ; i ++ ){
            x = x + xp[i];
            y = y + yp[i];
            if(validarSalto(x,y,N,coord))
                saltos[i][0] = saltosPossiveis(x,y,N,coord,xp,yp);
                saltos[i][1] = i;
            else
            saltos[i][0] = saltosPossiveis(x,y,N,coord,xp,yp);
            saltos[i][1] = i;
        }
        bubble_sort(saltos);
        for(int j = 0; j < 8 ; j++){
          A[j] = saltos[j][1];
        }
        return A;
    }

    void bubble_sort(int A[8][2]){   // Ordenar elementos de array
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





    5)Funcao Saltos
        int cont = 0;
        for(0 a 8)
            ValidarSalto(int next_x, int next_y)
                cont++;
        return cont;

    6)Reposta final:
        bool resultado(int cont, int N, int peoes);
        - Se contador de passos = (N*N)-peoes-1 -> R: YES
        - Caso contrário -> R: NO


------------------------RASCUNHO 1-----------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int validarSalto(int x, int y, int N, int matriz[N][N]){
    if ((x >= 0) && (x < N) && (y >= 0) && (y < N) && (matriz[x][y] == 0))
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

void bubble_sort(int A[8][2]){   // Ordenar elementos de array
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
    int saltos[8][2], x, y;
    for ( int i = 0 ; i < 8 ; i ++ ){
        x = x + xp[i];
        y = y + yp[i];
        if(validarSalto(x,y,N,coord) == 1){
            saltos[i][0] = saltosPossiveis(x,y,N,coord,xp,yp);
            saltos[i][1] = i;
        } else{
        saltos[i][0] = saltosPossiveis(x,y,N,coord,xp,yp);
        saltos[i][1] = i;
        }
    }
    bubble_sort(saltos);
    for(int j = 0; j < 8 ; j++){
      A[j] = saltos[j][1];
    }
}

int resultado(int x, int y, int N, int saltos,int coord[N][N], int possivel, int *xp, int *yp){
    int i, A[8], next_x, next_y;
    if(saltos == possivel)
        return 1;
    arrMenor(N,A,coord,xp,yp);
    for(i = 0; i < 8; i++){
        next_x = x + xp[A[i]];
        next_y = y + yp[A[i]];
        if ( validarSalto(next_x , next_y , N , coord) == 1 ){
            coord[next_x][next_y] = saltos;
            if ( resultado(next_x,next_y,N, (saltos+1) ,coord,possivel,xp,yp) == 1)
                return 1;
            else
                coord[next_x][next_y] = 0;
       }
    }
    return 0;
}

int main(){
    int i, j, N, x_init, y_init, peoes, posx, posy, possivel, res;

    scanf("%d", &N);
    scanf("%d", &x_init);
    scanf("%d", &y_init);
    scanf("%d", &peoes);

    int xp[8] = {-2, -2, -1, -1,  1, 1,  2, 2 };
    int yp[8] = {-1,  1, -2,  2, -2, 2, -1, 1 };
    int coord[N][N];

    for( i = 0; i < N; i++){
      for( j = 0; j < N; j++)
        coord[i][j] = 0;
    }

    for( i = 0 ; i < peoes ; i++){
        printf("x :");
        scanf("%d",&posx);
        printf("y :");
        scanf("%d",&posy);
        coord[posx][posy] = -1;
    }

    possivel = (N*N)-peoes;
    coord[x_init][y_init] = 1;

    res = resultado(x_init, y_init, N, 1, coord, possivel, xp, yp);

    if ( res ==  1)
      printf("YES");
    else
      printf("NO");

    return 0;
}










*/
