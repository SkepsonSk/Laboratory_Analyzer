cmake_minimum_required(VERSION 3.21)
project(lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab main.cpp obj/icsv.cpp obj/icsv.h obj/column/column.cpp obj/column/column.h obj/operation/operation.cpp obj/operation/operation.h obj/program/program.cpp obj/program/program.h obj/program/program_state.h obj/operation/operations/arithmetic_operation.cpp obj/operation/operations/arithmetic_operation.h obj/operation/operations/z2_avg_deviation_operation.cpp obj/operation/operations/z2_avg_deviation_operation.h obj/operation/operations/cross_correlation_operation.cpp obj/operation/operations/cross_correlation_operation.h obj/operation/operations/halt_operation.cpp obj/operation/operations/halt_operation.h)
