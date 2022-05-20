cmake_minimum_required(VERSION 3.21)
project(vortrag)

set(CMAKE_CXX_STANDARD 20)

add_executable(aufgabe aufgabe.cpp)
add_executable(a_worst_case a_worst_case.cpp)
add_executable(b_worst_case_solv b_worst_case_solv.cpp)
add_executable(speicher speicher.cpp)
add_executable(pointer pointer.cpp)
add_executable(unique_ptr unique_ptr.cpp)
add_executable(shared_ptr shared_ptr.cpp)
add_executable(weak_ptr weak_ptr.cpp)
add_executable(best_practice best_practice.cpp)