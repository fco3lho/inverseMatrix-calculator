# Introdução

O trabalho proposto na disciplina de Linguagens de Programação baseia-se em escolher duas linguagens de programação para resolver o problema proposto, de coletar dados de uma planilha em forma de matriz 12x12 linha por linha na planilha, e calcular a matriz inversa de cada matriz coletada.

# Fundamento teórico

Foram escolhidas as linguagens de programação Python e C++ para a resolução do problema, sendo Python uma linguagem interpretada, de fácil escrita e leitura, e C++ uma linguagem compilada e de rápida execução.

# Metodologia

### Python

Em Python, para a resolução do problema, foram usadas as bibliotecas <code>pandas</code> e <code>numpy</code>, para realizar a leitura da planilha, criação de matrizes e calcular as matrizes inversas. 

Inicialmente, foi criada uma variável que recebe a leitura da planilha, uma outra variável que para a criação da planilha 12x12 e uma variável de iteração. Logo após, o programa entra em um laço de repetição que coleta as colunas selecionadas na linha que a variável de iterador estiver no momento do laço. Possuindo a matriz 12x12 completa, pode-se calcular a matriz inversa usando a função <code>linalg.inv()</code> do <code>numpy</code>.

Possuindo a matriz normal e a matriz inversa, é feito a impressão das matrizes e indo para a próxima iteração, até que <i>i</i> seja igual a 6186.

### C++

# Conclusão

Na linguagem Python, foi consideravelmente fácil resolver o problema proposto pesquisando as funções que podem ser usadas na literatura, mas a facilidade do Python tem um preço, que foi o tempo de execução elevado.
