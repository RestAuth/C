set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/FindModules) 
find_package(CURL REQUIRED)
find_package(JANSSON REQUIRED)
add_library(restauth SHARED restauth.c helpers.c)
target_link_libraries(restauth ${CURL_LIBRARIES} ${JANSSON_LIBRARIES})

install(TARGETS restauth LIBRARY DESTINATION lib)
install(FILES restauth.h PUBLIC_HEADER DESTINATION include)
