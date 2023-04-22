# Trabalho AEDS I - O Labirinto Recorrente

# Descrição

Nesse trabalho, foi feito um programa usando a linguagem C++, que recebe um número N de matrizes MxM em um arquivo "input.data", e esse programa faz a simulação de um jogo onde um garoto tem que andar por um labirinto que possui três tipos de casas (posições da matriz), a casa com itens (números de 0 a 9), a casa com perigo ("*") e a casa com parede ("#").

A matriz gerada no programa com os dados do arquivo passará pela função onde será percorrida, com o critério citado anteriormente e com cinco possibilidades de avanço: para direita, para a esquerda, para baixo, para diagonal direita inferior e diagonal esquerda inferior, e sem a permissão para andar pra cima ou voltar a um elemento que já foi acessado.

## Arquivos

* ```main.cpp```: Arquivo e função principal do código;
* ```mat.hpp```: Declaração das funções utilizadas;
* ```mat.cpp```: Implementação das funções descritas no arquivo hpp;
* ```input.data```: Arquivo com as matrizes que serão lidas;
* ```Makefile```: Automatiza o processo de compilação;

## Funções

* int Tam() : Abre o arquivo e lê os dois primeiros caracteres que determinam o tamanho da matriz, como nessa atividade são usadas apenas matrizes quadradas (com mesma quantidade de linhas e colunas), é retornado apenas um valor.
* void ReadMatriz : A primeira função chamada no main.cpp, essa função lê uma matriz de cada vez após pegar o valor retornado pela função Tam() e gerar uma matriz de ponteiro com as posições obtidas, essa matriz será mostrada na tela do terminal e será encaminhada a próxima função, que é a responsável por percorrer a matriz. Nessa função também é calculada a soma total dos números que foram obtidos no percurso da matriz após passarem pela função WalkMatriz().
* void WalkMatriz (int **m,int size) : Essa função recebe como parâmetro a matriz obtida em ReadMatriz() e o tamanho obtido em Tam(). Aqui a matriz é percorrida seguindo os critérios citados na Descrição do Trabalho. Durante o processo dessa função, o número percorrido será igualado a -1, para não correr o risco de ser percorrido novamente, e esse número será salvo em um int do tipo vector, para depois que a função terminar o caminho ser mostrado na função anterior e a sua soma ser mostrada ao usuário.
* void SumUpTimes() : Segunda função chamada no main.cpp, essa irá mostrar o total de matrizes percorridas durante o programa, as somas de cada um dos caminhos percorridos nelas (salvos num int do tipo vector), e ao final dessa função e do programa, será mostrada a soma total de todos os números que foram obtidos em todas as matrizes percorridas no programa.

## Exemplos da execução

![image1](https://user-images.githubusercontent.com/127407951/227640068-807c981f-cea3-42e7-833f-9bb4f24664d7.jpg)


Print do arquivo "input.data" mostrando as duas primeiras matrizes e o tamanho delas.

![image2](https://user-images.githubusercontent.com/127407951/227640329-74c8c542-a1cb-4497-8a60-389d2b30dd7e.jpg)


Print do terminal com a leitura das duas matrizes e o caminho percorrido nelas.

![image3](https://user-images.githubusercontent.com/127407951/227640517-9cdaff96-429f-4e11-87f3-17936196c383.jpg)


Print do terminal com o final do programa, mostrando as somas dos caminhos percorridos nas matrizes.

## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contato

✉️ <i>vramoscabral2020@gmail.com</i>
