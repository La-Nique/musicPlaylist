#include "playlist.cpp"
#include <iostream>

int main(){
  PlayList myPlayList;
    Song song1("The Wave - Colouring");
    Song song2("Moonlight - XXXTENTACION");
    std::cout << song1.title << std::endl;
    std::cout << song2.title << std::endl;
}
