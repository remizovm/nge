#include "nge.h"

int main(int argc, char* argv[])
{
  nge_init();
	while (nge_running()) {
    nge_update();
    nge_draw_point(1, 1);
    nge_draw_point(159, 1);
    nge_draw_point(1, 143);
    nge_draw_point(159, 143);
    nge_swap();
	}
  nge_quit();
}
