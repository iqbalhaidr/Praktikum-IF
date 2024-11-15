/* File : prioqueue.h */
/* Definisi ADT Priority Queue terurut mengecil berdasarkan nilai elemen */

#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include "boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef int ElType;
typedef struct {
	ElType buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} PrioQueue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(pq) (pq).idxHead
#define IDX_TAIL(pq) (pq).idxTail
#define     HEAD(pq) (pq).buffer[(pq).idxHead]
#define     TAIL(pq) (pq).buffer[(pq).idxTail]

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq);
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq);
/* Mengirim true jika pq kosong: lihat definisi di atas */
boolean isFull(PrioQueue pq);
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

int length(PrioQueue pq);
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val);
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */

void dequeue(PrioQueue *pq, ElType *val);
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */

/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq);
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */


#endif