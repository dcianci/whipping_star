include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable (DLSens DLSens.cc)
add_executable (DLCovar DLCovariance.cc)
add_executable (UnfoldScale UnfoldScale.cxx)
add_executable (DLUnfold DLUnfold.cc)

target_link_libraries (DLSens SBNfitlib tinyxmllib EventWeight)
target_link_libraries (DLCovar SBNfitlib tinyxmllib EventWeight)
target_link_libraries (UnfoldScale SBNfitlib tinyxmllib EventWeight)
target_link_libraries (DLUnfold SBNfitlib tinyxmllib EventWeight)

