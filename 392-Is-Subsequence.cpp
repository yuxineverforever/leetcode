/**
 *
 * A Easy One.
 * @param s
 * @param t
 * @return
 */
bool isSubsequence(char * s, char * t){
    while (*s && *t) {
        if (*s == *t) {
            s++;
        }
        t++;
    }
    if (*s == '\0') {
        return true;
    } else {
        return false;
    }
}