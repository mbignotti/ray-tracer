cmake_minimum_required(VERSION 3.31.6)
project(RayTracer VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(RayTracer src/main.cpp)

# for cmake modules if u wnat to add some libraries
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

# flags for gcc or clang
set(GCC_COVERAGE_COMPILE_FLAGS "")

if(NOT MSVC)
	set(CMAKE_CXX_FLAGS	"${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif()

# ========= deps ================
# vulkan loader
find_package(Vulkan REQUIRED)

# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_VULKAN_STATIC ON CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

# glm
add_subdirectory(vendor/glm)

# imgui
add_subdirectory(vendor/imgui)

# ========= linking deps ==========
target_link_libraries(RayTracer PUBLIC Vulkan::Vulkan)
target_link_libraries(RayTracer PUBLIC glfw)
target_link_libraries(RayTracer PUBLIC imgui)
target_link_libraries(RayTracer PUBLIC glm)
# =================================

# ========== include dir ==========
target_include_directories(RayTracer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(RayTracer PUBLIC "${PROJECT_SOURCE_DIR}/vendor/stb_image")
# =================================