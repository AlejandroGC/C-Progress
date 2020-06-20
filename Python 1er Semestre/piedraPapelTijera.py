
def despliega_tiro():
    if user == 1:
        print("El jugador tiro Piedra")
    elif user == 2:
        print ("El jugador tiro Papel")
    elif user == 3:
        print ("El jugador tiro Tijera")
     
     
    if bot == 1:
        return "La computadora tiro Piedra"
    elif bot == 2:
        return "La computadora tiro Papel"
    elif bot == 3:
        return "La computadora tiro Tijera"

def piedra_papel_tijera():
    
    print(despliega_tiro())
    
    if user == 1 and bot == 1 or user == 2 and bot == 2 or user == 3 and bot == 3:
        print ("empate")
    elif user == 1 and bot == 3 or user == 2 and bot == 1 or user == 3 and bot == 2:
        print ("ganaste")
    elif user == 3 and bot == 1 or user == 1 and bot == 2 or user == 2 and bot == 3:
        print ("perdiste")
     
user = int(input())
bot = int(input())

def main():
    piedra_papel_tijera()

main()
