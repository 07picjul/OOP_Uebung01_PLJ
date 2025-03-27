
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
#include <Bounce2.h>

#define LED1 A1   // Low-side switch (leuchtet mit LOW)
#define LED2 A2   // Low-side switch (leuchtet mit LOW)
#define TASTER1 6 // LOW wenn gedrückt
#define TASTER2 5 // LOW wenn gedrückt
#define POT1 A7

Bounce bouncheTaster1 = Bounce();

int ledState = LOW;

void setup()
{
    Serial.begin(115200); // Baud rate
    Serial.println("..Start..\n");

    bouncheTaster1.attach(TASTER1, INPUT_PULLUP);

    bouncheTaster1.interval(50);

    pinMode(LED1, OUTPUT);
    digitalWrite(LED1, ledState);
}

void loop()
{
    bouncheTaster1.update();

    if (bouncheTaster1.rose())
    {
        digitalWrite(LED1, HIGH);
    }
}
