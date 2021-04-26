#include <stdlib.h>
#include <time.h>
#include "random_number_generator.h"

/* credit:
 * https://stackoverflow.com/questions/19870276/generate-a-random-number-from-0-to-10000000
 */
int generate_random_number(int range)
{
    if (range > RAND_MAX)
    {
        unsigned long x;
        x = rand();
        x <<= 15;   
        x ^= rand();
        x %= (range+1);

        return (int)x;
    } else {
        return rand() % range + 1;
    }
}