#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(vector<FrequencyListElement> & dict) {
    int len = dict.size();
    for(int i=0; i<len; i++) {
        ptr = new HuffmanNode;
        ptr->e = FrequencyListElement(dict[i].key, dict[i].frequency);
        ptr->leftChild = nullptr;
        ptr->rightChild = nullptr;
        tree.push_back(ptr);
    }
} 

HuffmanTree::~HuffmanTree() {

}

using namespace std;
// We make it a rule to define left child as 0, and right child as 1.
void HuffmanTree::construct() {
    int len = tree.size();
    for(int i=0; i<len-1; i++) {
        sort(tree.begin(), tree.end(), [](HuffmanNode * &a, HuffmanNode * &b) {
            return a->e.frequency < b->e.frequency;
        });
        ptr = new HuffmanNode;
        ptr->e = FrequencyListElement(0, tree[0]->e.frequency + tree[1]->e.frequency);
        ptr->leftChild = tree[0];
        ptr->rightChild = tree[1];
        tree.erase(tree.begin());
        tree.erase(tree.begin());
        tree.push_back(ptr);
    }
    ptr = tree.front();
}

vector<DictElement> HuffmanTree::getDict() {
    traverse(ptr);
    return dict;
}

void HuffmanTree::traverse(HuffmanNode *next, int code) {
    if(!next->leftChild && !next->rightChild) {
        DictElement e;
        e.key = next->e.key;
        e.code = code;
        dict.push_back(e);
    } else {
        int lCode, rCode;
        lCode = rCode = code << 1;
        rCode += 1;
        traverse(next->leftChild, lCode);
        traverse(next->rightChild, rCode);
    }
}