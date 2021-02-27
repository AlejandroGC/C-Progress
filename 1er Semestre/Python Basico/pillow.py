from PIL import Image
try:
 imagen = Image.open('laBandera.jpg')
 imagen.show()
except:
 print("No ha sido posible cargar la imagen")