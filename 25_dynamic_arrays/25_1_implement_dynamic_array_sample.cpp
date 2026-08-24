#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>

class DynamicArray {
public:
    explicit DynamicArray(std::size_t size)
        : total_size_(size), size_(0), array_(std::make_unique<int[]>(size)) {}

    void append(int val) {
        if (size_ == total_size_) {
            resize(total_size_ + extend_size_);
        }

        array_[size_] = val;
        size_++;
    }

    int get(int i) const {
        check_index(i);
        return array_[static_cast<std::size_t>(i)];
    }

    void set(int i, int val) {
        check_index(i);
        array_[static_cast<std::size_t>(i)] = val;
    }

    std::size_t size() const {
        return size_;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::runtime_error("No value");
        }

        size_--;
    }

private:
    static constexpr std::size_t extend_size_ = 10;

    std::size_t total_size_;
    std::size_t size_;
    std::unique_ptr<int[]> array_;

    void resize(std::size_t new_total_size) {
        std::unique_ptr<int[]> new_array =
            std::make_unique<int[]>(new_total_size);

        for (std::size_t i = 0; i < size_; i++) {
            new_array[i] = array_[i];
        }

        array_ = std::move(new_array);
        total_size_ = new_total_size;
    }

    void check_index(int i) const {
        if (i < 0 || static_cast<std::size_t>(i) >= size_) {
            throw std::out_of_range("out of range");
        }
    }
};

int main() {
    // Example
    DynamicArray array(10);
    for (int i = 0; i < 15; i++) {
        array.append(i);
    }

    for (std::size_t i = 0; i < array.size(); i++) {
        std::cout << array.get(static_cast<int>(i)) << '\n';
    }

    array.set(0, 100);

    array.pop_back();
    for (std::size_t i = 0; i < array.size(); i++) {
        std::cout << array.get(static_cast<int>(i)) << '\n';
    }

    return 0;
}
