#ifndef HASH_H
#define HASH_H

// Preset value
#define CRC_SEED 0xFFFF
// This represents the standard polynomial of CRC16 - x16+x15+x2+1
#define POLY16 0x1021

typedef unsigned short int_16;

class Hash
{
public:
    Hash(const char *data, int length);
    virtual ~Hash();
    int_16 crc16();

private:
    char * data;
    int length;
};

#endif // HASH_H
