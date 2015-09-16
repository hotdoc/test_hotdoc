#include "hello.h"

/**
 * SECTION:testhello
 * @shortdescription: This is a hello test
 *
 * A #TestHello will certainly be able to greet you at some
 * point, so be prepared.
 */

struct _TestHello
{
  GObject parent;
};

G_DEFINE_TYPE(TestHello, test_hello, G_TYPE_OBJECT)

static void
test_hello_class_init (TestHelloClass *klass)
{
}

static void
test_hello_init (TestHello *self)
{
}
