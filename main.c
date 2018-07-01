#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, N, M, S1, S2; // numero de servidores, numero de conexoes, conexao entre s1 e s2
    scanf("%d %d", &N, &M);
    int **matriz = (int **) calloc((size_t)N + 1, sizeof(int *)); // matriz de adjacência
    for(i = 0; i <= N; i++){
        matriz[i] = (int *) calloc((size_t)N + 1, sizeof(int));
    }
    for(i = 0; i < M; i++){ // realiza conexões não direcionadas
        scanf("%d %d", &S1, &S2);
        matriz[S1][S2] = 1;
        matriz[S2][S1] = 1;
    }
    int contVisitados = 0, contador = 0; // contador => conta rodadas. contVisitados => conta quantos vértices foram visitados em uma iteração
    while(contVisitados < N){ // roda até saber que todos os vértices foram verificados
        contVisitados = 0;
        for(i = 1; i < N + 1; i++){
            if(matriz[i][0] != 2){ // matriz[i][0] == 2 se vértice já foi verificado
                if(matriz[i][0] == 0){ // matriz[i][0] == 0 se o vértice não foi visitado
                    contVisitados++;
                    matriz[i][0] = 2; // marca vértice como visitado
                    for(j = i + 1; j < N + 1; j++){
                        if(i != j){ // ignora diagonal principal
                            if((matriz[i][j] == 1) && (matriz[j][0] != 2)) { // executa se há aresta entre S1 e S2
                                matriz[j][0] = 1; // marca matriz[j][0] como adjacente e não elegível para rodada atual
                            }
                        }
                    }
                }
                else if(matriz[i][0] == 1){ // zera os adjacentes anteriores para que possam ser visitados na próxima rodada
                    matriz[i][0] = 0;
                }
            }
            else{
                contVisitados++; // Soma contVisitados para servidores já atualizados nas rodadas anteriores
            }
        }
        contador++;
        if(contVisitados == N){ // sai do loop caso todos os vértices já tenham sido visitados
            break;
        }
    }
    for(i = 0; i <= N; i++){
        free(matriz[i]);
    }
    free(matriz);
    FILE *arq = fopen("rodada.txt", "w");
    fprintf(arq, "%d", contador);
    fclose(arq);
    return 0;
}