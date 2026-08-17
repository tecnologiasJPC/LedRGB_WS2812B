#include <Adafruit_NeoPixel.h>

#define PIN        3   // Pin de datos D2
#define NUMPIXELS  1   // Cantidad de LEDs conectados

// Configuración del LED (frecuencia de 800Khz y orden de color GRB)
Adafruit_NeoPixel pixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixel.begin();
  pixel.setBrightness(80); // Brillo general (0 - 255)
  pixel.show();
}

void loop() {
// Transición: Rojo -> Verde
  fadeToColor(255, 0, 0,   0, 255, 0,   100, 15);
  delay(500);

  // Transición: Verde -> Azul
  fadeToColor(0, 255, 0,   0, 0, 255,   100, 15);
  delay(500);

  // Transición: Azul -> Blanco (255, 255, 255)
  fadeToColor(0, 0, 255,   255, 255, 255, 100, 15);
  delay(500); // Pausa breve en Blanco

  // Transición: Blanco -> Magenta/Violeta
  fadeToColor(255, 255, 255,   255, 0, 255, 100, 15);
  delay(500);

  // Transición: Magenta -> Rojo
  fadeToColor(255, 0, 255,   255, 0, 0,   100, 15);
  delay(500);
}

void fadeToColor(int rStart, int gStart, int bStart, 
                 int rEnd,   int gEnd,   int bEnd, 
                 int steps,  int duration) {
                 
  for (int i = 0; i <= steps; i++) {
    // Calculamos el valor intermedio proporcional para cada canal
    int r = rStart + (rEnd - rStart) * i / steps;
    int g = gStart + (gEnd - gStart) * i / steps;
    int b = bStart + (bEnd - bStart) * i / steps;

    pixel.setPixelColor(0, pixel.Color(r, g, b));
    pixel.show();
    delay(duration);
  }
}
