#ifndef MAIN_CONTROLLER_DEFINES_HPP
#define MAIN_CONTROLLER_DEFINES_HPP



// *********************************************************
//
//				TFT SCREEN DEFINES
//
// *********************************************************

#ifdef USE_SCREEN

#define USER_SETUP_LOADED
#define ST7796_DRIVER

#define TFT_RST 32
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 4
#define TFT_DC 2

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT
#define SPI_FREQUENCY 27000000

#endif


#define DTR_PIN 0
#define SPI_CS_SD 5
#define POWER_ENABLE_PIN 21

// #define MOSI?
// #define MISO?
// #define SPI_CS_DISPLAY
// #define SCREEN_RST
// #define BACKLIT 12

#define ENABLE_SWITCH_PIN 22

#define ROTARY_ENCODER_A_PIN SENSOR_VP //WHAT IS SENSOR_VP?
#define ROTARY_ENCODER_B_PIN SENSOR_VN //????
#define ROTARY_ENCODER_PUSH_PIN 27

#define BUTTON_UP_PIN 34
#define BUTTON_DOWN_PIN 35

#define SPI_CS_XPT 33

//TODO WHAT ARE THOSEEEE?/
#define nRESET_SWITCH_PIN 25
#define nRESET_LED_SWITCH_PIN 13
#define nRESET_MC_SWITCH 15

#define SDA_PIN 26
#define SCL_PIN 14



#endif