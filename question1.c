#include <stdio.h>

int ques1(int x) {
    int z;
    int y  = ~x+1;
    z= (~(y|x));
    z = (z >> 31);

    return (z & 1);

}
