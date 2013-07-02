# "test/Makefile"

CLANG_BUILDDIR = /Volumes/Isolde/builds/LLVM/gcc40-cmake-build
CLANG_PATH = ${CLANG_BUILDDIR}/bin
CXX = $(CLANG_PATH)/clang++

HEADER_INCLUDE = -I../include
HEADER_INCLUDE += -cxx-isystem /Users/fang/local/src/LLVM-svn/libcxx.git/include
# for unwind.h
HEADER_INCLUDE += -I/usr/lib/gcc/powerpc-apple-darwin8/4.0.1/include
BUILT_LIB = ../lib/libc++abi.1.dylib
SOURCE_LIB = $(BUILT_LIB)
SOURCE_LIB += -L/Users/fang/local/src/LLVM-svn/libcxx-stage1-build/lib

CXXFLAGS = -std=c++0x -stdlib=libc++
CXXFLAGS += -O0 -no-integrated-as
# TRIPLE = powerpc-apple-darwin8

.SUFFIXES: .cpp

TEST_SOURCES = \
	catch_array_01.cpp \
	catch_array_02.cpp \
	catch_class_01.cpp \
	catch_class_02.cpp \
	catch_class_03.cpp \
	catch_class_04.cpp \
	catch_const_pointer_nullptr.cpp \
	catch_function_01.cpp \
	catch_function_02.cpp \
	catch_member_data_pointer_01.cpp \
	catch_member_function_pointer_01.cpp \
	catch_member_pointer_nullptr.cpp \
	catch_pointer_nullptr.cpp \
	catch_ptr.cpp \
	catch_ptr_02.cpp \
	dynamic_cast14.cpp \
	dynamic_cast3.cpp \
	dynamic_cast5.cpp \
	dynamic_cast_stress.cpp \
	test_aux_runtime.cpp \
	test_demangle.cpp \
	test_exception_storage.cpp \
	test_fallback_malloc.cpp \
	test_guard.cpp \
	test_vector1.cpp \
	test_vector2.cpp \
	test_vector3.cpp \
	unwind_01.cpp \
	unwind_02.cpp \
	unwind_03.cpp \
	unwind_04.cpp \
	unwind_05.cpp

TESTS = $(TEST_SOURCES:.cpp=)
all: $(TESTS)

.cpp:
	$(CXX) $(CXXFLAGS) $(HEADER_INCLUDE) $< $(SOURCE_LIB) $(LIBS) -o $@

$(TESTS): $(BUILT_LIB)
TESTS_ENVIROMENT = DYLD_LIBRARY_PATH=../lib

check: $(TESTS)
	for t in $(TESTS) ; \
	do $(TESTS_ENVIROMENT) ./$$t ; \
	done

clean:
	rm -f $(TESTS)

