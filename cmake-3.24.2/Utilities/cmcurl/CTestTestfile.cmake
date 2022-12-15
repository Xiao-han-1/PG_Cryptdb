# CMake generated Testfile for 
# Source directory: /root/pakages/copy/cryptdb/cmake-3.24.2/Utilities/cmcurl
# Build directory: /root/pakages/copy/cryptdb/cmake-3.24.2/Utilities/cmcurl
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[curl]=] "curltest" "http://open.cdash.org/user.php")
set_tests_properties([=[curl]=] PROPERTIES  _BACKTRACE_TRIPLES "/root/pakages/copy/cryptdb/cmake-3.24.2/Utilities/cmcurl/CMakeLists.txt;1546;add_test;/root/pakages/copy/cryptdb/cmake-3.24.2/Utilities/cmcurl/CMakeLists.txt;0;")
subdirs("lib")
