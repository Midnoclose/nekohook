
file(GLOB sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")

AddNekohook(test EXTERNAL ${sources})
AddNekohook(dummytest EXTERNAL ${sources})
target_compile_definitions(nekohook-dummytest PRIVATE -DNEKOHOOK_DUMMYTEST=1)
