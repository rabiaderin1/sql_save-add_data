// kaydet
#ifndef KAYDETME_H
#define KAYDETME_H

#include "sqlite3.h" // Use local header
#include <iostream>
#include <string>

using namespace std;

class kaydetme {
private:
  sqlite3 *veritabani;
  sqlite3_stmt *listele_stmt;
  std::string veri_isim;
  int veri_numara;

public:
  kaydetme();  // Constructor
  ~kaydetme(); // Destructor
  void dosyaAc();
  void dosyaYazdir();
  void dosyaListele();
};

#endif
