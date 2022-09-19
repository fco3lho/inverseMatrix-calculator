#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int GetMinor(float **src, float **dest, int row, int col, int order){
    int colCount = 0, rowCount = 0;
 
    for(int i = 0; i < order; i++ ){
        if( i != row ){
            colCount = 0;
            for(int j = 0; j < order; j++ ){
                if( j != col ){
                    dest[rowCount][colCount] = src[i][j];
                    colCount++;
                }
            }
            rowCount++;
        }
    }
 
    return 1;
}

double CalcDeterminant(float **mat, int order){
    if( order == 1 ){
        return mat[0][0];
    }

    float det = 0;

    float **minor;
    minor = new float*[order-1];

    for(int i = 0; i < order-1; i++){
        minor[i] = new float[order-1];
    }
 
    for(int i = 0; i < order; i++ ){
        GetMinor(mat, minor, 0, i , order);
 
        det += (i%2 == 1? -1.0:1.0) * mat[0][i] * CalcDeterminant(minor, order-1);
    }
 
    for(int i = 0; i < order-1; i++){
        delete [] minor[i];
    }

    delete [] minor;
 
    return det;
}

void MatrixInversion(float **A, int order, float **Y){
    double det = 1.0/CalcDeterminant(A,order);
 
    float *temp = new float[(order-1)*(order-1)];
    float **minor = new float*[order-1];
    
    for(int i=0;i<order-1;i++){
        minor[i] = temp+(i*(order-1));
    }
 
    for(int j=0;j<order;j++){
        for(int i=0;i<order;i++){
            GetMinor(A,minor,j,i,order);
            Y[i][j] = det*CalcDeterminant(minor,order-1);
            
            if( (i+j)%2 == 1){
                Y[i][j] = -Y[i][j];
            }
        }
    }
 
    delete [] temp;
    delete [] minor;
}

int main(){
    clock_t start, end;

    ifstream file;
    
    string values;
    string value;

    float **matrixA, **matrixB, **matrixInv;

    double StrToDouble;

    // Criação matriz A

    matrixA = new float *[12];

    for(int i = 0; i < 12; i++){
        matrixA[i] = new float[12];
    }

    // Criação matriz B

    matrixB = new float *[12];

    for(int i = 0; i < 12; i++){
        matrixB[i] = new float[12];
    }

    // Criação matriz inversa

    matrixInv = new float *[12];

    for(int i = 0; i < 12; i++){
        matrixInv[i] = new float[12];
    }

    start = clock();
    
    file.open("FECHAMENTO_MAIS__NEGOCIADAS_5minutos.txt");

    if(file.is_open()){
        for(int i = 0; i < 12; i++){
            getline(file, values);
            stringstream check1(values);

            for(int j = 0; j < 13; j++){
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

        for(int line = 0; line < 12; line++){
            for(int column = 0; column < 12; column++){
                cout << fixed << setprecision(2) << matrixA[line][column] << "\t";
            }
            cout << endl;
        }

        MatrixInversion(matrixA, 12, matrixInv);

        cout << endl << "\n\t\t\tImpressão da matriz inversa da principal" << endl << endl;

        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 12; j++){
                cout << matrixInv[i][j] << "\t";
            }
            cout << endl;
        }

        // Looping começa aqui

        for(int i = 0; i < 6187; i++){ // Quantidade de matrizes que irá calcular - 6187
            getline(file, values);
            stringstream check1(values);

            if(i%2 == 0){
                for(int j = 0; j < 11; j++){
                    for(int k = 0; k < 12; k++){
                        matrixB[j][k] = matrixA[j+1][k];
                    }
                }

                for(int k = 0; k < 13; k++){
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
                        matrixB[11][k-1] = StrToDouble;
                    }                 
                }

                cout << endl << "______________________________________________________________________________________________\n\t\t\t\t\tImpressão da matriz B" << endl << endl;

                for(int line = 0; line < 12; line++){
                    for(int column = 0; column < 12; column++){
                        cout << fixed << setprecision(2) << matrixB[line][column] << "\t";
                    }
                    cout << endl;
                }

                MatrixInversion(matrixB, 12, matrixInv);

                cout << endl << "\n\t\t\tImpressão da matriz inversa da matriz B" << endl << endl;

                for(int i = 0; i < 12; i++){
                    for(int j = 0; j < 12; j++){
                        cout << matrixInv[i][j] << "\t";
                    }
                    cout << endl;
                }       
            }

            else if(i%2 != 0){
                for(int j = 0; j < 11; j++){
                    for(int k = 0; k < 12; k++){
                        matrixA[j][k] = matrixB[j+1][k];
                    }
                }

                for(int k = 0; k < 13; k++){
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
                        matrixA[11][k-1] = StrToDouble;
                    }                 
                }

                cout << endl << "______________________________________________________________________________________________\n\t\t\t\t\tImpressão da matriz A" << endl << endl;

                for(int line = 0; line < 12; line++){
                    for(int column = 0; column < 12; column++){
                        cout << fixed << setprecision(2) << matrixA[line][column] << "\t";
                    }
                    cout << endl;
                } 

                MatrixInversion(matrixA, 12, matrixInv);

                cout << endl << "\n\t\t\tImpressão da matriz inversa da matriz A" << endl << endl;

                for(int i = 0; i < 12; i++){
                    for(int j = 0; j < 12; j++){
                        cout << matrixInv[i][j] << "\t";
                    }
                    cout << endl;
                }                          
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