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
    typedef T* iterator;
    void outOfRangeInt(int i){
        try {
            if (i < 0 || i > sizeArray) throw (Exeption());
        } catch (Exeption exeption){
            exeption.why();
        }
    }
    void outOfRangeIterator(iterator i){
        try {
            if (i < begin() || i >= end()) throw (Exeption());
        } catch (Exeption exeption){
            exeption.why();
        }
    }
    Vector(){
        array = (T*)(operator new (0));
    }
    Vector(unsigned int _sizeArray): Vector(_sizeArray, T()){}
    T &operator[](int i){
        outOfRangeInt(i);
        return array[i];
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
    iterator begin(){
        return array;
    }
    iterator end(){
        return begin() + sizeArray;
    }
    void insert(iterator i, const T &data){
        outOfRangeIterator(i);
        if (sizeArray == capacityArray) reserve(2 * capacityArray);
        for (iterator j = end(); j != i + 1; ++j) {
            *j = *(j - 1);
        }
        *(i+1) = data;
        sizeArray++;
    }
    void erase(iterator i){
        outOfRangeIterator(i);
        (*i).~T();
        for (iterator j = i; j != end() - 1; ++j) {
            *j = *(j + 1);
        }
        (*end() - 1).~T();
        sizeArray--;
    }
    void arase(iterator i, iterator j){
        outOfRangeIterator(i);
        outOfRangeIterator(j);
        if (i == j) erase(i);
        for (iterator k = i; k != j + 1 ; ++k) {
            (*k).~T();
        }
        iterator end = end();
        iterator _j = j + 1;
        for (iterator k = i; j+1 != end() ; ++k, j++) {
            *i = *(j+1);
        }
        sizeArray = sizeArray - ((int)(array - j) - (int)(array - i)) - 1;
        for (_j; _j != end ; ++_j) {
            (*_j).~T();
        }
    }
    class Exeption{
    public:
        void why(){
        cout << "выход за границу" << endl;
        }
    };
};


#endif //VECTOR_VECTOR_H
