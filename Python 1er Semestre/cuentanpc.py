#A01570396
def cuenta_pnc(iN):
    cc = 0
    cn = 0
    cp = 0
    iK = 1
    
    while (iK <= iN):
        iV = int(input(f'Ingresa el valor {iK}:'))
        if (iV > 0):
            cp = cp+1
        elif(iV == 0):
            cc = cc+1
        else:
            cn = cn+1
        iK = iK+1
    
    print(f'positivo={cp}\nnegativos={cn}\nceros={cc}')
    
def main():
    iN = int(input('ingresa la cantidad de numeros:'))
    cuenta_pnc(iN)

main()