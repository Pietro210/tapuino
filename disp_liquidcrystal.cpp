#include "config.h"
#ifdef LCD_USE_LIQUIDCRYSTAL

#include <LiquidCrystal.h>

LiquidCrystal lcd(
  LCD_PIN_RS,
  LCD_PIN_ENABLE,
  LCD_PIN_DATA4,
  LCD_PIN_DATA5,
  LCD_PIN_DATA6,
  LCD_PIN_DATA7
);

extern "C" {
  #include "lcd_interface.h"

  void lcd_init(uint8_t lcd_addr) {
    lcd.begin(MAX_LCD_LINE_LEN, LCD_NUM_LINES);
  }

  void lcd_cursor() {
    lcd.cursor();
  }

  void lcd_noCursor() {
    lcd.noCursor();
  }

  void lcd_backlight() {
    // always on
  }

  void lcd_noBacklight() {
    // always on
  }

  void lcd_setCursor(uint8_t col, uint8_t row) {
    lcd.setCursor(col, row);
  }

  void lcd_print(char* msg) {
    lcd.print(msg);
  }

  void lcd_write(uint8_t value) {
    lcd.write(value);
  }
}

#endif
