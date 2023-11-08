#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>

#include "huffman_node.h"

namespace huffman {
class Encoder {
  std::vector<char> getChars(std::istream &in) const;

  std::unordered_map<char, unsigned long>
  countFreq(const std::vector<char> &v) const;

  std::vector<std::shared_ptr<Node>>
  createNodes(const std::unordered_map<char, unsigned long> &freq) const;

  std::shared_ptr<Node>
  createTree(const std::vector<std::shared_ptr<Node>> &nodes) const;

public:
  void encode(std::istream &in, std::ostream &out) const;
};
} // namespace huffman
