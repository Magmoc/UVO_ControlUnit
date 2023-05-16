#include "gui.h"
#include <stdio.h>
#include <iostream>

// #include "images/test_image.h"
// #include "images/test_image2.h"
// #include "images/test_image3.h"
// #include "images/monke.h"
#include "images/monke2.h"

#include <JPEGDecoder.h>
#include <TJpg_Decoder.h>

#define minimum(a,b)     (((a) < (b)) ? (a) : (b))





GUI::GUI(void){
	init();
}

GUI::~GUI(){

}

void GUI::init(void){
	_tft.init();
	// Set the rotation to the orientation you wish to use in your project before calibration
	// (the touch coordinates returned then correspond to that rotation only)
	_tft.setRotation(1);
	pinMode(BACKLIGHT_PIN, OUTPUT);
	digitalWrite(BACKLIGHT_PIN, HIGH);
	update_frame = true;
	
}

void GUI::update(void){
	if (update_frame){
		update_frame = false;
		write_frame();
	}
}

void GUI::write_frame(void){
	// _tft.drawBitmap(0, 0, image, 100, 100, TFT_WHITE, TFT_BLACK);

	// _tft.begin ();                                 // initialize a ST7789 chip
	_tft.setSwapBytes(true);                      // swap the byte order for pushImage() - corrects endianness

	// _tft.setRotation(3);
	_tft.fillScreen (TFT_GREEN);
	
	// spr_main.createSprite(300, 240);
	// spr_main.fillScreen(TFT_TRANSPARENT);
	// drawArrayJpeg(spr_main, Baboon40, sizeof(Baboon40), 0, 0);
	// spr_main.pushSprite(0, 0);
	
	spr_popup.createSprite(480, 320);
	// spr_popup.setPivot(240, 160);
	// spr_popup.fillScreen(TFT_GREEN);
	drawArrayJpeg(spr_popup, monke2, sizeof(monke2), 0, 0);
	spr_popup.pushSprite(0, 0);

	// delay(2000);
	// _tft.fillScreen(TFT_BLUE);
	// delay(1000);
	// spr_popup.pushSprite(0, 0);
	// drawArrayJpeg(_tft, monke2, sizeof(monke2), 0, 0);
}


// https://github.com/Bodmer/TFT_eSPI/tree/master/examples/480%20x%20320/TFT_flash_jpg

//####################################################################################################
// Draw a JPEG on the TFT pulled from a program memory array
//####################################################################################################
void GUI::drawArrayJpeg(TFT_eSPI layer, const uint8_t arrayname[], uint32_t array_size, int xpos, int ypos) {

	int x = xpos;
	int y = ypos;

	JpegDec.decodeArray(arrayname, array_size);

	renderJPEGonLayer(layer, x, y);
}

//####################################################################################################
// Draw a JPEG on the TFT, images will be cropped on the right/bottom sides if they do not fit
//####################################################################################################
// This function assumes xpos,ypos is a valid screen coordinate. For convenience images that do not
// fit totally on the screen are cropped to the nearest MCU size and may leave right/bottom borders.

// void GUI::renderJPEGonLayer(TFT_eSPI layer, int xpos, int ypos){
	
// }


void GUI::renderJPEGonLayer(TFT_eSPI layer, int xpos, int ypos) {

	// retrieve infomration about the image
	uint16_t *pImg;
	uint16_t mcu_w = JpegDec.MCUWidth;
	uint16_t mcu_h = JpegDec.MCUHeight;
	uint32_t max_x = JpegDec.width;
	uint32_t max_y = JpegDec.height;

	// Jpeg images are draw as a set of image block (tiles) called Minimum Coding Units (MCUs)
	// Typically these MCUs are 16x16 pixel blocks
	// Determine the width and height of the right and bottom edge image blocks
	uint32_t min_w = minimum(mcu_w, max_x % mcu_w);
	uint32_t min_h = minimum(mcu_h, max_y % mcu_h);

	// save the current image block size
	uint32_t win_w = mcu_w;
	uint32_t win_h = mcu_h;

	// save the coordinate of the right and bottom edges to assist image cropping
	// to the screen size
	max_x += xpos;
	max_y += ypos;

	// read each MCU block until there are no more
	while (JpegDec.read()) {
		
	// save a pointer to the image block
	pImg = JpegDec.pImage ;

	// calculate where the image block should be drawn on the screen
	int mcu_x = JpegDec.MCUx * mcu_w + xpos;  // Calculate coordinates of top left corner of current MCU
	int mcu_y = JpegDec.MCUy * mcu_h + ypos;

	// check if the image block size needs to be changed for the right edge
	if (mcu_x + mcu_w <= max_x) win_w = mcu_w;
	else win_w = min_w;

	// check if the image block size needs to be changed for the bottom edge
	if (mcu_y + mcu_h <= max_y) win_h = mcu_h;
	else win_h = min_h;

	// copy pixels into a contiguous block
	if (win_w != mcu_w)
	{
		uint16_t *cImg;
		int p = 0;
		cImg = pImg + win_w;
		for (int h = 1; h < win_h; h++)
		{
		p += mcu_w;
		for (int w = 0; w < win_w; w++)
		{
			*cImg = *(pImg + w + p);
			cImg++;
		}
		}
	}

	// calculate how many pixels must be drawn
	uint32_t mcu_pixels = win_w * win_h;

	layer.startWrite();

	// draw image MCU block only if it will fit on the screen
	if (( mcu_x + win_w ) <= layer.width() && ( mcu_y + win_h ) <= layer.height())
	{

		// Now set a MCU bounding window on the _tft to push pixels into (x, y, x + width - 1, y + height - 1)
		layer.setAddrWindow(mcu_x, mcu_y, win_w, win_h);

		// Write all MCU pixels to the _tft window
		while (mcu_pixels--) {
		// Push each pixel to the _tft MCU area
		layer.pushColor(*pImg++);
		}

	}
	else if ( (mcu_y + win_h) >= layer.height()) JpegDec.abort(); // Image has run off bottom of screen so abort decoding

	layer.endWrite();

	// Return to use entire screen
	// layer.setAddrWindow(0, 0, layer.width(), layer.height());
	}
}

//####################################################################################################
// Print image information to the serial port (optional)
//####################################################################################################
void GUI::jpegInfo() {
  Serial.println(F("==============="));
  Serial.println(F("JPEG image info"));
  Serial.println(F("==============="));
  Serial.print(F(  "Width      :")); Serial.println(JpegDec.width);
  Serial.print(F(  "Height     :")); Serial.println(JpegDec.height);
  Serial.print(F(  "Components :")); Serial.println(JpegDec.comps);
  Serial.print(F(  "MCU / row  :")); Serial.println(JpegDec.MCUSPerRow);
  Serial.print(F(  "MCU / col  :")); Serial.println(JpegDec.MCUSPerCol);
  Serial.print(F(  "Scan type  :")); Serial.println(JpegDec.scanType);
  Serial.print(F(  "MCU width  :")); Serial.println(JpegDec.MCUWidth);
  Serial.print(F(  "MCU height :")); Serial.println(JpegDec.MCUHeight);
  Serial.println(F("==============="));
}



// https://github.com/Bodmer/TJpg_Decoder/tree/master/examples/FLash_array/Flash_Jpg
