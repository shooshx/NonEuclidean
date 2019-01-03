rem -O3
rem -g3 -O0 
rem run C:\lib\emscripten\emsdk\emsdk_env.bat before first time

%EMSCRIPTEN%\emcc -g3 -O0   ^
-o non_euc.html -std=c++11 --bind -s ENVIRONMENT=web -s ALLOW_MEMORY_GROWTH=0 -s TOTAL_MEMORY=33554432 -s EXPORTED_FUNCTIONS="['_main', '_run_main']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['cwrap']" -s WASM=0  -s USE_WEBGL2=1 -s ASSERTIONS=1 -s SAFE_HEAP=1 -s DEMANGLE_SUPPORT=1  -D_DEBUG -D_LIBCPP_DEBUG=1 --memory-init-file 0 -I../NonEuclidean ../NonEuclidean/Camera.cpp ../NonEuclidean/Collider.cpp ../NonEuclidean/FrameBuffer.cpp ../NonEuclidean/Mesh.cpp ../NonEuclidean/Object.cpp ../NonEuclidean/Physical.cpp ../NonEuclidean/Player.cpp ../NonEuclidean/Portal.cpp ../NonEuclidean/Resources.cpp ../NonEuclidean/Shader.cpp ../NonEuclidean/Texture.cpp ../NonEuclidean/Level1.cpp ../NonEuclidean/Level2.cpp ../NonEuclidean/Level3.cpp ../NonEuclidean/Level4.cpp ../NonEuclidean/Level5.cpp ../NonEuclidean/Level6.cpp ../NonEuclidean/Engine.cpp ../NonEuclidean/Input.cpp ../NonEuclidean/Main.cpp  -s ERROR_ON_UNDEFINED_SYMBOLS=0 --preload-file ../NonEuclidean/Shaders@/Shaders --preload-file ../NonEuclidean/Meshes@/Meshes

