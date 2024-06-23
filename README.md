OBJETIVO:

O objetivo deste código é, dada uma senha digitada pelo usuário, verificar se ela satisfaz as normas descritas acima.

ENTRADA:

A entrada é composta por um inteiro n, seguido por n palavras, que compõem o dicionário de palavras reservadas. Todas as palavras do dicionário estão em minúsculas. Por fim, temos a senha digitada pelo usuário. Você pode assumir que 0 <= n <= 50. A senha digitada pelo usuário possui entre 1 e 50 caracteres. Você pode assumir que não há caracteres acentuados.

SAÍDA:

A saída deve conter 'ok' se a senha digitada satisfaz as normas para uma senha ou um subconjunto das mensagens abaixo, descrevendo todos os erros encontrados. No caso de mais de uma mensagem de erro, a ordem de impressão deve seguir a ordem abaixo:

A senha deve conter pelo menos 8 caracteres.

A senha deve conter pelo menos uma letra maiúscula.

A senha deve conter pelo menos uma letra minúscula.

A senha deve conter pelo menos um número.

A senha deve conter pelo menos um símbolo.

A senha é um palíndromo.

A senha não pode conter palavras reservadas.
