#include <iostream>
#include <bitset>
#include "HuffmanTree.h"

using namespace std;

char *toBinaryCode(int number);

int main(int argc, char const *argv[])
{
    string str;
    vector<FrequencyListElement> freqList;
    cout << "Enter a string to analyze huffman tree:" << endl;
    getline(cin, str);

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
        cout << freqList[i].key << "\t" << (int)freqList[i].key << "\t" << freqList[i].frequency << endl; 
    }
    cout << "===========================" << endl;
    // Start building Huffman tree and get result table

    HuffmanTree huffman(freqList);
    huffman.construct();
    vector<DictElement> dict = huffman.getDict();

    cout << "Char\tASCII\tHuffman Code" << endl;
    for(int i=0; i<dict.size(); i++) {
        cout << dict[i].key << "\t" << (int)dict[i].key << "\t" << bitset<32>(dict[i].code) << " = " << dict[i].code << endl;
    }
    return 0;
}
