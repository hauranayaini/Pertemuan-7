#include <iostream>
#include "stack.h"

int main() {
    Stack S;
    createStack(S);
    int pilihan, val;

    do {
        std::cout << "\n=== MENU SOAL 2: STACK POINTER POINTER ===\n";
        std::cout << "1. Tambah Terurut (pushAscending)\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Tampilkan (printInfo)\n";
        std::cout << "4. Jalankan Contoh & Uji Tambahan Modul\n";
        std::cout << "5. Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan angka: ";
                std::cin >> val;
                pushAscending(S, val);
                break;
            case 2:
                if (pop(S, val)) {
                    std::cout << "Nilai keluar: " << val << "\n";
                } else {
                    std::cout << "Pop ditolak: Stack kosong!\n";
                }
                break;
            case 3:
                printInfo(S);
                break;
            case 4: {
                std::cout << "\n--- Menjalankan Uji Sesuai Contoh Modul ---\n";
                Stack testS;
                createStack(testS);

                std::cout << "Masukkan secara berurutan melalui pushAscending: 3, 7, 2, 7, 5\n";
                pushAscending(testS, 3);
                pushAscending(testS, 7);
                pushAscending(testS, 2);
                pushAscending(testS, 7);
                pushAscending(testS, 5);
                std::cout << "Sesudah memasukkan 3, 7, 2, 7, 5:\n";
                printInfo(testS); // Output -> TOP: 7 7 5 3 2

                pop(testS, val);
                std::cout << "Sesudah satu Pop (nilai keluar = " << val << "):\n";
                printInfo(testS); // Output -> TOP: 7 5 3 2

                std::cout << "Sesudah memasukkan 6 melalui pushAscending:\n";
                pushAscending(testS, 6);
                printInfo(testS); // Output -> TOP: 7 6 5 3 2

                std::cout << "\n--- Menjalankan Uji Tambahan Modul ---\n";
                Stack testBaru;
                createStack(testBaru);
                std::cout << "Gunakan masukan baru: -2, 0, -2\n";
                pushAscending(testBaru, -2);
                pushAscending(testBaru, 0);
                pushAscending(testBaru, -2);
                printInfo(testBaru); // Output -> TOP: 0 -2 -2

                std::cout << "Lakukan Pop hingga kosong:\n";
                while (!isEmpty(testBaru)) {
                    pop(testBaru, val);
                }
                printInfo(testBaru); // Output -> Stack Kosong

                std::cout << "Mencoba satu Pop lagi pada stack kosong:\n";
                if (!pop(testBaru, val)) {
                    std::cout << "Pop gagal karena keadaan stack kosong.\n";
                }

                clearStack(testS);
                clearStack(testBaru);
                break;
            }
            case 5:
                clearStack(S);
                std::cout << "Memori dibersihkan. Keluar program.\n";
                break;
            default:
                std::cout << "Pilihan tidak tersedia!\n";
        }
    } while (pilihan != 5);

    return 0;
}
