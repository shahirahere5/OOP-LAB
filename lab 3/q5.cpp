#include <iostream>
using namespace std;

class MusicPlayer{
    private:
    string playlist[10];
    int totalSongs;
    string currentlyPlayingSong;

    public:
    MusicPlayer(){
        totalSongs = 0;
        currentlyPlayingSong = "";
    }
    
    void addSong(string songName){
        if(totalSongs < 10){
            playlist[totalSongs] = songName;
            totalSongs++;
            cout << "Song added: " << songName << endl;
        }
        else{
            cout << "Playlist is full. Cannot add song." << endl;
        }
    }
    void removeSong(string songName){
        int index = -1;
        for(int i = 0; i < totalSongs; i++){
            if(playlist[i] == songName){
                index = i;
                break;
            }
        }
        if(index != -1){
            for(int i = index; i < totalSongs-1; i++){
                playlist[i] = playlist[i+1];
            }
            totalSongs--;
            cout << "Song removed: " << songName << endl;
        }
        else{
            cout << "Song not found in the playlist." << endl;
        }
    }
    void playSong(string songName){
        int index = -1;
        for(int i = 0; i < totalSongs; i++){
            if(playlist[i] == songName){
                index = i;
                break;
            }
        }
        if(index!= -1){
            currentlyPlayingSong = songName;
            cout << "Now playing: " << songName << endl;
        }
        else{
            cout << "Song not found in the playlist." << endl;
        }
    }
    void displayPlaylist(){
        cout << "Playlist:" << endl;
        for(int i = 0; i < totalSongs; i++){
            cout << i+1 << ". " << playlist[i] << endl;
        }
    }    
    
};

int main(){
    MusicPlayer player;
    
    player.addSong("Song 1");
    player.addSong("Song 2");
    player.addSong("Song 3");
    player.addSong("Song 4");
    player.addSong("Song 5");
    player.addSong("Song 6");
    player.addSong("Song 7");
    player.addSong("Song 8");
    player.addSong("Song 9");
    player.addSong("Song 10");
    
    player.displayPlaylist();
    
    player.playSong("Song 3");
    
    player.removeSong("Song 2");
    
    player.displayPlaylist();
    
    return 0;
}