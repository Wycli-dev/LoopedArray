//
// Created by Alex Denisov on 20.11.2021.
//

#ifndef DYNAMICARRAYLIB_LOOPEDARRAY_H
#define DYNAMICARRAYLIB_LOOPEDARRAY_H

template<typename T>
class LoopedArray {
private:
    T* _memory_start_ptr;
    T* _memory_end_ptr;
    T* _first_ptr;
    T* _last_ptr;

    int _capacity;
    int _size;

    void _init_list();

public:
    LoopedArray(int buffer_size);
    ~LoopedArray();
    T& operator[](int position);
    bool insert(T value, int position);
    bool append_first(T value);
    bool append_last(T value);

    int capacity();
    int size();
};

#endif //DYNAMICARRAYLIB_LOOPEDARRAY_H
