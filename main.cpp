#include "mbed.h"
#include <cmath>

const float pi = 3.141592653569793238462;
const float amplitude = 3.0/3.3;
const float offset = 65535;

AnalogOut aout(PA_4);

int main()
{
    float rads = 0.0;

    unsigned short Table[360];
    for (int i=0; i<180; i++) {
            rads = (pi * i) / 180.0f;
            Table[i] = (unsigned short)(amplitude * offset * (tanhf(rads)));
    }
    for (int i=180; i<360; i++) {
            rads = (pi * i) / 180.0f;
            Table[i] = (unsigned short)(amplitude * offset * (tanhf(2*pi - rads)));
    }
    
    while (1) {
        for (int i=0; i<360; i++) {
            aout.write_u16(Table[i]);
        }
    }
}