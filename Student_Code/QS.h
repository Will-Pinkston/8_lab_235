#pragma once

#include <sstream>
#include "QSInterface.h"

class QS : public QSInterface {
public:
    int* _A = NULL;
    int _size; //how many elements are currently in the array
    int _capacity; //the maximum size of the dynamically created aray
    
    QS();
    ~QS();
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    string getArray();
    int getSize();
    void addToArray(int value);
    bool createArray(int capacity);
    void clear();
};
