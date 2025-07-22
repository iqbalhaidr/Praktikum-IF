#ifndef PLAYBACK_HPP
#define PLAYBACK_HPP

#include <iostream>
#include <queue>

#include "Playlist.hpp"
#include "Song.hpp"

using namespace std;

class Playback {
   private:
    queue<Song> playbackQueue;

   public:
    /*
     * Menambahkan satu lagu ke akhir queue pemutaran.
     * Tidak perlu mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
     */
    void addToQueue(const Song &song);

    /*
     * Menambahkan semua lagu dari playlist yang diberikan ke akhir queue
     * pemutaran, dengan mempertahankan urutan mereka dari playlist. Tidak perlu
     * mengecek apakah lagu sudah ada di queue (boleh ada duplikat)
     */
    void addToQueue(const Playlist &playlist);

    /*
     * Memutar lagu berikutnya: Mencetak dengan format "Memutar: <lagu> <endl>"
     * dan menghapusnya dari queue. Jika queue kosong, mencetak pesan "Antrian
     * kosong"
     */
    void next();

    /*
     * Memutar semua lagu dari queue pemutaran.
     * Mencetak dengan format "Memutar: <lagu> <endl>" untuk setiap lagu di
     * queue. Jika queue kosong, mencetak pesan "Antrian kosong"
     */
    void playAll();

    /*
     * Melewati lagu berikutnya: Menghapus lagu dari depan queue tanpa mencetak
     * detail. Jika queue kosong, mencetak pesan "Antrian kosong"
     */
    void skip();

    /*
     * Menghapus semua lagu dari queue pemutaran.
     */
    void clearQueue();

    /*
     * Memeriksa apakah queue pemutaran kosong.
     */
    bool isEmpty() const;

    /*
     * Mengembalikan jumlah lagu yang ada dalam queue.
     */
    size_t queueSize() const;
};

#endif  // PLAYBACK_HPP