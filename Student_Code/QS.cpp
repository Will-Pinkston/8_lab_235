
#include "QS.h"


//////
QS::QS() {
    _size = 0;
}
//////
QS::~QS() {
    clear();
}
//////
void sortItR(int left, int right, QS* myQS) {
    if (left == right)
    {
        return;
    }
    if ((right - left) == 1)
    {
        if (myQS->_A[left] > myQS->_A[right])
        {
            int temp = myQS->_A[right];
            myQS->_A[right] = myQS->_A[left];
            myQS->_A[left] = temp;
        }
        return;
    }
    if ((right - left) == 2)
    {
        myQS->medianOfThree(left, right);
        return;
    }
    int pivot = myQS->medianOfThree(left, right);
    int partitionMid = myQS->partition(left, right, pivot);
    sortItR(left, partitionMid - 1, myQS);
    sortItR(partitionMid + 1, right, myQS);
    return;
}
//////
void QS::sortAll() {
//    cout << "sortAll()" << endl;
    if (_A == NULL) return;
    int left = 0;
    int right = _size - 1;
    sortItR(left, right, this);
}
//////
int QS::medianOfThree(int left, int right) {
//    cout << "medianOfThree(left: " << left << ", right: " << right << ")" << endl;
    //fail cases
    if (_A == NULL) return -1;
    if (left < 0 || right > _size - 1) return -1;
    if (left >= right) return -1;
    
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
//////
int QS::partition(int left, int right, int pivotIndex) {
//    cout << "partition(left: " << left << ", right: " << right << ", pivotIndex: " << pivotIndex << ")" << endl;
    //check fail cases
    if (_A == NULL) return -1;
    if (left < 0 || right > _size - 1) return -1;
    if (left > pivotIndex || right < pivotIndex) return -1;
    if (left >= right) return -1;
    
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
        bool loFound = false;
        bool hiFound = false;
        while (!(loFound && hiFound))
        {
            if (_A[loIndex] <= pivot) loIndex++;
            else loFound = true;
            if (_A[hiIndex] >  pivot) hiIndex--;
            else hiFound = true;
        }
        if (hiIndex < loIndex)
        {
            temp = _A[hiIndex];
            _A[hiIndex] = pivot;
            _A[left] = temp;
            terminus_sort = true;
        }
        else
        {
            temp = _A[hiIndex];
            _A[hiIndex] = _A[loIndex];
            _A[loIndex] = temp;
            hiIndex--;
            loIndex++;
        }
    }
    
    return hiIndex;
}
//////
string QS::getArray() {
//    cout << "getArray()" << endl;
    
    stringstream ss;
    for (int i = 0; i < _size; i++)
    {
        ss << _A[i];
        if (i != _size - 1) ss << ",";
    }
    return ss.str();
}
//////
int QS::getSize() {
//    cout << "getSize()" << endl;
    return _size;
}
//////
void QS::addToArray(int value) {
//    cout << "addToArray(value: " << value << ")" << endl;
    if (_size < _capacity)
    {
        _A[_size] = value;
        _size++;
    }
    return;
}
//////
bool QS::createArray(int capacity) {
//    cout << "createArray(capacity: " << capacity << ")" << endl;
    if (capacity <= 0) return false;
    
    else
    {
        if (_A != NULL)
        {
            delete[] _A;
        }
        _A = new int[capacity];
        for (int i = 0; i < capacity; i++)
        {
            _A[i] = 0;
        }
        _capacity = capacity;
        return true;
    }
}
//////
void QS::clear() {
//    cout << "clear()" << endl;
    delete[] _A;
    _A = NULL;
    _size = 0;
    return;
}
//////



