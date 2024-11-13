#include <iostream>
#include <cstring>

using namespace std;

class Track {
    char track_name[50];
    char release_date[20];
    float duration;

public:
    // Constructor
    Track() {
        strcpy(track_name, "");
        strcpy(release_date, "");
        duration = 0.0;
    }

    Track(const char* name, const char* date, float dur) {
        strcpy(track_name, name);
        strcpy(release_date, date);
        duration = dur;
    }

    // Destructor
    ~Track() {}

    void display() const {
        cout << "Track Name: " << track_name << "\nRelease Date: " << release_date << "\nDuration: " << duration << " minutes\n";
    }

    const char* getReleaseDate() const {
        return release_date;
    }

    friend class Album;
};

class Album {
    char album_name[50];
    char release_date[20];
    Track* tracks[10];  // Array of pointers to tracks
    int track_count;
    static int album_count;

public:
    // Constructor
    Album() {
        strcpy(album_name, "");
        strcpy(release_date, "");
        track_count = 0;
        album_count++;
    }

    Album(const char* name, const char* date) {
        strcpy(album_name, name);
        strcpy(release_date, date);
        track_count = 0;
        album_count++;
    }

    // Destructor
    ~Album() {
        for (int i = 0; i < track_count; ++i) {
            delete tracks[i];  // Memory management
        }
        cout << "Album \"" << album_name << "\" memory deallocated.\n";
    }

    // Static function to get album count
    static int getAlbumCount() {
        return album_count;
    }

    void addTrack(const char* track_name, const char* release_date, float duration) {
        if (track_count < 10) {
            tracks[track_count++] = new Track(track_name, release_date, duration);
        } else {
            cout << "Cannot add more tracks to the album.\n";
        }
    }

    void display() const {
        cout << "\nAlbum: " << album_name << "\nRelease Date: " << release_date << "\n";
        for (int i = 0; i < track_count; ++i) {
            tracks[i]->display();
        }
    }

    const char* getReleaseDate() const {
        return release_date;
    }

    friend class MusicLibrary;
};

// Initialize static member
int Album::album_count = 0;

class MusicLibrary {
    Album* albums[10];  // Array of pointers to albums
    int album_count;

public:
    // Inline constructor
    inline MusicLibrary() {
        album_count = 0;
    }

    // Destructor
    ~MusicLibrary() {
        for (int i = 0; i < album_count; ++i) {
            delete albums[i];  // Memory management
        }
        cout << "Music Library memory deallocated.\n";
    }

    void addAlbum(const char* name, const char* release_date) {
        if (album_count < 10) {
            albums[album_count++] = new Album(name, release_date);
        } else {
            cout << "Cannot add more albums to the library.\n";
        }
    }

    void addTrackToAlbum(int album_index, const char* track_name, const char* release_date, float duration) {
        if (album_index >= 0 && album_index < album_count) {
            albums[album_index]->addTrack(track_name, release_date, duration);
        } else {
            cout << "Album index out of range!\n";
        }
    }

    void displayAlbums() const {
        for (int i = 0; i < album_count; ++i) {
            albums[i]->display();
        }
    }

    void displayByReleaseDate(const char* date) const {
        cout << "\nAlbums and tracks released on or after: " << date << "\n";
        for (int i = 0; i < album_count; ++i) {
            if (strcmp(albums[i]->getReleaseDate(), date) >= 0) {
                albums[i]->display();
            }
        }
    }
};

// Main function
int main() {
    MusicLibrary library;

    library.addAlbum("Thriller", "1982-11-30");
    library.addTrackToAlbum(0, "Beat It", "1982-11-30", 4.18);
    library.addTrackToAlbum(0, "Billie Jean", "1982-11-30", 4.54);

    library.addAlbum("Back in Black", "1980-07-25");
    library.addTrackToAlbum(1, "Hells Bells", "1980-07-25", 5.12);
    library.addTrackToAlbum(1, "Shoot to Thrill", "1980-07-25", 5.17);

    cout << "\nMusic Library Details:\n";
    library.displayAlbums();

    cout << "\nDisplaying albums and tracks released after 1980-01-01:\n";
    library.displayByReleaseDate("1980-01-01");

    return 0;
}