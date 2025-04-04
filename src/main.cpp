
// ****************************************************************************
// *                                                                          *
// * Aufgabe:                                                                 *
// *                                                                          *
// * -> Schreib ein Programm mit folgenden Eigenschaften:                     *
// *    Es gibt zwei Taster (TASTER1, TASTER2), zwei LEDs (LED1, LED2) und    *
// *    ein Potentiometer. Taster1 schaltet einen digitalen Blinker auf die   *
// *    beiden LEDs, Taster2 schaltet einen analogen Blinker auf die beiden   *
// *    LEDs. Die Geschwindigkeit des Blinkers soll mit dem Poti zwischen     *
// *    50ms und 1000ms eingestellt werden können. Ein langer Tastendruck     *
// *    auf einen der beiden Taster toggelt die Blinkfunktion ein/aus.        *
// *                                                                          *
// * -> Suche dir ein/zwei Mitarbeiter und forke dieses Projekt               *
// * -> Teile die Arbeit auf die Mitarbeiter so auf, dass ein fast-forward-   *
// *    merge ermöglicht wird.                                                *
// * -> Fülle die bestehenden Header-Dateien und erzeuge die entsprechenden   *
// *    Implementierungen (cpp-Dateien). Verwende ausschließlich Klassen!     *
// *                                                                          *
// * -> Erstelle einen pull-request                                           *
// *                                                                          *
// *                                                                          *
// ****************************************************************************

#include <Arduino.h>
#include "analogblinker.h"

#define LED1 11   // Low-side switch (leuchtet mit LOW)
#define LED2 10   // Low-side switch (leuchtet mit LOW)
#define TASTER1 6 // LOW wenn gedrückt
#define TASTER2 5 // LOW wenn gedrückt
#define POT1 A7

analogblinker a_blinker(LED1, LED2, true);

void setup()
{
    Serial.begin(115200); // Baud rate
    Serial.println("..Start..\n");

    pinMode(TASTER1, INPUT_PULLUP);
}

uint32_t wert = 0;

void loop()
{
    a_blinker.poll();

    if (Serial.available())
    {
        uint8_t c = Serial.read();
        // Serial.println(c);

        if (c >= '0' && c <= '9')
        {
            c = c - '0';
            Serial.print(c);
            wert = (wert * 10) + c;
        }
        else if (c == 13)
        {
            if (wert > 0 && wert <= 2000)
            {
                Serial.print("\nBlink-Zeit: ");
                Serial.println(wert);
                a_blinker.blinkTime = wert;
            }
            else
            {
                Serial.print("\nungültiger Wert! ");
            }
        }
        else if(c == 'o')
        {
            a_blinker.enable = true;
        }
        else if (c == 'f')
        {
            a_blinker.enable = false;
        }
        
    }
}
