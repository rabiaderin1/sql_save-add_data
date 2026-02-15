#include "kaydetme.h" // kaydetme.h already includes sqlite3.h
#include <iostream>
#include <string>

using namespace std;

kaydetme::kaydetme() {
  int rc = sqlite3_open("veritabani.db", &veritabani);
  if (rc) {
    cerr << "Veritabanı açılamadı: " << sqlite3_errmsg(veritabani) << endl;
  } else {
    cout << "Veritabanı başarıyla açıldı." << endl;
    // Create table if not exists
    char *hata = 0;
    const char *sql =
        "CREATE TABLE IF NOT EXISTS ogrenciler (id INTEGER PRIMARY KEY "
        "AUTOINCREMENT, adsoyad TEXT, numara INTEGER);";
    rc = sqlite3_exec(veritabani, sql, 0, 0, &hata);
    if (rc != SQLITE_OK) {
      cerr << "SQL hatası: " << hata << endl;
      sqlite3_free(hata);
    }
  }
}

kaydetme::~kaydetme() { sqlite3_close(veritabani); }

void kaydetme::dosyaAc() {
  // This function originally acted as an input/insert loop.
  // Keeping it simple for now, asking only once.
  cout << "Ad soyad giriniz: ";
  cin.ignore();            // Clear buffer if needed
  getline(cin, veri_isim); // Allow spaces in name

  cout << "Numara giriniz: ";
  cin >> veri_numara;

  string kaydet = "INSERT INTO ogrenciler (adsoyad, numara) VALUES ('" +
                  veri_isim + "', " + to_string(veri_numara) + ");";

  char *hata = 0;
  int ekleme_ok = sqlite3_exec(veritabani, kaydet.c_str(), NULL, 0, &hata);

  if (ekleme_ok != SQLITE_OK) {
    cerr << "Ekleme Hatasi: " << hata << endl;
    sqlite3_free(hata);
  } else {
    cout << "Veri basariyla eklendi!" << endl;
  }
}

void kaydetme::dosyaYazdir() {
  // Seems redundant with dosyaAc based on original code, but keeping it as
  // requested. Maybe this was intended to be "Print to file" or "Show inputs"?
  // For now, I'll make it another insertion point to match previous logic,
  // or arguably we could just make it empty if it was a duplicate copy-paste.
  // Let's implement it as another add for now.

  dosyaAc(); // Re-use logic
}

void kaydetme::dosyaListele() {
  string selectSQL = "SELECT * FROM ogrenciler;";

  if (sqlite3_prepare_v2(veritabani, selectSQL.c_str(), -1, &listele_stmt,
                         NULL) != SQLITE_OK) {
    cerr << "Sorgu hazirlanamadi: " << sqlite3_errmsg(veritabani) << endl;
  } else {
    cout << "Guncel Liste:" << endl;

    while (sqlite3_step(listele_stmt) == SQLITE_ROW) {
      int kimlik = sqlite3_column_int(listele_stmt, 0);
      const unsigned char *isim = sqlite3_column_text(listele_stmt, 1);
      int numara = sqlite3_column_int(listele_stmt, 2);

      string isimSTR = reinterpret_cast<const char *>(isim);

      if (isimSTR == "Tuğçe Özdemir") {
        cout << "veri bulundu" << endl;
      }

      cout << kimlik << " " << isimSTR << " " << numara << endl;
    }
    sqlite3_finalize(listele_stmt);
  }
}