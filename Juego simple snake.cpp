#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool perdiste;
const int ancho = 20;
const int alto = 20;
int x, y, frutaX, frutaY, puntuacion;
int colaX[100], colaY[100];
int cola;
enum eDireccion { PARADO = 0, IZQUIERDA, DERECHA, ARRIBA, ABAJO };//google
eDireccion direccion;//google
void gotoxy(int x, int y) //gotoxy
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Inicializar() //inicia las variables fruta,ancho alto y los puntos tambien la serpiente
{
    perdiste = false;
    direccion = PARADO;
    x = ancho / 2;
    y = alto / 2;
    frutaX = rand() % ancho;
    frutaY = rand() % alto;
    puntuacion = 0;
}
void Dibujar() //se actualiza constantemente para mostrar el mapa, posicion de la fruta  puntos etc...
{
    gotoxy(0, 0);
    for (int i = 0; i < ancho + 2; i++)//mapa 
        cout <<char(177);
    cout << endl;
    for (int i = 0; i < alto; i++) 
	{
        for (int j = 0; j < ancho; j++) 
		{
            if (j == 0)//cabeza
                cout <<char(177);
            if (i == y && j == x)
                cout << "O";
            else if (i == frutaY && j == frutaX)
                cout << "F";
            else {
                bool imprimir = false;
                for (int k = 0; k < cola; k++)//cuerp o de serpiente 
				{
                    if (colaX[k] == j && colaY[k] == i) {
                        cout << "o";
                        imprimir = true;
                    }
                }
                if (!imprimir)
                    cout << " ";
            }
            if (j == ancho - 1)//mapa
                cout <<char(177);
        }
        cout << endl;
    }
    for (int i = 0; i < ancho + 2; i++)//mapa
        cout <<char(177);
    cout << endl;
    cout << "Puntuacion: " << puntuacion << endl;//puntos 
}
void Entrada() //entrada del teclado
{
    if (_kbhit()) //verifica si se presiono una tecla
	{
        switch (_getch())//lee la tecla ingresada
		{
        case 'a':
            direccion = IZQUIERDA;
            break;
        case 'd':
            direccion = DERECHA;
            break;
        case 'w':
            direccion = ARRIBA;
            break;
        case 's':
            direccion = ABAJO;
            break;
        case 'x':
            perdiste = true;
            break;
        }
    }
}

void Logica() //logica aca verifico la posicion de la serpiente,las colisiones y verificar si la serpiente comio fruta
{
    int prevX = colaX[0];
    int prevY = colaY[0];
    int prev2X, prev2Y;
    colaX[0] = x;
    colaY[0] = y;
    for (int i = 1; i < cola; i++)
	 {
        prev2X = colaX[i];//inicia las variables de la serpiente actualizando su valor constantemente
        prev2Y = colaY[i];
        colaX[i] = prevX;
        colaY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (direccion) //se actualiza la posicion de la serpiente
	{
    case IZQUIERDA:
        x--;
        break;
    case DERECHA:
        x++;
        break;
    case ARRIBA:
        y--;
        break;
    case ABAJO:
        y++;
        break;
    default:
        break;
    }
    if (x >= ancho) x = 0; else if (x < 0) x = ancho - 1;//esta parte la saque google aca JAJAJAJA nose profe me quede sin ideas
    if (y >= alto) y = 0; else if (y < 0) y = alto - 1;//pero basicamente sirve para detectar cuando la serpiente sale del mapa vuelva a salir por el otro lado

    for (int i = 0; i < cola; i++)//detecta si la serpiente se choco con ella misma
        if (colaX[i] == x && colaY[i] == y)
            perdiste = true;
    if (x == frutaX && y == frutaY) //detecta que la serpiente comio fruta
	{
        puntuacion += 10;
        frutaX = rand() % ancho;
        frutaY = rand() % alto;
        cola++;
    }
}
int main() 
{
    Inicializar();
    while (!perdiste) 
	{
        Dibujar();
        Entrada();
        Logica();
        Sleep(10); //velocidad del juego
    }
    return 0;
}
