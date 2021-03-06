# Copyright 2011 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Include python install macros
########################################################################
include(GrPython)
if(NOT PYTHONINTERP_FOUND)
    return()
endif()

########################################################################
# Install python sources
########################################################################
GR_PYTHON_INSTALL(
    FILES
    __init__.py
        py_channel_estimator_cc.py DESTINATION ${GR_PYTHON_DIR}/gfdm
)

########################################################################
# Handle the unit tests
########################################################################
include(GrTest)

add_subdirectory(pygfdm)

set(GR_TEST_TARGET_DEPS gnuradio-gfdm)
set(GR_TEST_PYTHON_DIRS ${CMAKE_BINARY_DIR}/swig)
GR_ADD_TEST(qa_modulator_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_modulator_cc.py)
GR_ADD_TEST(qa_sync_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_sync_cc.py)
GR_ADD_TEST(qa_cyclic_prefixer_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_cyclic_prefixer_cc.py)
GR_ADD_TEST(qa_simple_modulator_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_simple_modulator_cc.py)
GR_ADD_TEST(qa_transmitter_chain_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_transmitter_chain_cc.py)
GR_ADD_TEST(qa_simple_receiver_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_simple_receiver_cc.py)
GR_ADD_TEST(qa_advanced_receiver_sb_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_advanced_receiver_sb_cc.py)
GR_ADD_TEST(qa_resource_mapper_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_resource_mapper_cc.py)
GR_ADD_TEST(qa_frame_energy_detector_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_frame_energy_detector_cc.py)
GR_ADD_TEST(qa_simple_preamble_sync_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_simple_preamble_sync_cc.py)
GR_ADD_TEST(qa_resource_demapper_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_resource_demapper_cc.py)
GR_ADD_TEST(qa_remove_prefix_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_remove_prefix_cc.py)
GR_ADD_TEST(qa_extract_burst_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_extract_burst_cc.py)
GR_ADD_TEST(qa_py_channel_estimator_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_py_channel_estimator_cc.py)
GR_ADD_TEST(qa_channel_estimator_cc ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/qa_channel_estimator_cc.py)
