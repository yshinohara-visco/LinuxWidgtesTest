# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)

project ("LinuxWidgetsTest")

# wxWidgetsの準備
find_package(wxWidgets REQUIRED COMPONENTS core base adv )
include(${wxWidgets_USE_FILE}) # インクルードパス等はここで全体に適用される
message("wxWidgets_USE_FILE = ${wxWidgets_USE_FILE}")
message("wxWidgets_INCLUDE_DIRS = ${wxWidgets_INCLUDE_DIRS}")
message("wxWidgets_LIBRARY_DIRS = ${wxWidgets_LIBRARY_DIRS}")
message("wxWidgets_LIBRARIES = ${wxWidgets_LIBRARIES}")

# 共通のビルド設定
function(func_target_build_options target_name)
	set_target_properties(${target_name} PROPERTIES
		CXX_STANDARD 17
		CXX_EXTENSIONS ON
	)

	target_compile_options(${target_name} PUBLIC
		$<$<CONFIG:Release>:-O3 >
		$<$<CONFIG:Debug>:-g>
		-MMD -MP --pedantic
		-mfpu=neon  -mfloat-abi=hard
		-Wall -Wextra -Wno-unknown-pragmas -Wno-switch
		-Wno-unused-but-set-variable -Wno-pointer-arith -Wno-unused-parameter -Wno-psabi
	)
endfunction(func_target_build_options)

# ビルド成果物はビルドルートに作る
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH  ${PROJECT_BINARY_DIR})

# ---------ここまで準備-------

# サブディレクトリの追加
add_subdirectory(Hello)

