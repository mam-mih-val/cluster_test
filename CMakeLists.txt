project(fuck_ncx)

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

find_package(ROOT REQUIRED)

add_executable(fuck_ncx src/main.cc)
target_link_libraries(fuck_ncx ROOT::Tree ROOT::RIO ROOT::Net ROOT::Graf ROOT::ProofDraw ROOT::Graf3d ROOT::RooFitCore)