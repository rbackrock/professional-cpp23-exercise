#include <iostream>
#include <string_view>
#include <string>
#include <algorithm>
#include <vector>
#include <format>

std::string sort(std::string_view str1) {
  std::vector<int> tmp_v1 {};
  for (const auto it : str1) {
    tmp_v1.push_back(static_cast<int>(it));
  }
  std::sort(tmp_v1.begin(), tmp_v1.end(), [](const int &a, const int &b) {
    return a < b;
  });

  char c_arr[tmp_v1.size()];
  for (int i = 0; i < tmp_v1.size(); ++i) {
    c_arr[i] = static_cast<char>(tmp_v1[i]);
  }

  return std::string { c_arr, sizeof(c_arr) / sizeof(char) };
}

int main() {
  std::string input_str1 {};
  std::string input_str2 {};

  std::cout << "请输入一段字符串, Enter 结束:" << std::endl;
  std::cin >> input_str1;
  std::cout << "请再输入一段字符串, Enter 结束:" << std::endl;
  std::cin >> input_str2;

  std::string result_str = sort(std::string_view { input_str1 + input_str2 });
  std::cout << std::format("最终排序的结果为{}", result_str) << std::endl;

  return 0;
}