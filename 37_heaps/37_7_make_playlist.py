def make_playlist(songs: list[list[str]])->list[str]:
    hashmap = {}
    song_count = 0
    for song in songs:
        if song[1] not in hashmap:
            hashmap[song[1]] = []
        hashmap[song[1]].append(song[0])
        song_count +=1

    output = []
    last_artist = None
    while song_count > 0:
        for artist in hashmap.keys():
            if len(hashmap[artist]) > 0:
                if artist != last_artist:
                    output.append(hashmap[artist][-1])
                    last_artist = artist
                    hashmap[artist].pop()
                    song_count -= 1
                else:
                    return []

    return output

if __name__ == "__main__":
    # Example1
    songs = [
        ["Coding In The Deep", "A Dell"],
        ["Hello World", "A Dell"],
        ["Someone Like GNU", "A Dell"],
        ["Make You Read My Logs", "A Dell"],
        ["Hey Queue", "The Bugs"],
        ["Here Comes the Bug", "The Bugs"],
        ["Merge Together", "The Bugs"],
        ["Dirty Data", "Michael JSON"],
        ["Man in the Middle Attack", "Michael JSON"],
        ["Ring Of Firewalls", "Johnny Cache"]
    ]
    print(make_playlist(songs))
    
    # Example2
    songs = [
            ["Coding In The Deep", "A Dell"],
            ["Hello World", "A Dell"],
            ["Someone Like GNU", "A Dell"],
            ["Make You Read My Logs", "A Dell"],
            ["Hey Queue", "The Bugs"],
            ["Here Comes the Bug", "The Bugs"],
            ["Merge Together", "The Bugs"],
            ["Dirty Data", "Michael JSON"],
            ["Man in the Middle Attack", "Michael JSON"],
            ["Ring Of Firewalls", "Johnny Cache"]
        ]
    print(make_playlist(songs))
