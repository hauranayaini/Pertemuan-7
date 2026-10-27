#include <iostream>
#include "stack.h"

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(const Stack &S) {
    return S.Top == nullptr;
}

Node* alokasi(int x) {
    Node* P = new Node;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(Node* P) {
    delete P;
}

void push(Stack &S, int x) {
    Node* P = alokasi(x);
    if (P != nullptr) {
        P->next = S.Top;
        S.Top = P;
    }
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    Node* P = S.Top;
    x = P->info;
    S.Top = P->next;
    dealokasi(P);
    return true;
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        std::cout << "Stack Kosong\n";
        return;
    }
    std::cout << "TOP:";
    Node* P = S.Top;
    while (P != nullptr) {
        std::cout << " " << P->info;
        P = P->next;
    }
    std::cout << "\n";
}

void pushAscending(Stack &S, int x) {
    Stack SBantu;
    createStack(SBantu);
    int temp;

    // Pindahkan elemen yang lebih besar dari x ke stack bantu
    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, temp);
        push(SBantu, temp);
    }

    // Masukkan data baru ke stack utama
    push(S, x);

    // Kembalikan data dari stack bantu ke stack utama
    while (!isEmpty(SBantu)) {
        pop(SBantu, temp);
        push(S, temp);
    }
}

void clearStack(Stack &S) {
    int dummy;
    while (!isEmpty(S)) {
        pop(S, dummy);
    }
    S.Top = nullptr;
}
