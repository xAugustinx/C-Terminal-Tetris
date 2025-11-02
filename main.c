#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <pthread.h>
#include <string.h>

int dlugoscCzekania = 500000;

int klocekSpadajacy[4][2];

int czyPostawicKloca = 1;

int doUsunenca[4][2];


int licznikPrzyspieszenia = 0;

int czyBreak = 0;

int wysokosc = 0;
int szerokosc = 0;

int poleTetris[20][10];

int typKlocaMeow = 0;

int dodatkowyMeowMeow = 0;

int obrot = 0;

int strona = 0;

int potelcjalneKloce[7][8] = {
    {0,2,0,3,0,4,0,5}, //zrobiony chuj

    {0,2,0,3,1,2,1,3}, //zrobiony chuj

    {1,2,0,2,0,3,0,4},
    {1,4,0,2,0,3,0,4}, //zrobione

    {1,3,0,2,0,3,1,4}, // zaraz zrobie
    {1,3,1,2,0,3,0,4},

    {1,3,0,2,0,3,0,4} //zrobiony chuj

};

int czyRuszony = 0;

char x = 'o';


int startVoid() {

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            poleTetris[i][j] = 0;
        }
    }

    licznikPrzyspieszenia = 0;

    for (int meow = 0; meow < 4; meow++) {
        klocekSpadajacy[meow][0] = 8;
        klocekSpadajacy[meow][1] = 8;
    }
    czyPostawicKloca = 1;
    czyBreak = 0;
    typKlocaMeow = 0;
    dodatkowyMeowMeow = 0;
    obrot = 0;
    strona = 0;
    czyRuszony = 0;
    szerokosc = 0;
    wysokosc = 0;

    while (1) {
        if (wysokosc == 20) {
            break;
        }
        else if (wysokosc == 19) {
            poleTetris[wysokosc][szerokosc] = 2;
        }
        else {
            poleTetris[wysokosc][szerokosc] = 0;
        }

        szerokosc++;
        if (szerokosc == 10) {
            wysokosc++;
            szerokosc = 0;
        }

    }
    return 0;
}


int prosteWypychanie() {
    int jjakisInt = 0;
    int superFajnyInt = 0;
    for (int xy = 0; xy < 2; xy++) {
        for (int i = 0; i < 4; i++)
        {
            if (poleTetris[klocekSpadajacy[i][0]][klocekSpadajacy[i][1]] == 1 || poleTetris[klocekSpadajacy[i][0]][klocekSpadajacy[i][1]] == 3) {
                jjakisInt = 1;
            }
        }
        if (jjakisInt) {
            jjakisInt = 0;
            for (int i = 0; i < 4; i++) {
                klocekSpadajacy[i][0] = klocekSpadajacy[i][0] - 1;
            }
        }
    }
    return 0;
}

void* input_handler(void* arg) {

    char c;
    while (1) {
        scanf(" %c", &c);

            x = c;

    }
    return NULL;
}
void smacznego() {

            //ustawienie kloca

            for (int ie = 0; ie < 4; ie++) {

                doUsunenca[ie][0] = klocekSpadajacy[ie][0];
                doUsunenca[ie][1] = klocekSpadajacy[ie][1];
            }

            //int wazne = 0;
            //Sprawdzanie kolizji
            for (int ie = 0; ie < 4; ie++) {
                if (poleTetris[klocekSpadajacy[ie][0] +1][klocekSpadajacy[ie][1]] > 0 && klocekSpadajacy[ie][0] +1 != klocekSpadajacy[ie -1][0]  ) {
                    czyPostawicKloca = 1;

                    for (int meow = 0; meow < 4; meow++) {
                        poleTetris[klocekSpadajacy[meow][0]][klocekSpadajacy[meow][1]] = 1;
                        doUsunenca[meow][0] = 67;
                        doUsunenca[meow][1] = 67;

                    }


                }
            }

            if (czyPostawicKloca)
                {

                czyPostawicKloca = 0;


                typKlocaMeow = rand() % 7;
                //tutaj


                if (1) {
                    obrot = 0;
                }
                else {}


                int jeden = 0;
                int dwa = 0;
                int trzy = 0;

                while (1) {
                    klocekSpadajacy[jeden][dwa] = potelcjalneKloce[typKlocaMeow][trzy];

                    trzy++;

                    dwa++;
                    if (dwa == 2) {
                        dwa = 0;
                        jeden++;
                    }
                    if (trzy >= 8) {
                        break;
                    }
                }

            }
            else
            {


                for (int ie = 0; ie < 4; ie++) {

                    klocekSpadajacy[ie][0] = klocekSpadajacy[ie][0] + 1;
                }
                czyRuszony = 1;
            }
            //koniec ustawienia kloca

            //wybierz strone

            if (x == 'a') {
                int bool = 1;
                for (int meow = 0; meow < 4; meow++) {
                    if (poleTetris[klocekSpadajacy[meow][0]][klocekSpadajacy[meow][1] -1 ] == 1 || poleTetris[klocekSpadajacy[meow][0]][klocekSpadajacy[meow][1] -1 ] == 2) {
                        {
                            for (int ie = 0; ie < 4; ie++) {
                                if (klocekSpadajacy[meow][1] -1 == klocekSpadajacy[ie][0]) {
                                    bool = 0;
                                }
                            }
                        }
                    }

                }
                for (int nya = 0; nya < 4; nya++)
                {
                    if (klocekSpadajacy[nya][1] < 1) {
                        bool = 0;
                    }
                }
                if (bool) {
                    for (int meow = 0; meow < 4; meow++) {
                        klocekSpadajacy[meow][1]--;
                    }
                }

                x = 'o';
            }
            else if (x == 'd') {
                int bool = 1;
                for (int meow = 0; meow < 4; meow++) {
                    if (poleTetris[klocekSpadajacy[meow][0]][klocekSpadajacy[meow][1] + 1 ] == 1 || poleTetris[klocekSpadajacy[meow][0]][klocekSpadajacy[meow][1] + 1 ] == 2 ) {
                        {
                            for (int ie = 0; ie < 4; ie++) {
                                if (klocekSpadajacy[meow][1] + 1 == klocekSpadajacy[ie][0]) {
                                    bool = 0;
                                }
                            }
                        }
                    }

                }

                for (int nya = 0; nya < 4; nya++)
                {
                    if (klocekSpadajacy[nya][1] > 8) {
                        bool = 0;
                    }
                }

                if (bool) {
                    for (int meow = 0; meow < 4; meow++) {
                        klocekSpadajacy[meow][1]++;
                    }
                }

                x = 'o';
            }
            //obrot
            else if (x == 's') {
                licznikPrzyspieszenia = 3;
                x = 'o';
            }
            else if (x == 'r')
            {

                if (typKlocaMeow == 1) {obrot = 0;}

                if (typKlocaMeow == 0) {




                    if (obrot == 0) {

                        obrot = 1;

                        for (int meow = 0; meow < 4; meow++)
                        {
                            klocekSpadajacy[meow][1] = klocekSpadajacy[1][1];
                        }

                        int wazny = klocekSpadajacy[1][0] + 1;

                        klocekSpadajacy[0][0] = klocekSpadajacy[1][0]+1;
                        //klocekSpadajacy[1][0] = klocekSpadajacy[1][0];
                        klocekSpadajacy[2][0] = klocekSpadajacy[1][0]-1;
                        klocekSpadajacy[3][0] = klocekSpadajacy[1][0]-2;

                        for (int meow = 19; meow > -1; meow--) {
                            for (int meowmeow3 = 0; meowmeow3 < 4; meowmeow3++) {

                                if (poleTetris[klocekSpadajacy[meowmeow3][0]][klocekSpadajacy[meowmeow3][1]] != 0 && poleTetris[klocekSpadajacy[meowmeow3][0]][klocekSpadajacy[meowmeow3][1]] != 3)
                                {
                                    for (int ie = 0; ie < 4; ie++)
                                    {
                                        klocekSpadajacy[ie][0] = klocekSpadajacy[ie][0] -1;
                                    }
                                    break;

                                }

                            }
                            while (1) {
                                int licznikUjemnych = 0;
                                for (int meow = 0; meow < 4; meow++)
                                {
                                    if (klocekSpadajacy[meow][0] < 0) {
                                        for (int meow34 = 0; meow34 < 4; meow34++) {
                                            klocekSpadajacy[meow34][0]++;
                                        }
                                        licznikUjemnych++;
                                    }
                                    else if (klocekSpadajacy[meow][0] > 19) {
                                        for (int meow34 = 0; meow34 < 4; meow34++) {
                                            klocekSpadajacy[meow34][1]--;
                                        }
                                        licznikUjemnych++;
                                    }

                                    if (klocekSpadajacy[meow][1] < 0) {
                                        for (int meow34 = 0; meow34 < 4; meow34++) {
                                            klocekSpadajacy[meow34][1]++;
                                        }
                                        licznikUjemnych++;
                                    }
                                    else if (klocekSpadajacy[meow][1] > 9) {
                                        for (int meow34 = 0; meow34 < 4; meow34++) {
                                            klocekSpadajacy[meow34][1]--;
                                        }
                                        licznikUjemnych++;
                                    }
                                }
                                if (licznikUjemnych == 0) {break;}
                            }
                        }

                    }
                    else {
                        obrot = 0;

                        for (int meow = 0; meow < 4; meow++)
                        {
                            klocekSpadajacy[meow][0] = klocekSpadajacy[1][0];
                        }
                        klocekSpadajacy[0][1] = klocekSpadajacy[1][1]+1;
                        klocekSpadajacy[2][1] = klocekSpadajacy[1][1]-1;
                        klocekSpadajacy[3][1] = klocekSpadajacy[1][1]-2;


                        while (1) {
                            int licznikUjemnych = 0;
                            for (int meow = 0; meow < 4; meow++)
                            {
                                if (klocekSpadajacy[meow][0] < 0) {
                                    for (int meow34 = 0; meow34 < 4; meow34++) {
                                        klocekSpadajacy[meow34][0]++;
                                    }
                                    licznikUjemnych++;
                                }
                                else if (klocekSpadajacy[meow][0] > 19) {
                                    for (int meow34 = 0; meow34 < 4; meow34++) {
                                        klocekSpadajacy[meow34][1]--;
                                    }
                                    licznikUjemnych++;
                                }

                                if (klocekSpadajacy[meow][1] < 0) {
                                    for (int meow34 = 0; meow34 < 4; meow34++) {
                                        klocekSpadajacy[meow34][1]++;
                                    }
                                    licznikUjemnych++;
                                }
                                else if (klocekSpadajacy[meow][1] > 9) {
                                    for (int meow34 = 0; meow34 < 4; meow34++) {
                                        klocekSpadajacy[meow34][1]--;
                                    }
                                    licznikUjemnych++;
                                }
                            }
                            if (licznikUjemnych == 0) {break;}
                        }

                        int licznik777 = 0;

                        int wysokoscZapisanaUwu = klocekSpadajacy[0][0];

                        for (int meowmeow = 0; meowmeow < 10; meowmeow++) {
                            if (poleTetris[meowmeow][wysokoscZapisanaUwu] != 1) {
                                licznik777++;
                            }
                            else {licznik777 == 0;}

                            if (licznik777 > 3) {

                                klocekSpadajacy[3][1] = meowmeow;
                                klocekSpadajacy[2][1] = meowmeow-1;
                                klocekSpadajacy[1][1] = meowmeow-2;
                                klocekSpadajacy[0][1] = meowmeow-3;
                                break;
                            }
                        }

                        if (licznik777 > 3)
                        {
                            for (int meow = 19; meow > -1; meow--)
                            {
                                for (int meow3 = 0; meow3 < 4; meow3++)
                                {
                                    if (poleTetris[klocekSpadajacy[meow3][0]][klocekSpadajacy[meow3][1]] != 0 && poleTetris[klocekSpadajacy[meow3][0]][klocekSpadajacy[meow3][1]] != 3)
                                    {
                                        for (int ie = 0; ie < 4; ie++)
                                        {
                                            klocekSpadajacy[ie][0] = klocekSpadajacy[ie][0] -1;
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                if (typKlocaMeow == 6) {
                    int jt = 0;
                    int y = klocekSpadajacy[0][0];
                    int x = klocekSpadajacy[0][1];
                    if (obrot == 0 || obrot == 2) {
                        if (obrot == 0) { jt = 1;}
                        else {jt = -1;}

                        klocekSpadajacy[1][0] = y-jt;
                        klocekSpadajacy[1][1] = x-jt;
                        klocekSpadajacy[2][0] = y;
                        klocekSpadajacy[2][1] = x-jt;
                        klocekSpadajacy[3][0] = y+jt;
                        klocekSpadajacy[3][1] = x-jt;

                        obrot++;
                    }
                    else if (obrot == 1 || obrot == 3) {
                        if (obrot == 1) { jt = 1;}
                        else {jt = -1;}
                        klocekSpadajacy[1][0] = y+jt;
                        klocekSpadajacy[1][1] = x-jt;
                        klocekSpadajacy[2][0] = y+jt;
                        klocekSpadajacy[2][1] = x;
                        klocekSpadajacy[3][0] = y+jt;
                        klocekSpadajacy[3][1] = x+jt;
                        obrot++;
                    }
                    //wypychanie gowna
                    prosteWypychanie();
                    //koniec wypychania gowna

                }
                else if (typKlocaMeow == 3 || typKlocaMeow == 2) {
                    int y;
                    int x;

                    if (obrot == 0 || obrot == 1) {
                        x = -1;
                        y = -2;
                    }
                    else if (obrot == 2 || obrot == 3) {
                        x = 1;
                        y = 2;
                    }

                    if (obrot == 0 || obrot == 2) {
                        klocekSpadajacy[1][0] = klocekSpadajacy[0][0];
                        klocekSpadajacy[1][1] = klocekSpadajacy[0][1]+x;
                        klocekSpadajacy[2][1] = klocekSpadajacy[0][1];
                        klocekSpadajacy[3][1] = klocekSpadajacy[0][1];
                        klocekSpadajacy[2][0] = klocekSpadajacy[0][0]+x;
                        klocekSpadajacy[3][0] = klocekSpadajacy[0][0]+y;
                        obrot++;
                    }
                    else if (obrot == 1 || obrot == 3) {

                        klocekSpadajacy[1][0] = klocekSpadajacy[0][0];
                        klocekSpadajacy[1][1] = klocekSpadajacy[0][1]+x;

                        klocekSpadajacy[2][0] = klocekSpadajacy[0][0];
                        klocekSpadajacy[2][1] = klocekSpadajacy[0][1]+y;

                        klocekSpadajacy[3][0] = klocekSpadajacy[0][0]+x;
                        klocekSpadajacy[3][1] = klocekSpadajacy[0][1]+y;

                        obrot++;

                    }
                    if (obrot > 3) {
                        obrot = 0;
                    }

                    int jjakisInt = 0;

                    int superFajnyInt = 0;
                    for (int xy = 0; xy < 2; xy++) {
                        for (int i = 0; i < 4; i++)
                        {
                            if (poleTetris[klocekSpadajacy[i][0]][klocekSpadajacy[i][1]] == 1 || poleTetris[klocekSpadajacy[i][0]][klocekSpadajacy[i][1]] == 3) {
                                jjakisInt = 1;
                            }
                        }
                        if (jjakisInt) {
                            jjakisInt = 0;
                            for (int i = 0; i < 4; i++) {
                                klocekSpadajacy[i][0] = klocekSpadajacy[i][0] - 1;
                            }
                        }
                    }
                }
                else if (typKlocaMeow == 5) {

                    if (obrot == 0) {
                        klocekSpadajacy[1][0] = klocekSpadajacy[0][0]-1;
                        klocekSpadajacy[1][1] = klocekSpadajacy[0][1];

                        klocekSpadajacy[2][0] = klocekSpadajacy[0][0];
                        klocekSpadajacy[2][1] = klocekSpadajacy[0][1]+1;

                        klocekSpadajacy[3][0] = klocekSpadajacy[0][0]+1;
                        klocekSpadajacy[3][1] = klocekSpadajacy[0][1]+1;
                        obrot++;
                    }
                    else {
                        klocekSpadajacy[1][0] = klocekSpadajacy[0][0];
                        klocekSpadajacy[1][1] = klocekSpadajacy[0][1]-1;

                        klocekSpadajacy[2][0] = klocekSpadajacy[0][0]-1;
                        klocekSpadajacy[2][1] = klocekSpadajacy[0][1];

                        klocekSpadajacy[3][0] = klocekSpadajacy[0][0]-1;
                        klocekSpadajacy[3][1] = klocekSpadajacy[0][1]+1;


                        obrot = 0;
                    }
                    prosteWypychanie();
                }
                else if (typKlocaMeow == 4) {

                    if (obrot == 0) {
                        klocekSpadajacy[1][0] = klocekSpadajacy[0][0]-1;
                        klocekSpadajacy[1][1] = klocekSpadajacy[0][1];

                        klocekSpadajacy[2][0] = klocekSpadajacy[0][0];
                        klocekSpadajacy[2][1] = klocekSpadajacy[0][1]-1;

                        klocekSpadajacy[3][0] = klocekSpadajacy[0][0]+1;
                        klocekSpadajacy[3][1] = klocekSpadajacy[0][1]-1;
                        obrot++;
                    }
                    else {
                        klocekSpadajacy[1][0] = klocekSpadajacy[0][0]-1;
                        klocekSpadajacy[1][1] = klocekSpadajacy[0][1];

                        klocekSpadajacy[2][0] = klocekSpadajacy[0][0];
                        klocekSpadajacy[2][1] = klocekSpadajacy[0][1]-1;

                        klocekSpadajacy[3][0] = klocekSpadajacy[0][0]-1;
                        klocekSpadajacy[3][1] = klocekSpadajacy[0][1]+1;


                        obrot = 0;
                    }
                    prosteWypychanie();
                }
            }





            //RENDER
            //RENDER
            //RENDER

            wysokosc = 0;
            szerokosc = 0;

            if (czyPostawicKloca == 0) {
                poleTetris [doUsunenca[0][0] ] [doUsunenca[0][1] ] = 0;
                poleTetris [doUsunenca[1][0] ] [doUsunenca[1][1] ] = 0;
                poleTetris [doUsunenca[2][0] ] [doUsunenca[2][1] ] = 0;
                poleTetris [doUsunenca[3][0] ] [doUsunenca[3][1] ] = 0;

            }

            for (int meow = 0; meow < 4; meow++) {

                poleTetris [klocekSpadajacy[meow][0] ] [klocekSpadajacy [meow][1] ] = 3;

            }


            while (1) {
                if (wysokosc == 20) {
                    break;
                }




                if (poleTetris[wysokosc][szerokosc] == 2) {
                    printf("\033[33m%d\033[0m", poleTetris[wysokosc][szerokosc]);
                }
                else if(poleTetris[wysokosc][szerokosc] == 0) {
                    printf("%d", poleTetris[wysokosc][szerokosc]);
                }
                else if(poleTetris[wysokosc][szerokosc] == 3) {
                    printf("\033[31m%d\033[0m", poleTetris[wysokosc][szerokosc]);
                }
                else if(poleTetris[wysokosc][szerokosc] == 1) {
                    printf("\033[90m%d\033[0m", poleTetris[wysokosc][szerokosc]);
                }

                //printf("%d",poleTetris[wysokosc][szerokosc]);



                szerokosc++;
                if (szerokosc == 10) {
                    wysokosc++;
                    szerokosc = 0;
                    printf("\n");
                }
            }

            //koniec renderu

            //ZBIJANIE "|" wybieranie lini
            int doUsunencaLinia[4] = {68,68,68,68};
            int wskaznik = 0;
            int usunoc = 1;

            for (int wysokosc8 = 0; wysokosc8 < 20; wysokosc8++) {
                usunoc = 1;

                for (int szerokosc8 = 0; szerokosc8 < 10; szerokosc8++) {
                    if (poleTetris[wysokosc8][szerokosc8] != 1) { usunoc = 0; break; }
                }

                if (usunoc == 1)
                {
                    doUsunencaLinia[wskaznik] = wysokosc8;
                    wskaznik++;
                }
            }

            int ostatniElement = wskaznik;

            //ZBIJANIE "||" usuwanie lini
            if (wskaznik > -1) {
                int wskaznik2 = 0;

                for (int meow = 0; meow < ostatniElement; meow++) {
                    for (int szerokosc8 = 0; szerokosc8 < 10; szerokosc8++)
                    {
                        poleTetris [doUsunencaLinia[meow]][szerokosc8] = 0;
                    }
                }
                //ZBIJANIE "|||" eleminacja spadającego
                poleTetris[klocekSpadajacy[0][0] ] [klocekSpadajacy [0][1] ] = 0;
                poleTetris[klocekSpadajacy[1][0] ] [klocekSpadajacy [1][1] ] = 0;
                poleTetris[klocekSpadajacy[2][0] ] [klocekSpadajacy [2][1] ] = 0;
                poleTetris[klocekSpadajacy[3][0] ] [klocekSpadajacy [3][1] ] = 0;


                //ZBIJANIE "IV" przesówanie wszystkich poziomów
                for (int meow = 0; meow < 4; meow++)
                {

                    if (doUsunencaLinia[meow] != 68) {

                        for (int wysokosc16 = doUsunencaLinia[meow]; wysokosc16 > 0; wysokosc16--)
                        {
                            for (int szerokosc16 = 0; szerokosc16 < 10; szerokosc16++) {
                                poleTetris[wysokosc16][szerokosc16] = poleTetris[wysokosc16 - 1][szerokosc16];

                            }

                        }
                    }
                    else {
                        break;
                    }

                }
            }
            //for (int)

            //koniec Zbijania



            if (czyPostawicKloca == 0) {
                for (int ie = 0; ie < 4; ie++) {
                    poleTetris[klocekSpadajacy[ie][0]][klocekSpadajacy[ie][1]] = 0;
                }
            }




            //scanf(" %c", &x);
            //system("clear");
    x = 'o';
}


int main() {
    srand(time(NULL));

    pthread_t input_thread;
    pthread_create(&input_thread, NULL, input_handler, NULL);

    while (1) {
        startVoid();
        x = 'o';

        while (1) {
            smacznego();
            // while (1) {
            //
            //     if (licznikPrzyspieszenia == 0) {
            //         dlugoscCzekania = 500000;
            //
            //     }
            //     else {
            //         licznikPrzyspieszenia--;
            //         dlugoscCzekania = 1;
            //         break;
            //     }
            //
            //
            // }
            usleep(dlugoscCzekania);

            for (int meow = 0; meow < 10; meow++) {
                if (poleTetris[0][meow] == 1) {czyBreak = 1;}
            }
            if (czyBreak == 1) {
                break;
            }

            system("clear");
        }
        printf("gej Ower, Czy kontynulowac? y/n");
        usleep(50000000);
        if (x == 'n' || x == 'N') {break;}

        x = 'o';


    }

    system("clear");
    pthread_join(input_thread, NULL);
    return 0;
}