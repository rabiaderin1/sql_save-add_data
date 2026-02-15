// kaydet

#include "kaydetme.h"
#include <iostream>


using namespace std;

int main() {
  kaydetme program;
  int secim;

  while (true) {
    cout << "\n--- OGRENCI KAYIT SISTEMI ---\n";
    cout << "1. Ogrenci Ekle\n";
    cout << "2. Listele\n";
    cout << "3. Cikis\n";
    cout << "Seciminiz: ";
    cin >> secim;

    if (secim == 1) {
      program.dosyaAc();
    } else if (secim == 2) {
      program.dosyaListele();
    } else if (secim == 3) {
      cout << "Cikis yapiliyor..." << endl;
      break;
    } else {
      cout << "Gecersiz secim! Tekrar deneyin." << endl;
      // Clear input buffer to avoid infinite loops on invalid input (like
      // characters)
      cin.clear();
      cin.ignore(10000, '\n');
    }
  }

  return 0;
}
