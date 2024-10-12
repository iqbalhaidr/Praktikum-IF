#include "matrix.h"
#include <stdio.h>


void createMatrix(int nRows, int nCols, Matrix *m) {
   ROW_EFF(*m) = nRows;
   COL_EFF(*m) = nCols;
}

boolean isMatrixIdxValid(int i, int j) {
   return i>=0 && i<ROW_CAP && j>=0 && j<COL_CAP;
}

IdxType getLastIdxRow(Matrix m) {
   return ROW_EFF(m)-1;
}

IdxType getLastIdxCol(Matrix m) {
   return COL_EFF(m)-1;
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j) {
   return i>=0 && i<ROW_EFF(m) && j>=0 && j<COL_EFF(m);
}

ElType getElmtDiagonal(Matrix m, IdxType i) {
   return ELMT(m, i, i);
}

void copyMatrix(Matrix mIn, Matrix *mOut) {
   createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
   for (int i=0; i<=getLastIdxRow(mIn); ++i) {
      for (int j=0; j<=getLastIdxCol(mIn); ++j) {
         ELMT(*mOut, i, j) = ELMT(mIn, i, j);
      }
   }
}

void readMatrix(Matrix *m, int nRow, int nCol) {
   createMatrix(nRow, nCol, m);
   for (int i=0; i<nRow; ++i) {
      for (int j=0; j<nCol; ++j) {
         scanf("%d", &ELMT(*m, i, j));
      }
   }
}

void displayMatrix(Matrix m) {
   for (int i=0; i<=getLastIdxRow(m); ++i) {
      if (i > 0) {
         printf("\n");
      } else {
         for (int j=0; j<=getLastIdxCol(m); ++j) {
            if (j > 0) {
               printf(" ");
            }
            printf("%d", ELMT(m, i, j));
         }
      }
   }
}

Matrix addMatrix(Matrix m1, Matrix m2) {
   Matrix mResult;
   createMatrix(ROW_EFF(m1), COL_EFF(m1), &mResult);
   for (int i=0; i<=getLastIdxRow(m1); ++i) {
      for (int j=0; j<=getLastIdxCol(m1); ++j) {
         ELMT(mResult, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
      }
   }
   return mResult;
}

Matrix subtractMatrix(Matrix m1, Matrix m2) {
   Matrix mResult;
   createMatrix(ROW_EFF(m1), COL_EFF(m1), &mResult);
   for (int i=0; i<=getLastIdxRow(m1); ++i) {
      for (int j=0; j<=getLastIdxCol(m1); ++j) {
         ELMT(mResult, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
      }
   }
   return mResult;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2) {
   Matrix mResult;
   int sum;
   createMatrix(ROW_EFF(m1), COL_EFF(m2), &mResult);
   for (int i=0; i<=getLastIdxRow(m1); ++i) {
      for (int j=0; j<=getLastIdxCol(m2); ++j) {
         sum = 0;
         for (int n=0; n<=COL_EFF(m1); ++n) {
            sum += ELMT(m1, i, n) * ELMT(m2, n, j);
         }
         ELMT(mResult, i, j) = sum;
      }
   }
   return mResult;
}

Matrix multiplyByConst(Matrix m, ElType x) {
   Matrix mResult;
   createMatrix(ROW_EFF(m), COL_EFF(m), &mResult);
   for (int i=0; i<=getLastIdxRow(m); ++i) {
      for (int j=0; j<=getLastIdxCol(m); ++j) {
         ELMT(mResult, i, j) = ELMT(m, i, j) * x;
      }
   }
   return mResult;
}

void pMultiplyByConst(Matrix *m, ElType k) {
   for (int i=0; i<=getLastIdxRow(*m); ++i) {
      for (int j=0; j<=getLastIdxCol(*m); ++j) {
         ELMT(*m, i, j) = ELMT(*m, i, j) * k;
      }
   }
}

boolean isMatrixEqual(Matrix m1, Matrix m2) {
   if ((ROW_EFF(m1) != ROW_EFF(m2)) || (COL_EFF(m1) != COL_EFF(m2))) {
      return false;
   } else {
      for (int i=0; i<=getLastIdxRow(m1); ++i) {
         for (int j=0; j<=getLastIdxCol(m1); ++j) {
            if (ELMT(m1, i, j) != ELMT(m2, i, j)) {
               return false;
            }
         }
      }
      return true;
   }
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2) {
   return !isMatrixEqual;
}

boolean isMatrixSizeEqual(Matrix m1, Matrix m2) {
   return (ROW_EFF(m1) == ROW_EFF(m2)) || (COL_EFF(m1) == COL_EFF(m2));
}

int countElmt(Matrix m) {
   return ROW_EFF(m) * COL_EFF(m);
}

boolean isSquare(Matrix m) {
   return ROW_EFF(m) == COL_EFF(m);
}

boolean isSymmetric(Matrix m) {
   if (!isSquare(m)) {
      return false;
   } else {
      for (int i=0; i<=getLastIdxRow(m); ++i) {
         for (int j=0; j<=getLastIdxCol(m); ++j) {
            if (ELMT(m, i, j) != ELMT(m, j, i)) {
               return false;
            }
         }
      }
      return true;
   }
}

boolean isIdentity(Matrix m) {
   if (!isSquare(m)) {
      return false;
   } else {
      for (int i=0; i<=getLastIdxRow(m); ++i) {
         for (int j=0; j<=getLastIdxCol(m); ++j) {
            if (i==j) {
               if (ELMT(m, i, j)!=1) {
                  return false;
               }
            } else {
               if (ELMT(m, i, j)!=0) {
                  return false;
               }
            }
         }
      }
      return true;
   }
}

//====================================================================================================
#define PERCENTAGE_SPARSE 0.05

boolean isSparse(Matrix m) {
    int totalElements = ROW_EFF(m) * COL_EFF(m); // Total elemen efektif dalam matriks
    int nonZeroCount = 0;  // Menghitung jumlah elemen yang bukan nol

    // Iterasi untuk menghitung elemen non-nol
    for (int i = 0; i < ROW_EFF(m); i++) {
        for (int j = 0; j < COL_EFF(m); j++) {
            if (ELMT(m, i, j) != 0) {
                nonZeroCount++;
            }
        }
    }

    // Jika jumlah elemen non-nol kurang dari atau sama dengan 5% dari total elemen
    return (nonZeroCount <= PERCENTAGE_SPARSE * totalElements);
}
//====================================================================================================

Matrix negation(Matrix m) {
   return multiplyByConst(m, -1);
}

void pNegation(Matrix *m) {
   pMultiplyByConst(m, -1);
}

//============================================================================
// Fungsi untuk menghitung kofaktor dari matriks
void getCofactor(Matrix m, Matrix *temp, int p, int q, int n) {
    int i = 0, j = 0;

    // Iterasi untuk setiap elemen matriks
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Lewati baris dan kolom yang dihapus
            if (row != p && col != q) {
                ELMT(*temp, i, j++) = ELMT(m, row, col);

                // Jika baris telah diisi, lanjutkan ke baris berikutnya
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }

    // Set ukuran baris dan kolom submatriks
    ROW_EFF(*temp) = n - 1;
    COL_EFF(*temp) = n - 1;
}

// Fungsi rekursif untuk menghitung determinan matriks
float determinant(Matrix m) {
    float det = 0;  // Variabel untuk menyimpan hasil determinan
    int n = ROW_EFF(m);

    // Kasus dasar: Jika matriks berukuran 1x1
    if (n == 1) {
        return ELMT(m, 0, 0);
    }

    // Kasus dasar: Jika matriks berukuran 2x2
    if (n == 2) {
        return ELMT(m, 0, 0) * ELMT(m, 1, 1) - ELMT(m, 0, 1) * ELMT(m, 1, 0);
    }

    Matrix temp; // Menyimpan kofaktor
    int sign = 1;     // Menyimpan tanda +/- untuk ekspansi kofaktor

    // Iterasi untuk setiap elemen pada baris pertama
    for (int f = 0; f < n; f++) {
        // Dapatkan kofaktor matriks[0][f]
        getCofactor(m, &temp, 0, f, n);

        // Hitung determinan secara rekursif dan tambahkan ke hasil
        det += sign * ELMT(m, 0, f) * determinant(temp);

        // Ganti tanda
        sign = -sign;
    }

    return det;
}
//============================================================================

Matrix transpose(Matrix m) {
   Matrix mResult;
   createMatrix(ROW_EFF(m), COL_EFF(m), &mResult);
   for (int i=0; i<=getLastIdxRow(m); ++i) {
      for (int j=0; j<=getLastIdxCol(m); ++j) {
         ELMT(mResult, j, i) = ELMT(m, i, j);
      }
   }
   return mResult;
}

void pTranspose(Matrix *m) {
   Matrix mCopy;
   copyMatrix(*m, &mCopy);
   for (int i=0; i<=getLastIdxRow(mCopy); ++i) {
      for (int j=0; j<=getLastIdxCol(mCopy); ++j) {
         ELMT(*m, i, j) = ELMT(mCopy, j, i);
      }
   }
}