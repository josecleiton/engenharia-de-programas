#include <iostream>
#include <map>
#include <vector>

std::map<double, double> solve(const std::vector<double> &input) {
  const auto item_percentage = 100.0 / (double)input.size();

  auto result = std::map<double, double>();

  for (const auto &x : input) {
    result[x] += item_percentage;
  }

  return result;
}

int main(int argc, char const *argv[]) {
  std::cout.precision(2);

  const std::vector<double> input = {1, 2, 23, 3,  3, 3, 3,  3, 32,
                                     2, 1, 1,  23, 2, 3, 32, 4};

  for (const auto &[key, value] : solve(input)) {
    std::cout << key << ": " << std::fixed << value << '\n';
  }

  return 0;
}