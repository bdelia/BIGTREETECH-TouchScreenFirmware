#ifndef _ST7920_SIMULATOR_H_
#define _ST7920_SIMULATOR_H_

#include "stdint.h"
#include "../../Configuration.h"
#include "TouchEncoder.h"

// User-defined colors for 12864 mode from Configuration.h
#ifndef ST7920_BKCOLOR
  #define ST7920_BKCOLOR LCD_BLACK
#endif

#ifndef ST7920_FNCOLOR
  #define ST7920_FNCOLOR LCD_GREEN
#endif

#define ST7920_XSTART    (0x80)
#define ST7920_YSTART    (0x80)


//# ST7920_FULLSCREEN
#define LCD_XROWS_FULLSCREEN 128.0f
#define LCD_YROWS_FULLSCREEN 64.0f
#define PIXEL_XSIZE_FULLSCREEN      (MIN(LCD_WIDTH/LCD_XROWS_FULLSCREEN, LCD_HEIGHT/LCD_YROWS_FULLSCREEN))
#define PIXEL_YSIZE_FULLSCREEN      (PIXEL_XSIZE_FULLSCREEN)
#define SIMULATOR_XSTART_FULLSCREEN ((LCD_WIDTH - PIXEL_XSIZE_FULLSCREEN*LCD_XROWS_FULLSCREEN) / 2)
#define SIMULATOR_YSTART_FULLSCREEN ((LCD_HEIGHT - PIXEL_YSIZE_FULLSCREEN*LCD_YROWS_FULLSCREEN) / 2)

#define LCD_XROWS 128
#define LCD_YROWS 64
#define PIXEL_XSIZE      (MIN(LCD_WIDTH/LCD_XROWS, LCD_HEIGHT/LCD_YROWS))
#define PIXEL_YSIZE      (PIXEL_XSIZE)
#define SIMULATOR_XSTART ((LCD_WIDTH - PIXEL_XSIZE*LCD_XROWS) / 2)

#ifdef ST7920_ONSCREEN_CONTROLS
#define SIMULATOR_YSTART ((LCD_HEIGHT - PIXEL_YSIZE*LCD_YROWS) / 2)
#else
#define SIMULATOR_YSTART  (START_X / 2)
#endif

typedef enum
{
  ST7920_IDLE = 0,
  ST7920_WCMD = 0xF8,
  ST7920_WDATA = 0xFA,
  ST7920_RCMD = 0xFC,
  ST7920_RDATA = 0xFE,
} ST7920_CTRL_STATUS;

typedef struct
{
  int16_t x, y;
  uint8_t x_cur;
  uint8_t x_record;
}ST7920_PIXEL;


void ST7920_WriteXY(uint8_t xy);
void ST7920_ST7920_ParseWCmd(uint8_t cmd);
void ST7920_DrawPixel(int16_t x, int16_t y, uint16_t color);

void menuST7920(void);

#endif
