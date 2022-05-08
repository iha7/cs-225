// #include <cmath>
// #include <iterator>
// #include <iostream>

// #include "../cs225/HSLAPixel.h"
// #include "../cs225/PNG.h"
// #include "../Point.h"

// #include "ImageTraversal.h"

// /**
//  * Calculates a metric for the difference between two pixels, used to
//  * calculate if a pixel is within a tolerance.
//  *
//  * @param p1 First pixel
//  * @param p2 Second pixel
//  * @return the difference between two HSLAPixels
//  */
// double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
//   double h = fabs(p1.h - p2.h);
//   double s = p1.s - p2.s;
//   double l = p1.l - p2.l;

//   // Handle the case where we found the bigger angle between two hues:
//   if (h > 180) { h = 360 - h; }
//   h /= 360;

//   return sqrt( (h*h) + (s*s) + (l*l) );
// }

// /**
//  * Default iterator constructor.
//  */
// ImageTraversal::Iterator::Iterator() {
//   /** @todo [Part 1] */
//   traversal = NULL;    
//   }

// ImageTraversal::Iterator::Iterator(ImageTraversal* type, PNG png, double tolerance, Point start) {
//   traversal = type;
//   current = start;
//   start_ = start;
//   png_ = png;
//   tolerance_ = tolerance;
//   visited.resize(png.width(), vector<bool>(png.height(), false));
// }

// /**
//  * Iterator increment opreator.
//  *
//  * Advances the traversal of the image.
//  */
// ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
//   /** @todo [Part 1] */

//   return *this;
// }

// /**
//  * Iterator accessor opreator.
//  *
//  * Accesses the current Point in the ImageTraversal.
//  */
// Point ImageTraversal::Iterator::operator*() {
//   /** @todo [Part 1] */
//   return Point(0, 0);
// }

// /**
//  * Iterator inequality operator.
//  *
//  * Determines if two iterators are not equal.
//  */
// bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
//   /** @todo [Part 1] */
//   return false;
// }

















  
#include <cmath>
#include <iterator>
#include <iostream>

#include <vector>
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

using namespace std;
/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 * 
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );    
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  move = NULL;
  /** @todo [Part 1] */
}

ImageTraversal::Iterator::Iterator(ImageTraversal * type, PNG png, double tolerance, Point start){
  startPoint= start;
  inputPng = png;
  tolerance_ = tolerance;
  move = type;
  current = start;
  visited.resize(png.width(), vector<bool>(png.height(), false));

}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  if(move->empty() == false){
    Point popped = move->pop();
    while(move->empty() == false && visited[popped.x][popped.y] == true) {
      popped = move->pop();
    }
    current = popped;
  }

  visited[current.x][current.y] = true;
  
  HSLAPixel startPixel = inputPng.getPixel((startPoint.x),(startPoint.y));
  
  HSLAPixel savedPixel = inputPng.getPixel((startPoint.x),(startPoint.y));
  
  
  // if(current.x+1 < inputPng.width() && current.y < inputPng.height()){
  //   savedPixel = inputPng.getPixel((current.x+1),current.y);
  //   if( calculateDelta(startPixel,savedPixel) <= tolerance_){
  //     if(visited[current.x+1][current.y] == false)
  //     move->add(Point(current.x+1,current.y));
  //   }
  // }
  if(current.y < inputPng.height() && current.x+1 < inputPng.width()){
    savedPixel = inputPng.getPixel((current.x+1),current.y);
    if(tolerance_ >= calculateDelta(startPixel,savedPixel)){
      if(visited[current.x+1][current.y] == false)
      move->add(Point(current.x+1,current.y));
    }
  }
  // if(current.x < inputPng.width() && current.y+1 < inputPng.height()){
  //   savedPixel = inputPng.getPixel((current.x),(current.y+1));
  //   if( calculateDelta(startPixel,savedPixel) <= tolerance_){
  //     if(visited[current.x][current.y+1] == false)
  //     move->add(Point(current.x,current.y+1));
  //   }
  // }
    if(current.y+1 < inputPng.height() && current.x < inputPng.width()){
    savedPixel = inputPng.getPixel((current.x),(current.y+1));
    if( tolerance_ >= calculateDelta(startPixel,savedPixel)){
      if(visited[current.x][current.y+1] == false)
      move->add(Point(current.x,current.y+1));
    }
  }
  
  if(current.x != 0 && current.x-1 < inputPng.width() && current.y < inputPng.height()){
    savedPixel = inputPng.getPixel((current.x-1),(current.y));
    if(tolerance_ >=calculateDelta(startPixel,savedPixel)){
      if(visited[current.x-1][current.y] == false)
      move->add(Point(current.x-1,current.y));
    }
  }
  if(current.x < inputPng.width() && current.y != 0 && current.y-1 < inputPng.height()){
    savedPixel = inputPng.getPixel((current.x),(current.y-1));
    if(tolerance_ >= calculateDelta(startPixel,savedPixel)){
      if(visited[current.x][current.y-1] == false)
      move->add(Point(current.x,current.y-1));
    }
  }
  while(move->empty() == false && visited[move->peek().x][move->peek().y] == true){
    move->pop();
  }
  if(move->empty() == false)
    current = move->peek();
  return *this;
}

/**
 * Iterator accessor opreator.
 * 
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  return current;
}

/**
 * Iterator inequality operator.
 * 
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  bool thisEmpty = false; 
  bool otherEmpty = false;


  if (other.move == NULL) {
     otherEmpty = true;
  }
  if (this->move == NULL) {
    thisEmpty = true;
  }
  if (!otherEmpty) {
     otherEmpty = other.move->empty();
  }
  if (!thisEmpty)  {
     thisEmpty = this->move->empty();
  }
  if ((!thisEmpty)&&(!otherEmpty)){
   return (this->move != other.move); // both empty then the traversals are equal, return true
  }
  else if (thisEmpty && otherEmpty) {
     return false; //both not empty then compare the traversals

  } else {

   return true; // one is empty while the other is not, return true
  }
}


