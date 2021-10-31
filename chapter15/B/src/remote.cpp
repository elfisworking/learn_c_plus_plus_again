#include "tvf.h"

// if useing "inline", this function should be in header file.
// inline int Remote::getNum(TV & tv) {
//     return tv.num;
// }
// otherwsie not using "inline"
int Remote::getNum(TV & tv) {
    return tv.num;
}