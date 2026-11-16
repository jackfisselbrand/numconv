cmake_minimum_required(VERSION 3.12)
project(numconv)

include(FetchContent)

FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v7.0.1  # Replace with a version, tag, or commit hash
)

FetchContent_MakeAvailable(ftxui)

add_executable(numconv)
target_sources(numconv PRIVATE
	src/main.cpp
	src/numconv.cpp
)
target_link_libraries(numconv
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)