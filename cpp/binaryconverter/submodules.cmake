# Factorial excercise
# Copyright (C) 2024 by Piotr Kmiecik
# E-mail: info@aserio.pl

find_package(Git)
if(Git_FOUND)
        message("Git version ${GIT_VERSION_STRING} found.")
        option(UPDATE_SUBMODULES "Update submodules." ON)
        if(UPDATE_SUBMODULES)
                execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                                RESULT_VARIABLE RESULT)

                if(NOT RESULT EQUAL "0")
                        message(FATAL_ERROR "Error updating submodules: ${RESULT}.")
                        return()
                endif()
                message(STATUS "Git submodules updated successfully.")
        endif()
endif()
