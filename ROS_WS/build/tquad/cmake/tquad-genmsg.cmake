# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "tquad: 1 messages, 0 services")

set(MSG_I_FLAGS "-Itquad:/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(tquad_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg" NAME_WE)
add_custom_target(_tquad_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "tquad" "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(tquad
  "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tquad
)

### Generating Services

### Generating Module File
_generate_module_cpp(tquad
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tquad
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(tquad_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(tquad_generate_messages tquad_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg" NAME_WE)
add_dependencies(tquad_generate_messages_cpp _tquad_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tquad_gencpp)
add_dependencies(tquad_gencpp tquad_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tquad_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(tquad
  "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/tquad
)

### Generating Services

### Generating Module File
_generate_module_eus(tquad
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/tquad
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(tquad_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(tquad_generate_messages tquad_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg" NAME_WE)
add_dependencies(tquad_generate_messages_eus _tquad_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tquad_geneus)
add_dependencies(tquad_geneus tquad_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tquad_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(tquad
  "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tquad
)

### Generating Services

### Generating Module File
_generate_module_lisp(tquad
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tquad
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(tquad_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(tquad_generate_messages tquad_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg" NAME_WE)
add_dependencies(tquad_generate_messages_lisp _tquad_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tquad_genlisp)
add_dependencies(tquad_genlisp tquad_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tquad_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(tquad
  "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/tquad
)

### Generating Services

### Generating Module File
_generate_module_nodejs(tquad
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/tquad
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(tquad_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(tquad_generate_messages tquad_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg" NAME_WE)
add_dependencies(tquad_generate_messages_nodejs _tquad_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tquad_gennodejs)
add_dependencies(tquad_gennodejs tquad_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tquad_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(tquad
  "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tquad
)

### Generating Services

### Generating Module File
_generate_module_py(tquad
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tquad
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(tquad_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(tquad_generate_messages tquad_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/cherif/OMCRI4CP/T-quad/ROS_WS/src/tquad/msg/LineSensor.msg" NAME_WE)
add_dependencies(tquad_generate_messages_py _tquad_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(tquad_genpy)
add_dependencies(tquad_genpy tquad_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS tquad_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tquad)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/tquad
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(tquad_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/tquad)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/tquad
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(tquad_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tquad)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/tquad
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(tquad_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/tquad)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/tquad
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(tquad_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tquad)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tquad\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/tquad
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(tquad_generate_messages_py std_msgs_generate_messages_py)
endif()
