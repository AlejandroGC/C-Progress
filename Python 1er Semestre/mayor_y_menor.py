def mayor_y_menor(iN):
    iK = 1
    menor = 0
    mayor = 0
    
    if iN <= 0:
        print("npv")
    for i in range(iN):
        if iK <= iN:
            iV = int(input())
            if menor > iV:
                menor = iV
            if mayor < iV:
                mayor = iV
                
            iK = iK + 1
            
    if iN > 0:
        print(f'{mayor}\n{menor}')

def main():
    iN = int(input())
    
    mayor_y_menor(iN)
    

main()