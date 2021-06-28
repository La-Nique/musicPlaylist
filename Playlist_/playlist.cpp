/****************************************************************************************************************************
Title        : PlayList.cpp
Author       : Lanique Peterson
Description  : Implementation file for the PlayList class
****************************************************************************************************************************/

#include "playlist.h"
#include <iostream>

PlayList::PlayList() ///Default Constructor - Should initalize a linkedlist, if we are creating a playlist without any songs yet.
{
    start = nullptr;
    size = 0;
}

PlayList::PlayList(Song* song) ///Constructor - Should initalize a LinkedList with the given Song, we are creating a playlist.
{
    size = 1; ///size would only be of size one because we would start off the playlist with one user given song.
    PlayListNode* newNode = new PlayListNode; /// asking cpu to allocate memory on the heap and assigning it to the pointer called newNode.
    newNode->song = song; ///newNode start pointer will point to the song.
    newNode->next = nullptr; ///not required because we intialize in our h file, but good for practice.
    start = newNode; ///start is our PlaylistNode pointer, start points to the beginning song of the playlist.
}

PlayListNode* PlayList::insertSong(Song* song, int position) ///we are adding songs to our playlist.
{
    PlayListNode* insertedSong = new PlayListNode;
    insertedSong->song = song;
    insertedSong->next = nullptr; ///not required because we intialize in our h file, but good for practice.
    PlayListNode* songCurrentLocation = start; ///copies the address of the initial starting node, will be used to traverse the playlist

        if(size == 0) ///if playlist is empty, insert song in front.
        {
            start = insertedSong;
        }
        else
        {
            if (position == 0) ///if song position is 0 but the playlist/linkedlist is not empty, insert the song to the beginning/start of the playlist.
            {
                insertedSong->next = start; ///pushes the previous starting song to the next position.
                start = insertedSong; ///puts the inserted song in the first position.
            }
            else if (position > size) ///if the position of the inserted song is at a higher index than the total number of songs.
            {
                while (songCurrentLocation->next != nullptr)
                {
                    songCurrentLocation = songCurrentLocation->next; ///traversing from start, overlapping start pointer at first, to end through the list while traveling through each song until we get to the last index.
                }
                songCurrentLocation->next = insertedSong; ///once we hit the end of the playlist via while loop, we will append the new song to the their position in the end of the playlist.
            }
            else ///inserting inbetween nodes within linked list
            {
                for (int i = 0; i < position - 1; i++) /// -1 because we travel via ->next.
                songCurrentLocation = songCurrentLocation->next; ///our "counter++" but for the playlist nodes.
                
                insertedSong->next = songCurrentLocation->next; ///copies the actual linker.
                songCurrentLocation->next = insertedSong; ///song inserted, linker of previous song is now attached to the data of the desired inserted song.
            }
        }
    size++; ///increment size of our playlist!
    
    return insertedSong;
}

int PlayList::getSize() /// return size/total number of songs in playlist.
{
    return size;
}

PlayListNode* PlayList::searchForSong(std::string title) ///return the pointer to the song in the playlist.
{
    PlayListNode* songCurrentLocation = start;
        if (songCurrentLocation->song->title == title) ///checks the start/first song's title.
            return songCurrentLocation;
        
        while (songCurrentLocation->next != nullptr)
        {
            songCurrentLocation = songCurrentLocation->next; ///this with the while loop makes the linker crawl through the playlist, our "counter++".
            if (songCurrentLocation->song->title == title)
            {
                return songCurrentLocation;
                break;
            }
        }
    return nullptr;
}

int PlayList::songPosition(std::string title) ///return the position of the song in the playlist.
{
    PlayListNode* currentSong = start;
    int current_position = 0; ///counter needed to locate index of specific song.
    
        if (currentSong->song->title == title)
            return current_position;
        
    current_position++;
    
        while (currentSong->next != nullptr)
        {
            currentSong = currentSong->next; ///our node crawling "counter++".
            
                if (currentSong->song->title == title)
                    return current_position;
                
            current_position++; ///incerement position if title not found
        }
    return -1; ///if not found.
}

PlayListNode* PlayList::getStart() ///return pointer to the first node in the list.
{
    return start;
}

int PlayList::getTotalPlayTime() ///return total playtime of each song in the playlist, assuming each song's playtime is positive.
{
    int total_playtime = 0;
    PlayListNode* currentSong = start;
    
        while (currentSong != nullptr) ///traverses entire linkedlist and adds time together of each song in the playlist.
        {
            total_playtime = total_playtime + currentSong->song->durationInSeconds;
            currentSong = currentSong->next; ///our handy-dandy node crawling "counter++".
        }
    return total_playtime;
}

PlayList::~PlayList() /// Deconstructor
{
    PlayListNode* currentSong = start;
    PlayListNode* nextSong = nullptr;
    
        while (currentSong != nullptr)
        {
            nextSong = currentSong->next;
            delete currentSong;
            currentSong = nextSong;
        }
}

void display(PlayListNode* start) ///display func to print out our playlist.
{
    while (start != nullptr)
    {
        std::cout << start->song << std::endl;
        start = start->next;
    }
}
