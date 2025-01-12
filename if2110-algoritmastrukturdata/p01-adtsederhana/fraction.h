/* File: fraction.h */
/* Tanggal: 21 September 2024 */
/* Definisi ADT FRACTION */

#ifndef FRACTION_H
#define FRACTION_H

#include "boolean.h"

/* *** Definisi TYPE FRACTION *** */
typedef struct {
    int N; /* Pembilang */
    int D; /* Penyebut */
} FRACTION;

/* *** Notasi Akses: selektor FRACTION *** */
#define Numerator(F) (F).N
#define Denominator(F) (F).D

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsFRACTIONValid(int N, int D);
/* Mengirim TRUE jika pecahan valid */

/* *** Konstruktor: Membentuk FRACTION F dari komponen-komponennya *** */
void CreateFRACTION(FRACTION *F, int N, int R);
/* Membentuk sebuah FRACTION yang valid */
/* Prekondisi : N, R valid */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void ReadFRACTION(FRACTION *F);
/**
 * I.S. : F tidak terdefinisi
 * F.S. : F terdefinisi dan merupakan FRACTION yang valid
 * Proses : Mengulangi membaca komponen N, R sehingga membentuk F
 *  - Pembacaan dilakukan dengan mengetikkan komponen N, R dalam
 *    1 baris, dipisah spasi, diakhiri enter.
 *  - Jika FRACTION tidak valid, maka berikan pesan: "FRACTION tidak valid"
 *    dengan newline, pembacaan diulangi hingga didapat FRACTION yang valid.
 */

void WriteFRACTION(FRACTION F);
/**
 * I.S. : F sembarang
 * F.S. : Nilai F ditulis dengan format "N/R"
 * Proses : Penulisan tanpa spasi, enter, atau karakter lain di depan,
 * belakang, atau di antaranya
 * NOTE: hasil dalam bentuk paling sederhana
 */

/* ***************************************************************** */
/* KELOMPOK OPERASI DASAR TERHADAP TYPE                              */
/* ***************************************************************** */
/* NOTE: untuk hasil FRACTION = 0, maka kembalikan 0/1 */

FRACTION AddFRACTION(FRACTION F1, FRACTION F2);
/* Mengirim hasil penjumlahan F1 + F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2);
/* Mengirim hasil pengurangan F1 - F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2);
/* Mengirim hasil perkalian F1 * F2 */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2);
/* Mengirim hasil pembagian F1 / F2 */
/* Prekondisi: F2 tidak nol */
/* NOTE: hasil dalam bentuk paling sederhana */

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1);
/* Mengirim hasil perkalian n * F1 */
/* NOTE: hasil dalam bentuk paling sederhana */

/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */
FRACTION SimplifyFRACTION(FRACTION F);
/* Mengembalikan FRACTION dalam bentuk sederhana */
/* NOTE: pastikan hanya numerator yang memiliki nilai negatif */

float ToDecimal(FRACTION F);
/* Mengonversi FRACTION ke bentuk desimal */

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

#endif