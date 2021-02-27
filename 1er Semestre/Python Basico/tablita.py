#A01570396

def tablita(iX):
    iK = 10
    while(iK >= 1):
        print(f'{iK}X{iX}={iX*iK}')
        iK = iK - 1

def main():
    iX = int(input('Ingresa tu valor: '))
    tablita(iX)

main()