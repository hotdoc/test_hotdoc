#include "hello.h"

struct _TestHello
{
  GObject parent;
};

G_DEFINE_TYPE(TestHello, test_hello, TEST_TYPE_HELLO)

static void
test_hello_class_init (TestHelloClass *klass)
{
}

static void
test_hello_init (TestHello *self)
{
}
