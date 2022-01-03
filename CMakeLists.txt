cmake_minimum_required(VERSION 3.1.0)
project(r-type)

add_definitions("-fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -luuid")
set(CONAN_DISABLE_CHECK_COMPILER True)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/bin")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

set(CLIENT_SRC
    client/src/client_sys.cpp
    engine/src/componentArray.cpp
    engine/src/componentManager.cpp
    engine/src/systemManager.cpp
    engine/src/entityManager.cpp
    engine/src/coordinator.cpp
    engine/src/systems/transformSystem.cpp
    engine/src/systems/ColliderSystem.cpp
    engine/src/systems/spriteSystem.cpp
    engine/src/Game.cpp
    client/src/r-type.cpp
    client/src/main.cpp
    client/src/ClassClient.cpp
    )

set (CLIENT_HEADERS
    client/include/clientInclude.hpp
    client/include/client_sys.hpp
    engine/include/components/transformComponent.hpp
    engine/include/components/colliderComponent.hpp
    engine/include/components/spriteComponent.hpp
    engine/include/componentArray.hpp
    engine/include/componentManager.hpp
    engine/include/defines.hpp
    engine/include/system.hpp
    engine/include/systemManager.hpp
    engine/include/coordinator.hpp
    engine/include/systems/transformSystem.hpp
    engine/include/systems/colliderSystem.hpp
    engine/include/systems/spriteSystem.hpp
    engine/include/Game.hpp
    client/include/r-type.hpp
    client/include/ClassClient.hpp
    )

set(SERVER_SRC
    server/src/main.cpp
    server/src/server_sys.cpp
    server/src/ClassServer.cpp
)

set (SERVER_HEADERS
    server/include/server_sys.hpp
    server/include/ClassServer.hpp
)

include(
    ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake
)

conan_basic_setup(TARGETS)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sprites DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)

#find_package(SqliteOrm REQUIRED)

add_executable(r-type_client ${CLIENT_SRC} ${CLIENT_HEADERS})
target_link_libraries(r-type_client CONAN_PKG::sfml)
target_link_libraries(r-type_client CONAN_PKG::boost)
target_link_libraries(r-type_client CONAN_PKG::asio)

add_executable(r-type_server ${SERVER_SRC} ${SERVER_HEADERS})
target_link_libraries(r-type_server CONAN_PKG::sfml)
target_link_libraries(r-type_server CONAN_PKG::boost)
target_link_libraries(r-type_server CONAN_PKG::asio)