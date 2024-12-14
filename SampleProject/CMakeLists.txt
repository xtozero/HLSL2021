set(HEADER
	"./Source/Public/Point2d.h"
)

set (SOURCE
	"./Source/Private/Main.cpp"
)

add_executable(sample_project ${HEADER} ${SOURCE})

target_include_directories(sample_project
PUBLIC
	Source/Public)
