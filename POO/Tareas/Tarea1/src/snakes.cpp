/*
Alejandro Daniel González Carrillo
A01570396
Tarea 1 - Serpientes y Escaleras

Tiempos:
Analisis - 50 min
Desarrollo - 4 horas (me tarde 1 hora en algo que me debi de haber tardado 5 min)

*/

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// .-.-.-.-.-.-.JUGADOR.-.-.-.-.-.-.

class Jugador {
    private:
        int player, positionb, positiona, turn;
        int infoJugador[6];
        char ic;
    public:
        Jugador();
        Jugador(int, int, int);
        void info(int, char, int);
        void setposb(int);
        int getpos();
        int turno();
        int posicion(int, char);
        char continuar(int);
};

// Constructor del Jugador
Jugador::Jugador(){
    turn = 0;
    player = 1;
    positionb = 1;
}

// Inicializador
Jugador::Jugador(int turn,int player,int positionb){
    this->turn = turn;
    this->player = player;
    this->positionb = positionb;
}

// Este metodo lo utilice para actualizar la posicion inicial al finalizar el turno del jugador.
void Jugador::setposb(int posf) {
    positionb = posf;
}

int Jugador::getpos(){
    return positionb;
}

// String que imprime los 6 valores del jugador.
void Jugador::info(int tiro, char lugar, int posf){
    cout << turn << " " << player << " " << positionb << " " << tiro << " " << lugar << " " << posf << endl;
}

// Hace el cambio de turno.
int Jugador::turno() {
    turn = turn + 2;
    return turn;
}

// Actualiza la posicion de acuerdo al dado y la casilla especial o no especial en donde cae.
int Jugador::posicion(int dado, char letra) {
    positiona = positionb;
    positiona = positiona + dado;
    if (letra == 'S') {
        positiona -= 3;
        if (positiona < 0) {
            positiona = 0;
        }
    } else if (letra == 'L') {
        positiona += 3;
    } else {
        positiona += 0;
    };

    if (positiona > 30) {
        positiona = 30;
    };
    
    return positiona;
}

// Metodo que decide si el jugador quiere continuar o no en el juego (no se puede introducir ningun otro caracter diferente a "E" o "C").
char Jugador::continuar(int posf){
    if (posf == 30)
    {
        cout << "-- GAME OVER --" << endl;
        cout << "Player " << player << " is the winner!!!" << endl;
        ic = 'E';
    } else {
        cin >> ic;
        ic = toupper(ic);
        while(ic != 'C' && ic != 'E'){
            cout << "Invalid option, please press C to continue next turn or E to end the game: ";
            cin >> ic;
            ic = toupper(ic);
            if (ic == 'E') {
                cout << "-- GAME OVER --" << endl << "Thanks for playing!!!"; 
            }
        };
    };
    
    return ic;
}

// .-.-.-.-.-.-.TABLERO.-.-.-.-.-.-.

class Tablero {
    private:
        char cTablero[30];
        int c;

    public:
        Tablero();
        char getValor(int, int);
};

//Crea el tablero
Tablero::Tablero() {
    for (int i = 0; i < 31; i++) {
        cTablero[i] = 'N';
    };

    cTablero[23] = 'S';
    cTablero[1] = 'S';
    cTablero[12] = 'S';
    cTablero[5] = 'L';
    cTablero[18] = 'L';
    cTablero[22] = 'L';
}

// Este metodo retorna el caracter de la casilla y con esto determino si es una casilla especial o no.
char Tablero::getValor(int letra, int ipos) {
    c = letra + ipos;
    return cTablero[c];
}



// .-.-.-.-.-.-.DADO.-.-.-.-.-.-.

class Dado{
    public:
        Dado();
        int getTiro();
};

Dado::Dado() {
    srand( time(0));
}

// Se genera un numero aleatorio entre 1 y 6.
int Dado::getTiro() {
    return  (rand() % 6) + 1;
}

// .-.-.-.-.-.-.JUEGO.-.-.-.-.-.-.

class MyGame {
    public:
        void start();
};

void MyGame::start(){
    // Se crea los objetos de cada clase, asi como tambien las variables.
    Tablero miTablero;
    Dado miDado;
    Jugador j1(1,1,1), j2(2,2,1);
    int iTiro, posf, ipos;
    char letra, continuar;
    
    // Ciclo centinela para validar que el jugador ingreso una E o C.
    cout << "Press C to continue next turn, or E to end the game: " << endl;
    cin >> continuar;

    while(continuar != 'C' && continuar != 'E'){
        cout << "Invalid option, please press C to continue next turn or E to end the game: ";
        cin >> continuar;
        continuar = toupper(continuar);
    };

    while (posf != 30 && continuar == 'C') {
        
        // JUGADOR 1
        
        // Obtengo valor del dado
        iTiro = miDado.getTiro();
        // Obtengo la posicion inicial del jugador 1
        ipos = j1.getpos();
        /* Se introduce el valor recibido del dado en el metodo del objeto miTablero de la 
           clase Tablero para obtener del indice del arreglo la posicion de la letra. */
        letra = miTablero.getValor(iTiro, ipos);
        /*Se introduce la letra recibida y el valor del dado en el metodo, con el valor del tiro se lo sumaremos a la posicion antes de 
          tirar el dado, luego con la letra se determinara si se le suma o restan 3 o se queda como estaba. */
        posf = j1.posicion(iTiro, letra);

        // Se envian los valores ya obtenidos que son el valor del dado, la posicion letra y la posicion final donde quedaria el jugador.
        j1.info(iTiro,letra,posf);
        // Se actualiza la posicion inicial del jugador con la que termino el turno.
        j1.setposb(posf);
        // El metodo hace el cambio de turno este va sumando de dos en dos debido a que se cuenta el turno del otro jugador.
        j1.turno();
        /* Verifica de acuerdo a su posicion final si el jugador ya gano le muestra el mensaje de ganador. En caso de que todavia no acabe, tambien 
           se le pregunta si quiere seguir jugando. */
        continuar = j1.continuar(posf);
        
        // JUGADOR 2 (Las mismas clases para el jugador 1 se usaron en el jugador 2.)

        // En tal caso de que el jugador 1 no alla oprimido 'C' o no haya ganado se corre el siguiente codigo.
        if(posf < 30 && continuar == 'C') {
            iTiro = miDado.getTiro();
            ipos = j2.getpos();
            letra = miTablero.getValor(iTiro, ipos);
            posf = j2.posicion(iTiro, letra);
        
            j2.info(iTiro,letra,posf);
            j2.setposb(posf);
            j2.turno();
            continuar = j2.continuar(posf);
        };
        
    };   

}

int main() {
    
    MyGame match;
    match.start();

    return 0;
}
