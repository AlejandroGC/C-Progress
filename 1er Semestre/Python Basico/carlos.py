def incrementa():
    iN = int(input())
    for i in range(1,iN+1):
        print(f'{i}', end=', ')
    for j in range(iN-1,0,-1):
        if j == 1:
            print(f'{j}')
        else:
            print(f'{j}', end=', ')

    
def main():
    incrementa()

main()