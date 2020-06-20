import random
from PIL import Image

def loteria():
    jugar = "si"
    while(jugar == "si"):
        cartas = ["El gallo", "El diablito", "La dama", "El catrin", "El paraguas", "La sirena", "La escalera", "La botella", "El barril", "El arbol", "El melon", "El valiente", "El gorrito",
        "La muerte", "La pera", "La bandera", "El bandolon", "El violoncello", "La garza", "El pajaro", "La mano", "La bota", "La luna", "El cotorro", "El borracho", "El negrito",
        "El corazon", "La sandia", "El tambor", "El camaron", "Las jaras", "El musico", "La araña", "El soldado", "La estrella", "El cazo", "El mundo", "El apache", "El nopal",
        "El alacran", "La rosa", "La calavera", "La campana", "El cantarito", "El venado", "El sol", "La corona", "La chalupa", "El pino", "El pescado", "La palma", "La maceta",
        "El arpa", "La rana"]

        print("Las cartas estan ordenadas: \n\n", cartas ,"\n")
       
        
        random.shuffle(cartas)
        print("Las cartas desordenadas: \n\n", cartas)
        
        loteria = input("Presiona enter para empezar: \n")
        
        while(loteria != "loteria" and len(cartas) > 1 ):
            print("Para terminar esta jugada teclea 'loteria': \n")
            carta = random.choice(cartas)
            print(carta)
            try:
                imagen = Image.open(carta +'.jpg')
                imagen.show()
            except:
                print("No ha sido posible cargar la imagen")
            cartas.remove(carta)
            loteria = input()
        jugar = input("Quieres volver jugar a la loteria <si><no>:?")
    
    
def main():
    loteria()
    
main()