import pandas as pd

df = pd.read_csv('comida.csv')
primera_fila = df.iloc[0]
segunda_fila = df.iloc[1]


print(primera_fila)
print(segunda_fila)