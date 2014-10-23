#ifndef _TORRENT_H_
#define _TORRENT_H_
/*
 * Torrent File Format
 *
 * All file is a Dictionary
 * 
 * announce: Tracker server URL(string)
 * announce-list(alter): Alter tracker server URL(string)
 * creation date(alter): Time of the torrent created. Std Unix time(integer)
 * comment(alter): Comment(string)
 * created by(alter): Author
 * info: A dictionary about main infomation
 *
 * info with single file:
 *     length: File lenght, byte(integer)
 *     md5sum(alter): MD5 sum, 32 bytes, useless(string)
 *     name: File name(string)
 *     piece length: Block size, byte(integer)
 *     pieces: SHA1 Hash value, 20 bytes(binary)
 * info with multi file:
 *     files: A dictionary
 *         length: File length, byte(integer)
 *         md5sum(alter): MD5 sum, as single file before
 *         path: File path and name(list)
 *     name: Top dir name(string)
 *     piece length: As single file before
 *     pieces: As single file before
 */

//String type
//<len>:<string>  eg. 4:char -> "char"

//Integer type
//i<integer>e   eg. i1024e -> 1024
//Forbid starting with 0
#define TORRENT_INTEGER_HEAD 'i'
#define TORRENT_INTEGER_TAIL 'e'

//List type
//l<bencoding>e  eg. l4:test5:abcdee -> ["test","abcde"]
#define TORRENT_LIST_HEAD 'l'
#define TORRENT_LIST_TAIL 'e'

//Dictionary type
//d<bencoding(char)><bencoding>e 
//eg. d4:path4:/usrfilename8:test.txte -> {"path":"/usr","filename":"test.txt"}
#define TORRENT_DIC_HEAD 'd'
#define TORRENT_DIC_TAIL 'e'

typedef enum{
    TORRENT_VALUE_BIN     = 0,
    TORRENT_VALUE_INTEGER = 1,
    TORRENT_VALUE_STRING  = 2,
    TORRENT_VALUE_LIST    = 3,
    TORRENT_VALUE_DIC     = 4,
    TORRENT_VALUE_MAX     = 5,
}torrent_value_type_t;

#endif
