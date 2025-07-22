#ifndef SONG_HPP
#define SONG_HPP

#include <iostream>
#include <string>

using namespace std;

class Song {
   private:
    string title;
    string artist;

   public:
    Song() : title("Unknown"), artist("Unknown") {}

    Song(string title, string artist) : title(title), artist(artist) {}

    const string &getTitle() const { return title; }

    const string &getArtist() const { return artist; }

    // Fungsi untuk menentukan apakah dua buah lagu merupakan lagu yang sama
    bool operator==(const Song &other) const {
        return title == other.title && artist == other.artist;
    }

    // Fungsi friend untuk melakukan overload operator output stream untuk
    // mempermudah print
    friend ostream &operator<<(ostream &os, const Song &song);
};

// Implementasi fungsi friend
inline ostream &operator<<(ostream &os, const Song &song) {
    os << "\"" << song.title << "\" by " << song.artist;
    return os;
}

#endif  // SONG_HPP