#include <vector>
template <typename T>
void cutVector(std::vector<T>& input, int number) {
    if (number >= 0 && input.size() >= number)
        input = std::vector<T>(input.begin(), input.end() - number);
};