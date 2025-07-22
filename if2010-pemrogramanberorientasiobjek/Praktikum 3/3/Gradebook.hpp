// Gradebook.hpp
#ifndef GRADEBOOK_HPP
#define GRADEBOOK_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Gradebook
{
private:
    // Struktur data utama: memetakan nama mahasiswa (string) ke nilai (double)
    map<string, double> studentGrades;

public:
    /*
     * Menambah atau mengupdate nilai mahasiswa.
     * Jika mahasiswa sudah ada, nilainya akan diupdate.
     * Jika mahasiswa belum ada, akan ditambahkan dengan nilai yang diberikan.
     */
    void addOrUpdateStudent(const string &studentName, double grade);

    /*
     * Menghapus mahasiswa dari gradebook.
     * Mengembalikan true jika mahasiswa ditemukan dan berhasil dihapus,
     * false jika tidak ditemukan.
     */
    bool removeStudent(const string &studentName);

    /*
     * Mengambil nilai dari mahasiswa tertentu.
     * Mengembalikan true jika mahasiswa ditemukan dan nilainya disimpan
     * di parameter 'grade', false jika mahasiswa tidak ditemukan.
     */
    bool getGrade(const string &studentName, double &grade) const;

    /*
     * Memeriksa apakah mahasiswa ada dalam gradebook.
     * Mengembalikan true jika mahasiswa ada, false jika tidak.
     */
    bool studentExists(const string &studentName) const;

    /*
     * Mencetak semua nama mahasiswa dan nilai mereka
     * Jika gradebook kosong, akan mencetak pesan "Gradebook kosong\n"
     * Format:
     * 1. <nama_mahasiswa>: <nilai>
     * 2. <nama_mahasiswa>: <nilai>
     * ...
     */
    void printGrades() const;

    /*
     * Mencetak semua nama mahasiswa dan nilai mereka, terurut berdasarkan nilai terbesar ke terkecil.
     * Hint: gunakan vector<pair<string, double>> untuk menyimpan semua data mahasiswa untuk memudahkan pengurutan. Gunakan fungsi bantuan untuk komparasi pada std::sort.
     * Format:
     * 1. <nama_mahasiswa>: <nilai>
     * 2. <nama_mahasiswa>: <nilai>
     * ...
     */
    void printGradesRank() const;

    /*
     * Mengembalikan daftar nama mahasiswa yang nilainya di atas threshold tertentu.
     * Mengembalikan vector berisi nama mahasiswa dengan nilai lebih besar dari threshold,
     * terurut berdasarkan abjad.
     */
    vector<string> getStudentsWithGradeAbove(double threshold) const;

    /*
     * Menghitung rata-rata nilai semua mahasiswa dalam gradebook.
     * Mengembalikan rata-rata nilai, atau 0.0 jika gradebook kosong.
     */
    double getAverageGrade() const;

    /*
     * Mengembalikan jumlah mahasiswa yang ada dalam gradebook.
     */
    size_t getNumberOfStudents() const;
};

#endif // GRADEBOOK_HPP