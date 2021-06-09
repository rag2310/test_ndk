cmake_minimum_required(VERSION 3.4.1)

find_library(
        log-lib
        log)

add_library(
        native-lib
        SHARED
        src/main/cpp/native-lib.cpp
        src/main/cpp/Calculator.cpp
        src/main/cpp/Calculator.h
        src/main/cpp/db/sqlite3.c
        src/main/cpp/db/sqlite3.h
        src/main/cpp/db/sqlite3ext.h
        src/main/cpp/db/shell.c
        ${log-lib}
)

target_link_libraries(
        native-lib
        ${log-lib}
)