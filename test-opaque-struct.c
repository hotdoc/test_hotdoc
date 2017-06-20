#include "test-opaque-struct.h"

G_DEFINE_BOXED_TYPE (TestOpaqueStruct, test_opaque_struct,
    (GBoxedCopyFunc) test_opaque_struct_ref,
    (GBoxedFreeFunc) test_opaque_struct_unref);

struct _TestOpaqueStruct
{
  volatile gint refcount;
};

/**
 * test_opaque_new:
 *
 * Returns: A new TestOpaqueStruct
 */
TestOpaqueStruct * test_opaque_struct_new (void)
{
    return NULL;
}

void
test_opaque_struct_ref(TestOpaqueStruct * self)
{
    return;
}

void
test_opaque_struct_unref(TestOpaqueStruct * self)
{
    return;
}
