
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */
using namespace std;

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    return currentIdx * 2;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return (currentIdx * 2) + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    return _elems.size() > leftChild(currentIdx);
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if (rightChild(currentIdx) > _elems.size()) {
        return leftChild(currentIdx);
    }
    if (rightChild(currentIdx) < _elems.size()) {
      if (higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)])) {
        return leftChild(currentIdx);
      } else {
        return rightChild(currentIdx);
      }
    }
    return leftChild(currentIdx);
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    size_t higherIndex = maxPriorityChild(currentIdx);
    if (hasAChild(currentIdx) == false) {
        return;
    } else {
        if (higherPriority(_elems[higherIndex], _elems[currentIdx]) == true) {
          swap(_elems[currentIdx], _elems[higherIndex]);
          heapifyDown(higherIndex);
        }
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    size_t ancestorIdx = parent(currentIdx);
    if (currentIdx == root()) {
        return;
    } else {
        if (higherPriority(_elems[currentIdx], _elems[ancestorIdx])) {
            swap(_elems[currentIdx], _elems[ancestorIdx]);
            heapifyUp(ancestorIdx);
        }
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
     _elems.push_back(T());
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems) 
{
    // @TODO Construct a heap using the buildHeap algorithm
    _elems.push_back(T());
    for (T element : elems) {
      _elems.push_back(element);
    }
    for (unsigned i = parent(_elems.size()); i > 0; --i) {
      heapifyDown(i);
    }
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
    int counter = 1;
    if (empty() == false) {
        T answer = peek();
        swap(_elems[root()], _elems[_elems.size() - counter]);
        _elems.pop_back();
        heapifyDown(root());
        return answer;
    } else {
        return T();
    }
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    if (empty() == false){
    return _elems[root()];
    } else {
        return T();
    }
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    // @TODO Add elem to the heap
    _elems.push_back(elem);
    heapifyUp(_elems.size() - 1);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    size_t inputIndex = idx;
    _elems[inputIndex] = elem;
    if (higherPriority(_elems[inputIndex], _elems[parent(inputIndex)])) {
      heapifyUp(inputIndex);
    } else if (higherPriority(_elems[maxPriorityChild(inputIndex)], _elems[inputIndex])) {
      heapifyDown(inputIndex);
    }
}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    bool result = true;
    if (_elems.size() == root() == true) {
        return result;
    } else {
        result = false;
        return result;
    }
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
