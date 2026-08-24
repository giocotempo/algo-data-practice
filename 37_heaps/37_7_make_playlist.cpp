#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> make_playlist(
    const std::vector<std::vector<std::string>>& songs) {
    std::unordered_map<std::string, std::vector<std::string>> songs_by_artist;
    std::vector<std::string> artist_order;
    std::size_t song_count = 0;

    for (const std::vector<std::string>& song : songs) {
        const std::string& title = song[0];
        const std::string& artist = song[1];

        if (songs_by_artist.find(artist) == songs_by_artist.end()) {
            songs_by_artist[artist] = {};
            artist_order.push_back(artist);
        }
        songs_by_artist[artist].push_back(title);
        ++song_count;
    }

    std::vector<std::string> output;
    std::string last_artist;
    bool has_last_artist = false;

    while (song_count > 0) {
        for (const std::string& artist : artist_order) {
            std::vector<std::string>& artist_songs = songs_by_artist[artist];
            if (!artist_songs.empty()) {
                if (!has_last_artist || artist != last_artist) {
                    output.push_back(artist_songs.back());
                    artist_songs.pop_back();
                    last_artist = artist;
                    has_last_artist = true;
                    --song_count;
                } else {
                    return {};
                }
            }
        }
    }
    return output;
}

void print_playlist(const std::vector<std::string>& playlist) {
    std::cout << "[";
    for (std::size_t i = 0; i < playlist.size(); ++i) {
        std::cout << "'" << playlist[i] << "'";
        if (i + 1 < playlist.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    // Example 1
    std::vector<std::vector<std::string>> songs = {
        {"Coding In The Deep", "A Dell"},
        {"Hello World", "A Dell"},
        {"Someone Like GNU", "A Dell"},
        {"Make You Read My Logs", "A Dell"},
        {"Hey Queue", "The Bugs"},
        {"Here Comes the Bug", "The Bugs"},
        {"Merge Together", "The Bugs"},
        {"Dirty Data", "Michael JSON"},
        {"Man in the Middle Attack", "Michael JSON"},
        {"Ring Of Firewalls", "Johnny Cache"}
    };
    print_playlist(make_playlist(songs));

    // Example 2
    songs = {
        {"Coding In The Deep", "A Dell"},
        {"Hello World", "A Dell"},
        {"Someone Like GNU", "A Dell"},
        {"Make You Read My Logs", "A Dell"},
        {"test", "A Dell"},
        {"Hey Queue", "The Bugs"},
        {"Here Comes the Bug", "The Bugs"},
        {"Merge Together", "The Bugs"},
        {"Dirty Data", "Michael JSON"},
        {"Man in the Middle Attack", "Michael JSON"},
        {"Ring Of Firewalls", "Johnny Cache"}
    };
    print_playlist(make_playlist(songs));

    return 0;
}
