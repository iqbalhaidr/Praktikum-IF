#include "Playlist.hpp"

// Constructor
Playlist::Playlist(string playlistName) : name(playlistName) {}

// Getters
const string &Playlist::getName() const { return name; }

const vector<Song> &Playlist::getSongs() const { return songs; }

/*
 * Menambahkan salinan lagu yang diberikan ke akhir playlist apabila lagu
 * tersebut belum ada di playlist. Menggunakan Song::operator== untuk
 * perbandingan.
 */
void Playlist::addSong(const Song &song) {
    bool isFound = false;
    for (int i = 0; i < songs.size(); i++) {
        if (songs[i] == song) {
            isFound = true;
            break;
        }
    }

    if (not isFound) {
        songs.push_back(song);
    }
}

/*
 * Menghapus kemunculan pertama dari lagu yang ditentukan dari playlist.
 * Mengembalikan true jika lagu berhasil dihapus, false jika tidak.
 * Menggunakan Song::operator== untuk perbandingan.
 */
bool Playlist::removeSong(const Song &songToRemove) {
    int idx = -1;
    for (int i = 0; i < songs.size(); i++) {
        if (songs[i] == songToRemove) {
            idx = i;
            break;
        }
    }

    if (idx != -1) {
        songs.erase(songs.begin() + idx);
        return true;
    } else {
        return false;
    }
}

/*
 * Menghapus lagu pada indeks yang ditentukan.
 * Melempar out_of_range jika indeks tidak valid.
 */
void Playlist::removeSongByIndex(size_t index) {
    if (index > songs.size() - 1) {
        throw out_of_range("Index out of range");
    }

    songs.erase(songs.begin() + index);
}

/*
 * Mengembalikan jumlah lagu dalam playlist.
 */
size_t Playlist::numberOfSongs() const { return songs.size(); }

/*
 * Friend function untuk mencetak isi playlist.
 * Format:
 * Playlist: <nama_playlist> (<jumlah_lagu> lagu)
 * 1. <lagu1>
 * 2. <lagu2>
 * ...
 * <jumlah_lagu>. <laguN> <endl>
 */
ostream &operator<<(ostream &os, const Playlist &pl) {
    vector<Song> temp = pl.getSongs();

    os << "Playlist: " << pl.getName() << " (" << pl.numberOfSongs() << " lagu)"
       << endl;
    for (int i = 0; i < pl.numberOfSongs(); i++) {
        os << (i + 1) << ". " << temp[i] << endl;
    }

    return os;
}