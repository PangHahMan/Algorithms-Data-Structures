/* 
描述
输入一个英文句子，把句子中的单词(不区分大小写)按出现次数按从多到少把单词和次数在屏幕上输出来，次数一样的按照单词小写的字典序排序输出，要求能识别英文单词和句号。

输入描述：
输入为一行，由若干个单词和句号组成

输出描述：
输出格式参见样例。

示例1
输入：A blockhouse is a small castle that has four openings through which to shoot.
输出：
a:2
blockhouse:1
castle:1
four:1
has:1
is:1
openings:1
shoot:1
small:1
that:1
through:1
to:1
which:1
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 比较函数，用于排序
bool compare(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

// 将句子中的所有字母转换为小写
string toLowerCase(string &str) {
    for (auto &s: str) {
        if (s >= 'A' && s <= 'Z') {
            s += 32;
        }
    }
}

// 统计单词出现次数并输出结果
void wordFrequency(string &sentence) {
    //先将字符都转换成小写
    toLowerCase(sentence);
    unordered_map<string, int> wordCount;// 用于存储单词和其出现次数的映射

    size_t pos = 0;
    while (pos < sentence.size()) {
        // 找到下一个单词的起始位置,当pos位置不是字母,就往后遍历
        while (pos < sentence.size() && !isalpha(sentence[pos])) {
            pos++;
        }

        // 找到单词的结束位置
        size_t endPos = pos;
        while (endPos < sentence.size() && (isalpha(sentence[endPos]) || sentence[endPos] == '.')) {
            endPos++;
        }

        // 提取单词,endPos-pos就是单词的长度
        string word = sentence.substr(pos, endPos - pos);

        if (!word.empty()) {
            if (word.back() == '.') {
                word.pop_back();// 去除句号
            }
            wordCount[word]++;// 统计单词出现次数
        }

        //更新pos
        pos = endPos;
    }

    // 将单词和次数存储到向量中，并按要求排序
    vector<pair<string, int>> sortedWords(wordCount.begin(), wordCount.end());
    sort(sortedWords.begin(), sortedWords.end(), compare);

    // 输出结果
    for (const auto &entry: sortedWords) {
        cout << entry.first << ":" << entry.second << endl;
    }
}

int main() {
    string sentence;
    getline(cin, sentence);// 输入句子
    wordFrequency(sentence);

    return 0;
}

//https://www.nowcoder.com/practice/16f59b169d904f8898d70d81d4a140a0?tpId=94&tqId=31064&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fbit-kaoyan%2Fquestion-ranking&tPage=2