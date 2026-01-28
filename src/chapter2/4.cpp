/**
 * 编写一个程序，要求用户输入未知数量的浮点数，
 * 并将所有数字存储在 vector 中，键入每个数字之后都按 Enter 键，
 * 当用户输入数字 0 时，停止输入更多的数字。要从控制台读取浮点数，请使用 cin 方法与第一章输入整数值方法相同，
 * 使用一个两列表格式化所有数字，其中列以不同的方式格式化数字，表中的每一行对应一个输入的数字
 */

#include <vector>
#include <iostream>
#include <format>

using namespace std;

int main()
{
	// A vector to store all values.
	vector<double> values;

	// Ask the user to enter values until 0 is entered.
	cout << "Input values, one at a time followed by Enter. 0 to stop:" << endl;
	while (true) {
		double value;
		cin >> value;
		if (value == 0.0) {
			break;
		}
		values.push_back(value);
	}

	// Format the values in a table with a couple of columns.
	for (auto value : values) {
		cout << format("{0:16e} | {0:12f} | {0:<12g} | {0:#>+12g}", value) << endl;
	}

	return 0;
}