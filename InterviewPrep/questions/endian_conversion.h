#ifndef ENDIAN_CONVERSION_H
#define ENDIAN_CONVERSION_H
union uint_data{
    unsigned int v;
    char bytes[4];
};

unsigned int swap_endian32(unsigned int val);

#endif
