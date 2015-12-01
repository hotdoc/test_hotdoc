#include "test-other-file.h"

/**
 * test_bar_ze_foo:
 * @bar: a nice bar
 * @foo: a nicer foo
 *
 * This function will @bar ze @foo, provided
 * the foo is nice and not a la wack bar.
 */
gint
test_bar_ze_foo(gint bar, gint foo)
{
  return 42;
}

/**
 * test_bar_ze_bar:
 * @bar: a wack bar
 * @other_bar: another, nicer bar
 *
 * This function will bar ze wack bar with a nicer bar
 */
gint
test_bar_ze_bar(gint bar, gint other_bar)
{
  return 84 / 2;
}