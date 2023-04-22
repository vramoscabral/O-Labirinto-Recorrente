# Trabalho AEDS I - O Labirinto Recorrente

# Descrição

Neste segundo trabalho, foi feito um programa usando a linguagem C++, que recebe um número N de matrizes MxM em um arquivo "input.data", e esse programa faz a simulação de um jogo onde um garoto tem que andar por um labirinto que possui três tipos de casas (posições da matriz), a casa com itens (números de 0 a 9), a casa com perigo, ("*") e a casa com parede ("#").

O programa irá carregar as matrizes e percorrê-las segundo as regras do jogo, e irá encerrar em duas ocasiões: caso a quantidade de vidas do garoto chegue a 0, ou caso o garoto não consiga mais coletar itens ao passar por todas as matrizes e voltar à primeira.

## Objetivo

Após a leitura do arquivo "input.data", o programa salvará cada matriz em N arquivos do tipo "matN.data" de 1 até N, e eles vão sendo abertos ao longo da execução do código e modificados antes de serem fechados. O garoto terá 8 possibilidades de movimentação, e o movimento vai ser selecionado randomicamente, em um número de 1 a 8, e depois será verificado se o movimento leva o garoto até uma casa com itens, ou uma casa com perigo, ou uma casa com parede.

![Captura de tela 2023-04-22 115836](https://user-images.githubusercontent.com/127407951/233792398-61109db7-b0e4-4a74-8448-cb2d75122fa4.png)

Nesse print de exemplo, o x é a posição em que o garoto está (i,j), e cada número entre 1 e 8 representa uma movimentação, que mudará o valor i ou j, ou os dois.

A posição i e j são geradas randomicamentes quando o garoto entra em uma nova matriz, e ele cai em um ponto que não esteja nos limites da matriz (primeira linha, primeira coluna, última linha e última coluna), porque quando o garoto atinge uma posição que esteja em qualquer um dos limites, ele irá ser transportado a próxima matriz.

![image](https://user-images.githubusercontent.com/127407951/233793401-c20f1749-5f97-4d6c-954f-bfcc22c8b347.png)

Nesse exemplo, o G da matriz 1 é a posição do garoto, e pelo método, se o movimento gerado for 1, 3, 4 ou 5, ele pega o item de uma das posições que serão alcançadas nesses movimentos, sai dessa matriz e o programa lê o arquivo da matriz 2 e gera uma posição pra começar o caminhamento novamente.

```Regras e Limitações```

- O garoto começa com 10 vidas, e não pode ter mais vidas que isso.
- Quando o garoto chega em uma casa com itens de (1 a 9), ele coleta esse item e subtrai da posição que ele alcançou. Se a casa tiver valor 0, ele apenas considera como mais uma casa que ele andou e o número de itens que ele pegou continua o mesmo. A cada 4 itens coletados, ele aumenta 1 vida (se tiver 9 vidas ou menos).
- Quando o garoto chega em uma casa de perigo ("*"), ele  considera como uma casa a mais que ele andou e tira uma de suas vidas.
- Quando o movimento leva o garoto a uma parede, ele não sai da posição em que está e outro movimento é gerado, portanto, nada acontece.
- Se a quantidade de vidas chegar a 0, ou ele não consiga mais pegar itens ao atravessar todas as matrizes e voltar para a primeira, o jogo acaba.
- O garoto sempre pula para a matriz consecutiva, ex: da matriz 2 para a 3, da 5 para 6, mas quando ele chega na última matriz, após andar por ela ele volta para a primeira.

## Implementação

* No momento em que o programa inicia, ele abre o arquivo "input.data", que contém na primeira linha a quantidade de linhas e colunas de cada matriz, e a quantidade de matrizes, e a partir daí, ele lê cada matriz como char e salva em arquivos separados, assim evitando sobrecarga do uso da memória e tendo controle sobre o que acontece em cada matriz quando ela começa e termina o seu andamento. Esses arquivos separados são de acordo com a quantidade de matrizes, como exemplo: Arquivo com 4 matrizes, vai gerar os arquivos "mat1.data", "mat2.data", "mat3.data" e "mat4.data", que serão modificados ao longo do programa ao longo da jornada do personagem coletando itens, e ao final do jogo cada uma das matrizes nesses arquivos serão incluídas no arquivo "output.data" que mostra o que aconteceu com as matrizes em comparação ao arquivo inicial "input.data", e depois esses arquivos matN.data serão excluídos.
* Quando cada matriz for lida para ser colocada na função de andamento, será criado uma variável do tipo "**int" para armazená-la, e os caracteres ("*") e ("#") que não são inteiros, serão transformados em -1 e -2, apenas quando a função estiver executando, mas serão printados no arquivo como ("*") e ("#").



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
