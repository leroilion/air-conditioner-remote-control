#include <Arduino.h>
#include <IRremote.h>

#define LED 13
#define RECV_IR_PIN 2

// Create object IR recv
IRrecv irrecv(RECV_IR_PIN);

// Create object to decode IR result
decode_results results;

void setup()
{
    /// Init serial and send version number
    Serial.begin(115200);
    Serial.print(F("VERSION : "));
    Serial.println(F(VERSION));

    /// Init LED
    pinMode(LED, OUTPUT);

    /// Init IR Module
    irrecv.enableIRIn();
}

void loop()
{
    if (irrecv.decode(&results))
    {
        Serial.print(F("Decode_type : "));
        switch(results.decode_type)
        {
            case UNKNOWN:
                Serial.println(F("UNKNOWN"));
                break;
            case UNUSED:
                Serial.println(F("UNUSED"));
                break;
            case RC5:
                Serial.println(F("RC5"));
                break;
            case RC6:
                Serial.println(F("RC6"));
                break;
            case NEC:
                Serial.println(F("NEC"));
                break;
            case SONY:
                Serial.println(F("SONY"));
                break;
            case PANASONIC:
                Serial.println(F("PANASONIC"));
                break;
            case JVC:
                Serial.println(F("JVC"));
                break;
            case SAMSUNG:
                Serial.println(F("SAMSUNG"));
                break;
            case WHYNTER:
                Serial.println(F("WHYNTER"));
                break;
            case AIWA_RC_T501:
                Serial.println(F("AIWA_RC_T501"));
                break;
            case LG:
                Serial.println(F("LG"));
                break;
            case SANYO:
                Serial.println(F("SANYO"));
                break;
            case MITSUBISHI:
                Serial.println(F("MITSUBISHI"));
                break;
            case DISH:
                Serial.println(F("DISH"));
                break;
            case SHARP:
                Serial.println(F("SHARP"));
                break;
            case DENON:
                Serial.println(F("DENON"));
                break;
            case PRONTO:
                Serial.println(F("PRONTO"));
                break;
            case LEGO_PF:
                Serial.println(F("LEGO_PF"));
                break;
        }
        Serial.print(F("Value : "));
        Serial.println(results.value, HEX);
        Serial.print(F("Address : "));
        Serial.println(results.address, HEX);
        Serial.print(F("Bits : "));
        Serial.println(results.bits, HEX);
        Serial.print(F("rawlen : "));
        Serial.println(results.rawlen, HEX);
        Serial.print(F("overflow : "));
        Serial.println(results.overflow, HEX);
        Serial.println();
        // Serial.println(F("Raw data : "));
        // for( int i = 0; i < results.rawlen; i++)
        // {
        //     Serial.print(F("0x"));
        //     Serial.print(results.rawbuf[i], HEX);
        //     Serial.print(" ");
        // }
        Serial.println();
        Serial.println();
        Serial.println();
        irrecv.resume();
    }
    delay(100);
}
