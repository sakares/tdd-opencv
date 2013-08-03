#include "../convolution.h"
#include <gtest/gtest.h>
#include <cv.h>
#include <highgui.h>
#include <stdlib.h> 
#include <iostream>

TEST(convolve1D, calculationIsCorrect) {

    // given
	int i; 
	float input[5] = {3.00, 4.00, 5.00, 0.00, 0.00};
	float output[5];
	float kernel[2] = {2,1};
	float expected[5] = {6.00, 11.00, 14.00, 5.00, 0.00};

    // when
	convolve1D(input, output, 5, kernel, 2);

    // then
	for(i = 0; i < (sizeof(expected)/sizeof(*expected)); i++){
		ASSERT_EQ(expected[i], output[i]);
	}
}
