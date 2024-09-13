#include "funcionalidades.h"

void resolucaoMochila(elemento* elementos, int qtd, int pesoMax){
    int soma=0, i=0;

    //Em construção
    while(soma<pesoMax && i<qtd){
        if(soma + elementos[i].peso < pesoMax){
            soma+= elementos[i].peso;
            elementos[i].entrou = 1;
        }
        i++;
    }
}

int main(){
    FILE *arq = fopen("knapPI_1_100_1000_1", "r");
    int qtd, pesoMax;
    infoMochila(arq, &qtd, &pesoMax);
    elemento *elementos = (elemento *)calloc(qtd, sizeof(elemento));
    leituraPesoValor(arq, elementos, qtd);

    fclose(arq);

    ordenaRelacao(elementos, 0, qtd-1);
    resolucaoMochila(elementos, qtd, pesoMax);
    ordenaPosicao(elementos, 0, qtd-1);

    output(elementos, qtd);

    free(elementos);

    return 0;
}