def menor():
    iV = int(input())
    menor = 10000000
    
    if iV == 0:
        return print("npv")
    else:
        while iV != 0:
            if menor > iV:
                menor = iV
            iV = int(input())
    if iV == 0:       
        print(f'{menor}')

def main():
    menor()
    

main()