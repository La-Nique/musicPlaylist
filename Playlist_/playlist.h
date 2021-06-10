/****************************************************************************************************************************
Title        : Playlist.h
Author       : Lanique Peterson
Description  : Header file for the Playlist class
****************************************************************************************************************************/
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

struct Song{

    Song(){};

    Song(std::string assignedTitle){
    };

    Song(std::string assignedTitle,int songDuration){
    };

    std::string title;
    int durationInSeconds;
};

struct PlayListNode{
    Song* song;
    PlayListNode* next;
};

class PlayList{
    public:

        /**
        * Default Constructor - Should initalize a linkedlist
        * @ param  None
        * @ return None
        */
        PlayList();

        /**
        * Constructor - Should initalize a LinkedList with the given Song 
        * @ param  Song*
        * @ return None
        */
        PlayList(Song* song);

        /**
        * @ param  Song* Struct containing the song's meta information
        * @ param  Position Where the song should be in the playlist. This value is 0 indexed (0 = first song to play)
        * @return A pointer to the playlistnode that should have been inserted
        * Note: If position is greater than the size of the list, just append to the end
        */
        PlayListNode* insertSong(Song* song, int position);

        /**
        * @ param  None
        * @return Size of playlist
        */
        int getSize();

        /**
        * @param  title Title of the song we want to search for 
        * @return A pointer to the PlayListNode, NULL if song not found
        * Note: Assume there are no repeat titles and one will match if it exists in the playlist
        */
        PlayListNode* searchForSong(std::string title);
        
        /**
        * @param  title Title of the song we want to search for 
        * @return The position of the song in the playlist, -1 if not found. this should be 0 indexed (0 being the first song in the list)
        */
        int songPosition(std::string title);

        /**
        * @ param  None
        * @return Pointer to the first node in the list
        */
        PlayListNode* getStart();

        /**
        * @ param  None
        * @return Returns the total playtime of each song in the playlist (assuming each song's playtime is positive)
        */
        int getTotalPlayTime();

        /**
        * Deconstructor
        * @ param  None
        * @ return None
        */
        ~PlayList();

};
#endif