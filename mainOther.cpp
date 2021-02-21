#include "Windows.h"

int main()
{
	LiauWindows* windows = new LiauWindows;
	windows->createWindows();

	if (!windows->directX())
	{
		return 0;
	}

	while (windows->loop())
	{

	}
	windows->clearWindows();

	return 0;
}