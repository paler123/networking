broker_test_sources = [
  'main.cpp',
  'network.cpp'
]

broker_ut_exe = executable(
  'broker_ut',
  broker_test_sources,
  dependencies : [broker_dep, catch2_dep],
  include_directories : broker_private_includes,
  cpp_args : used_warnings
)

test(
  'broker_ut',
  broker_ut_exe
)
