// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Mytree;
    std::ifstream file(filename);
    std::string word;
    std::string word1 = "";
    std::string word2 = "";
    while (!file.eof()) {
        file >> word;
        word1 = word2 = "";
        if (w.find(",") != -1) {
                int length = word.length();
                int find = word.find(",");
                if ((find != length - 1) && ((word[find + 1] >= 'A' && word[find + 1] <= 'Z') ||
                    (word[find + 1] >= 'A' && word[find + 1] <= 'z'))) {
                for (int item = 0; item < find; item++) {
                    word1 += word[item];
                }
                for (int item = find+1; item < length; item++) {
                    word2 += word[item];
                }
            }
        }
        if (word1 != "" && word2 != "") {
            word1 = get_corr_word(word1);
            word2 = get_corr_word(word2);
            Mytree.add(word1);
            Mytree.add(word2);
        } else {
            w = get_corr_word(word);
            Mytree.add(word);
        }
    }
    return Mytree;
}

std::string get_corr_word(std::string s) {
    if (s[0] < '0' || s[0] > '9') {
        while ((s[0] >= 32 && s[0] <= 64) || (s[0] >= 91 && s[0] <= 96))
        s.erase(0, 1);
        if (s != "") {
            char c = s[s.length() - 1];
            while ((c >= 32 && c <= 64) || (c >= 91 && c <= 96)) {
                s.pop_back();
                c = s[s.length() - 1];
            }
        }
        int it = 0;
        if (s != "") {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '\'') {
                    it = i;
                }
            }
            if (it != 0)
                s.erase(it);
        }
        if (s != "") {
            for (int i = 0; i < s.length(); i++) {
                s[i] = tolower(s[i]);
            }
        }
    } else {
        s.clear();
    }
    return s;
}
