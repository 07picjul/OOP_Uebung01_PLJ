
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
#include "helper.h"
#include "analogblinker.h"

#define LED1 A1   // Low-side switch (leuchtet mit LOW)
#define LED2 A2   // Low-side switch (leuchtet mit LOW)
#define TASTER1 6 // LOW wenn gedrückt
#define TASTER2 5 // LOW wenn gedrückt
#define POTI A7

#define DB_ZEIT 50
#define BLINKTIME 300
#define LONGPRESSTIME 1000

#define ANALOGBLINKER_POLLTIME 10 // ms
#define ANALOGBLINKER_MIN 100     // ms
#define ANALOGBLINKER_MAX 3000    // ms

// Instanzieren der Strukturen
button taster1;

analogblinker a_blinker;

void setup()
{
    Serial.begin(115200); // Baud rate
    Serial.println("..Start..\n");

    taster1.init(TASTER1, false, DB_ZEIT, LONGPRESSTIME);
    a_blinker.init(LED1, LED2, BLINKTIME, ANALOGBLINKER_POLLTIME, false, true);
}

void loop()
{
    taster1.poll();
    a_blinker.poll();

    a_blinker.blinkTime = ((((ANALOGBLINKER_MAX - ANALOGBLINKER_MIN) / 1023.0) * analogRead(POTI)) + 100) / 4;

}
