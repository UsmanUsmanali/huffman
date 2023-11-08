cmake_minimum_required(VERSION 3.27)

project(
    Huffman
    VERSION 0.1
    LANGUAGES CXX
)

add_library(
    back
    src/decoder.cc src/decoder.h
    src/encoder.cc src/encoder.h
    src/huffman_node.cc src/huffman_node.h
)

target_compile_features(
    back
    PUBLIC cxx_std_20
)

add_executable(
    huffman
    main.cc
)

target_compile_features(
    huffman
    PUBLIC cxx_std_20
)

target_link_libraries(
    huffman
    PRIVATE back
)
