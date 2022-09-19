# Problema proposto

O trabalho proposto na disciplina de Linguagens de Programação baseia-se em escolher duas linguagens de programação para resolver o problema proposto, de coletar dados de uma planilha em forma de matriz 12x12 linha por linha na planilha, e calcular a matriz inversa de cada matriz coletada.

# Critério de escolha das linguagens

Foram escolhidas as linguagens de programação <i>Python</i>, que é uma linguagem popular e de fácil aprendizagem, e <i>C++</i>, que é uma linguagem teoricamente rápida e que me senti mais apto para solucionar o problema proposto.

# Avaliação das linguagens

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

# Metodologia

### Python

Em Python, para a resolução do problema, foram usadas as bibliotecas <code>pandas</code> e <code>numpy</code>, para realizar a leitura da planilha, criação de matrizes e calcular as matrizes inversas. 

Inicialmente, foi criada uma variável que recebe a leitura da planilha, uma outra variável que para a criação da planilha 12x12 e uma variável de iteração. Logo após, o programa entra em um laço de repetição que coleta as colunas selecionadas na linha que a variável de iterador estiver no momento do laço. Possuindo a matriz 12x12 completa, pode-se calcular a matriz inversa usando a função <code>linalg.inv()</code> do <code>numpy</code>.

### C++

Em C++, para a resolução do problema, foram usadas apenas bibliotecas padrões do C++ para leitura do arquivo.

O cálculo completo foi feito de forma manual e braçal, utilizando o <strong><i>método recursivo de solução analítica</i></strong>, e sem a utilização de biblioteca de terceiros onde foram criadas as funções <code>GetMinor()</code>, <code>CalcDeterminant()</code> e <code>MatrixInversion()</code> para calcular a matriz inversa da matriz que o programa está executando naquele momento.

<strong>Observação</strong>: Devido a dificuldade que a linguagem propõe, os dados do arquivo <code>.xls</code> foram passados para um arquivo <code>.txt</code> para ser feita a leitura de forma mais fácil e correta.

# Conclusão

Comparando as duas linguagem escolhidas, podemos dizer que Python ganhou disparadamente, por sua facilidade e velocidade compara a C++ nesse caso. Em questão de linhas de código, Python ficou com 34 linhas e C++ com 273 linhas, e em questão de tempo, para Python executar todas as 6187 matrizes, gastou em média 24 segundos e para executar uma matriz, C++ gastou 295 segundos, ou seja, fazendo um cálculo básico de tempo e levando em conta a primeira matriz, C++ gastaria cerca de 505 horas ou 21 dias para executar todas as 6187 matrizes.
