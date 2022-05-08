#include "../cs225/HSLAPixel.h"
#include "../Point.h"
#include <stdlib.h>

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;

/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
MyColorPicker::MyColorPicker(){}

HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  return HSLAPixel(rand() % 180, 0.5, 0.5, 0.5);

}