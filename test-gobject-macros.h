#ifndef TEST_GOBJECT_MACROS_H_
#define TEST_GOBJECT_MACROS_H_

#include <glib-object.h>

/**
 * SECTION: test-gobject-macros.h
 * @title: GObject macros
 * @short_description: In this file, we test the G_DECLARE_FINAL_TYPE
 * and G_DECLARE_DERIVABLE_TYPE macros.
 *
 * We're particularly interested in smart filtering.
 */

G_BEGIN_DECLS

/**
 * TestDerivable:
 *
 * A derivable class declared with convenience macros.
 */

#define TEST_TYPE_DERIVABLE (test_derivable_get_type ())
G_DECLARE_DERIVABLE_TYPE (TestDerivable, test_derivable, TEST, DERIVABLE, GObject)

struct _TestDerivableClass
{
  GObjectClass parent_class;

  gpointer _padding[10];
};

/**
 * TestFinal:
 *
 * A final class, not meant to be inherited from, declared with convenience
 * macros.
 */

#define TEST_TYPE_FINAL (test_final_get_type ())
G_DECLARE_FINAL_TYPE (TestFinal, test_final, TEST, FINAL, GObject)

G_END_DECLS

#endif
