cmake_minimum_required(VERSION 3.21)
project(ACPP_Vortrag)

set(CMAKE_CXX_STANDARD 20)

add_executable(a_pointer a_pointer.cpp)
add_executable(b_speicher b_speicher.cpp)
add_executable(c_worst_case c_worst_case.cpp)
add_executable(c_worst_case_solv c_worst_case_solv.cpp)
add_executable(d_unique_ptr d_unique_ptr.cpp)
add_executable(e_shared_ptr e_shared_ptr.cpp)
add_executable(f_weak_ptr f_weak_ptr.cpp)
add_executable(g_best_practice g_best_practice.cpp)
add_executable(h_aufgabe h_aufgabe.cpp)