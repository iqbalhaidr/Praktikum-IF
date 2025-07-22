#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Song.hpp"

using namespace std;

class Playlist {
   private:
    string name;
    vector<Song> songs;

   public:
    // Constructor
    Playlist(string playlistName);

    // Getters
    const string &getName() const;

    const vector<Song> &getSongs() const;

    /*
     * Menambahkan salinan lagu yang diberikan ke akhir playlist apabila lagu
     * tersebut belum ada di playlist. Menggunakan Song::operator== untuk
     * perbandingan.
     */
    void addSong(const Song &song);

    /*
     * Menghapus kemunculan pertama dari lagu yang ditentukan dari playlist.
     * Mengembalikan true jika lagu berhasil dihapus, false jika tidak.
     * Menggunakan Song::operator== untuk perbandingan.
     */
    bool removeSong(const Song &songToRemove);

    /*
     * Menghapus lagu pada indeks yang ditentukan.
     * Melempar out_of_range jika indeks tidak valid.
     */
    void removeSongByIndex(size_t index);

    /*
     * Mengembalikan jumlah lagu dalam playlist.
     */
    size_t numberOfSongs() const;

    /*
     * Friend function untuk mencetak isi playlist.
     * Format:
     * Playlist: <nama_playlist> (<jumlah_lagu> lagu)
     * 1. <lagu1>
     * 2. <lagu2>
     * ...
     * <jumlah_lagu>. <laguN> <endl>
     */
    friend ostream &operator<<(ostream &os, const Playlist &pl);
};

#endif  // PLAYLIST_HPP