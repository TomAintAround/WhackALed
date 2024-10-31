byte minLed = 7;
byte maxLed = 13;
byte buttonPin = 4;
bool ultimoEstadoBotao = LOW;
bool estadoBotaoDebouncing = LOW;
long ultimoDebounce = 0;
byte delayDebounce = 50;
byte estadoJogo = 1;

void debouncing() {
    /*
        Contornar o problema do debouncing dos botões
    */
    bool estadoBotao = !digitalRead(buttonPin);

    // Se o estado do botão for diferente, atualizar o tempo do último debounce.
    if (estadoBotao != ultimoEstadoBotao) ultimoDebounce = millis();

    // Executar se o tempo atual menos o do último debounce for maior que a margem definida
    if (millis - ultimoDebounce > delayDebounce) {

        // Executar se o estado do botão tiver mudado
        if (estadoBotaoDebouncing != estadoBotao) {
            estadoBotaoDebouncing = estadoBotao;
        }
    }

    ultimoEstadoBotao = estadoBotao;
}

void preJogo() {
    /*
        Primeira fase do jogo
    */

}

void jogo() {
    /*
        Segunda fase do jogo
    */
}

void vitoria() {
    /*
        Terceira fase do jogo
    */
}

void acaoAtual() {
    /*
        Escolher a fase do jogo
        A variável estadoJogo começa a 1
    */
    if (estadoJogo == 1) preJogo();
    else if (estadoJogo == 2) jogo();
    else if (estadoJogo == 3) vitoria();
}

void setup() {
    Serial.begin(9600);

    for (byte led = minLed; led <= maxLed; led++) pinMode(led, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
    debouncing();
    acaoAtual();
}