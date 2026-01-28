/**
 * 要求用户输入未知数量的单词，当用户输入*时停止输入，将所有单个单词存储在 vector 中，
 * 输入完成后，计算最长单词的长度，最后，按列输出所有单词，一行5个，列的宽度基于最长的单词，
 * 输入以列为中心的单词，并用 | 字符分割列
 */

#include <iostream>
#include <vector>
#include <string>
#include <format>

using namespace std;

int main()
{
	// A vector to store all words.
	vector<string> words;

	// Ask the user to enter words until * is entered.
	cout << "Input words. * to stop:" << endl;
	while (true) {
		string word;
		cin >> word;
		if (word == "*") {
			break;
		}
		words.push_back(word);
	}

	// Find longest word.
	size_t longestWord{ 0 };
	for (const auto& word : words) {
		if (word.size() > longestWord) {
			longestWord = word.size();
		}
	}

	// Print words in columns. The width of the columns is
	// based on the length of the longest word.
	unsigned count{ 0 };
	for (const auto& word : words) {
		cout << format("| {:^{}} ", word, longestWord);
		if (++count == 5) {
			cout << format("|") << endl;
			count = 0;
		}
	}
	if (count != 0) {
		cout << format("|") << endl;
	}
}