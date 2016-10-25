
#include "QS.h"



QS::QS() {
    _size = 0;
}

void QS::sortAll() {
    cout << "sortAll()" << endl;
}

int QS::medianOfThree(int left, int right) {
    cout << "medianOfThree(left: " << left << ", right: " << right << ")" << endl;
    //fail cases
    if (_A == NULL)
    {
        return -1;
    }
    if (left < 0 || right > _size - 1)
    {
        return -1;
    }
    if (left >= right)
    {
        return -1;
    }
    int middle = (left + right) / 2;
    int temp;
    //bubble sort three indicies
    if (_A[left] > _A[middle])
    {
        temp = _A[middle];
        _A[middle] = _A[left];
        _A[left] = temp;
    }
    if (_A[middle] > _A[right])
    {
        temp = _A[right];
        _A[right] = _A[middle];
        _A[middle] = temp;
    }
    if (_A[left] > _A[middle])
    {
        temp = _A[middle];
        _A[middle] = _A[left];
        _A[left] = temp;
    }
    
    return middle;
}

//---------------------------------------------------
//---------------------------------------------------

int QS::partition(int left, int right, int pivotIndex) {
    cout << "partition(left: " << left << ", right: " << right << ", pivotIndex: " << pivotIndex << ")" << endl;
    //check fail cases
    if (_A == NULL)
    {
        return -1;
    }
    if (left < 0 || right > _size - 1)
    {
        return -1;
    }
    if (left > pivotIndex || right < pivotIndex)
    {
        return -1;
    }
    if (left >= right)
    {
        return -1;
    }
    
    int loIndex = left; int hiIndex = right;
    int temp;
    int pivot = _A[pivotIndex];
    //place pivot
    temp = _A[loIndex];
    _A[loIndex] = _A[pivotIndex];
    _A[pivotIndex] = temp;
    loIndex++;
    //sort-check lo values
    bool terminus_sort = false;
    while(!terminus_sort)
    {
        for (int i = 0; i < _size; i++)
        {
            cout << _A[i] << endl;
        }
        cout << endl << endl;
        bool loFound = false;
        bool hiFound = false;
        while (!(loFound && hiFound))
        {
            if (_A[loIndex] <= pivot) loIndex++;
            else loFound = true;
            if (_A[hiIndex] >  pivot) hiIndex--;
            else hiFound = true;
        }
        //if hiIndex < loIndex, swap hiIndex and the pivot
        //else swap _A[hi] with _A[lo], increment loIndex and decrement hiIndex
        if (hiIndex < loIndex)
        {
            //
            temp = _A[hiIndex];
            _A[hiIndex] = pivot;
            _A[left] = temp;
            terminus_sort = true;
            //swap _A[hiIndex] with the pivot
        }
        else
        {
            //
            temp = _A[hiIndex];
            _A[hiIndex] = _A[loIndex];
            _A[loIndex] = temp;
            hiIndex--;
            loIndex++;
            //swap _A[hi] with _A[lo], increment loIndex and decrement hiIndex
        }
    }
    
    return hiIndex;
}

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
    _size = 0;
    return;
}




