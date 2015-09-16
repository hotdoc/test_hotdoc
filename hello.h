#ifndef TEST_HELLO_H_
#define TEST_HELLO_H_

#include <glib-object.h>

G_BEGIN_DECLS

#define TEST_TYPE_HELLO (test_hello_get_type ())

G_DECLARE_FINAL_TYPE (TestHello, test_hello, Test, HELLO, GObject)

G_END_DECLS

#endif
