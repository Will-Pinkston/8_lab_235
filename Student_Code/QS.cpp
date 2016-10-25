
#include "QS.h"



QS::QS() {
    _size = 0;
}

void QS::sortAll() {
    cout << "sortAll()" << endl;
}

int QS::medianOfThree(int left, int right) {
    cout << "medianOfThree(left: " << left << ", right: " << right << ")" << endl;
    return -1;
}

int QS::partition(int left, int right, int pivotIndex) {
    cout << "partition(left: " << left << ", right: " << right << ", pivotIndex: " << pivotIndex << ")" << endl;
    return -1;
}

//---------------------------------------------------
//---------------------------------------------------

string QS::getArray() {
    cout << "getArray()" << endl;
    
    stringstream ss;
    for (int i = 0; i < _size; i++)
    {
        ss << _A[i];
        if (i != _size - 1)
        {
            ss << ",";
        }
    }
    
    /*
     * Produces a comma delimited string representation of the array. For example: if my array
     * looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
     * with no trailing comma.  The number of cells included equals the number of values added.
     * Do not include the entire array if the array has yet to be filled.
     *
     * Returns an empty string, if the array is NULL or empty.
     *
     * @return
     *		the string representation of the current array
     */
    return ss.str();
}

int QS::getSize() {
    cout << "getSize()" << endl;
    return _size;
}

void QS::addToArray(int value) {
    cout << "addToArray(value: " << value << ")" << endl;
    if (_size < _capacity)
    {
        _A[_size] = value;
        _size++;
    }
    return;
}

bool QS::createArray(int capacity) {
    cout << "createArray(capacity: " << capacity << ")" << endl;
    if (capacity <= 0) return false;
    
    else
    {
        if (_A != NULL)
        {
            //delete current array
            delete[] _A;
        }
        //create new aray
        _A = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            _A[i] = 0; //initialize all values of the new array
        }
        _capacity = capacity;
        return true;
    }
}

void QS::clear() {
    cout << "clear()" << endl;
    delete[] _A; //are the brackets important? should it be "delete[] _A;" ?
    _A = NULL;
    
    return;
}




