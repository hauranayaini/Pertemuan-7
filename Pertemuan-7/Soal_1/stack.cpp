#include <iostream>
#include "stack.h"

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(const Stack &S) {
    return S.Top == 0;
}

bool isFull(const Stack &S) {
    return S.Top == 20;
}

bool push(Stack &S, int x) {
    if (isFull(S)) {
        std::cout << "Push ditolak: Stack penuh (Elemen ke-21 tidak dapat masuk)!\n";
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        std::cout << "Pop ditolak: Stack kosong!\n";
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

void printInfo(const Stack &S) {
    if (isEmpty(S)) {
        std::cout << "Stack Kosong\n";
        return;
    }
    std::cout << "TOP:";
    for (int i = S.Top; i >= 1; i--) {
        std::cout << " " << S.info[i];
    }
    std::cout << "\n";
}

void balikStack(Stack &S) {
    if (isEmpty(S)) return;

    Stack SBantu;
    createStack(SBantu);
    int n = S.Top;

    // Proses membalik stack dengan tepat 1 stack bantu menggunakan operasi Push dan Pop
    for (int i = 1; i < n; i++) {
        int val;
        pop(S, val);

        for (int j = 1; j <= n - i; j++) {
            int temp;
            pop(S, temp);
            push(SBantu, temp);
        }

        push(S, val);

        while (!isEmpty(SBantu)) {
            int temp;
            pop(SBantu, temp);
            push(S, temp);
        }
    }
}
