#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    clock_t start, end;

    ifstream file;
    
    string values;
    string value;

    double matrixA[12][12];
    double matrixB[12][12];
    double StrToDouble;

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

        for(int i = 0; i < 6187; i++){
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
            }
        }


        // for(int i = 0; i < 1; i++){


        //     // cout << endl << "____________________________________________________________________________________\n\t\t\t\t\tImpressão da matriz inversa" << endl << endl;

        //     // if(INV(matrix, invMatrix)){
        //     //     for(int line = 0; line < 12; line++){
        //     //         for(int column = 0; column < 12; column++){
        //     //             cout << invMatrix[line][column] << "\t";
        //     //         }
        //     //         cout << endl;
        //     //     }
        //     // }
        // }
    }

    else{
        cout << "Falha ao abrir o arquivo!" << endl;
    }

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    cout << endl << "Tempo de execução: " << fixed << time_taken << " segundos." << endl;

    return 0;
}