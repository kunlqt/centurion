# centurion
Centurion Platform

docker run -it -w /centurion -v $PWD:/centurion -e HOST_PERMS="$(id -u):$(id -g)" vaskomitanov/centurion-devel bash
mkdir -p build && cd build && cmake .. && make -j

