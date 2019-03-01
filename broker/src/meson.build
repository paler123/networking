broker_sources = [
  'network.cpp'
]

broker_lib = library(
  'broker_lib',
  broker_sources,
  cpp_args : used_warnings,
  include_directories : broker_includes,
  dependencies : tools_dep
)

broker_private_includes = include_directories('.')

broker_dep = declare_dependency(
  link_with : broker_lib,
  include_directories : broker_includes,
  dependencies : tools_dep
)

broker_exe = executable(
  'broker_exe',
  'main.cpp',
  dependencies : [broker_dep, zmq_dep, proto_interface],
  cpp_args : ['-std=c++17']
)
