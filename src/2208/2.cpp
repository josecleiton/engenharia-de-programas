#include <iostream>
#include <map>
#include <vector>

using input_arr = std::vector<std::pair<double, double>>;

enum classes { ST = 1, ND, RD };

std::map<classes, double> solve(const input_arr &input, const double a,
                                const double b) {
  const auto item_percentage = 100.0 / (double)input.size();
  auto result = std::map<classes, double>();

  for (const auto &p : input) {
    if (p.first < a) {
      result[ST] += item_percentage;
    } else if (p.first > b) {
      result[ND] += item_percentage;
    } else {
      result[RD] += item_percentage;
    }
  }

  return result;
}

int main(int argc, char const *argv[]) {
  std::cout.precision(2);

  const double a = 1;
  const double b = 2;
  const input_arr input = {{2, 3}, {3, 4}, {5, 5}, {1, 1}, {0, 2}, {2, 2}};

  for (const auto &[key, value] : solve(input, a, b)) {
    std::cout << key << ": " << std::fixed << value << '\n';
  }

  return 0;
}
