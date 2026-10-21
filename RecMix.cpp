#include <iostream>
#include <string>
using namespace std;

// ==========================================
// Part 1 — Design the Abstract Media Class
// ==========================================
class Media {
protected:
    string title;
    string creator;
    int duration; // Length in seconds

public:
    Media(string t, string c, int d) 
        : title(t), creator(c), duration(d) {}

    virtual ~Media() {}

    string getTitle() const {
        return title;
    }

    virtual void displayInfo() const = 0;
    virtual void play() const = 0;
};

// ==========================================
// Part 2 — Create Three Media Types
// ==========================================

// Derived Class: Song
class Song : public Media {
private:
    string genre;

public:
    Song(string t, string c, int d, string g)
        : Media(t, c, d), genre(g) {}

    void displayInfo() const override {
        cout << "[SONG]\n"
             << "Title: " << title << "\n"
             << "Artist: " << creator << "\n"
             << "Genre: " << genre << "\n"
             << "Duration: " << duration << " seconds\n";
    }

    void play() const override {
        cout << "Now playing: " << title << "\n\n";
    }
};

// Derived Class: Podcast
class Podcast : public Media {
private:
    int episodeNumber;

public:
    Podcast(string t, string c, int d, int e)
        : Media(t, c, d), episodeNumber(e) {}

    void displayInfo() const override {
        cout << "[PODCAST]\n"
             << "Title: " << title << "\n"
             << "Host: " << creator << "\n"
             << "Episode: " << episodeNumber << "\n"
             << "Duration: " << duration << " seconds\n";
    }

    void play() const override {
        cout << "Playing podcast: " << title << "\n\n";
    }
};

// Derived Class: Audiobook
class Audiobook : public Media {
private:
    string narrator;

public:
    Audiobook(string t, string c, int d, string n)
        : Media(t, c, d), narrator(n) {}

    void displayInfo() const override {
        cout << "[AUDIOBOOK]\n"
             << "Title: " << title << "\n"
             << "Author: " << creator << "\n"
             << "Narrator: " << narrator << "\n"
             << "Duration: " << duration << " seconds\n";
    }

    void play() const override {
        cout << "Playing audiobook: " << title << "\n\n";
    }
};

// ==========================================
// Part 4 — Search Function Implementation
// ==========================================
int searchMedia(Media* library[], int size, const string& target) {
    for (int i = 0; i < size; i++) {
        if (library[i]->getTitle() == target) {
            return i;
        }
    }
    return -1;
}

// ==========================================
// Part 3 — Main Program Flow
// ==========================================
int main() {
    const int SIZE = 5;
    Media* library[SIZE] = {};

    // Populating with the exact sample dataset from your expected output
    library[0] = new Song("Blinding Lights", "The Weeknd", 200, "Synth-pop");
    library[1] = new Song("Levitating", "Dua Lipa", 203, "Pop");
    library[2] = new Podcast("Tech Talk", "Alex Morgan", 1800, 12);
    library[3] = new Podcast("Science Weekly", "Jordan Lee", 2400, 8);
    library[4] = new Audiobook("The Time Machine", "H. G. Wells", 14400, "Taylor Brooks");

    cout << "=== RECMIX MEDIA LIBRARY ===\n\n";

    // TODO: Use a loop to display and play each media item
    for (int i = 0; i < SIZE; i++) {
        library[i]->displayInfo();
        library[i]->play();
    }

    cout << "\n=== SEARCH RESULTS ===\n\n";

    // TODO: Perform a successful search
    string targets = "Tech Talk";
    int indexS = searchMedia(library, SIZE, targets);
    if (indexS != -1) {
        cout << "Searching for \"" << targets << "\"... Found at index " << indexS << "!\n";
    }

    // TODO: Perform an unsuccessful search
    string targetU = "Nonexistent Track";
    int indexU = searchMedia(library, SIZE, targetU);
    if (indexU == -1) {
        cout << "Searching for \"" << targetU << "\"... Not found.\n";
    }

    // TODO: Delete all dynamically allocated objects
    for (int i = 0; i < SIZE; i++) {
        delete library[i];
        library[i] = nullptr;
    }

    return 0;
}
