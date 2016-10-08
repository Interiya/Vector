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
        delete array;
        array = _array;
    }
public:
    Vector(){
        array = (T*)(operator new (0));
    }
    Vector(unsigned int _sizeArray): Vector(_sizeArray, T()){}
    T &operator[](int i){
        try {
            if (i < 0 && i > sizeArray) throw(Exeption());
            return array[i];
        }
        catch (Exeption exeption){
            exeption.why();
        }
    }
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
    T &front(){
        return array[0];
    }
    T &back(){
        return array[sizeArray - 1];
    }
    class Exeption{
    public:
        void why(){
        cout << "выход за границу" << endl;
        }
    };
};





#endif //VECTOR_VECTOR_H
