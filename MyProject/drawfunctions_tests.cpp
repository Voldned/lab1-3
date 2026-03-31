#include <assert.h>
#include "drawfunctions.h"

// Lightweight unit checks for sign-change helper used by local-extrema logic.
int main()
{
	assert(HasDerivativeSignChange(1.0f, -1.0f));
	assert(HasDerivativeSignChange(-0.5f, 0.5f));
	assert(!HasDerivativeSignChange(1.0f, 0.5f));
	assert(!HasDerivativeSignChange(-1.0f, -0.5f));
	assert(!HasDerivativeSignChange(0.0f, 2.0f));
	assert(!HasDerivativeSignChange(-2.0f, 0.0f));
	return 0;
}
