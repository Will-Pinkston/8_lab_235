
#include "QS.h"



QS::QS(){}

void QS::sortAll() {}

int QS::medianOfThree(int left, int right) {
    return -1;
}

int QS::partition(int left, int right, int pivotIndex) {
    return -1;
}

string QS::getArray() {
    return "";
}

int QS::getSize() {
    return -1;
}

void QS::addToArray(int value) {
    return;
}

bool QS::createArray(int capacity) {
    if (capacity <= 0) return false;
    
    if (_A != NULL)
    {
        //delete current array
        delete _A;
    }
    
    //create new aray
    _A = new int [capacity];
    
    
    /*
     * Dynamically allocates an array with the given capacity.
     * If a previous array had been allocated, delete the previous array.
     * Returns false if the given capacity is non-positive, true otherwise.
     *
     * @param
     *		size of array
     * @return
     *		true if the array was created, false otherwise
     */
    return false;
}

void QS::clear() {
    delete[] _A; //are the brackets important?
    _A = NULL;
    
    return;
}




