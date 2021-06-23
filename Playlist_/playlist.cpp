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
    size = 1;
    PlayListNode* newNode = new PlayListNode;
    newNode->song = song;
    newNode->next = nullptr;
    start = newNode;
}

PlayListNode* PlayList::insertSong(Song* song, int position)
{
    PlayListNode* current_node = start;
    PlayListNode* newNode = new PlayListNode;
    newNode->song = song;
    newNode->next = nullptr;
    //int counter = 0;

    if(size == 0) ///when empty linkedlist, insert in front
    {
        start = newNode;
    }
    else
    {
        if (position == 0) ///insert in front, non-empty linkedlist
        {
            newNode->next = start;
            start = newNode;
        }
        else if (position > size) ///insert in back,
        {
            while (current_node->next != nullptr)
            {
                current_node = current_node->next;
            }
            current_node->next = newNode;
        }
        else ///inserting inbetween nodes within linked list
        {
            for (int i = 0; i < position - 1; i++)
                current_node = current_node->next;
            
            newNode->next = current_node->next;
            current_node->next = newNode;
        }
    }
    size++;
    return newNode;
}

int PlayList::getSize() /// return Size of playlist
{
    return size;
}

PlayListNode* PlayList::searchForSong(std::string title)
{
    PlayListNode* newNode = start;
    if (newNode->song->title == title)
        return newNode;
    
    while (newNode->next != nullptr)
    {
        newNode = newNode->next;
        if (newNode->song->title == title)
            return newNode;
    }
    return nullptr;
}

int PlayList::songPosition(std::string title)
{
    PlayListNode* current_node = start;
    int current_position = 0;
    
    if (current_node->song->title == title)
    {
        return current_position;
    }
    current_position++;
    
    while ( current_node->next != nullptr )
    {
        current_node = current_node->next;
        if (current_node->song->title == title)
        {
            return current_position;
        }
        current_position++;
    }
    return -1;
}

PlayListNode* PlayList::getStart() /// return Pointer to the first node in the list
{
    return start;
}

int PlayList::getTotalPlayTime() /// Returns the total playtime of each song in the playlist (assuming each song's playtime is positive)
{
    int total_playtime = 0;
    PlayListNode* currentNode = start;
    
    while (currentNode != nullptr) {
        total_playtime = total_playtime + currentNode->song->durationInSeconds;
        currentNode = currentNode->next;
    }
    return total_playtime;
}

PlayList::~PlayList() /// Deconstructor
{
    PlayListNode* current_node = start;
    PlayListNode* next_node = nullptr;
    while (current_node != nullptr)
    {
        next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }
}

void display(PlayListNode* start) ///custom function
{
    while (start != nullptr)
    {
        std::cout << start->song << " ";
        start = start->next;
    }
}
