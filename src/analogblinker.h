#ifndef ANALOGBLINKER_H
#define ANALOGBLINKER_H

#include <Arduino.h>

/*
    ----------- INFO -------------
    Diese Struktur implementiert einen analogen Blinker. Die Helligkeit
    wird über die Zeit gesteuert. Die init-Methode erwartet die Pin-Nummer
    und die Zeitgrenzen für die Helligkeit. Die poll-Methode muss bei jedem
    Loop ausgeführt werden.
*/
class analogblinker
{

public:
    // PinNr1, PinNr2, Blinkzeit[ms], Abfrage-Zeit[ms], Sync-Modus, Enable[T/F]
    analogblinker(uint8_t, uint8_t, uint16_t, uint8_t, bool, bool);

    // PinNr1, PinNr2, Enable[T/F]
    analogblinker(uint8_t, uint8_t, bool);  // überladener KONSTRUKTOR


    bool enable = false;
    uint16_t blinkTime = 0;

    void poll();

    
private:
    bool sync = false;
    uint8_t pin1 = 0, pin2 = 0, step = 0;
    uint16_t dutycycle = 0;
    unsigned long lastpoll = 0, polltime = 0;
};

#endif
