#include <iostream>
#include <bitset>
#include <fstream>
#include "HuffmanTree.h"

using namespace std;

char *toBinaryCode(int number);

int main(int argc, char const *argv[])
{
    string str;
    vector<FrequencyListElement> freqList;

    // Parse CLI args
    if(argc != 3) {
        cout << "Usage: " << argv[0] << "[-s <string>] | [-f <file>]" << endl;
        return 0;
    } else {
        if(!strcmp(argv[1], "-s")) {
            str = argv[2];
        } else if(!strcmp(argv[1], "-f")) {
            ifstream fp(argv[2]);
            if(!fp) {
                cout << "Error opening the file - " << argv[2] << endl;
                return 1;
            }
            while(!fp.eof()) {
                str.push_back(fp.get());
            }
            fp.close();
        }
    }

    // Analyze
    int str_size = str.size();
    for(int i=0; i<str_size; i++) {
        char c = str[i];
        bool flagExist = false;
        for(int j=0; j<freqList.size(); j++) {
            if(freqList[j].key == c) {
                freqList[j].frequency += 1;
                flagExist = true;
                break;
            }
        }
        if(!flagExist) {
            FrequencyListElement e;
            e.key = c;
            e.frequency = 1;
            freqList.push_back(e);
        }
    }
    // Print the frequency table
    cout << "Char\tASCII\tFrequency" << endl;
    for(int i=0; i<freqList.size(); i++){
        cout << ((freqList[i].key>=32 && freqList[i].key <= 127)?freqList[i].key:'*') << "\t" << (int)freqList[i].key << "\t" << freqList[i].frequency << endl; 
    }
    cout << "===========================" << endl;
    // Start building Huffman tree and get result table

    HuffmanTree huffman(freqList);
    huffman.construct();
    vector<DictElement> dict = huffman.getDict();

    cout << "Char\tASCII\tHuffman Code" << endl;
    for(int i=0; i<dict.size(); i++) {
        cout << ((dict[i].key>=32 && dict[i].key <= 127)?dict[i].key:'*') << "\t" << (int)dict[i].key << "\t" << toBinaryCode(dict[i].code) << " = " << dict[i].code << endl;
    }
    return 0;
}

char *toBinaryCode(int number) {
    int length, num = number;
    for(length=1; number>0; number>>=1, length++){}

    char *code = new char[length+1];
    for(int i=length-1; i>=0; i--){
        int k = num & 1;
        if(k == 1) {
            code[i] = '1';
        } else {
            code[i] = '0';
        }
        num >>= 1;
    }
    code[length] = '\0';
    return code;
}