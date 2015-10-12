#ifndef HASH_H
#define HASH_H


class Hash
{
public:
    Hash(char *data);
    virtual ~Hash();
    unsigned char * crc16();
    char * hexDigest();
    char * base64Encode();

private:
    char * data;
    unsigned char * result;
};

#endif // HASH_H
