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
    int sizeArray = 0;
    int capacityArray = 0;

    void reserve(){
        if (capacityArray == 0) capacityArray = 2;
        else capacityArray = 2 * capacityArray;
        T *_array = (T *) (operator new(sizeof(T) * capacityArray));
        for (int i = 0; i < sizeArray; ++i) new(_array + i)T(array[i]);
        for (int j = 0; j < sizeArray; ++j) array[j].~T();
        array = _array;
    }
public:
    Vector(){
        array = (T*)(operator new (0));
    }
    Vector(int _sizeArray): Vector(_sizeArray, T()){}

    Vector(int _sizeArray, const T &data){
        sizeArray = _sizeArray;
        capacityArray = 2 * sizeArray;
        array = (T*)(operator new (sizeof(T) * capacityArray));
        for (int i = 0; i < sizeArray; ++i) new (array + i)T(data);
    }
    void pushBack(const T& data){
        if (sizeArray == capacityArray) reserve();
        new (array + sizeArray)T(data);
        sizeArray++;
    }
};





#endif //VECTOR_VECTOR_H
