// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T arr[50];
    int temp;
 public:
    TStack(): temp(-1) {}
    bool isEmpty() { return temp == -1; }
    bool isFull() { return temp == size-1; }
    void pop() {
        if (!isEmpty()) --temp;
    }
    T get() { return arr[temp]; }
    void push(T data) {
        if (!isFull())
           arr[++temp] = data;
        else 
        throw "Full!";
    }
};
#endif  // INCLUDE_TSTACK_H_
