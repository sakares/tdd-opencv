# This makefile was adopt from the Makefile in Driver-Awareness Project by VGL Team
# For more information please contact : mdailey@ait.ac.th
# A sample Makefile for building Google Test and using it in user
# tests.  Please tweak it to suit your environment and project.  You
# may want to move it to your project's root directory.

GTEST_DIR = ./gtest-1.6.0

# Where to find user code.
USER_DIR = ..

# Flags passed to the preprocessor.
CPPFLAGS += -I$(GTEST_DIR) -I$(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra

# created to the list. You can add more test suite such as camera_unittest, ransac_unittest or etc.
TESTS = convolution_unittest

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
								$(GTEST_DIR)/include/gtest/internal/*.h

############################## Custom Variables ##############################
#OpenCV headers
OPENCV_INCL = `pkg-config opencv --cflags`
OPENCV_LIBS = `pkg-config opencv --libs`
##############################################################################

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o : $(GTEST_SRCS_)
	$(CXX)  $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX)  $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

##############################################################################
convolution.o : $(USER_DIR)/convolution.cpp $(USER_DIR)/convolution.h \
  							$(GTEST_HEADERS)
	$(CXX)  $(OPENCV_INCL)  $(CXXFLAGS) -c $(USER_DIR)/convolution.cpp

convolution_unittest.o : convolution_unittest.cpp \
                      	 $(USER_DIR)/convolution.h $(GTEST_HEADERS)
	$(CXX)   $(OPENCV_INCL) $(CPPFLAGS) $(CXXFLAGS) -c \
	convolution_unittest.cpp 

convolution_unittest : convolution.o convolution_unittest.o \
							gtest_main.a
	$(CXX) $(OPENCV_INCL) $(OPENCV_LIBS) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
##############################################################################
