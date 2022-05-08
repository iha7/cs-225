/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if (first[curDim] == second[curDim]) {
      return first < second;
    }
    return first[curDim] < second[curDim];

}



/**from double to ints change
*/
template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
int sum = 0;
int futureSum = 0;
   
for (unsigned int i = 0; i < Dim; i++) {
  sum = sum + pow((target[i] - currentBest[i]), 2.0);
  futureSum = futureSum + pow((target[i] - potential[i]), 2.0);
}
if (futureSum == sum) {
  return potential < currentBest;
}
return futureSum < sum;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     * changed
     */

  if (newPoints.size() == false) {
    root = nullptr;
    } else {
    vector<Point<Dim>> copyPoint = newPoints;
    root = construct(copyPoint, 0);
    size = newPoints.size();
    }
}


template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */

    vector<Point<Dim>> points;
    buildVector(other.root, points);
    this = new KDTree(points);
    size = other.size;
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  destroy(root);
  vector<Point<Dim>> newPoint;
  buildVector(rhs.root, newPoint);
  this = new KDTree(newPoint);
  size = rhs.size;
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
destroy(root);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

     return search(root, query, 0);
    // return Point<Dim>();
}




















template <int Dim>
Point<Dim> KDTree<Dim>::search(KDTreeNode * subroot, const Point<Dim>& query, unsigned newDim) const { 

KDTreeNode * first;
KDTreeNode * second;
Point<Dim> best;
Point<Dim> notBest;

if (subroot->right == NULL && subroot->left == NULL) {
  return subroot->point;
}
if (subroot == NULL) {
  return Point<Dim>();
}
if (smallerDimVal(query, subroot->point, newDim)) {
  second = subroot->right;
  first = subroot->left;
} else {
  second = subroot->left;
  first = subroot->right;
}
if (first != NULL) {
  best = search(first, query, (newDim + 1) % Dim);
}
if ((shouldReplace(query, best, subroot->point) && first != NULL) || first == NULL) {
  best = subroot->point;
}
if (inRadius(subroot->point, query, best, newDim) && second != NULL) {
  notBest = search(second, query, (newDim + 1) % Dim);
  if(shouldReplace(query, best, notBest) == true) {
    best = notBest;
  }
}
return best;
}


template <int Dim>
bool KDTree<Dim>::inRadius(const Point<Dim>& potential, const Point<Dim>& target, const Point<Dim>& best, unsigned newDim) const {
    double radius = 0.0;
    double distance = pow((target[newDim] - potential[newDim]), 2.0);

    for (unsigned i = 0; i < Dim; i++) {
      radius = radius + pow((target[i] - best[i]), 2.0);
    }
    if (distance > radius) {
      return false;
    } else {
    return true;
    }
}


template <int Dim>
unsigned KDTree<Dim>::select(std::vector<Point<Dim>>& points, unsigned bottom, unsigned top, unsigned median, unsigned newDim) const {
    
    
    unsigned pivot = (bottom + top) / 2;

    pivot = partition(points, bottom, top, pivot, newDim);
    if (bottom == top) {
       return bottom;
    }
    if (median < pivot){
       return select(points, bottom, pivot - 1, median, newDim);
    } else if (median == pivot){
        return median;
    } else {
        return select(points, pivot + 1, top, median, newDim);
    }
}


template <int Dim>
unsigned KDTree<Dim>::partition(std::vector<Point<Dim>>& points, unsigned bottom, unsigned top, unsigned index, unsigned newDim) const {

     Point<Dim> pivot = points[index];
     swap(points, index, top);
     unsigned temp = bottom;

     
     for (unsigned newIndex = bottom; newIndex < top; ++newIndex) {
       if (smallerDimVal(points[newIndex], pivot, newDim) == true) {
         if (temp != newIndex) {
           swap(points, temp, newIndex);
         }
         temp++;
       }
     }
     swap(points, temp, top);
     return temp;
}


template <int Dim>
void KDTree<Dim>::swap(std::vector<Point<Dim>>& points, unsigned first, unsigned second) const {


  if (points.size() != false) {
    Point<Dim> temp = points[first];
    points[first] = points[second];
    points[second] = temp;
  }
  return;
}



template <int Dim>
typename KDTree<Dim>::KDTreeNode * KDTree<Dim>::construct(std::vector<Point<Dim>>& points, unsigned newDim) const {
   
    vector<Point<Dim>> left;
    vector<Point<Dim>> right;

    if (points.size() == false) {
       return NULL;
    }
    unsigned temp = select(points, 0, points.size() - 1, ((points.size() - 1) / 2), newDim);
    KDTreeNode * subroot = new KDTreeNode(points[temp]);

    for (unsigned i = temp + 1; i < points.size(); ++i) {
      right.push_back(points[i]);
    }
    for (unsigned i = 0; i < temp; ++i) {
      left.push_back(points[i]);
    }

    subroot->right = construct(right, (newDim + 1) % Dim);
    subroot->left = construct(left, (newDim + 1) % Dim);

    return subroot;
}


template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode * subroot) {
    if (subroot != NULL) {
    destroy(subroot->left);
    destroy(subroot->right);

    delete subroot;
    subroot = NULL;
    }
    return;
  }




