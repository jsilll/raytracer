add_subdirectory(rt)

add_executable(raytracer main.cpp)

target_link_libraries(raytracer LINK_PUBLIC rt)