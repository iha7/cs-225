/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
  head_ = NULL;
  tail_ = NULL;
  length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(tail_->next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
//   if (head_ != NULL) {
//   ListNode* current = head_;
//   ListNode* temp = head_;
//   while(current->next != NULL) {
//     temp = current;
//     current = current->next;
//     delete temp;
//   }
//   // delete current;
//   // delete head_;
//   // delete tail_;

//   length_ = 0;
// }
// }
// if (head_ == NULL) {
//   return;
// }
// ListNode * prev = head_;
// ListNode * curr = head_->next;

// while(curr != NULL) {
//   delete prev->next;
//   prev = curr;
//   curr = curr->next;
// }
// delete head_;
// delete tail_;
// length_ = 0;
// }



// if (head_ == NULL) {
//   return;
// }
// ListNode * next = head_;
// ListNode * current = head_;

// while(current != NULL) {
//   next = current->next;
//   delete current;
//   current = next;
// }
// length_ = 0;
// }
// if (head_ == NULL) {
//   return;
// }
// ListNode * theCurr = tail_;
// ListNode * thePrev = tail_;

// while (theCurr != NULL) {
//   thePrev = theCurr->prev;
//   delete theCurr;
//   theCurr = thePrev;
// }
// length_ = 0;
// }
if (head_ == NULL || tail_ == NULL) {
  return;
}
ListNode * theCurr = head_;
ListNode * theNext = head_;

while (theCurr != NULL) {
  theNext = theCurr->next;
  delete theCurr;
  theCurr = theNext;
}
length_ = 0;
}


/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  if (head_ != NULL) {
    newNode->next = head_;
    head_->prev = newNode;
    // newNode->prev = NULL;
    head_ = newNode;
  } else if (head_ == NULL) {
    head_ = newNode;
    newNode->next = NULL;
    newNode->prev = NULL;
    tail_ = newNode;
  }
  
  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata); {

    if (tail_ == NULL) {
      head_ = newNode;
      newNode->next = NULL;
      newNode->prev = NULL;
      tail_ = newNode;
    }else if (tail_ != NULL) {
      newNode->next = NULL;
      newNode->prev = tail_;
      tail_-> next = newNode;
      tail_ = newNode;


    }
    // newNode->next = NULL;
    // newNode->prev = tail_;
    length_++;
  }
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
//   ListNode * curr = start;

//   for (int i = 0; i < splitPoint || curr != NULL; i++) {
//     curr = curr->next;
//   }

//   if (curr != NULL) {
//       curr->prev->next = NULL;
//       curr->prev = NULL;
//   }

//   return NULL;
// }
//   ListNode * curr = start;
//   // ListNode * returnHead_ = NULL;
//   if (start == NULL) {
//     return NULL;
//   }

//   if (curr == NULL) {
//     return NULL;
//   }
//   if (splitPoint <= 0) {
//     return start;
//   }
//   for (int i = 0; i < splitPoint - 1  && curr; i++) {
//     curr = curr->next;
//   }
//   if (curr != NULL) {
//     ListNode* temp = curr->next;
//       curr->next = NULL;
//       temp->prev = NULL;
//       // curr->prev = newHead_;
//       return temp;
//   }

//   return NULL;
// }
if (!start) {
  return NULL;
}
if (splitPoint <= 0) {
  return start;
}
ListNode* curr = start;
for (int i = 0; i < splitPoint - 1 && curr; i++) {
  curr= curr->next;
}
if (curr) {
  ListNode* temp = curr->next;
  curr->next = NULL;
  temp->prev = NULL;
  return temp;
}
return NULL;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
if (head_ == NULL) {
  return;
}
if (length_ < 3) {
  return;
}

ListNode* current = head_;
ListNode* nextNum = NULL;
ListNode* newStart = head_->next;
head_ = newStart;
while(current->next) {
  if (current->next->next) {
    if (current->next->next->next) {
      nextNum = current->next->next->next;
      newStart ->next->next = current;
      current->next =nextNum->next;
      current = nextNum;
      newStart = current->next;
      nextNum = current->next->next;
      current->next = NULL;
      newStart->next->next = current;
    }
    return;
  }
  return;
  } 
}



// if (head_ == NULL) {
//   return;
// }
// if (length_ > 3) {
//   return;
// }
// int counter = 0;
// int overLength = 0;
// if (length_ % 3 != 0) {
//   overLength = 10;
// }
// ListNode* current = head_;
// ListNode* newHead = head_->next;
// ListNode* nextNum = NULL;
// ListNode* newStart = head_->next;
// head_ = newHead;
// while (newStart) {
//       nextNum = newStart->next->next;
//       newStart ->next->next = current;
//       current->next =nextNum->next;
//       current = nextNum;
//       newStart = current->next;
//       nextNum = current->next->next;
//       current->next = NULL;
//       newStart->next->next = current;
//     counter = 3;
//     if (overLength == 10) {
//       return;
//     }

//     return;
//   }
// }




/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  ListNode* newEnd = endPoint;
  ListNode* newStart =startPoint;
  ListNode* prevStart = startPoint->prev;
  ListNode* current = startPoint;
  ListNode* nextEnd = endPoint->next;
  while(current != nextEnd) {
    if((head_ != startPoint || tail_ != endPoint) && (current==startPoint || current==endPoint)) {
        if(current==endPoint) {
        ListNode tempNode = *current;
        current->next = tempNode.prev;
        current->prev = prevStart;
        break;
            }
      if(current == startPoint) {
        ListNode tempNode = *current;
        current->next = nextEnd;
        current->prev = tempNode.next;
      }
      current = current->prev;
    }
    else {
      ListNode tempNode = *current;
      current->prev = tempNode.next;
      current->next = tempNode.prev;
      current=current->prev;
    }
  }
  if (tail_ == endPoint) {
    tail_ = newStart;
  }
  if(head_ == startPoint) {
    head_ = newEnd;
  }
  if (nextEnd) {
    nextEnd-> prev = newStart;
  }
  if (prevStart) {
    prevStart->next = newEnd;
  }
  startPoint = newEnd;
  endPoint = newStart;
  return;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2

int rotate;
ListNode* start = head_;
ListNode* end = head_;

if (n > length_) {
  reverse();
  return;
}
if (length_ % n != 0 )  {
  rotate = length_ / n + 1;
}
else {
  rotate = length_ / n;
}
while (rotate > 0) {
  for ( int i = 0; i < n - 1 ; i++) {
    if (end->next == NULL) {
      reverse(start, end);
      return;
    }
     else {
      end = end->next;
      }
    }
    reverse(start,end);
    start = end->next;
    end = start;
    rotate--;
  }
  return;
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2

//   ListNode* result = NULL;
//   bool keepGoing = true;

//   if(first->data < second->data) {
//     result = first;
//     first = first->next;
//   } else {
//       result = second;
//     second = second->next;
//   }

//   result->prev = NULL;
//   ListNode* head = result;

//   while(keepGoing == true) {
//     if(second == NULL) {
//       result->next = first;
//       break;
//     }
//     if (first == NULL) {
//       result->next = second;
//       break;
//     }
//     if (first->data < second -> data) {
//         result->next = first;
//         first = first->next;
//     }else {
//           result->next = second;
//       second = second->next;
//     }
//     result = result->next;
//     if(first == NULL && second == NULL) {
//         keepGoing = false;
//     }
//   }

//   return head;
// }
  ListNode* result = NULL;
  bool keepGoing = true;

  
  if (first->data < second->data) {
    result = first;
    first = first->next;
  } else {
    result = second;
    second = second->next;
  }

  result->prev = NULL;
  ListNode* front = result;

  while(keepGoing == true) {
    if(second == NULL) {
      result->next = first;
      break;
    }
    if (first == NULL) {
      result->next = second;
      break;
    }
    if (second->data < first -> data) {
        result->next = second;
        second = second->next;
    }else {
          result->next = first;
      first = first->next;
    }
    result = result->next;
    if(second == NULL && first == NULL) {
        keepGoing = false;
    }
  }

  return front;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if (chainLength == 1) {
    return start;
  }
  ListNode* firstHalf = NULL;
  ListNode* secondHalf = NULL;
  ListNode* headOne = start;
  ListNode* headTwo = NULL;
  int midLength = chainLength/2;
  headTwo = split(start,midLength);


  if (chainLength % 2 == 1) {
        secondHalf = mergesort(headTwo, midLength + 1);

    firstHalf = mergesort(headOne, midLength);
  } else {
        secondHalf = mergesort(headTwo, midLength);

    firstHalf = mergesort(headOne, midLength);
  }

  return merge(firstHalf,secondHalf);
}

//    result = a;
//     result->next = mergesort(a->next, chainLength);
//   } else {
//     result = b;
//     result ->next = mergesort(b->next, chainLength);
//   }

//   return merge(firstHalf,secondHalf)
// }

