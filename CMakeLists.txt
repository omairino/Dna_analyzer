cmake_minimum_required(VERSION 3.12)
project(excellenteam_erez_c_dna_analyzer_omairino)

set(CMAKE_CXX_STANDARD 98)

add_executable(excellenteam_erez_c_dna_analyzer_omairino MODEL/DnaSequence.cpp MODEL/DnaSequence.h CONTROLLER/main.cpp VIEW/CLI.cpp VIEW/CLI.h CONTROLLER/Controller.cpp CONTROLLER/Controller.h)