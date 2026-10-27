#ifndef STACK_H
#define STACK_H

struct Stack {
    int info[21]; // Perbaikan: Tambahkan [21] sesuai ketentuan modul
    int Top;
};

void createStack(Stack &S);
bool isEmpty(const Stack &S);
bool isFull(const Stack &S);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(const Stack &S);
void balikStack(Stack &S);

#endif
