tools_sources = [
  'bidir_multimap.cpp'
]

tools_lib = library(
  'tools',
  tools_sources,
  cpp_args : used_warnings,
  include_directories : tools_includes
)

tools_dep = declare_dependency(
  link_with : tools_lib,
  include_directories : tools_includes
)
