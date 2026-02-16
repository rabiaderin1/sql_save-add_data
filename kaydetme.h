#ifndef KAYDETME_H
#define KAYDETME_H

#include <sqlite3.h>

private:
// Variable declarations
extern sqlite3* veritabani;
extern sqlite3_stmt* listele_stmt;

public:
// Function prototypes
void dosyaAc();
void dosyaYazdir();
void dosyaListele();
int sqliteAc();  // Optional SQLite open function

#endif
