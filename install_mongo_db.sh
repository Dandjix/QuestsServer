curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r4.1.4/mongo-cxx-driver-r4.1.4.tar.gz
tar -xzf mongo-cxx-driver-r4.1.4.tar.gz
cd mongo-cxx-driver-r4.1.4/build

cmake ..                                \
    -DCMAKE_BUILD_TYPE=Release          \
    -DCMAKE_CXX_STANDARD=17

cmake --build .
cmake --build . --target install
ldconfig