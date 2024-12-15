set (SOURCE
	"./Source/Private/main.cpp"
)

add_executable(HLSL2021 ${SOURCE})

target_include_directories(HLSL2021
PUBLIC
	Source/Public
PRIVATE
	./../../ThirdParty/DXC/inc)

target_link_directories(HLSL2021
PRIVATE
	./../../ThirdParty/DXC/lib/x64)
	
target_link_libraries(HLSL2021
PRIVATE
	dxcompiler.lib
)

add_custom_command(TARGET HLSL2021 POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/ThirdParty/DXC/bin/x64/dxcompiler.dll" "${CMAKE_BINARY_DIR}/HLSL2021/\$\(Configuration\)/dxcompiler.dll")

set_target_properties(HLSL2021 PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/HLSL2021")