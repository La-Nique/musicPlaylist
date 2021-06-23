#include "playlist.cpp"
#include <iostream>




int main(){
  PlayList myPlayList;
    Song song1("The Wave - Colouring", 2);
    Song song2("Moonlight - XXXTENTACION", 1);
    std::cout << song1.title << std::endl;
    std::cout << song2.title << std::endl;
    Song* song3 = new Song("Goodbye World", 9);
    PlayList playList1;
    playList1.insertSong(song3,100);
    playList1.display();
    
}
