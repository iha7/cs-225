/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */

#pragma once
#include <iostream>
//#include <sstream>
#include "cs225/PNG.h"
using namespace std;

//namespace cs225 {
    class Image : public cs225::PNG  {
        public :
            Image(PNG inputPng);
            Image();
            Image(double one, double two);
            void lighten();
            void lighten(double amount);
            void darken();
            void darken(double amount);
            void saturate();
            void saturate(double amount);
            void desaturate();
            void desaturate(double amount);
            void grayscale();
            void rotateColor(double degrees);
            void illinify();
            void scale(double factor);
            void scale(unsigned w, unsigned h);

        private :

    };


