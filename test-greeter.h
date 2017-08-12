#ifndef TEST_GREETER_H_
#define TEST_GREETER_H_

#include <glib-object.h>
#include "test_include.h"

/**
 * SECTION:test-greeter.h
 * @title: TestGreeter
 * @short_description: a *short* description
 *
 * This is a module to greet people.
 * Linking to #TestGreeter:count-greets
 */

G_BEGIN_DECLS

#define TEST_TYPE_GREETER (test_greeter_get_type ())
#define TEST_IS_GREETER(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), TEST_TYPE_GREETER))
#define TEST_IS_GREETER_CLASS(klass)		(G_TYPE_CHECK_CLASS_TYPE ((klass), TEST_TYPE_GREETER))
#define TEST_GREETER(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), TEST_TYPE_GREETER, TestGreeter))
#define TEST_GREETER_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), TEST_TYPE_GREETER, TestGreeterClass))

typedef struct _TestGreeter TestGreeter;
typedef struct _TestGreeterClass TestGreeterClass;

/**
 * TestGreeterTranslateFunction:
 * @greeter: The #TestGreeter asking for translation
 * @word: The word to translate
 *
 * This function shall return the translation of @word in any target language,
 * so that @greeter knows how to greet properly.
 *
 * Returns: (transfer full): The translation of @word
 */
typedef gchar * (* TestGreeterTranslateFunction) (TestGreeter *greeter, const gchar *word);

/**
 * TestGreeterCountUnit:
 *
 * The unit in which greets are counted.
 */
typedef gint TestGreeterCountUnit;

/**
 * TestGreeterThing:
 *
 * A thing.
 */
typedef const GObject *TestGreeterThing;

/**
 * _TestGreeterClass:
 * @do_greet: Subclasses can implement this to greet themselves
 */
struct _TestGreeterClass
{
  /*< private >*/
  GObjectClass parent_class;

  /*< public >*/
  void (*do_greet) (TestGreeter *greeter, const gchar *name, TestGreeterTranslateFunction func);
};

/**
 * TestSomeStruct:
 *
 * Just a random record.
 */

struct TestSomeStruct
{
  gboolean plop;
};

/**
 * _TestGreeter:
 * @greet_count: The number of times the greeter greeted.
 * @peer: A peer #TestGreeter
 *
 * The #TestGreeter structure. Use the functions to update
 * the variables please;
 */
struct _TestGreeter
{
  GObject parent;

  /*< public >*/
  TestGreeterCountUnit greet_count;
  TestGreeter *peer;
  /*< private >*/
  gboolean count_greets;
};

GType test_greeter_get_type ();

/**
 * test_greeter_greet_count:
 *
 * The number of times the greeter greeted.
 */
extern TestGreeterCountUnit test_greeter_greet_count;

void test_greeter_greet (TestGreeter *self,
                         const gchar *name,
                         TestGreeterTranslateFunction translator);

gchar
test_greeter_do_foo_bar (gint *foo, gchar *bar);

/**
 * TEST_GREETER_VERSION:
 *
 * The current version of the #TestGreeter
 */
#define TEST_GREETER_VERSION "1.0"

/**
 * TEST_GREETER_UPDATE_GREET_COUNT:
 * @greeter: a #TestGreeter
 *
 * Increments the greet counter.
 *
 * MT safe.
 *
 * Returns: void
 */
#define TEST_GREETER_UPDATE_GREET_COUNT(greeter) \
G_STMT_START {                                   \
  g_atomic_int_inc (&greeter->greet_count);      \
  g_atomic_int_inc (&test_greeter_greet_count);               \
} G_STMT_END;

/**
 * TestGreeterLanguage:
 * @TEST_GREETER_ENGLISH: Shakespeare language
 * @TEST_GREETER_FRENCH: Moliere Language
 *
 * A language for greeting.
 */
typedef enum _TestGreeterLanguage {
  TEST_GREETER_ENGLISH,
  TEST_GREETER_FRENCH
} TestGreeterLanguage;

TestGreeterTranslateFunction
test_greeter_get_translate_function (TestGreeter *greeter, TestGreeterLanguage language);

void
test_greeter_deprecated_function (TestGreeter *greeter);

gchar **
test_greeter_list_greets (TestGreeter *greeter);

GList*
test_greeter_get_friends (TestGreeter *greeter);

G_END_DECLS

#endif
