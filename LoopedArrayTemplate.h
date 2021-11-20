//
// Created by Alex Denisov on 20.11.2021.
//

#ifndef DYNAMICARRAYLIB_LOOPEDARRAYTEMPLATE_H
#define DYNAMICARRAYLIB_LOOPEDARRAYTEMPLATE_H

#include "LoopedArray.h"

template<typename T>
LoopedArray<T>::LoopedArray(int buffer_size) {
    _memory_start_ptr = (T*) malloc(sizeof(T) * buffer_size);
    _memory_end_ptr = _memory_start_ptr + buffer_size - 1;
    _first_ptr = NULL;
    _last_ptr  = NULL;
    _capacity = buffer_size;
    _size = 0;
}

template<typename T>
LoopedArray<T>::~LoopedArray() {
    free(_memory_start_ptr);
}

template<typename T>
T& LoopedArray<T>::operator[](int position) {
    if(_first_ptr && position >= 0 && _first_ptr + position <  _last_ptr + 1) {
        return _first_ptr[position];
    }
    throw;
}

template<typename T>
bool LoopedArray<T>::insert(T value, int position) {
    if (_last_ptr < _memory_end_ptr && position >= 0 and _first_ptr + position < _last_ptr + 1) {
        _last_ptr++;
        for (int *i = _last_ptr; i >= _first_ptr+position; i--) {
            *(i + 1) = *i;
        }
        _first_ptr[position] = value;
        return true;
    }
    return false;
}

template<typename T>
bool LoopedArray<T>::append_first(T value) {
    if(_first_ptr && _last_ptr){
        if(_first_ptr == _memory_start_ptr) {
            return false;
        }
        _first_ptr--;
        *_first_ptr = value;
        return true;
    } else {
        _init_list();
        *_first_ptr = value;
        return true;
    }
}

template<typename T>
bool LoopedArray<T>::append_last(T value) {
    if(_first_ptr && _last_ptr) {
        if(_last_ptr == _memory_end_ptr) {
            return false;
        }
        _last_ptr++;
        *_last_ptr = value;
        return true;
    } else {
        _init_list();
        *_last_ptr = value;
        return true;
    }
}

template<typename T>
int LoopedArray<T>::capacity() {
    return _capacity;
}

template<typename T>
int LoopedArray<T>::size() {
    if(_first_ptr && _last_ptr){
        return (_last_ptr - _first_ptr) + 1;
    }
    return 0;
}

template<typename T>
void LoopedArray<T>::_init_list() {
    _first_ptr = _memory_start_ptr + (_capacity / 2);
    _last_ptr = _first_ptr;
}

#endif //DYNAMICARRAYLIB_LOOPEDARRAYTEMPLATE_H
