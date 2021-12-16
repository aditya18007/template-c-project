cmake_minimum_required(VERSION 3.15)

project(dispersion_tool C)
set(TARGET ${PROJECT_NAME})

set(CMAKE_C_STANDARD 99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(
        HEADERS
        "src/utils/logging.h"
        "src/utils/memory.h"
        "src/utils.h"
        "src/dns.h"
        "ext/log_c/src/log.h"
)

set(
        SOURCES
        "main.c"
        "src/utils/logging.c"
        "src/utils/memory.c"
        "src/utils/utils.c"
        "src/dns.c"
        "ext/log_c/src/log.c"
)
include_directories(  ${CMAKE_SOURCE_DIR}/ext/log_c/src)
add_executable(dispersion_tool ${SOURCES} ${HEADERS})