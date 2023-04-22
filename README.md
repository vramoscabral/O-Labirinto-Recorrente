# Trabalho AEDS I - O Labirinto Recorrente

# Descrição

Neste segundo trabalho, foi feito um programa usando a linguagem C++, que recebe um número N de matrizes MxM (sendo M maior ou igual a 3) em um arquivo "input.data", e esse programa faz a simulação de um jogo onde um garoto tem que andar por um labirinto que possui três tipos de casas (posições da matriz), a casa com itens (números de 0 a 9), a casa com perigo, ("*") e a casa com parede ("#").

O programa irá carregar as matrizes e percorrê-las segundo as regras do jogo, e irá encerrar em três ocasiões: caso a quantidade de vidas do garoto chegue a 0, ou caso o garoto não consiga mais coletar itens ao passar por todas as matrizes e voltar à primeira, ou - no caso mais específico - caso o jogador cair em uma posição na qual ele fique cercado por paredes.

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
- Quando o garoto alcança uma posição que esteja nos limites da matriz, seja posição de itens ou perigo, ele pula para a próxima matriz.

```Caso Específico```

O terceiro caso de parada, quando o jogador acaba ficando cercado por paredes, só é possível quando ele entra em uma matriz e cai em tal posição antes de dar o primeiro movimento ou após movimentar pela primeira vez ao entrar em uma matriz.

## Implementação

- No momento em que o programa inicia, ele abre o arquivo "input.data", que contém na primeira linha a quantidade de linhas e colunas de cada matriz, e a quantidade de matrizes, e a partir daí, ele lê cada matriz como char e salva em arquivos separados, assim evitando sobrecarga do uso da memória e tendo controle sobre o que acontece em cada matriz quando ela começa e termina o seu andamento. Esses arquivos separados são de acordo com a quantidade de matrizes, como exemplo: Arquivo com 4 matrizes, vai gerar os arquivos "mat1.data", "mat2.data", "mat3.data" e "mat4.data", que serão modificados ao longo do programa ao longo da jornada do personagem coletando itens, e ao final do jogo cada uma das matrizes nesses arquivos serão incluídas no arquivo "output.data" que mostra o que aconteceu com as matrizes em comparação ao arquivo inicial "input.data", e depois esses arquivos matN.data serão excluídos. O "output.data" será obtido ao executar o código, portanto mesmo que já exista um arquivo com outras matrizes e o usuário altera o input.data, após a execução o "output.data" será sobrescrevido com os parâmetros do "input.data".
- Quando cada matriz for lida para ser colocada na função de andamento, será criado uma variável do tipo "**int" para armazená-la, e os caracteres * e # que não são inteiros, serão transformados em -1 e -2, apenas quando a função estiver executando, mas serão printados no arquivo como * e #.
- Ao final do código são apresentadas as informações de quantas casas foram percorridas, total de itens consumidos, perigos enfrentados, e quantas casas não foram percorridas, sendo que essas três primeiras informações que vêm de atributos estáticos que são modificados ao longo da execução do código, e as casas não percorridas são determinadas em uma função que compara as matrizes em seu estado inicial com as matrizes modificadas ao longo da execução até o fim do jogo, e as casas que permaneceram com a mesma quantidade de itens, não foram percorridas, desconsiderando casas sem item, perigos e paredes.
- No momento em que o personagem entra em uma matriz, ou sai de uma para entrar em outra, o as coordenadas i e j são redefinidas randomicamente, e no momento da entrada da matriz, ele cai em uma posição que inicialmente não é considerada ação de jogo, mas sim um ponto para uma nova movimentação, podendo ser acessada posteriormente caso não seja uma parede.

## Arquivos

* ```main.cpp```: Arquivo e função principal do código;
* ```mat.hpp```: Declaração das funções utilizadas;
* ```mat.cpp```: Implementação das funções descritas no arquivo hpp;
* ```input.data```: Arquivo com as matrizes que serão lidas;
* ```output.data```: Arquivo com as matrizes em seu estado final após as modificações no decorrer do programa;
* ```Makefile```: Automatiza o processo de compilação;

## Funções

* As funções que começam com "see" e a função int sabc() são para retornar valores de atributos estáticos para o arquivo main.cpp.
* void ReadFile() : A primeira função chamada no main.cpp, é responsável por ler todas as matrizes do arquivo "input.data" e salvá-las separadamente em N arquivos com o nome "matN.data".
* int Tam() : Abre o arquivo "input.data" e lê os dois primeiros caracteres que determinam o tamanho da matriz, como nessa atividade são usadas apenas matrizes quadradas (com mesma quantidade de linhas e colunas), é retornado apenas um valor.
* int Quant() : Abre o arquivo "input.data", lê os 3 primeiros caracteres e retorna o último, esse valor representa a quantidade de matrizes.
* void OpenMatrix() : Segunda função chamada no main.cpp, o início e o final da execução dessa função estão diretamente relacionadas com o início e fim do jogo, porque ela abre uma matriz de cada vez e manda para a função WalkMatrix() para realizar os movimentos do jogo. Quando uma das três possibilidades de encerramento do jogo é atingida, o laço de repetição para chamar a WalkMatrix() se encerra. Além disso, essa função gera randomicamente as coordenadas im e jm que serão usadas como ponto de start no caminhamento da matriz.
* int WalkMatrix (int **m, int im, int jm, int rsize, int n) : Essa função recebe como parâmetro a matriz obtida em OpenMatrix(), as coordenadas i e j pro ponto de start para o primeiro movimento, o rsize que é o tamanho da matriz -1, para facilitar na verificação de condições para o movimento, e também o n que é o número da matriz que foi aberta. Aqui a matriz é percorrida seguindo os critérios citados na Descrição do Trabalho, por meio de uma switch que analisa as condições para as 8 possibilidades de movimentação. Essa função retorna o valor n que será enviado ao OpenMatrix() para abrir e armazenar a outra matriz que será voltada para essa função.
* int NotVisited() : Essa função é responsável por retornar a quantidade de casas que não foram visitadas e modificadas na execução do jogo. Aqui são comparados os aruqivos "input.data" e "output.data", e a quantidade de posições que mantiveram a mesma quantidade de itens (mais que 0) são as casas que não foram exploradas.
* void Output() : Terceira função chamada no main.cpp, é responsável por salvar todas as matrizes modificadas dos arquivos separados em um arquivo só.
* void remove() : Remove os arquivos utilizados para armazenar matrizes separadas na realização do jogo, e assim sobra na pasta dataset apenas os arquivos "input.data" e "output.data".

## Exemplos da execução

![fexample](https://user-images.githubusercontent.com/127407951/233801694-207a7f67-a38f-4b84-9414-0ec34f9230be.png)

Print da execução do programa no terminal, onde a cada movimento ou tentativa de movimento, mostra a quantidade de vidas, o número da matriz, o ponto de saída, o número do movimento e quantos itens foram coletados até aquele momento.

![final 1](https://user-images.githubusercontent.com/127407951/233801778-1670850c-d702-4104-a0b3-6ccd1cc84e6d.png)

Print do terminal mostrando a primeira e mais provável possibilidade de final no encerramento do jogo, em que as vidas do personagem se acabam. Nos três finais são mostrados quantas casas foram percorridas, quantos itens foram consumidos, quantas casas ficaram sem ser exploradas e o total de perigos enfrentados. 

![final 2](https://user-images.githubusercontent.com/127407951/233801942-02284479-cfa2-4d7b-8415-9fbe039343af.png)

Print do terminal com a segunda possibilidade de final do jogo. Aqui e no final do caso mais específico, são mostradas o total de vidas que restavam para o personagem.

![final 3](https://user-images.githubusercontent.com/127407951/233801997-eede145d-7c74-4cab-bd0f-9df71ee9402f.png)

Print do terminal com a terceira possibilidade de final, do caso mais específico.

## Conclusão

O objetivo principal da construção desse programa com o jogo, é ver a quantidade máxima de itens que o personagem pode pegar e também o quanto se pode modificar das matrizes iniciais ao decorrer da execução. O programa é funcional e está de acordo com as especificações do trabalho e as regras do jogo. Não é viável fazer o cálculo do custo computacional desse programa, devido à decisão de movimentação do jogo que é feita randomicamente, também pelo tamanho da matriz, que pode ser definido pelo usuário ao inserir o arquivo input.data com as matrizes randômicas.

Uma possibilidade de um caso computacional de baixo custo, seria de quando toda vez que uma matriz aberta para o caminhamento, as coordenadas randomicamente geradas fossem sempre de posições próximas a um dos 4 limites da matriz (primeira e última coluna, primeira e última linha), e sempre alcançar uma posição de item ou perigo que levasse à próxima matriz e assim agisse até um dos critérios de parada serem atingidos, isso tudo em comparação ao caso do personagem ficar dando voltas e voltas dentro dos labirintos, que geraria um custo bem maior.

Usar arquivos separados para armazenar cada matriz e serem abertos um de cada vez na execução do código é uma solução ideal para evitar um overflow, ou estouro de memória, no caso de matrizes grandes ou muitas matrizes sendo armazenadas na memória do programa ao mesmo tempo durante toda a execução do código.

## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contato

✉️ <i>vramoscabral2020@gmail.com</i>
