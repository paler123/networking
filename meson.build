project('netowork_ex', 'cpp',
    version : '0.1',
    default_options : ['warning_level=3', 'cpp_std=c++17', 'werror=true']
)

warnings = [
    '-Werror',
    '-Wall',
    '-Wextra',
    '-Wnon-virtual-dtor',
    '-Wcast-align',
    '-Wunused',
    '-Woverloaded-virtual',
    '-Wpedantic',
    '-Wmisleading-indentation',
    '-Wduplicated-cond',
    '-Wlogical-op',
    '-Wnull-dereference',
    '-Wdouble-promotion',
    '-Wformat=2',
    '-Wlifetime'
]

used_warnings = []
cxx = meson.get_compiler('cpp')
if cxx.get_argument_syntax() == 'gcc'
    foreach warn : warnings
        if cxx.has_argument(warn)
            used_warnings += warn
        endif
    endforeach
endif

boost_dep = dependency('boost')
catch2_dep = dependency('catch2', fallback : ['catch2', 'catch2_dep'])
zmq_dep = dependency('cppzmq')

protoc = find_program('protoc')
proto_dep = dependency('protobuf')

subdir('messages') # protobuf interfaces
subdir('tools')
subdir('broker')
subdir('node')
