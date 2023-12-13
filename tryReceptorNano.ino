const int inputPin = 2; // Pin de entrada para leer la señal del LED
unsigned long signalDuration;
unsigned long lastChangeTime;
int lastState = HIGH; // Estado inicial
String currentMorseSymbol = "";
String decodedMessage = "";

void setup()
{
    pinMode(inputPin, INPUT);
    Serial.begin(9600);
    lastChangeTime = millis();
}

void loop()
{
    int currentState = digitalRead(inputPin);
    if (currentState != lastState)
    {
        signalDuration = millis() - lastChangeTime;

        if (currentState == HIGH && lastState == LOW)
        { // Fin de una señal (LED apagado)
            if (signalDuration >= 200 && signalDuration < 375)
            {
                currentMorseSymbol += ".";
            }
            else if (signalDuration >= 375 && signalDuration < 750)
            {
                currentMorseSymbol += "-";
            }
        }
        lastChangeTime = millis();
        lastState = currentState;
    }
    else if (currentMorseSymbol != "" && millis() - lastChangeTime >= 800)
    {
        char decodedChar = decodeMorse(currentMorseSymbol);
        Serial.print(decodedChar); // Imprime la letra decodificada
        decodedMessage += decodedChar;
        currentMorseSymbol = "";
    }
    else if (millis() - lastChangeTime >= 2000 && decodedMessage != "")
    {
        Serial.print(" ");
        decodedMessage = "";
        currentMorseSymbol = "";
    }

    if (millis() - lastChangeTime > 10000 && decodedMessage != "")
    { // Final de la transmisión
        Serial.println("\nMensaje Completo: " + decodedMessage);
        decodedMessage = "";
    }
}

char decodeMorse(String morseCode)
{
    if (morseCode == ".-")
        return 'A';
    if (morseCode == "-...")
        return 'B';
    if (morseCode == "-.-.")
        return 'C';
    if (morseCode == "-..")
        return 'D';
    if (morseCode == ".")
        return 'E';
    if (morseCode == "..-.")
        return 'F';
    if (morseCode == "--.")
        return 'G';
    if (morseCode == "....")
        return 'H';
    if (morseCode == "..")
        return 'I';
    if (morseCode == ".---")
        return 'J';
    if (morseCode == "-.-")
        return 'K';
    if (morseCode == ".-..")
        return 'L';
    if (morseCode == "--")
        return 'M';
    if (morseCode == "-.")
        return 'N';
    if (morseCode == "---")
        return 'O';
    if (morseCode == ".--.")
        return 'P';
    if (morseCode == "--.-")
        return 'Q';
    if (morseCode == ".-.")
        return 'R';
    if (morseCode == "...")
        return 'S';
    if (morseCode == "-")
        return 'T';
    if (morseCode == "..-")
        return 'U';
    if (morseCode == "...-")
        return 'V';
    if (morseCode == ".--")
        return 'W';
    if (morseCode == "-..-")
        return 'X';
    if (morseCode == "-.--")
        return 'Y';
    if (morseCode == "--..")
        return 'Z';
    return ' '; // Carácter no reconocido o espacio
}