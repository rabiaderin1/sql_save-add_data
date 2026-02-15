// kaydet

#include "kaydetme.h"
#include <iostream>

int main() {
    // Open SQLite database (optional)
    if (sqliteAc() != SQLITE_OK) {
        std::cout << "Veritabani acilamadi." << std::endl;
        return 1;
    }

    // Call functions
    dosyaAc();
    dosyaYazdir();
    dosyaListele();

    // SQLite cleanup
    if (listele_stmt) sqlite3_finalize(listele_stmt);
    if (veritabani) sqlite3_close(veritabani);

    return 0;
}
