/****************************************************************************************************************************
Title        : Playlist.h
Author       : Lanique Peterson
Description  : Header file for the Playlist class
****************************************************************************************************************************/
#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>

struct Song{

    Song() ///Default Constructor - initialization of a song
    {
        title = "";
        durationInSeconds = 0;
    };

    Song(std::string assignedTitle) ///Parameterized std::string Constructor
    {
        title = assignedTitle;
        durationInSeconds = 0;
    };

    Song(std::string assignedTitle,int songDuration) ///Parameterized std::string and int Constructor
    {
        title = assignedTitle;
        durationInSeconds = songDuration;
    }; ///when this parameterized constructor is called when creating an object, both public data members will be updated

    std::string title;
    int durationInSeconds;
};

struct PlayListNode  ///initialization of a node
{                    /// O  <----Node/Circle, Part of Linked List, it contains a song, and a pointer to another node/circle
    
    Song* song; ///Song data, from our struct, always dereference the passed in song to this data member. new_node->song = song;
    PlayListNode* next = nullptr; ///playlist node pointer
};

class PlayList  ///our linkedlist; the linking of the nodes/circles
{               ///O->O->O->O     <----This is the linked list
    
    private:
        PlayListNode* start = nullptr; //pointer to the starting point.
        PlayListNode* end = nullptr; //pointer to the end point.
        int size = 0;

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
    
        /**
         * Display playlist
         * @ param  None
         * @ return None
         */
        
        void display(PlayListNode* start);
};
#endif
