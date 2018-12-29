cmake_minimum_required(VERSION 3.12)
project(excellenteam_erez_c_dna_analyzer_omairino)

set(CMAKE_CXX_STANDARD 98)

set(BOOST_INCLUDEDIR C:/Users/Administrator/Downloads/boost_1_69_0/boost_1_69_0)
add_executable(excellenteam_erez_c_dna_analyzer_omairino MODEL/DnaSequence.cpp MODEL/DnaSequence.h VIEW/Cmd.cpp VIEW/Cmd.h CONTROLLER/Controller.cpp CONTROLLER/Controller.h MODEL/Command.cpp MODEL/Command.h MODEL/WriteReadFile.cpp MODEL/WriteReadFile.h MODEL/CommandParser.cpp MODEL/CommandParser.h)