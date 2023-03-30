
cmake_minimum_required( VERSION 3.8 )

project ("HelloWorld")
set(TARGET_NAME ${PROJECT_NAME})
add_executable(${TARGET_NAME})

func_target_build_options(${TARGET_NAME})

# src
target_sources (${TARGET_NAME} PRIVATE
	main.cpp
)

# library
target_link_libraries(${TARGET_NAME} PRIVATE
	${wxWidgets_LIBRARIES}
)


