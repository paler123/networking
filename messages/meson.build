gen = generator(protoc,
  output    : ['@BASENAME@.pb.cc', '@BASENAME@.pb.h'],
  arguments : ['--proto_path=@CURRENT_SOURCE_DIR@', '--cpp_out=@BUILD_DIR@', '@INPUT@']
)

generated = gen.process(['defs.proto'])

proto_interface = declare_dependency(
  sources : generated,
  dependencies : proto_dep
)
