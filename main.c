/*
    OBJETIVO: O objetivo deste desafio e, dada uma senha digitada pelo usuario,
                verificar se esta satisfaz as normas descritas acima.

    ENTRADA: A entrada e composta por um inteiro n, seguido por n palavras, que compoem o dicionario de palavras reservadas.
Todas as palavras do dicionario estao em minusculas. Por fim, temos a senha digitada pelo usuario.
Voce pode assumir que 0 <= n <= 50. A senha digitada pelo usuario possui entre 1 e 50 caracteres.
Voce pode assumir que nao ha caracteres acentuados.

    SAIDA: A saida deve conter 'ok' se a senha digitada satisfaz as normas para uma senha,
ou um subconjunto das mensagens abaixo descrevendo todos os erros encontrados.
No caso de mais de uma mensagem de erro, a ordem de impressao deve seguir a ordem abaixo.

    A senha deve conter pelo menos 8 caracteres
    A senha deve conter pelo menos uma letra maiuscula
    A senha deve conter pelo menos uma letra minuscula
    A senha deve conter pelo menos um numero
    A senha deve conter pelo menos um simbolo
    A senha e um palindromo
    A senha nao pode conter palavras reservadas */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i = 0, j = 0, k = 0;
    int maiu = 0, minu = 0, simbolo = 0, n = 0, num = 0, ok = 0, tam = 0, palavra = 0, palindromo = 0;
    char senha[50], palind[50], senhaminu[50];

    scanf("%d", &n);

    char dicionario[n][50]; //O dicionario = uma matriz pois necessita buscar cada letra de cada palavra do dicionario

    //Limita para que a entrada do usuario esteja entre 0 e 50
    if (0 > n || 50 < n) { return 0; }

    for (i = 0; i < n; i++) {
        scanf("%s", dicionario[i]);
    }

    printf("\nSENHA: ");
    scanf("%s", senha);
    tam = strlen(senha);

    //Verifica se a senha e um palindromo
    for (i = 0; i < tam; i++) {
        palind[i] = senha[tam - 1 - i];
    }
    palind[tam] = '\0'; // Encerramente de matriz em '\0', verificando totalmente se a senha e um palindromo
    i = 0;  // inicializa `i` antes do while
    while (i < tam && palind[i] == senha[i]) {
        i++;
        if (i == tam) {
            palindromo = 1;
            ok = 0;
        }
    }

    // Transforma todos os caracteres da senha em letras minusculas para verificar palavras do dicionario
    for (i = 0; i < tam; i++) {
        senhaminu[i] = tolower(senha[i]);
    }
    senhaminu[tam] = '\0';  // adiciona terminador de string

    // Verifica se ha palavras no dicionario
    for (i = 0; i < n; i++) {
        for (j = 0; j <= (tam - strlen(dicionario[i])) + 1; j++) {
            palavra = 1;
            for (k = 0; k < strlen(dicionario[i]); k++) {
                if ((senhaminu[j + k]) != (dicionario[i][k])) {
                    palavra = 0;
                    break;
                }
            }
            if (palavra) {
                ok = 0;
                break;
            }
        }
        if (palavra) {
            break;
        }
    }

    // Valida cada requisito
    for (i = 0; i < tam; i++) {
        if (isdigit(senha[i])) {
            num = 1;
        }
        if (isupper(senha[i])) {
            maiu = 1;
        }
        if (islower(senha[i])) {
            minu = 1;
        }
        if (senha[i] == '?' || senha[i] == '!' || senha[i] == '#' || senha[i] == '@' || senha[i] == '$') {
            simbolo = 1;
        }
    }

    // Verifica cada um dos requisitos
    if (tam < 8) {
        printf("\nA senha deve conter pelo menos 8 caracteres");
    }
    if (maiu == 0) {
        printf("\nA senha deve conter pelo menos uma letra maiuscula");
    }
    if (minu == 0) {
        printf("\nA senha deve conter pelo menos uma letra minuscula");
    }
    if (num == 0) {
        printf("\nA senha deve conter pelo menos um numero");
    }
    if (simbolo == 0) {
        printf("\nA senha deve conter pelo menos um simbolo");
    }
    if (palindromo) {
        printf("\nA senha e um palindromo");
    }
    if (palavra) {
        printf("\nA senha nao pode conter palavras reservadas");
    }

    // Invalida 'ok' caso requisito nao cumprido
    if (num == 0 || maiu == 0 || minu == 0 || simbolo == 0 || tam < 8 || palavra) {
        ok = 0;
    } else {
        ok = 1;
    }

    // Se a senha estiver correta (ok==1)
    if (ok == 1) {
        printf("\nok");
    }

    return 0;
}
