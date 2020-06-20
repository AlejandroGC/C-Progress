def promedio():
    iK = 1
    iV = int(input())
    suma = iV
    prom = suma/iK
    if iV == 0:
        return print("npv")
    while iV != 0:
        prom = suma / iK
        iV = int(input())
        suma = suma + iV
        iK = iK + 1
        
    print(prom)

def main():
    promedio()
    

main()
