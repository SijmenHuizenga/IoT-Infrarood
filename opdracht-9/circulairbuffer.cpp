#include <Arduino.h>

#define SIZE 200

template<class T> class CirculairBuffer {

private:
    T buffer[SIZE];
    int start = 0;
    int size = 0;

    int circle(int in){
        int out = in % SIZE;
        while(out < 0)
            out += SIZE;
        return out;
    }

public:
    int empty(){
        return this->size == 0;
    }
    int length(){
        return this->size;
    }
    T get(int index){
        return this->buffer[circle(this->start + index)];
    }
    void add(T data){
        this->buffer[circle(this->start + this->size)] = data;
        this->size++;
        this->size = this->size % SIZE;
    }
    void removeLast(){
        if(empty())
            return;
        this->size--;
    }
    int full(){
        return this->size == SIZE;
    }
    void clear(){
        this->start = 0;
        this->size = 0;
    }

};



