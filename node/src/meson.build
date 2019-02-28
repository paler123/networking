node_sources = [
]

node_lib = library(
  'node_lib',
  node_sources,
  cpp_args : used_warnings,
  include_directories : node_includes,
  dependencies : tools_dep
)

node_private_includes = include_directories('.')

node_dep = declare_dependency(
  link_with : node_lib,
  include_directories : node_includes,
  dependencies : tools_dep
)

node_exe = executable(
  'node_exe',
  'main.cpp',
  dependencies : [node_dep, zmq_dep]
)
