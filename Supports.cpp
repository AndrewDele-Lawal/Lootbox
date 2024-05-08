#include <string>
#include <iostream>


static bool y_or_n_check(const std::string& checker) {
	return (checker == "y" || checker == "n");
}

static void sleep(float seconds) {
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while (clock() < startClock + secondsAhead);
    return;
}

//static bool is_numb_of_items_a_numb(int numb_of_itemss) {
//	if (numb_of_itemss != int()) {
//		return false;
//	}
//	else {
//		return true;
//	}
//}