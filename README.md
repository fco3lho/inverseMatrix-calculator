## Problema proposto

O trabalho proposto na disciplina de Linguagens de Programação baseia-se em escolher duas linguagens de programação para resolver o problema proposto, de coletar dados de uma planilha em forma de matriz 12x12 linha por linha na planilha, e calcular a matriz inversa de cada matriz coletada.

## Critério de escolha das linguagens

Foram escolhidas as linguagens de programação <i>Python</i>, que é uma linguagem popular e de fácil aprendizagem, e <i>C++</i>, que é uma linguagem teoricamente rápida e que me senti mais apto para solucionar o problema proposto.

## Avaliação das linguagens

### Python
<ul>
  <li><strong>Nível de segurança: </strong>Alto</li>
  <li><strong>Confiabilidade: </strong>Baixa</li>
  <li><strong>Paradigma da linguagem: </strong>Imperativo, orientado a objetos e funcional</li>
  <li><strong>Classe: </strong>Interpretado</li>
</ul>

### C++
<ul>
  <li><strong>Nível de segurança: </strong>Baixo</li>
  <li><strong>Confiabilidade: </strong>Alto</li>
  <li><strong>Paradigma da linguagem: </strong>Orientado a objetos e procedural</li>
  <li><strong>Classe: </strong>Compilado</li>
</ul>

## Metodologia

### Python

Em Python, para a resolução do problema, foram usadas as bibliotecas <code>pandas</code> e <code>numpy</code>, para realizar a leitura da planilha, criação de matrizes e calcular as matrizes inversas. 

Inicialmente, foi criada uma variável que recebe a leitura da planilha, uma outra variável que para a criação da planilha 12x12 e uma variável de iteração. Logo após, o programa entra em um laço de repetição que coleta as colunas selecionadas na linha que a variável de iterador estiver no momento do laço. Possuindo a matriz 12x12 completa, pode-se calcular a matriz inversa usando a função <code>linalg.inv()</code> do <code>numpy</code>.

### C++

Em C++, para a resolução do problema, foram usadas apenas bibliotecas padrões do C++ para leitura do arquivo.

O cálculo completo foi feito de forma manual, utilizando o <strong><i>método de Gauss-Jordan</i></strong>, e sem a utilização de biblioteca de terceiros onde foi criada apenas uma função, chamada de <code>calculateInverse()</code> para calcular a matriz inversa da matriz que o programa está executando naquele momento.

<strong>Observação</strong>: Devido a dificuldade que a linguagem propõe, os dados do arquivo <code>.xls</code> foram passados para um arquivo <code>.txt</code> para ser feita a leitura de forma mais fácil e correta.

## Conclusão

Comparando as duas linguagem escolhidas, podemos dizer que Python ganhou disparadamente, por sua facilidade e velocidade compara a C++ nesse caso. Em questão de linhas de código, Python ficou com 42 linhas e C++ com 230 linhas, e em questão de tempo, para Python executar todas as 6187 matrizes, gastou em média 24 segundos e para executar uma matriz, C++ gastou 4.26 segundos, ou seja, C++ cumpriu o esperado de ser uma linguagem rápida e de alta confiança, com o programador podendo ver tudo o que está acontecendo, diferente de Python que não é possível ver o que a função usada para calcular a matriz inversa faz.

## Compilação e Execução em C++

Na pasta <code>cplusplus</code>, possui um arquivo <i>Makefile</i> que realiza todo o procedimento de compilação e execução. Abra o diretório da pasta no terminar e siga os comandos abaixo:

<table align="center">
  <tr>
    <td><strong>Comando</strong></td>
    <td><strong>Função</strong></td>
  </tr>
  <tr>
    <td><code>make clean</code></td>
    <td>Apaga a última compilação realizada contida na pasta build.</td>
  </tr>
  <tr>
    <td><code>make</code></td>
    <td>Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build.</td>
  </tr>
  <tr>
    <td><code>make run</code></td>
    <td>Executa o programa da pasta build após a realização da compilação.</td>
  </tr>
</table>

## Execução em Python

Após abrir a pasta <code>python</code> no terminal, siga os passos abaixo para executar o programa.

<table align="center">
  <tr>
    <td><strong>Comando</strong></td>
    <td><strong>Função</strong></td>
  </tr>
  <tr>
    <td><code>python3 main.py</code></td>
    <td>Irá executar o código escrito em "main.py".</td>
  </tr>
</table>

