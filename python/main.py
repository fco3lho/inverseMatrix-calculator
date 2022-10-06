import numpy as np
import pandas as pd
import math
import time

def isNum(num):
    if num != num:
        return False
    else:
        return True

start_time = time.time()

x = pd.read_excel(r"FECHAMENTO_MAIS__NEGOCIADAS_5minutos.xls")
matrix = np.zeros((12,12), dtype = np.float64)
i = 0
count = 0

while(i+12 < 6200):
    matrix[0:12, 0] = round(x["ITSA4"][i:i+12], 2)
    matrix[0:12, 1] = round(x["BBDC4"][i:i+12], 2)
    matrix[0:12, 2] = round(x["USIM5"][i:i+12], 2)
    matrix[0:12, 3] = round(x["BRFS3"][i:i+12], 2)
    matrix[0:12, 4] = round(x["BVMF3"][i:i+12], 2)
    matrix[0:12, 5] = round(x["CMIG4"][i:i+12], 2)
    matrix[0:12, 6] = round(x["GGBR4"][i:i+12], 2)
    matrix[0:12, 7] = round(x["BBAS3"][i:i+12], 2)
    matrix[0:12, 8] = round(x["ITUB4"][i:i+12], 2)
    matrix[0:12, 9] = round(x["PETR4"][i:i+12], 2)
    matrix[0:12, 10] = round(x["VALE5"][i:i+12], 2)
    matrix[0:12, 11] = round(x["ABEV3"][i:i+12], 2)

    det = np.linalg.det(matrix)
    det = round(det, 15)

    if(det != 0 and not math.isnan(det)):
        matrix_inv = np.linalg.inv(matrix)
        print(matrix)
        print("\n======================================================================\n")
        print(det)
        print('\n\n')
        print(matrix_inv)
        print('\n\n')

    elif(det == 0):
        print(matrix)
        print("\n======================================================================\n")
        print(det)
        print('\n\n')
        print("A matriz não possui inversa.")
        count += 1
        print('\n\n')

    i += 1

print("--- %s seconds ---" % (time.time() - start_time))
print("Número de matrizes que não possuem inversa: " + str(count))