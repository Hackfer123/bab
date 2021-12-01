// Пример Adafruit_NeoMatrix для одиночного NeoPixel Shield.
// Прокручивает «Привет» по матрице в портретной (вертикальной) ориентации.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN A0
// ОБЪЯВЛЕНИЕ МАТРИЦЫ:
// Параметр 1 = ширина матрицы NeoPixel
// Параметр 2 = высота матрицы
// Параметр 3 = номер контакта (действительны большинство)
// Параметр 4 = флаги компоновки матрицы, при необходимости сложите вместе:
//    NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//      Положение ПЕРВОГО светодиода в матрице; выберите два, например
//      NEO_MATRIX_TOP + NEO_MATRIX_LEFT для верхнего левого угла.
//    NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: светодиоды расположены горизонтально
//      строками или вертикальными столбцами соответственно; выберите один или другой.
//    NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: все строки / столбцы продолжаются
//      в том же порядке или чередуя строки в обратном направлении; Выбери один.
//    См. Пример ниже для этих значений в действии.
// Параметр 5 = флаги типа пикселя, при необходимости сложите вместе:
//    NEO_KHZ800 800 кГц битовый поток (большинство продуктов NeoPixel со светодиодами WS2812)
//    NEO_KHZ400 400 кГц (классические пиксели FLORA 'v1' (не v2), драйверы WS2811)
//    NEO_GRB Пиксели привязаны к битовому потоку GRB (большинство продуктов NeoPixel)
//    NEO_GRBW Пиксели привязаны к битовому потоку GRBW (продукты RGB + W NeoPixel)
//    Пиксели NEO_RGB связаны для битового потока RGB (пиксели FLORA v1, а не v2)


// Пример для NeoPixel Shield. В этом приложении мы хотели бы использовать его
// как матрица высотой 5x8, с USB-портом, расположенным в верхней части
// Ардуино. В таком положении первый пиксель находится вверху справа, а
// строки расположены в столбцы в прогрессивном порядке. Щит использует
// 800 кГц (v2) пикселей, которые ожидают данные цвета GRB.

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
  NEO_MATRIX_TOP     + NEO_MATRIX_LEFT +
  NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB            + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(0, 255, 200), matrix.Color(255, 0, 200), matrix.Color(255, 200, 0), matrix.Color(255, 255, 200)};

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(10);
  matrix.setTextColor(colors[0]);
}

int x    = matrix.width();
int pass = 0;

void loop() {
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  matrix.print(F("Subscribe!"));
  if(--x < -36) {
    x = matrix.width();
    if(++pass >= 4) pass = 0;
    matrix.setTextColor(colors[pass]);
  }
  matrix.show();
  delay(150);
}
