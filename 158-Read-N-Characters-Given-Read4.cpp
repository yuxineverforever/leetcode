/**
 * Q: The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 *
 * A: See the following code and comment.
 *https://leetcode-cn.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
 */

class Solution {
public:
    char *buf4 = new char[4];
    int buf4Index = 0;
    int buf4Size = 0;
    int read(char *buf, int n) {
        int index = 0;
        while(index<n){

            // move the bytes stored in internal buffer to external buffer
            while(buf4Index<buf4Size && index<n){
                buf[index++] = buf4[buf4Index++];
            }

            // decide whether we need another read.
            if(index<n){
                buf4Size = read4(buf4);
                buf4Index = 0;
                if(buf4Size==0) break;
            }

        }
        return index;
    }
};