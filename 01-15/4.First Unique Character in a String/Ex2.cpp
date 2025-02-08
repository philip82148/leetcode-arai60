#if __has_include("../../debug.hpp")
#include "../../debug.hpp"
#endif
// ここまでローカルでのデバッグ用なので気にしないでください --------------------

#include <queue>
#include <set>
#include <stdexcept>

using namespace std;

// こちらは番外編です。入力がintのstreamだったときです。
// <時間>
// 15分
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
// - 若干分かりにくかったが、もう一度書き直したらわかりやすくなった
class SolutionStream {
 public:
  int firstUniqueNum(int num) {
    if (duplicated_numbers.contains(num)) {
      if (numbers.empty()) throw new range_error("No unique number was found");
      return numbers.front();
    }

    if (auto it = unique_numbers.find(num); it != unique_numbers.end()) {
      unique_numbers.erase(it);
      duplicated_numbers.insert(num);
    } else {
      unique_numbers.insert(num);
      numbers.push(num);
    }

    while (!numbers.empty() && duplicated_numbers.contains(numbers.front())) {
      numbers.pop();
    }

    if (numbers.empty()) throw new range_error("No unique number was found");
    return numbers.front();
  }

 private:
  queue<int> numbers;
  set<int> unique_numbers;
  set<int> duplicated_numbers;
};

// <時間>
// 不明
// <疑問・不安点(・個人的な感想、違う意見があれば教えてほしいもの)>
class SolutionStream2 {
 public:
  int firstUniqueNum(int num) {
    if (duplicated_numbers.contains(num)) {
      if (numbers.empty()) throw new range_error("No unique number was found");
      return numbers.front();
    }
    if (auto it = unique_numbers.find(num); it != unique_numbers.end()) {
      unique_numbers.erase(it);
      duplicated_numbers.insert(num);
      while (!numbers.empty() && duplicated_numbers.contains(numbers.front())) {
        numbers.pop();
      }
      if (numbers.empty()) throw new range_error("No unique number was found");
    } else {
      unique_numbers.insert(num);
      numbers.push(num);
    }
    return numbers.front();
  }

 private:
  queue<int> numbers;
  set<int> unique_numbers;
  set<int> duplicated_numbers;
};
