
#ifndef __PUSH_BOX_BASE_H__
#define __PUSH_BOX_BASE_H__
////////////////////////////////////////////////////////////////////////////////

// // OS

// #if defined(WIN32)
// #elif defined(__linux__)
// #else
// #error This OS system is not supported!
// #endif

// // headers

// #ifdef WIN32
// #define WIN32_LEAN_AND_MEAN
// #include <windows.h>
// #include <io.h>
// #include <direct.h>
// #define _USE_MATH_DEFINES
// #include <math.h>
// #else
// #include <limits.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <sys/wait.h>
// #include <pthread.h>
// #include <unistd.h>
// #include <iconv.h>
// #include <fcntl.h>
// #include <signal.h>
// #include <dlfcn.h>
// #include <semaphore.h>
// #endif

#include <cstdint>
#include <cfloat>
#include <limits>
#include <cmath>

#include <cassert>
#include <stdexcept>

#include <cstring>
#include <string>
#include <cwchar>

#include <locale>
#include <ctime>

#include <memory>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

#include <sstream>
#include <fstream>
#include <iostream>

#include <functional>
#include <tuple>

#include <atomic>
#include <thread>
#include <mutex>
#include <chrono>

#include <regex>
#include <utility>

//C++17
#ifdef CPP_17
#include <filesystem>
#include <any>
#include <memory_resource>
#endif

#endif


