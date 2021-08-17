add_subdirectory(Utility)
add_subdirectory(WindowServer)

add_executable(server server.cpp)
target_link_libraries(server rpc)

add_executable(client client.cpp)
target_link_libraries(client rpc)
