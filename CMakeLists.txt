cmake_minimum_required(VERSION 3.14) # FetchContent precisa >= 3.14
project(learning-gtest-gmock LANGUAGES CXX)

enable_testing()

include(FetchContent)

# Baixa o GoogleTest/GoogleMock direto do GitHub
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2 # versão estável atual (2024/2025)
)

# Opções para evitar conflito
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK ON CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Adiciona subdiretórios de estudo
add_subdirectory(gtest)
add_subdirectory(gmock)
