#pragma once
#include <memory>
#include <string>

namespace huffman {
struct Node {
  char data;
  int freq;
  std::shared_ptr<Node> left, right;
  Node(char data, int freq, std::shared_ptr<Node> left = nullptr,
       std::shared_ptr<Node> right = nullptr)
      : data(data), freq(freq), left(left), right(right) {}

  bool operator<(const Node &other) const { return freq > other.freq; }

  bool isLeaf() const { return left == nullptr && right == nullptr; }
};
} // namespace huffman
