# lar_tools



# Using Netbeans

1. Setup Netbeans configuration. (Force Netbeans to call setup.sh)

$ roscd
$ cd ..
$ echo ". $(pwd)/setup.sh" > ~/.netbeans/{version}/etc/netbeans.conf

2. Create Netbeans project From existing Source. If you are using catkin_make then you'll have a boilerplate CMakeLists.txt in myworkspace/src, so if you point Netbeans at that "CMake project" then you can mimic the behavior of catkin_make by:

running cmake in myworkspace/build
passing -DCATKIN_DEVEL_SPACE=../devel to cmake
passing -DCMAKE_INSTALL_PREFIX=../install to cmake

