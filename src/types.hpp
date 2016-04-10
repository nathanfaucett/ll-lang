#ifndef __LL_TYPES_HPP__
#define __LL_TYPES_HPP__


namespace ll {
    typedef unsigned char byte;

    typedef signed long int intsize;
    typedef signed char int8;
    typedef signed short int16;
    typedef signed int int32;
    typedef signed long int int64;

    typedef unsigned long int uintsize;
    typedef unsigned char uint8;
    typedef unsigned short uint16;
    typedef unsigned int uint32;
    typedef unsigned long int uint64;

    typedef float float32;
    typedef double float64;

    #ifndef EOF
    #define EOF ((int)-1)
    #endif

    typedef std::vector<int32> String;
}


#endif
