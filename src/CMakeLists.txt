add_subdirectory(Utility)
add_subdirectory(WindowServer)

add_executable(main main.cpp)
add_executable(server server.cpp)
add_executable(client client.cpp)

target_link_libraries(main rpc)
target_link_libraries(server rpc)
target_link_libraries(client rpc)