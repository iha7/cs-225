#include <string>
#include "Image.h"
#include <iostream>
#include "cs225/HSLAPixel.h"
//using cs225::HSLAPixel;
#include "cs225/PNG.h"
using namespace cs225;
#include <cmath>

//namespace cs225 {
    Image::Image() {

    }
    Image::Image(double one, double two) {

    }
    void Image::darken() {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                cs225::HSLAPixel & pixel = getPixel(x,y);
                pixel.l = pixel.l - 0.1;
            }
        }
    }
    void Image::darken(double amount) {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                pixel.l = pixel.l - amount;
                if (pixel.l < 0) {
                    pixel.l = 0;
                }
            }
        }
    } 
    void Image::desaturate() {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                pixel.s = pixel.s - 0.1;
            }
        }
    }
    void Image::desaturate(double amount) {
        //Image picture;
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                //picture.getPixel(x,y).s = picture.getPixel(x,y).s - amount;
                //if (picture.getPixel(x,y).s <0) {
                //    picture.getPixel(x,y).x = 0;
                //}
                HSLAPixel & pixel = getPixel(x,y);
                pixel.s = pixel.s - amount;
            }
        }
    }
    void Image::grayscale() {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                pixel.s = 0;
            }
        }
    }
    void Image::illinify() {
        const int orange = 11;
        const  int blue = 216;

        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);

                if (pixel.h >= 113.5 && pixel.h <= 293.5) {
                    pixel.h = blue;
                } else {
                    pixel.h = orange;
                }
            }
        }
    }
    void Image::lighten() {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                pixel.l = pixel.l + 0.1;
                if (pixel.l > 1) {
                    pixel.l = 1;
                }
            }
        }
    }
    void Image::lighten(double amount) {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                pixel.l = pixel.l + amount;
                if (pixel.l > 1) {
                    pixel.l =1;
                }
            }
        }
    }
    void Image::rotateColor(double degrees) {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                //pixel.h = pixel.h + degrees;
                //if(pixel.h > 360) {
                  //  unsigned muchHigher = pixel.h;
                    //pixel.h = muchHigher % 360;
                //}
                pixel.h = pixel.h + degrees;
                if (pixel.h < 0) {
                    int pos = abs(pixel.h);
                    pixel.h = 360 - (pos % 360);
                } else if (pixel.h > 360) {
                    double remainder = 0;
                    remainder = pixel.h - 360;
                    pixel.h = remainder;
                }
            }
        }
    }
    void Image::saturate() {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                pixel.s = pixel.s + 0.1;
            }
        }
    }
    void Image::saturate(double amount) {
        for (unsigned x = 0; x < width(); x++ ) {
            for (unsigned  y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                pixel.s = pixel.s + amount;
            }
        }
    }
    void Image::scale(double factor) {
        Image scaledImage = Image();
        scaledImage.resize(width(), height());
        unsigned newWidth = (width() * factor);
        unsigned newHeight = (height() * factor);
        for (unsigned x = 0; x < width(); x++) {
            for( unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x,y);
                HSLAPixel & scaledPixel = scaledImage.getPixel(x,y);
                scaledPixel = pixel;
            }
        }
        if (factor > 1) {
            resize(newWidth, newHeight);
            for (unsigned x = 0; x < newWidth; x++) {
                for(unsigned y = 0; y < newHeight; y++) {
                    HSLAPixel & pixel = getPixel(x,y);
                    HSLAPixel & scaledPixel = scaledImage.getPixel(x / factor, y / factor);
                    pixel = scaledPixel;
                }
            }
        }
        if (factor < 1 && factor > 0) {
            resize(newWidth, newHeight);
            for (unsigned x = 0; x < scaledImage.width(); x++) {
                for( unsigned y = 0; y < scaledImage.height(); y++) {
                    HSLAPixel & pixel = getPixel(x * factor , y * factor);
                    HSLAPixel & scaledPixel = scaledImage.getPixel(x, y);
                    pixel = scaledPixel;
                }
            }
        }
    }
    void Image:: scale(unsigned w, unsigned h) {
        double scaler;
        if (h/height()> w/width()) {
            scaler = w/width();
        } else {
            scaler = h/height();
        }
        scale(scaler);
    }


