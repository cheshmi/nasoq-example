cmake_minimum_required(VERSION 3.1)


# set NASOQ properties such BLAS Type, etc
set(NASOQ_BLAS_BACKEND "OpenBLAS" CACHE STRING "BLAS implementation for NASOQ to use")
set(NASOQ_USE_CLAPACK  ON CACHE STRING "Use CLAPACK as the LAPACK implementaiton")


add_subdirectory(nasoq)

if(NOT DEFINED NASOQ_ROOT)
    set(NASOQ_ROOT_DIR "nasoq") #assumed the example folder is within nasoq
else()
    set(NASOQ_ROOT_DIR "${NASOQ_ROOT}")
endif()

# Set include and library directories
set(NASOQ_INC ${NASOQ_ROOT_DIR}/include)
set(NASOQ_LIB ${NASOQ_ROOT_DIR}/lib/)
include_directories(${NASOQ_INC} )
link_directories(${NASOQ_LIB})

### NASOQ example
project(NASOQ_Test)
set(CMAKE_CXX_STANDARD 11)
add_executable(NASOQ_Test ${SOURCE_FILES_NAS} nasoq_main.cpp)
target_link_libraries(NASOQ_Test PRIVATE
        nasoq
        )

set(SOURCE_FILES_NAS_ST nasoq_step_main.cpp)
add_executable(NASOQ_Step_Test ${SOURCE_FILES_NAS_ST} )
target_link_libraries(NASOQ_Step_Test PRIVATE
        nasoq
        )


### LBL example
project(LBL_Test)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES_NAS lbl_main.cpp)
add_executable(LBL_Test ${SOURCE_FILES_NAS} lbl_main.cpp)
target_link_libraries(LBL_Test PRIVATE
        nasoq
        )


### LBL SOMOD
project(LBLSOMOD_Test)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES_NASOM lbl_somod_main.cpp)
add_executable(LBLSOMOD_Test ${SOURCE_FILES_NASOM} lbl_somod_main.cpp)
target_link_libraries(LBLSOMOD_Test PRIVATE
        nasoq
        )


### NAOSQ Eigen
project(NASOQ_EIGEN_Test)
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES_NASOQ nasoq_eigen_test.cpp)
add_executable(NASOQ_EIGEN_Test ${SOURCE_FILES_NASOQ})
target_link_libraries(NASOQ_EIGEN_Test PRIVATE
        nasoq
        )