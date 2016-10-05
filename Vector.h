//
// Created by Esteno on 04.10.2016.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H


#include <new>
using namespace std;

template<typename T>
class Vector{
    T * array;
    unsigned int sizeArray = 0;
    unsigned int capacityArray = 0;

    void reserve(unsigned int _capacityArray){
        if (_capacityArray == 0) capacityArray = 2;
        else capacityArray = _capacityArray;
        T *_array = (T *) (operator new(sizeof(T) * capacityArray));
        for (int i = 0; i < sizeArray; ++i) new(_array + i)T(array[i]);
        for (int j = 0; j < sizeArray; ++j) array[j].~T();
        array = _array;
    }
public:
    Vector(){
        array = (T*)(operator new (0));
    }
    Vector(unsigned int _sizeArray): Vector(_sizeArray, T()){}

    Vector(unsigned int _sizeArray, const T &data){
        sizeArray = _sizeArray;
        capacityArray = sizeArray;
        array = (T*)(operator new (sizeof(T) * capacityArray));
        for (int i = 0; i < sizeArray; ++i) new (array + i)T(data);
    }
    void pushBack(const T& data){
        if (sizeArray == capacityArray) reserve(2 * capacityArray);
        new (array + sizeArray)T(data);
        sizeArray++;
    }
};





#endif //VECTOR_VECTOR_H
