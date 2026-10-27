#include <iostream>
#include "stack.h"

int main() {
    Stack S;
    createStack(S);
    int pilihan, val;

    do {
        std::cout << "\n=== MENU SOAL 1: STACK ARRAY ===\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Tampilkan (printInfo)\n";
        std::cout << "4. Balik Stack (balikStack)\n";
        std::cout << "5. Jalankan Contoh & Uji Tambahan Modul\n";
        std::cout << "6. Keluar\n";
        std::cout << "Pilihan: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                std::cout << "Masukkan angka: ";
                std::cin >> val;
                push(S, val);
                break;
            case 2:
                if (pop(S, val)) {
                    std::cout << "Nilai yang berhasil di-Pop: " << val << "\n";
                }
                break;
            case 3:
                printInfo(S);
                break;
            case 4:
                balikStack(S);
                std::cout << "Stack berhasil dibalik.\n";
                break;
            case 5: {
                std::cout << "\n--- Menjalankan Uji Sesuai Contoh Modul ---\n";
                Stack testS;
                createStack(testS);
                
                push(testS, 7);
                push(testS, 12);
                push(testS, 5);
                pop(testS, val); std::cout << "Pop berhasil, nilai: " << val << "\n"; // Keluar 5
                push(testS, 9);
                push(testS, 3);
                pop(testS, val); std::cout << "Pop berhasil, nilai: " << val << "\n"; // Keluar 3
                push(testS, 15);
                
                std::cout << "Kondisi sesudah urutan operasi di atas:\n";
                printInfo(testS); // Output yang benar -> TOP: 15 9 12 7
                
                balikStack(testS);
                std::cout << "Sesudah balikStack:\n";
                printInfo(testS); // Output yang benar -> TOP: 7 12 9 15

                std::cout << "\n--- Menjalankan Uji Tambahan Modul ---\n";
                std::cout << "1. Uji Pop pada stack kosong:\n";
                Stack emptyS;
                createStack(emptyS);
                pop(emptyS, val);

                std::cout << "2. Uji Push hingga elemen ke-21:\n";
                Stack fullS;
                createStack(fullS);
                for (int i = 1; i <= 20; i++) {
                    push(fullS, i);
                }
                push(fullS, 21); // Harus memicu pesan ditolak yang jelas
                break;
            }
            case 6:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak tersedia!\n";
        }
    } while (pilihan != 6);

    return 0;
}
