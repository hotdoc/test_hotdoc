#pragma once

#include <glib-object.h>

#define TEST_TYPE_OPAQUE_STRUCT (test_opaque_struct_get_type())

/**
 * TestOpaqueStruct:
 *
 * An Opaque structure
 */
typedef struct _TestOpaqueStruct TestOpaqueStruct;

GType test_opaque_struct_get_type (void);

TestOpaqueStruct * test_opaque_struct_new (void) G_GNUC_MALLOC;

void test_opaque_struct_ref(TestOpaqueStruct * self);
void test_opaque_struct_unref(TestOpaqueStruct * self);
