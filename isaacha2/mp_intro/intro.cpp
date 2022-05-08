#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
using namespace cs225;
using cs225::HSLAPixel;


void rotate(std::string inputFile, std::string outputFile) {

    //PNG* inputPng = new PNG();
    //(*inputPng).readFromFile(inputFile);
    //PNG *outputPng = new PNG(inputPng->width(), inputPng->height());
  
    cs225::PNG inputPng;
    inputPng.readFromFile(inputFile);
    cs225::PNG outputPng = cs225::PNG(inputPng.width(),inputPng.height());

  for (unsigned x = 0; x < inputPng.width(); x++) {
    for (unsigned y = 0; y < inputPng.height(); y++) {
      cs225::HSLAPixel & flipPixel1 = inputPng.getPixel(x,y);
      cs225::HSLAPixel & flipPixel2 = outputPng.getPixel(inputPng.width() -1 - x, inputPng.height() -1 - y);
      flipPixel2  = flipPixel1;
    }
  }
  outputPng.writeToFile(outputFile);
}


cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  int hue = 0;
  int saturation = 1;
  int counter = 0;
  double luminance = 0.0;
  for (unsigned x = 0; x < png.width(); x++) {
    for (unsigned y = 0; y < png.height(); y++) {
       cs225::HSLAPixel & pixelColor = png.getPixel(x,y);
        pixelColor.l = 0;
        pixelColor.s = 1;
        pixelColor.a = 1;
        pixelColor.h = 0;
      if (hue < 360) {
        pixelColor.h = hue;
        pixelColor.s = saturation;
        pixelColor.l = luminance;
        counter++;
      }
      if (counter == 225) {
        hue++;
        saturation = saturation + 1;
        luminance = luminance + 0.1;
        counter = 0;
      }
      if (hue == 359) {
        hue = 0;
      }
      if (x < png.width()/2 + 100 && y > png.height()/2 + png.height()/3 && y < png.height()/2 - png.height()/3) {
        pixelColor.h = 200;
        luminance = 1.0;
        saturation = 30;
      }
    }
  }
  return png;
}
