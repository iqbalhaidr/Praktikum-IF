/* File : bintree.h */
/* ADT pohon biner */
/* Representasi Address dengan pointer */
/* ElType adalah integer */

#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"

/* Selektor */
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef int ElType;
typedef struct treeNode* Address;
typedef struct treeNode {
    ElType info;
    Address left;
    Address right;
} TreeNode;

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef Address BinTree;

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree);
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika
   alokasi berhasil Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree* p);
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi
   berhasil
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode(Address p);
/* I.S. p terdefinisi
   F.S. p dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty(BinTree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt(BinTree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft(BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft:
   hanya mempunyai subpohon kiri */

boolean isUnerRight(BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright:
   hanya mempunyai subpohon kanan */

boolean isBinary(BinTree p);
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner:
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan
   pohon kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup
   (). Pohon kosong ditandai dengan (). Tidak ada tambahan karakter apa pun di
   depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan
   subpohon kanan (C()()) */

void printInorder(BinTree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon
   kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan
   subpohon kanan (()C()) */

void printPostorder(BinTree p);
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan,
   dan akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan
   subpohon kanan (()()C) */

void printTree(BinTree p, int h);
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini
jika diperlukan
*/

boolean isEqual(BinTree p1, BinTree p2);
/* I.S. p1 dan p2 terdefinisi */
/* F.S. Mengirimkan true jika struktur dan nilai node pada p1 dan p2 identik,
 * false jika tidak */

int getMaximumDepth(BinTree p);
/* I.S. p terdefinisi */
/* F.S. Mengembalikan kedalaman maksimum pohon biner p */
/* Kedalaman maksimum adalah panjang lintasan dari akar ke simpul daun terjauh
 */
/* Jika pohon kosong, maka kedalaman = 0 */

BinTree createBinSearchTreeFromSortedArray(ElType* arr, ElType start,
                                           ElType end);
/* Mengembalikan pohon biner yang seimbang (balanced) dibangun dari array yang
 * terurut */
/* arr terdefinisi dan tidak kosong, start dan end adalah indeks awal dan akhir
 * array */
/* arr merupakan array berisi ElType yang terurut menaik (ascending) */
/* dipastikan semua elemen pada array unik */
/* Pilih elemen tengah dari array (indeks mid = (start + end) / 2) sebagai akar
 * pohon. */
/* Pohon yang dihasilkan adalah Binary Search Tree(BST), di mana setiap node
   kiri lebih kecil dari parent node, dan setiap node kanan lebih besar dari
   parent node. */
/* Misalnya, jika array [1, 2, 3, 4, 5], pohon yang dihasilkan adalah:
    3
   / \
  1   4
   \   \
    2    5
*/

int countNodes(BinTree p);
/* p terdefinisi, p adalah pohon biner yang mungkin kosong */
/* Mengembalikan jumlah seluruh node dalam pohon biner p */
/* Contoh:
   Misalkan pohon biner p adalah sebagai berikut:
       1
      / \
     2   3
    / \
   4   5

   Panggilan fungsi: countNodes(p)

   Output: 5
   Penjelasan: Pohon ini memiliki 5 simpul (1, 2, 3, 4, 5)
*/

void printPathToElement(BinTree p, ElType target);
/* I.S. p terdefinisi, target adalah elemen yang dicari dalam pohon biner p.
 * Dipastikan node pada pohon biner p unik */
/* F.S. Menampilkan jalur menuju elemen target dalam pohon p dalam format "x ->
   y -> z" jika elemen ditemukan, atau "-1" jika elemen tidak ditemukan */
/* Untuk memudahkan implementasi, dipastikan path tidak lebih panjang dari 100
 * elemen */
/* Contoh:
   Jika pohon p adalah:
       1
      / \
     2   3
    / \
   4   5

   Panggilan: printPathToElement(p, 5)
   Output: 1 -> 2 -> 5
*/

#endif