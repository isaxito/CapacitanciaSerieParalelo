#include <iostream>
//#include <windows.h>
#include <math.h>
//#include <MMSystem.h>

using namespace std;
// Estructura de capacitor, medio al pedo porque solo tiene la capacitancia
struct Capacitor
{
    double capacitancia;
};

// Prototipo de funcion de calculo de capacitores en serie
void capacitanciaSerieF(int & cantCaps, Capacitor * capacitores);


int main()
{
    // Variable del loop
    bool loopState = true;
    // Musica del terraria porque si (comentada porque solo es para windows)
    //PlaySound("plantera.wav", NULL, SND_FILENAME | SND_NODEFAULT | SND_ASYNC | SND_LOOP);
    system("mode con: cols=100 lines=30");

    // Input del usuario, serie o paralelo
    int unoUOtro = 0;
    cout << "Calculador de capacitancia y voltaje de capacitores en serie o en paralelo x isaquito." << endl;
    while(loopState)
    {
        cout << "Capacitores en serie o paralelo? Usar 1 o 2 respectivamente: ";
        cin >> unoUOtro;
        // Capacitores en serie
        if(unoUOtro == 1)
        {
            int cantCapacitores = 0;
            cout << "Capacitores en serie. Cuantos?: ";
            if(!(cin >> cantCapacitores))
            {
                cout << "Sos un pelotudo hermano.";
                return 0;
            }
            cin.get();
            Capacitor capacitores[cantCapacitores];
            char sn2;
            cout << "Todos los capacitores tienen el mismo valor? s/n: ";
            cin >> sn2;
            if(sn2 == 's')
            {
                cout << "Inserta el valor de la capacitancia: ";
                if(!(cin >> capacitores[0].capacitancia))
                {
                    cout << "Mala entrada.";
                    cin.get();
                    return 0;
                }
                else
                {
                    // Suma de las inversas
                    double totalInversas = 0;
                    for (int i = 0; i < cantCapacitores; i++)
                    {
                        totalInversas += 1/capacitores[0].capacitancia;
                    }
                    double capacidadTotal = 1/totalInversas;
                    cout << "Capacitancia total: " << capacidadTotal << " F, uF, pF o la unidad usada." << endl;
                }
                // Comprobación de si hacer otro cálculo o no
                char sn;
                cout << "De nuevo? s/n: ";
                cin >> sn;
                if (sn == 's')
                {
                    loopState = true;
                    cantCapacitores = 0;
                }
                else if (sn == 'n')
                {
                    loopState = false;
                    cout << "Nos vemos." << endl;
                }
                else
                {
                    cout << "Tomado como no." << endl;
                    loopState = false;
                }
            }
            else
            {
                capacitanciaSerieF(cantCapacitores, capacitores);
                // Comprobación de si hacer otro cálculo o no
                char sn;
                cout << "De nuevo? s/n: ";
                cin >> sn;
                if (sn == 's')
                {
                    loopState = true;
                    cantCapacitores = 0;
                }
                else if (sn == 'n')
                {
                    loopState = false;
                    cout << "Nos vemos." << endl;
                }
                else
                {
                    cout << "Tomado como no." << endl;
                    loopState = false;
                }
            }
        }
        // Capacitores en paralelo
        if(unoUOtro == 2)
        {
            int cantCapacitores = 0;
            cout << "Capacitores en paralelo. Cuantos?: ";
            if(!(cin >> cantCapacitores))
            {
                cout << "Sos un pelotudo hermano.";
                return 0;
            }
            Capacitor capacitores[cantCapacitores];
            double capacidadTotal = 0;
            char sn2;
            cout << "Todos los capacitores tienen el mismo valor? s/n: ";
            cin >> sn2;
            if(sn2 == 's')
            {
                cout << "Inserta el valor de la capacitancia: ";
                if(!(cin >> capacitores[0].capacitancia))
                {
                    cout << "Mala entrada.";
                    cin.get();
                    return 0;
                }
                else
                {
                    capacidadTotal = capacitores[0].capacitancia * cantCapacitores;
                    cout << "Capacitancia total: " << capacidadTotal << " F, uF, pF o la unidad usada." << endl;

                    // Comprobación de si hacer otro cálculo o no
                    char sn;
                    cout << "De nuevo? s/n: ";
                    cin >> sn;
                    if (sn == 's')
                    {
                        loopState = true;
                        cantCapacitores = 0;
                    }
                    else if (sn == 'n')
                    {
                        loopState = false;
                        cout << "Nos vemos." << endl;
                    }
                    else
                    {
                        cout << "Tomado como no." << endl;
                        loopState = false;
                    }
                }
            }
            else
            {
                cout << "Inserta las capacitancias, todas en la misma unidad: " << endl;
                for(int i = 0; i < cantCapacitores; i++)
                {
                    cout << "Capacitor numero #" << i+1 << ": ";
                    if(!(cin >> capacitores[i].capacitancia))
                    {
                        cout << "Mala respuesta.";
                        return 0;
                    }
                    // La capacitancia total solo es la suma de las mismas
                    capacidadTotal += capacitores[i].capacitancia;
                }
                cout << "Capacitancia total: " << capacidadTotal << " F, uF, pF o la unidad usada. " << endl;
                cout << "El voltaje total va a ser el que proporcione la fuente en todos los capacitores." << endl;
                // Comprobación de si hacer otro cálculo o no
                char sn;
                cout << "De nuevo? s/n: ";
                cin >> sn;
                if (sn == 's')
                {
                    loopState = true;
                    cantCapacitores = 0;
                }
                else if (sn == 'n')
                {
                    loopState = false;
                    cout << "Nos vemos." << endl;
                }
                else
                {
                    cout << "Tomado como no." << endl;
                    loopState = false;
                }
            }
        }
    }
    cout << "Nos re vimos.";
    cin.get();
    cin.get();
    return 0;
}

// Desarrollo de la función
void capacitanciaSerieF(int & cantCaps, Capacitor * capacitores)
{
    cout << "Inserta las capacitancias, todas en la misma unidad: " << endl;
    // Input del usuario de las capacitancias
    for(int i = 0; i < cantCaps; i++)
    {
        cout << "Capacitor numero #" << i+1 << ": ";
        if(!(cin >> capacitores[i].capacitancia))
        {
            cout << "Mala respuesta.";
            return;
        }
    }
    // La formula es la inversa de la suma de las inversas de las capacitancias
    double totalInversos = 0;
    // Calculo de la suma de las inversas
    for(int j = 0; j < cantCaps; j++)
    {
        totalInversos += 1/capacitores[j].capacitancia;
    }
    // Calculo final de la formula
    double capacitanciaTotal = 1 / totalInversos;
    cout << "Capacitancia total: " << capacitanciaTotal << " F, uF, pF o la unidad usada." << endl;
    cout << "El voltaje maximo es la suma de los voltajes de todos los capacitores. " << endl;
}
