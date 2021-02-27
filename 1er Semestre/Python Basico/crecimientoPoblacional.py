

def main():
    a = int(input("año a buscar: "))
    r = int(input("tasa de crecimiento como porcentaje: "))
    r = r / 100
    n = a - 2009
    po = 100
    pf = po * (1+r)**n
    print(f'mi poblacion en {a} va a ser {pf}.')
    

main()