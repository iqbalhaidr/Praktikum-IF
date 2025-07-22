#include "Gradebook.hpp"

static bool compare(const pair<string, double> &a,
                    const pair<string, double> &b) {
    return a.second > b.second;
}

static bool compare2(const string &a, const string &b) { return a < b; }

/*
 * Menambah atau mengupdate nilai mahasiswa.
 * Jika mahasiswa sudah ada, nilainya akan diupdate.
 * Jika mahasiswa belum ada, akan ditambahkan dengan nilai yang diberikan.
 */
void Gradebook::addOrUpdateStudent(const string &studentName, double grade) {
    studentGrades[studentName] = grade;
}

/*
 * Menghapus mahasiswa dari gradebook.
 * Mengembalikan true jika mahasiswa ditemukan dan berhasil dihapus,
 * false jika tidak ditemukan.
 */
bool Gradebook::removeStudent(const string &studentName) {
    return studentGrades.erase(studentName);
}

/*
 * Mengambil nilai dari mahasiswa tertentu.
 * Mengembalikan true jika mahasiswa ditemukan dan nilainya disimpan
 * di parameter 'grade', false jika mahasiswa tidak ditemukan.
 */
bool Gradebook::getGrade(const string &studentName, double &grade) const {
    map<string, double>::const_iterator i = studentGrades.find(studentName);
    if (i != studentGrades.end()) {
        grade = i->second;
        return true;
    } else {
        return false;
    }
}

/*
 * Memeriksa apakah mahasiswa ada dalam gradebook.
 * Mengembalikan true jika mahasiswa ada, false jika tidak.
 */
bool Gradebook::studentExists(const string &studentName) const {
    return studentGrades.find(studentName) != studentGrades.end();
}

/*
 * Mencetak semua nama mahasiswa dan nilai mereka
 * Jika gradebook kosong, akan mencetak pesan "Gradebook kosong\n"
 * Format:
 * 1. <nama_mahasiswa>: <nilai>
 * 2. <nama_mahasiswa>: <nilai>
 * ...
 */
void Gradebook::printGrades() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong\n";
    } else {
        map<string, double>::const_iterator itr = studentGrades.begin();
        for (int i = 0; i < studentGrades.size(); i++) {
            cout << (i + 1) << ". " << itr->first << ": " << itr->second
                 << endl;
            itr++;
        }
    }
}

/*
 * Mencetak semua nama mahasiswa dan nilai mereka, terurut berdasarkan nilai
 * terbesar ke terkecil. Hint: gunakan vector<pair<string, double>> untuk
 * menyimpan semua data mahasiswa untuk memudahkan pengurutan. Gunakan fungsi
 * bantuan untuk komparasi pada std::sort. Format:
 * 1. <nama_mahasiswa>: <nilai>
 * 2. <nama_mahasiswa>: <nilai>
 * ...
 */
void Gradebook::printGradesRank() const {
    vector<pair<string, double>> v;
    map<string, double>::const_iterator itr = studentGrades.begin();
    for (int i = 0; i < studentGrades.size(); i++) {
        v.push_back({itr->first, itr->second});
        itr++;
    }

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
        cout << (i + 1) << ". " << v[i].first << ": " << v[i].second << endl;
    }
}

/*
 * Mengembalikan daftar nama mahasiswa yang nilainya di atas threshold tertentu.
 * Mengembalikan vector berisi nama mahasiswa dengan nilai lebih besar dari
 * threshold, terurut berdasarkan abjad.
 */
vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> v;
    map<string, double>::const_iterator itr = studentGrades.begin();
    for (int i = 0; i < studentGrades.size(); i++) {
        if (itr->second > threshold) {
            v.push_back(itr->first);
        }
        itr++;
    }

    sort(v.begin(), v.end(), compare2);
    return v;
}

/*
 * Menghitung rata-rata nilai semua mahasiswa dalam gradebook.
 * Mengembalikan rata-rata nilai, atau 0.0 jika gradebook kosong.
 */
double Gradebook::getAverageGrade() const {
    if (studentGrades.empty()) {
        return 0.0;
    } else {
        double sum = 0;
        int count = studentGrades.size();
        map<string, double>::const_iterator itr = studentGrades.begin();
        for (int i = 0; i < count; i++) {
            sum += itr->second;
            itr++;
        }
        return sum / count;
    }
}

/*
 * Mengembalikan jumlah mahasiswa yang ada dalam gradebook.
 */
size_t Gradebook::getNumberOfStudents() const { return studentGrades.size(); }