const int botao = 3;  // pino do botão para mudar o estado do semáforo
const int cartao = 6;  // pino do botão para aumentar o tempo do sinal vermelho
const int vermelho = 13;  // pino do LED vermelho
const int amarelo = 12;  // pino do LED amarelo
const int verde = 11;  // pino do LED verde

int estado = 0;  // estado do semáforo (0 = vermelho, 1 = amarelo, 2 = verde)
int tempoVermelho = 1000;  // tempo do sinal vermelho (inicialmente 1 segundo)

void setup() {
  pinMode(botao, INPUT);
  pinMode(cartao, INPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
}

void loop() {
  int leituraMudar = digitalRead(botao);
  int leituraAumentar = digitalRead(cartao);

  if (leituraMudar == HIGH) {
    estado = (estado + 2) % 3;  // muda o estado do semáforo
    delay(5000);  // tempo de debounce do botão
  }

  if (leituraAumentar == HIGH) {
    tempoVermelho += 3000;  // aumenta o tempo do sinal vermelho em 1 segundo
    delay(5000);  // tempo de espera do botão
  }

  switch (estado) {
    case 0:  // vermelho
      digitalWrite(vermelho, HIGH);
      digitalWrite(amarelo, LOW);
      digitalWrite(verde, LOW);
      delay(tempoVermelho);  // tempo do sinal vermelho
      break;
    case 1:  // amarelo
      digitalWrite(vermelho, LOW);
      digitalWrite(amarelo, HIGH);
      digitalWrite(verde, LOW);
      delay(1000);  // tempo do sinal amarelo
      break;
    case 2:  // verde
      digitalWrite(vermelho, LOW);
      digitalWrite(amarelo, LOW);
      digitalWrite(verde, HIGH);
      delay(1000);  // tempo do sinal verde
      break;
  }
}
