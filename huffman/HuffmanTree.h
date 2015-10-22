#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstddef>

struct FrequencyListElement {
    char key;
    int frequency;
    FrequencyListElement(char k, int f){
        key = k;
        frequency = f;
    }
    FrequencyListElement(){}
};

struct HuffmanNode {
    FrequencyListElement e;
    HuffmanNode *leftChild, *rightChild;
    HuffmanNode(){}
};

struct DictElement{
    char key;
    int code;
};

using namespace std;

class HuffmanTree
{
public:
    HuffmanTree(vector<FrequencyListElement> & dict);
    virtual ~HuffmanTree();
    void construct();
    vector<DictElement> getDict();

private:
    HuffmanNode *ptr;
    vector<HuffmanNode *> tree;
    vector<DictElement> dict;

    void traverse(HuffmanNode *next=nullptr, int code=0);
};

#endif // HUFFMAN_TREE_H
