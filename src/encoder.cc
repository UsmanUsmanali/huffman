#include "encoder.h"
#include <memory>
#include <queue>
#include <vector>

namespace huffman {
std::unordered_map<char, unsigned long>
Encoder::countFreq(const std::vector<char> &v) const {
  std::unordered_map<char, unsigned long> freq(255);
  for (const auto &c : v) {
    freq[c]++;
  }
  return freq;
}

std::vector<std::shared_ptr<Node>> Encoder::createNodes(
    const std::unordered_map<char, unsigned long> &freq) const {
  std::vector<std::shared_ptr<Node>> nodes;
  for (const auto &pair : freq) {
    nodes.push_back(std::make_shared<Node>(pair.first, pair.second));
  }
  return nodes;
}

std::shared_ptr<Node>
Encoder::createTree(const std::vector<std::shared_ptr<Node>> &nodes) const {
  std::priority_queue<std::shared_ptr<Node>> pq(nodes.begin(), nodes.end());

  while (pq.size() > 1) {
    auto left = pq.top();
    pq.pop();
    auto right = pq.top();
    pq.pop();
    auto parent =
        std::make_shared<Node>(0, left->freq + right->freq, left, right);
    pq.push(parent);
  }

  return pq.top();
}

void Encoder::encode(std::istream &in, std::ostream &out) const {
  auto chars = getChars(in);
  auto freq = countFreq(chars);
  auto nodes = createNodes(freq);
  auto root = createTree(nodes);
}
} // namespace huffman