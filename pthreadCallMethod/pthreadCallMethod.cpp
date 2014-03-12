#include<stdio.h>
#include<pthread.h> // pthread_create
#include<unistd.h>  // sleep

extern "C" {
  typedef void* (*ThreadFunc_t)(void*);
}

class Test {
private:
  int number;

public:
  Test() {
    number = 5;
  }
  ~Test() {
  }

  // static function to call test_function
  static void* thread_function(void *arg) {
    Test* test = (Test*)arg;
    test->test_function();
    return NULL;
  }

  // Target class member method
  // We want to call this function from pthread
  void* test_function() {
    printf("Called successfully, number = %d\n", number);
    return NULL;
  }
};

// Call class member function from pthread
int main(void) {
  Test test;
  pthread_t thread;
  pthread_create(&thread, NULL, (ThreadFunc_t)Test::thread_function, (void *)&test);
  sleep(1); // Wait for pthread to call target function
  return 0;
}
