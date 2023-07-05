#include <stdio.h>
#define MACRO_NO_ARG Hello
#define MACRO_WITH_ARGS(x) x

// catenation happens right away
#define CAT_(x,y) x ## y
//expansion happens before concatenation
#define CAT(x,y) CAT_(x,y)

#define STRINGIZE(x) #x
#define TO_STRING(x) STRINGIZE(x)


int main( int argc, char *argv[] ) {

    //printf("%s\n",MACRO_NO_ARG);
    //printf("%s\n",MACRO_WITH_ARGS);
    //printf("%s\n",CAT(MACRO_NO_ARG, MACRO_WITH_ARGS));

    // In stringify example we saw that this is how you stringify macros
    // but this still fails because the concatenation does not expand into macros
    printf("%s\n", TO_STRING(CAT_(MACRO_NO_ARG,MACRO_WITH_ARGS(Hi))));

    // to concatenate the stringification of two macros you must do:
    printf("%s\n", TO_STRING(CAT(MACRO_NO_ARG,MACRO_WITH_ARGS(Hi))));
    //so that you let the expansion to take place before the concatenation

    //Other logical errors to show that expansion must take place
    printf("%s\n", STRINGIZE(CAT_(MACRO_NO_ARG,MACRO_WITH_ARGS(Hi))));
    printf("%s\n", STRINGIZE(CAT(MACRO_NO_ARG,MACRO_WITH_ARGS(Hi))));
    return 0;
}
