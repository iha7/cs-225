#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
  inputPng = png;
  startPoint = start;
  tolerance_ = tolerance;
  vectorPtr.push_back(start);

}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this, inputPng, tolerance_, startPoint);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
  vectorPtr.push_back(Point(point.x, point.y));
  Point current = vectorPtr.back();
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
    // Point front = vectorPtr[0];
    // vectorPtr.erase(vectorPtr.begin(),vectorPtr.begin() +1);
    // return front;
  Point temp = vectorPtr[vectorPtr.size() - 1];
  vectorPtr.pop_back();
  return temp;
    
  }
  // return Point(0, 0);

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  // int x_ = current.x;
  // int y_ = current.y;
  // return vectorPtr[0];
    return vectorPtr[vectorPtr.size() - 1];

  
  }

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return vectorPtr.empty();
}