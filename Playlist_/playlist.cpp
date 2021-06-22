/****************************************************************************************************************************
Title        : PlayList.cpp
Author       : Lanique Peterson
Description  : Implementation file for the PlayList class
****************************************************************************************************************************/

#include "playlist.h"
#include <iostream>

PlayList::PlayList() /// Default Constructor - Should initalize a linkedlist
{
    start = nullptr;
    size = 0;
}

PlayList::PlayList(Song* song) /// Constructor - Should initalize a LinkedList with the given Song
{
    size++;
    PlayListNode* temp = new PlayListNode;
    temp->song = song;
    temp->next = nullptr;
    start = temp;
}

PlayListNode* PlayList::insertSong(Song* song, int position)
{
    /**
     * @ param  Song* Struct containing the song's meta information
     * @ param  Position Where the song should be in the playlist. This value is 0 indexed (0 = first song to play)
     * @ return A pointer to the playlistnode that should have been inserted
     * Note: If position is greater than the size of the list, just append to the end
     */
    PlayListNode*temp = new PlayListNode;
    temp->song = song;
    temp->next = nullptr;
    
    if(position == 0 && start == nullptr) ///when empty linkedlist, insert in front
    {
        start = temp;
        size++;
    }
    else if (position == 0 && start != nullptr) ///insert in front, non-empty linkedlist
    {
        temp->next = start;
        start = temp;
        size++;
    }
    else if (<#condition#>) ///inserting inbetween nodes within linked list
    {
        size++;
    }
}

int PlayList::getSize() /// return Size of playlist
{
    return size;
}

PlayListNode* PlayList::searchForSong(std::string title)
{
    /**
     * @ param  title Title of the song we want to search for
     * @ return A pointer to the PlayListNode, NULL if song not found
     * Note: Assume there are no repeat titles and one will match if it exists in the playlist
     */
    int counter = 0;
    song_title = title;
    
    while(counter < size)
    {
        
    }
}

int PlayList::songPosition(std::string title)
{
    /**
     * @ param  title Title of the song we want to search for
     * @ return The position of the song in the playlist, -1 if not found. this should be 0 indexed (0 being the first song in the list)
     */
    int counter = 0;
    song_title = title;
    
    while(counter < size)
    {
        
    }
    
}

PlayListNode* PlayList::getStart() /// return Pointer to the first node in the list
{
    return start;
}

int PlayList::getTotalPlayTime() /// Returns the total playtime of each song in the playlist (assuming each song's playtime is positive)
{
    if(total_playtime >= 0)
    {
        return total_playtime;
    }
    else
    {
        return -1;
    }
}

PlayList::~PlayList() /// Deconstructor
{
    PlayListNode* currentNode = start;
    PlayListNode* nextNode = nullptr;
    while (currentNode != nullptr)
    {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
}
