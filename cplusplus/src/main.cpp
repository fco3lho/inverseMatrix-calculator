#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

//Cálculo da matriz inversa usando o método de Gauss-Jordan
void calculateInverse(float **matriz, int n){
    float A[n][n], identidade[n][n], pivot, aux;

    //Copiando matriz
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i][j] = matriz[i][j];
        }
    }

    //Criando matriz identidade
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                identidade[i][i] = 1;
            }
            else{
                identidade[i][j] = 0;
            }
        }
    }

    //Calculando matriz inversa
    for(int i = 0; i < n; i++){
        pivot = A[i][i];

        for(int k = 0; k < n; k++){
            A[i][k] = A[i][k]/pivot;
            identidade[i][k] = identidade[i][k]/pivot;
        }

        for(int j = 0; j < n; j++){
            if(i != j){
                aux = A[j][i];

                for(int k = 0; k < n; k++){
                    A[j][k] = A[j][k] - aux * A[i][k];
                    identidade[j][k] = identidade[j][k] - (aux * identidade[i][k]);
                }
            }
        }
    }

    //Impressão da inversa
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << identidade[i][j] << "\t";
        }
        cout << endl;
    }
}



int main(){
    clock_t start, end;

    ifstream file;
    
    string values;
    string value;

    float **matrixA, **matrixB, **matrixInv;
    int n = 12;

    double StrToDouble;

    // Criação matriz A
    matrixA = new float *[n];
    for(int i = 0; i < n; i++){
        matrixA[i] = new float[n];
    }

    // Criação matriz B
    matrixB = new float *[n];
    for(int i = 0; i < n; i++){
        matrixB[i] = new float[n];
    }

    // Criação matriz inversa
    matrixInv = new float *[n];
    for(int i = 0; i < n; i++){
        matrixInv[i] = new float[n];
    }

    //Programa começa a ser executado aqui
    start = clock();
    
    file.open("FECHAMENTO_MAIS__NEGOCIADAS_5minutos.txt");

    if(file.is_open()){
        for(int i = 0; i < n; i++){
            getline(file, values);
            stringstream check1(values);

            for(int j = 0; j < n+1; j++){
                getline(check1, value, '\t');

                if(j >= 1){
                    for(int z = 0; z < int(value.size()); z++){
                        if(value[z] == ','){
                            char point = '.';
                            swap(value[z], point);
                            break;
                        }
                    }

                    StrToDouble = stod(value);
                    matrixA[i][j-1] = StrToDouble;
                }
            }
        }

        cout << endl << "______________________________________________________________________________________________\n\t\t\t\t\tImpressão da matriz principal" << endl << endl;

        for(int line = 0; line < n; line++){
            for(int column = 0; column < n; column++){
                cout << fixed << setprecision(2) << matrixA[line][column] << "\t";
            }
            cout << endl;
        }

        cout << endl << "\n\t\t\tImpressão da matriz inversa da principal" << endl << endl;

        calculateInverse(matrixA, n);

        // Looping começa aqui

        for(int i = 0; i < 30; i++){ // Quantidade de matrizes que irá calcular - 6187
            getline(file, values);
            stringstream check1(values);

            if(i%2 == 0){
                for(int j = 0; j < n-1; j++){
                    for(int k = 0; k < n; k++){
                        matrixB[j][k] = matrixA[j+1][k];
                    }
                }

                for(int k = 0; k < n+1; k++){
                    getline(check1, value, '\t');

                    if(k >= 1){
                        for(int z = 0; z < int(value.size()); z++){
                            if(value[z] == ','){
                                char point = '.';
                                swap(value[z], point);
                                break;
                            }
                        }

                        StrToDouble = stod(value);
                        matrixB[n-1][k-1] = StrToDouble;
                    }                 
                }

                cout << endl << "______________________________________________________________________________________________\n\t\t\t\t\tImpressão da matriz " << i << endl << endl;

                for(int line = 0; line < n; line++){
                    for(int column = 0; column < n; column++){
                        cout << fixed << setprecision(2) << matrixB[line][column] << "\t";
                    }
                    cout << endl;
                }

                cout << endl << "\n\t\t\tImpressão da matriz inversa da matriz " << i << endl << endl;

                calculateInverse(matrixB, n);       
            }

            else if(i%2 != 0){
                for(int j = 0; j < n-1; j++){
                    for(int k = 0; k < n; k++){
                        matrixA[j][k] = matrixB[j+1][k];
                    }
                }

                for(int k = 0; k < n+1; k++){
                    getline(check1, value, '\t');

                    if(k >= 1){
                        for(int z = 0; z < int(value.size()); z++){
                            if(value[z] == ','){
                                char point = '.';
                                swap(value[z], point);
                                break;
                            }
                        }

                        StrToDouble = stod(value);
                        matrixA[n-1][k-1] = StrToDouble;
                    }                 
                }

                cout << endl << "______________________________________________________________________________________________\n\t\t\t\t\tImpressão da matriz " << i << endl << endl;

                for(int line = 0; line < n; line++){
                    for(int column = 0; column < n; column++){
                        cout << fixed << setprecision(2) << matrixA[line][column] << "\t";
                    }
                    cout << endl;
                } 

                cout << endl << "\n\t\t\tImpressão da matriz inversa da matriz " << i << endl << endl;

                calculateInverse(matrixA, n);                         
            }
        }
    }

    else{
        cout << "Falha ao abrir o arquivo!" << endl;
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << endl << "Tempo de execução: " << fixed << time_taken << " segundos." << endl;

    return 0;
}