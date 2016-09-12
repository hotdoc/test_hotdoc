#include "test-gobject-macros.h"

G_DEFINE_TYPE (TestDerivable, test_derivable, G_TYPE_OBJECT)

struct _TestFinal
{
  TestDerivable parent;
};

G_DEFINE_TYPE (TestFinal, test_final, G_TYPE_OBJECT)

static void
test_derivable_class_init (TestDerivableClass *klass)
{
}

static void
test_derivable_init (TestDerivable *self)
{
}

static void
test_final_class_init (TestFinalClass *klass)
{
}

static void
test_final_init (TestFinal *self)
{
}
