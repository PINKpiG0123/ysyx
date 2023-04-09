#include <stdlib.h>
#include <assert.h>
#include <nvboard.h>
#include <Vtop.h>

void nvboard_bind_all_pins(Vtop *top);

static TOP_NAME dut;
int main(int argc, char ** argv){



  //insert pins
  nvboard_bind_all_pins(&dut);
  nvboard_init();
  //sim_main.cpp


  while (1) {
  int a = rand() & 1;
  int b = rand() & 1;
  dut.a = a;
  dut.b = b;
  dut.eval();
  printf("a = %d, b = %d, f = %d\n", a, b, dut.f);


  assert(dut.f == (a ^ b));
  //here is the end
  nvboard_update();
}

  nvboard_quit();

}

