cmd_Release/obj.target/addon/hello.o := c++ '-DNODE_GYP_MODULE_NAME=addon' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/Users/xing/.node-gyp/9.5.0/include/node -I/Users/xing/.node-gyp/9.5.0/src -I/Users/xing/.node-gyp/9.5.0/deps/uv/include -I/Users/xing/.node-gyp/9.5.0/deps/v8/include  -Os -gdwarf-2 -mmacosx-version-min=10.7 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++0x -stdlib=libc++ -fno-rtti -fno-exceptions -fno-threadsafe-statics -fno-strict-aliasing -MMD -MF ./Release/.deps/Release/obj.target/addon/hello.o.d.raw   -c -o Release/obj.target/addon/hello.o ../hello.cc
Release/obj.target/addon/hello.o: ../hello.cc \
  /Users/xing/.node-gyp/9.5.0/include/node/node_api.h \
  /Users/xing/.node-gyp/9.5.0/include/node/node_api_types.h \
  ../test_class.h
../hello.cc:
/Users/xing/.node-gyp/9.5.0/include/node/node_api.h:
/Users/xing/.node-gyp/9.5.0/include/node/node_api_types.h:
../test_class.h:
