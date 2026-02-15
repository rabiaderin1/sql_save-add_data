#include "kaydetme.h"
#include <iostream>
#include <fstream>
#include <string>

// Variable definitions
sqlite3* veritabani = nullptr;
sqlite3_stmt* listele_stmt = nullptr;

// Function implementations
void dosyaAc() {
    std::ifstream dosya("veri.txt");
    if (dosya.is_open()) {
        std::string satir;
        while (std::getline(dosya, satir)) {
            std::cout << satir << std::endl;
        }
        dosya.close();
    } else {
        std::cout << "Dosya acilamadi." << std::endl;
    }
}

void dosyaYazdir() {
    std::ofstream dosya("veri.txt", std::ios::app);
    if (dosya.is_open()) {
        dosya << "Yeni kayit\n";
        dosya.close();
        std::cout << "Kayit yazildi." << std::endl;
    } else {
        std::cout << "Dosya yazilamadi." << std::endl;
    }
}

void dosyaListele() {
    std::ifstream dosya("veri.txt");
    if (dosya.is_open()) {
        std::string satir;
        std::cout << "Dosya icerigi:" << std::endl;
        while (std::getline(dosya, satir)) {
            std::cout << satir << std::endl;
        }
        dosya.close();
    } else {
        std::cout << "Dosya listelenemedi." << std::endl;
    }
}

int sqliteAc() {
    return sqlite3_open("veritabani.db", &veritabani);
}