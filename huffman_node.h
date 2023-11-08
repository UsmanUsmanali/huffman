namespace huffman {
struct Node {
  char data;
  int freq;
  Node *left, *right;
  Node(char data, int freq, Node *left = nullptr, Node *right = nullptr)
      : data(data), freq(freq), left(left), right(right) {}

  bool operator<(const Node &other) const { return freq > other.freq; }

  bool isLeaf() const { return left == nullptr && right == nullptr; }

  void print() const {
    std::cout << "data: " << data << ", freq: " << freq << std::endl;
  }

  void printTree() const {
    if (isLeaf()) {
      print();
      return;
    }
    left->printTree();
    right->printTree();
  }

  void printCode(std::string code, std::ostream &out) const {
    if (isLeaf()) {
      out << data << ": " << code << std::endl;
      return;
    }
    left->printCode(code + "0", out);
    right->printCode(code + "1", out);
  }

  void printCode(std::string code) const { printCode(code, std::cout); }

  ~Node() {
    delete left;
    delete right;
  }
};
} // namespace huffman
