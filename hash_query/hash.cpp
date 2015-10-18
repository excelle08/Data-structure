/*

名称              生成多项式               简记式*        应用举例
CRC-4               x4+x+1                  3           ITU G.704
CRC-8               x8+x5+x4+1              31          DS18B20
CRC-12              x12+x11+x3+x2+x+1       80F 　       
CRC-16              x16+x15+x2+1            8005        IBM SDLC
CRC-ITU**           x16+x12+x5+1            1021        ISO HDLC, ITU X.25, V.34/V.41/V.42, PPP-FCS,ZigBee
CRC-32              x32+x26+x23+...+x2+x+1  04C11DB7    ZIP, RAR, IEEE 802 LAN/FDDI, IEEE 1394, PPP-FCS
CRC-32c             x32+x28+x27+...+x8+x6+1 1EDC6F41    SCTP
*/

// 1100000000000011

#include <cstring>
#include "hash.h"

Hash::Hash(const char *data, int length) {
    this->data = new char [length];
    for(int i=0; i<length; i++) {
        this->data[i] = (data[i]);
    }
    this->length = length;
}

Hash::~Hash() {

}

int_16 Hash::crc16() {
    int_16 shift = CRC_SEED;
    int_16 data = 0, val = 0;

    for(int i=0; i<length; i++) {
        for(int j=0; j<8; j++) {
            val = ((this->data[i] << j) & 0x80) ^ ((shift & 0x8000) >> 8);

            shift <<= 1;

            if(val != 0) {
                shift ^= 0x1021;
            }
        }
    }

    return shift;
}
