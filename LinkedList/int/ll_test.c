#include "ll_int.h"

int main(int argc, char * argv)
{
	int i;
	struct ll *list = new_ll();
	for (i = 0; i < 100; i++)
		ll_push_back(list, i);
	ll_print(list);
	for (i = 0; i < 50; i++)
		ll_pop_back(list);
	ll_print(list);
	for (i = 0; i < 100; i++)
		ll_pop_back(list);
	ll_print(list);
	ll_push_back((struct ll*)0, 1);
	ll_pop_back((struct ll*)0);
	ll_print((struct ll*)0);

	for (i = 0; i < 20; i++)
		ll_insert(list, i, 100);

	ll_print(list);

	for (i = -1; i > -20; i--)
		ll_insert(list, i, 0);

	ll_print(list);

	for (i = 0; i < 40; i+=5)
		ll_insert(list, 999, i);

	ll_print(list);
}
