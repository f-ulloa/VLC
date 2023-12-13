const int ledPin = 16;

String getMorseCode(char character)
{
    character = toupper(character); // Convierte a mayúscula para simplificar
    switch (character)
    {
    case 'A':
        return ".-";
    case 'B':
        return "-...";
    case 'C':
        return "-.-.";
    case 'D':
        return "-..";
    case 'E':
        return ".";
    case 'F':
        return "..-.";
    case 'G':
        return "--.";
    case 'H':
        return "....";
    case 'I':
        return "..";
    case 'J':
        return ".---";
    case 'K':
        return "-.-";
    case 'L':
        return ".-..";
    case 'M':
        return "--";
    case 'N':
        return "-.";
    case 'O':
        return "---";
    case 'P':
        return ".--.";
    case 'Q':
        return "--.-";
    case 'R':
        return ".-.";
    case 'S':
        return "...";
    case 'T':
        return "-";
    case 'U':
        return "..-";
    case 'V':
        return "...-";
    case 'W':
        return ".--";
    case 'X':
        return "-..-";
    case 'Y':
        return "-.--";
    case 'Z':
        return "--..";
    default:
        return ""; // Para caracteres no reconocidos
    }
}

void dot()
{
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
}

void dash()
{
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
}

void sendMessageInMorse(String message)
{
    for (int i = 0; i < message.length(); i++)
    {
        String morseCode = getMorseCode(message[i]);
        for (int j = 0; j < morseCode.length(); j++)
        {
            if (morseCode[j] == '.')
            {
                dot();
            }
            else if (morseCode[j] == '-')
            {
                dash();
            }
            delay(500);
        }
        delay(1000);
    }
}

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    sendMessageInMorse("SOS");
    delay(3000);
}
